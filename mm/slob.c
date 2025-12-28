#include "slob.h"
#include "mm.h"
#include "pmm.h"
#include "debug.h"
#include "string.h"

/* 简易 SLOB（size-segregated free list）
 * 档次划分：32/64/128/256/512/1024/2048/4096
 * 小于等于 4096 的请求按档次分配，超过则整页分配
 *
 * 页头元数据：
 *   class_idx：档次索引，>= SLOB_CLASS_COUNT 表示大块
 *   n_pages  ：该分配占用的页数（大块或整页回收用）
 *
 * 小档切块时，在页首存元数据，剩余空间切成等长小块。
 */

//  档次配置
#define SLOB_CLASS_COUNT 8
static const uint32_t slob_sizes[SLOB_CLASS_COUNT] = {16, 32, 64, 128, 256, 512, 1024, 2048};

// 小块链表节点
typedef struct slob_block {
    struct slob_block *next;
} slob_block_t;

typedef struct slob_page_meta {
    // 0..7 表示这是一个“小块页”，页内块大小是 slob_sizes[class_idx]
    // =8 表示这是“大块分配”，不是按档次切块得到的
    uint32_t class_idx;    /* 档次索引，>=SLOB_CLASS_COUNT 表示大块 */
    // 小块页：固定 1
    // 大块：记录这次分配占用了多少页，释放时用
    uint32_t n_pages;      /* 占用页数（大块或整页回收用） */
} slob_page_meta_t;

// class_free[idx] 指向该档次的一条 free list
static slob_block_t *class_free[SLOB_CLASS_COUNT];

// 根据请求的size大小，选择合适的分配挡位
static inline uint32_t pick_class(uint32_t sz)
{
    for (uint32_t i = 0; i < SLOB_CLASS_COUNT; i++) {
        if (slob_sizes[i] >= sz) {
            return i;
        }
    }
    return SLOB_CLASS_COUNT; // 需要大块
}

void init_slob()
{
    for (uint32_t i = 0; i < SLOB_CLASS_COUNT; i++) {
        class_free[i] = 0;
    }
}

/* 分配内存 */
void *kmalloc(uint32_t sz)
{
    if (sz == 0) {
        return NULL;
    }

    uint32_t idx = pick_class(sz);

    // 大块：按页分配，页首写元数据
    if (idx == SLOB_CLASS_COUNT) {
        // 真实需要的空间 = 用户请求 + 元数据
        uint32_t total = sz + sizeof(slob_page_meta_t);
        // 向上取整，确保分配的页是足够的
        uint32_t pages = (total + PAGE_SIZE - 1) / PAGE_SIZE;
        page_t *pg = alloc_pages(pages);
        assert(pg, "kmalloc large alloc_pages failed");

        // 这段分配的内存开头先写元数据
        slob_page_meta_t *meta = (slob_page_meta_t *)page2kva(pg);
        meta->class_idx = SLOB_CLASS_COUNT;
        meta->n_pages = pages;

        // “强制转换”为 uint8_t*：把某个地址当成“字节指针”来做偏移或访问内存
        return (void *)((uint8_t *)meta + sizeof(*meta));
    }

    // 小块：确保该档次有空闲块；如果没有，从新页切块
    slob_block_t *blk = class_free[idx];
    // 看该档次有没有空闲块
    if (!blk) {
        page_t *pg = alloc_pages(1);
        assert(pg, "kmalloc slob page alloc failed");
        uint8_t *base = (uint8_t *)page2kva(pg);

        // 写页头元数据
        slob_page_meta_t *meta = (slob_page_meta_t *)base;
        meta->class_idx = idx;
        meta->n_pages = 1;

        // 把 base 移到“元数据之后”
        base += sizeof(*meta);
        // 页里真正可切块的空间大小
        uint32_t usable = PAGE_SIZE - sizeof(*meta);
        // 每块大小
        uint32_t chunk = slob_sizes[idx];
        // 这页能切出多少个块（向下取整，剩余碎片丢弃）
        uint32_t count = usable / chunk;

        blk = NULL; 
        // 头插法建立链表，blk最终指向表头元素
        for (uint32_t i = 0; i < count; i++) {
            slob_block_t *b = (slob_block_t *)(base + i * chunk);
            b->next = blk;
            blk = b;
        }
        class_free[idx] = blk;
    }

    class_free[idx] = blk->next;
    return (void *)blk;
}

/* 释放内存 */
void kfree(void *p)
{
    if (!p) {
        return;
    }

    uint32_t va = (uint32_t)p;
    uint32_t page_base = va & PAGE_MASK;
    // 这里拿到的是整个页的页首的页元数据的数据结构
    slob_page_meta_t *meta = (slob_page_meta_t *)page_base;

    if (meta->class_idx >= SLOB_CLASS_COUNT) {
        // 大块：按记录的页数归还
        free_pages(kva2page((void *)meta), meta->n_pages);
        return;
    }

    // 小块：挂回对应档次链表，使用头插法将其归还
    // 这里直到了我们要归还的小页是哪个档次的
    uint32_t idx = meta->class_idx;
    // 将这块内存重新强制转换成 slob_block_t 类型
    slob_block_t *blk = (slob_block_t *)p;
    // 让它的下一个元素等于当前的链表头
    blk->next = class_free[idx];
    class_free[idx] = blk;
}

// 基本自检：小块、大块分配/释放，日志输出
#ifdef SLOB_TEST
void test_slob()
{
    printk_color(rc_black, rc_light_brown, "Test SLOB allocator...\n");

    void *a = kmalloc(16);    // 将归入 32 字节档
    void *b = kmalloc(100);   // 128 档
    void *c = kmalloc(5000);  // 大于 4096，触发整页分配

    printk("kmalloc 16  -> %p\n", a);
    printk("kmalloc 100 -> %p\n", b);
    printk("kmalloc 5000-> %p\n", c);

    if (!a || !b || !c) {
        panic("SLOB alloc test failed");
    }

    kfree(a);
    kfree(b);
    kfree(c);

    // 再做一组小块分配，确保链表回收正常
    void *arr[8];
    for (int i = 0; i < 8; i++) {
        arr[i] = kmalloc(64);
        if (!arr[i]) {
            panic("SLOB small alloc failed");
        }
    }
    for (int i = 0; i < 8; i++) {
        kfree(arr[i]);
    }

    printk_color(rc_black, rc_light_brown, "SLOB alloc/free basic test passed\n\n");
}
#endif
