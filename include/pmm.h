#ifndef INCLUDE_PMM_H_
#define INCLUDE_PMM_H_

#include "types.h"
#include "multiboot.h"

// 线程栈大小
#define STACK_SIZE 8192

// 支持的最大的物理内存(512MB)
#define PMM_MAX_SIZE 0x20000000

// 物理内存页框大小
#define PMM_PAGE_SIZE 0x1000

// 最多支持的物理内存页面个数
#define PAGE_MAX_SIZE (PMM_MAX_SIZE / PMM_PAGE_SIZE)

// 页掩码 按照 4096 对齐地址 0xFFFFF000
#define PHY_PAGE_MASK (~(PMM_PAGE_SIZE - 1))

// 地址按页对齐：若本来对齐，则不变，若不对齐，则落到下一页开始处
#define PAGE_ALIGN(addr) (((addr) + PMM_PAGE_SIZE - 1) & PHY_PAGE_MASK)

// 内核文件在内存中的起始和结束位置（链接脚本定义）
extern uint8_t kern_start[];
extern uint8_t kern_end[];

// 页元数据类型在 mm.h 中定义，这里做前置声明避免循环包含
struct page;
typedef struct page page_t;

// 页元数据数组基址（内核虚拟地址），在 init_pmm() 中初始化
extern page_t *pages;

// 当前空闲物理页总数
extern uint32_t phy_page_count;

// 输出 BIOS 提供的物理内存布局
void show_memory_map();

// 初始化物理内存管理（建立页元数据并填充空闲链表）
void init_pmm();

// 新接口：分配/释放连续物理页（实现位于 pmm.c）
page_t *alloc_pages(uint32_t n);
void free_pages(page_t *base, uint32_t n);

// 兼容旧接口：分配/释放单个物理页，返回物理地址
uint32_t pmm_alloc_page();
void pmm_free_page(uint32_t p);

#endif /* INCLUDE_PMM_H_ */
