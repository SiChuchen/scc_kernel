/* 物理内存管理（Physical Memory Manager）
 * 使用页元数据 + 有序空闲链表分配器，支持连续页的 first-fit
 * 页大小：4KB（0x1000 字节）
 * 最大支持：512MB 物理内存
 */

#include "common.h"
#include "debug.h"
#include "string.h"
#include "mm.h"
#include "pmm.h"

// 页元数据数组基址（内核虚拟地址），在 init_pmm() 中放置到 kern_end 之后
page_t *pages;

// 空闲页链表头（按物理地址升序，节点 run 表示连续空闲段长度）
static page_t *free_list = 0;

// 当前可用物理页总数
uint32_t phy_page_count;

// 显示 BIOS 提供的物理内存布局
void show_memory_map()
{
    uint32_t mmap_addr = glb_mboot_ptr->mmap_addr;
    uint32_t mmap_length = glb_mboot_ptr->mmap_length;

    printk("Memory map:\n");

    mmap_entry_t *mmap = (mmap_entry_t *)(mmap_addr + PAGE_OFFSET);
    mmap_entry_t *mmap_end = (mmap_entry_t *)(mmap_addr + mmap_length + PAGE_OFFSET);

    for (; mmap < mmap_end;
         mmap = (mmap_entry_t *)((uint32_t)mmap + mmap->size + sizeof(mmap->size)))
    {
        printk("base_addr = 0x%x%08x,length = 0x%x%08x, type = 0x%x\n",
               (uint32_t)mmap->base_addr_high, (uint32_t)mmap->base_addr_low,
               (uint32_t)mmap->length_high, (uint32_t)mmap->length_low,
               (uint32_t)mmap->type);
    }
}

// 判断一个物理页是否属于保留区域：低端、内核自身、页元数据所在区
static inline int is_reserved(uint32_t pa, uint32_t kern_start_pa, uint32_t meta_end_pa)
{
    return pa < 0x100000 || (pa >= kern_start_pa && pa < meta_end_pa);
}

// 在有序空闲链表中插入一个空闲块，并尝试与前后相邻块合并
static void free_list_insert_merge(page_t *block)
{
    page_t *prev = NULL, *cur = free_list;

    // 从头开始遍历，直到找到我们要插入的块在链表中的位置
    while (cur && cur < block) {
        prev = cur;
        cur = cur->next;
    }

    block->next = cur;
    block->flags |= PG_FREE;

    // 先尝试与前一个块合并
    if (prev && (page2pa(prev) + prev->run * PMM_PAGE_SIZE == page2pa(block))) {
        prev->run += block->run;
        block = prev;
    } else {
        if (prev) {
            prev->next = block;
        } else {
            free_list = block;
        }
    }

    // 再尝试与后一个块合并
    if (cur && (page2pa(block) + block->run * PMM_PAGE_SIZE == page2pa(cur))) {
        block->run += cur->run;
        block->next = cur->next;
    }
}

// 把一个连续空闲段（物理起点 + 长度）放入链表
static void push_free_run(uint32_t start_pa, uint32_t len)
{
    if (len == 0) {
        return;
    }
    page_t *p = pa2page(start_pa);
    p->run = len;
    p->ref = 0;
    p->flags = PG_FREE;
    p->next = NULL;
    free_list_insert_merge(p);
    phy_page_count += len;
}

// 初始化物理内存管理：建立页元数据数组，遍历 mmap 链接空闲页
void init_pmm()
{
    // 计算内核的物理地址范围（kern_* 是高半虚拟地址）
    uint32_t kern_start_pa = (uint32_t)kern_start - PAGE_OFFSET;
    uint32_t kern_end_pa   = (uint32_t)kern_end   - PAGE_OFFSET;

    // 把页元数据数组放在 kern_end 之后，并按页对齐
    // 页元数据数组的初始物理地址
    uint32_t meta_start_pa = PAGE_ALIGN(kern_end_pa);
    // 页元数据数组的大小
    uint32_t meta_size     = PAGE_MAX_SIZE * sizeof(page_t);
    // 页元数据数组的结束物理地址
    uint32_t meta_end_pa   = meta_start_pa + meta_size;

    // pages 指向元数据数组的高半虚拟地址，元数据数组的初始虚拟地址
    pages = (page_t *)(meta_start_pa + PAGE_OFFSET);
    // 把这块区域清空用于作为页元数据数组的存放区
    bzero(pages, meta_size);

    phy_page_count = 0;
    free_list = 0;

    // 遍历 multiboot 提供的物理内存映射（物理地址转换为高半虚拟地址访问）
    uint32_t mmap_addr = glb_mboot_ptr->mmap_addr;
    uint32_t mmap_length = glb_mboot_ptr->mmap_length;
    mmap_entry_t *mmap = (mmap_entry_t *)(mmap_addr + PAGE_OFFSET);
    mmap_entry_t *mmap_end = (mmap_entry_t *)(mmap_addr + mmap_length + PAGE_OFFSET);

    // 这个大循环遍历的是保留区域和可用内存区域，是一段区域，是multiboot提供的内存映射表
    for (; mmap < mmap_end;
         mmap = (mmap_entry_t *)((uint32_t)mmap + mmap->size + sizeof(mmap->size)))
    {
        if (mmap->type != 1) {
            continue;   // 非可用内存区域直接跳过
        }

        // 这里得到的是一段可用的ram，而不是一页，所以这里要将这一段全部组织成页
        uint32_t begin = (uint32_t)mmap->base_addr_low;
        uint32_t end   = begin + (uint32_t)mmap->length_low;

        // 起始地址按页对齐
        begin = PAGE_ALIGN(begin);

        // 累积连续的空闲页段，遇到保留区就 flush
        uint32_t run_start = 0;
        uint32_t run_len = 0;

        for (uint32_t pa = begin; pa + PMM_PAGE_SIZE <= end && pa <= PMM_MAX_SIZE; pa += PMM_PAGE_SIZE)
        {
            // 如果这个页处于内核和元数据所在区域，则标记为保留页
            if (is_reserved(pa, kern_start_pa, meta_end_pa)) {
                // 遇到保留页，先把前面的空闲 run 刷入链表
                push_free_run(run_start, run_len);
                run_start = 0;
                run_len = 0;

                page_t *p = pa2page(pa);
                p->flags = PG_RESERVED;
                p->ref = 0;
                p->run = 0;
                p->next = NULL;
                // 跳过当前循环，强迫开启下次循环
                continue;
            }

            if (run_len == 0) {
                run_start = pa;
                run_len = 1;
            } else if (pa == run_start + run_len * PMM_PAGE_SIZE) {
                run_len++;
            } else {
                // 非连续，先 flush 之前的 run，再开始新的
                push_free_run(run_start, run_len);
                run_start = pa;
                run_len = 1;
            }
        }

        // 刷新本段末尾尚未入链的 run
        push_free_run(run_start, run_len);
    }

    printk("pmm init: free pages = %u\n", phy_page_count);
}

// 分配连续 n 页（first-fit）
page_t *alloc_pages(uint32_t n)
{
    page_t *prev = NULL, *cur = free_list;

    while (cur) {
        if (cur->run >= n) {
            page_t *ret = cur;

            if (cur->run == n) {
                // 恰好整段取走
                if (prev) {
                    prev->next = cur->next;
                } else {
                    free_list = cur->next;
                }
            } else {
                // 切割前 n 页，剩余部分继续留在空闲链表
                page_t *remain = cur + n;
                remain->run = cur->run - n;
                remain->flags = PG_FREE;
                remain->ref = 0;
                remain->next = cur->next;

                if (prev) {
                    prev->next = remain;
                } else {
                    free_list = remain;
                }
            }

            ret->run = n;
            ret->flags &= ~PG_FREE;
            ret->ref = 1;
            ret->next = NULL;
            return ret;
        }

        prev = cur;
        cur = cur->next;
    }

    return NULL; // 无可用空闲块
}

// 释放连续 n 页（按物理地址插入并尝试合并）
void free_pages(page_t *base, uint32_t n)
{
    base->run = n;
    base->ref = 0;
    base->flags = PG_FREE;
    base->next = NULL;
    free_list_insert_merge(base);
}

// 兼容旧接口：返回物理地址
uint32_t pmm_alloc_page()
{
    page_t *p = alloc_pages(1);
    return p ? page2pa(p) : 0;
}

void pmm_free_page(uint32_t p)
{
    free_pages(pa2page(p), 1);
}
