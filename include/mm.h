#ifndef INCLUDE_MM_H_
#define INCLUDE_MM_H_

#include "types.h"
#include "vmm.h"
#include "pmm.h"

// 用一个统一的元数据结构描述“一个物理页”的状态，内核后续的分配、释放、映射都操作它，而不是直接操作裸物理地址
typedef struct page {
    uint32_t flags;         /* 标志：保留/空闲等 */
    uint32_t ref;           /* 引用计数 */
    uint32_t run;           /* 连续空闲块长度（页数），仅在空闲链表节点上有效 */
    struct page *next;      /* 空闲链表指针（按物理地址有序，用于合并） */
} page_t;

#define PG_RESERVED   0x1     // 页面被保留，不能分配（如低端、内核自身、元数据所在页）
#define PG_FREE      0x2     // 页面空闲，可以分配

// pages 指向一个 page_t 数组的起始地址
extern page_t *pages;           /* 页元数据数组基址（内核虚拟地址） */

// 物理地址 → 页描述符指针,通过物理地址快速定位到它对应的元数据对象
static inline page_t *pa2page(uint32_t pa)
{
    return pages + (pa >> 12);
}

// 页描述符指针 → 物理页起始地址,从页元数据反推出对应物理页的起始地址
static inline uint32_t page2pa(page_t *p)
{
    return ((uint32_t)(p - pages) << 12);
}

// 页描述符 → 内核虚拟地址（线性映射）
static inline void *page2kva(page_t *p)
{
    return (void *)(page2pa(p) + PAGE_OFFSET);
}

// 内核虚拟地址 → 页描述符（高半地址减去 PAGE_OFFSET 再换算页号）
static inline page_t *kva2page(void *kva)
{
    return pa2page((uint32_t)kva - PAGE_OFFSET);
}

// 新的物理页分配接口（实现放在 pmm.c）
// n 表示连续页数，返回起始页的 page_t 指针；失败返回 NULL
page_t *alloc_pages(uint32_t n);
// 释放从 base 开始的 n 个连续页
void free_pages(page_t *base, uint32_t n);

#endif  // INCLUDE_MM_H_
