/* 物理内存管理（Physical Memory Manager）
 * 使用栈式页框分配器管理物理内存
 * 页大小：4KB（0x1000 字节）
 * 最大支持：512MB 物理内存
 *
 * 工作原理：
 * - 将所有可用的物理页框地址存储在一个栈中
 * - 分配时从栈顶弹出一个页框地址
 * - 释放时将页框地址压入栈顶
 */

#include "multiboot.h"
#include "common.h"
#include "debug.h"
#include "pmm.h"

// 物理内存页面管理栈
// 每个元素存储一个 4KB 页框的起始物理地址
static uint32_t pmm_stack[PAGE_MAX_SIZE + 1];

// 物理内存管理栈的栈顶指针
// 指向栈中最后一个有效元素的索引
static uint32_t pmm_stack_top;

// 可用物理内存页的总数量
uint32_t phy_page_count;

// 显示 BIOS 提供的物理内存布局
// 遍历 Multiboot 信息中的内存映射表，打印每个内存区域的信息
void show_memory_map()
{
    // 从 Multiboot 信息结构中获取内存映射表
    uint32_t mmap_addr = glb_mboot_ptr->mmap_addr;      // 内存映射表的起始地址
    uint32_t mmap_length = glb_mboot_ptr->mmap_length;  // 内存映射表的总长度（字节）

    printk("Memory map:\n");

    // 遍历内存映射表
    // 注意：不能简单地按固定步长遍历，因为每个条目的大小可能不同
    mmap_entry_t *mmap;
    for (mmap = (mmap_entry_t *)mmap_addr; (uint32_t)mmap < mmap_addr + mmap_length; 
            mmap = (mmap_entry_t *)((uint32_t)mmap + mmap -> size + sizeof(mmap -> size)))
    {
        // 打印每个内存区域的信息
        // base_addr: 起始地址（64位，分为高32位和低32位）
        // length: 长度（64位，分为高32位和低32位）
        // type: 类型（1=可用内存，其他=保留区域）
        printk("base_addr = 0x%x%08x,length = 0x%x%08x, type = 0x%x\n",
               (uint32_t)mmap->base_addr_high, (uint32_t)mmap->base_addr_low,
               (uint32_t)mmap->length_high, (uint32_t)mmap->length_low,
               (uint32_t)mmap->type);
    }
}

// 初始化物理内存管理
// 遍历 Multiboot 内存映射表，将所有可用的物理页框加入管理栈
void init_pmm()
{
    // 获取内存映射表的起始和结束地址
    mmap_entry_t *mmap_start_addr = (mmap_entry_t *)glb_mboot_ptr->mmap_addr;
    mmap_entry_t *mmap_end_addr = (mmap_entry_t *)glb_mboot_ptr->mmap_addr + glb_mboot_ptr->mmap_length;

    mmap_entry_t *map_entry;

    // 遍历内存映射表中的每个条目
    for (map_entry = mmap_start_addr; map_entry < mmap_end_addr; map_entry++)
    {
        // 检查是否为可用内存区域
        // type == 1 表示可用 RAM
        // base_addr_low == 0x100000 表示从 1MB 开始的内存区域
        // （0-1MB 区域留给 BIOS 和内核自身使用）
        if (map_entry->type == 1 && map_entry->base_addr_low == 0x100000)
        {
            // 计算可用内存的起始地址
            // 跳过内核占用的部分：内核从 0x100000 开始，到 kern_end 结束
            // kern_start 和 kern_end 是链接器脚本中定义的符号
            uint32_t page_addr = map_entry->base_addr_low + (uint32_t)(kern_end - kern_start);

            // 计算可用内存的结束地址
            uint32_t length = map_entry->base_addr_low + map_entry->length_low;

            // 将该区域中的所有页框加入管理栈
            while (page_addr < length && page_addr <= PMM_MAX_SIZE)
            {
                // 将页框地址加入空闲页框栈
                pmm_free_page(page_addr);
                // 移动到下一个页框（页大小为 4KB = 0x1000）
                page_addr += PMM_PAGE_SIZE;
                // 增加可用页框计数
                phy_page_count++;
            }
        }
    }
}

// 分配一个物理内存页
// 返回：分配的页框的起始物理地址
uint32_t pmm_alloc_page()
{
    // 检查是否还有可用页框
    // pmm_stack_top == 0 表示栈为空
    assert(pmm_stack_top != 0, "out of memory");

    // 从栈顶弹出一个页框地址
    uint32_t page = pmm_stack[pmm_stack_top--];

    return page;
}

// 释放一个物理内存页
// p - 要释放的页框的起始物理地址
void pmm_free_page(uint32_t p)
{
    // 检查栈是否已满
    // pmm_stack_top == PAGE_MAX_SIZE 表示栈已满
    assert(pmm_stack_top != PAGE_MAX_SIZE, "out of pmm_stack stack");

    // 将页框地址压入栈顶
    pmm_stack[++pmm_stack_top] = p;
}
