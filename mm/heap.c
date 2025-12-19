#include "debug.h"
#include "pmm.h"
#include "vmm.h"
#include "heap.h"

// 申请内存块 确保 [start, start+len) 这段虚拟地址有足够的物理页映射（不管里面有没有被“堆块”用完）
static void alloc_chunk(uint32_t start,uint32_t len);

// 释放内存块 在堆尾释放多余的物理页
static void free_chunk(header_t *chunk);

// 切分内存块 在一个大块中切出一个“前半块”给当前分配使用，后半块变成新的空闲块
static void split_chunk(header_t *chunk,uint32_t len);

// 合并内存块 把相邻的空闲块合并起来，避免内存碎片；如果位于尾端，还会调用 free_chunk 把多余页释放给物理内存管理器
static void glue_chunk(header_t *chunk);

// 初始时，堆还没真正映射任何页，所以 heap_max == HEAP_START。
// 每当通过 alloc_chunk 申请新的页，就会 heap_max += PAGE_SIZE，表示堆扩展了。
static uint32_t heap_max = HEAP_START;

// 内存块管理头指针
static header_t *heap_first;


// 堆初始化
void init_heap()
{
    heap_first = 0;
}

// 堆内存分配
void *kmalloc(uint32_t len)
{
    // 所有申请的内存长度加上管理头的长度
    // 因为在内存申请和释放的时候要通过该结构去管理
    len += sizeof(header_t);

    // 遍历链表时的当前块
    header_t *cur_header = heap_first;
    // 记录当前块的前驱
    header_t *prev_header = 0;

    while (cur_header)
    {
        // 如果当前的内存块没有被申请过并且长度大于待申请的块
        if (cur_header -> allocated == 0 && cur_header -> length >= len)
        {
            // 按照当前长度切割内存
            split_chunk(cur_header,len);
            cur_header -> allocated = 1;

            // 返回的时候必须将指针挪到管理结构之后
            return (void *)((uint32_t)cur_header + sizeof(header_t));
        }

        // 逐次推移指针
        prev_header = cur_header;
        cur_header = cur_header -> next;
    }

    uint32_t chunk_start;

    // 第一次执行该函数则初始化内存块起始位置
    // 之后根据当前指针加上申请的长度即可

    if (prev_header)
    {
        chunk_start = (uint32_t)prev_header + prev_header -> length;
    }
    else
    {
        chunk_start = HEAP_START;
        heap_first = (header_t *)chunk_start;
    }

    // 检查是否需要申请内存页
    alloc_chunk(chunk_start,len);
    cur_header = (header_t *)chunk_start;
    cur_header -> prev = prev_header;
    cur_header -> next = 0;
    cur_header -> allocated = 1;
    cur_header -> length = len;

    if (prev_header)
    {
        prev_header -> next = cur_header;
    }

    return (void *)(chunk_start + sizeof(header_t));
}


// 释放内存
// 传进来的 p 是当初 kmalloc 返回的“数据区起始地址”
void kfree(void *p)
{
    // 指针回退到管理结构，并将已经使用标记置0
    header_t *header = (header_t *)((uint32_t)p -sizeof(header_t));
    header -> allocated = 0;

    // 尝试合并内存块
    glue_chunk(header);
}


// 按需拓展堆
// 保证 [start, start+len) 的虚拟范围在当前堆上界 heap_max 之内,如果不够，就不断向上扩展堆，直到 heap_max >= start+len
void alloc_chunk(uint32_t start,uint32_t len)
{
    // 如果当前堆的位置已经到达界限则申请内存页
    // 必须循环申请内存页直到有到足够的可用内存
    while (start +len > heap_max)
    {
        // 分配真正的物理页用于内核堆使用
        uint32_t page = pmm_alloc_page();
        // 通过页表建立虚拟地址和物理地址的映射
        map(pgd_kern,heap_max,page,PAGE_PRESENT | PAGE_WRITE);
        heap_max += PAGE_SIZE;
    }
}

// 在堆尾释放多余页
// 这里的 chunk 必须是链表中的某个块，而且调用方保证它是堆尾（在 glue_chunk 的尾部判断）
void free_chunk(header_t *chunk)
{
    if (chunk -> prev == 0)
    {
        heap_first = 0;
    }
    else
    {
        chunk -> prev -> next = 0;
    }

    // 空闲的内存超过 1 页的话就释放掉
    while ((heap_max - PAGE_SIZE) >= (uint32_t)chunk)
    {
        heap_max -= PAGE_SIZE;

        // 存储当前堆顶对应的物理页的地址
        uint32_t page;
        // 查出当前这个虚拟地址对应的物理页帧
        get_mapping(pgd_kern,heap_max,&page);
        // 取消该地址在页表中的映射
        unmap(pgd_kern,heap_max);
        // 释放物理页
        pmm_free_page(page);
    }
}


// 切分内存块
// 
void split_chunk(header_t *chunk,uint32_t len)
{
    // 切分内存块之前要保证之后的剩余的内存至少能够容纳一个内存管理块的大小
    if (chunk -> length - len > sizeof(header_t))
    {
        header_t *newchunk = (header_t *)((uint32_t)chunk + len);
        newchunk -> prev = chunk;
        newchunk -> next = chunk -> next;
        newchunk -> allocated = 0;
        newchunk -> length = chunk -> length - len;

        chunk -> next = newchunk;
        chunk -> length = len;
    }
}

// 合并相邻的空闲块
void glue_chunk(header_t *chunk)
{
    // 先尝试和后面的块合并，如果该内存块后面又链内存块并且没有被使用则要进行合并
    if (chunk -> next && chunk -> next -> allocated == 0)
    {
        chunk -> length = chunk -> length + chunk -> next -> length;
        if (chunk -> next -> next)
        {
            chunk -> next -> next -> prev = chunk;
        }
        chunk -> next = chunk -> next -> next;
    }

    // 再尝试和前面的块合并，如果该内存块前面有链内存块且未被使用则拼合
    if (chunk -> prev && chunk -> prev -> allocated == 0)
    {
        chunk -> prev -> length = chunk -> prev -> length + chunk -> length;
        chunk -> prev -> next = chunk -> next;
        if (chunk -> next)
        {
            chunk -> next -> prev = chunk -> prev;
        }
        chunk = chunk -> prev;
    }

    // 如果合并后的 chunk 已经 位于链表末尾（next == 0）
    if (chunk -> next == 0)
    {
        free_chunk(chunk);
    }
}


// 测试内核堆的申请和释放
void test_heap()
{
    printk_color(rc_black,rc_magenta,"Test kmalloc() && kfree() now ...\n\n");

    void *addr1 = kmalloc(1000);
    printk("kmalloc   1000 byte in 0x%X\n",addr1);
    void *addr2 = kmalloc(5000);
    printk("kmalloc   5000 byte in 0x%X\n",addr2);
    void *addr3 = kmalloc(30000);
    printk("kmalloc  30000 byte in 0x%X\n",addr3);
    void *addr4 = kmalloc(70000);
    printk("kmalloc  70000 byte in 0x%X\n\n",addr4);

    printk("free mem in 0x%X\n",addr1);
    kfree(addr1);
    printk("free mem in 0x%X\n",addr2);
    kfree(addr2);
    printk("free mem in 0x%X\n",addr3);
    kfree(addr3);
    printk("free mem in 0x%X\n\n",addr4);
    kfree(addr4);
}