#include "idt.h"
#include "string.h"
#include "debug.h"
#include "vmm.h"
#include "pmm.h"
#include "mm.h"
// 内核页目录区域
pgd_t pgd_kern[PGD_SIZE] __attribute__ ((aligned (PAGE_SIZE)));

// 内核页表区域
static pte_t pte_kern[PTE_COUNT][PTE_SIZE] __attribute__ ((aligned (PAGE_SIZE)));

// 判断一个页表页的物理地址是否属于内核预置的 pte_kern 区域
static inline int is_kernel_pte_phys(uint32_t pa)
{
    uint32_t start = (uint32_t)pte_kern - PAGE_OFFSET;
    uint32_t end = start + sizeof(pte_kern);
    return pa >= start && pa < end;
}

// 初始化虚拟内存管理
// 这里其实只是为高地址 0xC0000000 开始的 128 个 PDE（页目录项）建立了页表指针
// 然后填充了物理地址，而其他的页目录和页表项之间的关系并没有在这里建立
void init_vmm()
{
    // 0xC0000000 这个地址在页目录的索引 768
    uint32_t kern_pte_first_idx = PGD_INDEX(PAGE_OFFSET);

    uint32_t i,j;
    // 这里就是先把内核的页目录设置好放在高地址空间
    // 所以我们是从页目录索引为 768 的地方开始的
    // 这里的 (uint32_t)pte_kern[j] 是二维数组的开头的指针！所以这里指向的是页表项的首地址（虚拟地址）
    // 减去 PAGE_OFFSET 得到物理地址
    for (i = kern_pte_first_idx,j = 0;i < PTE_COUNT + kern_pte_first_idx;i ++,j ++)
    {
        // 这里是设置了页目录项，即 将 0 - 127 这前面 128 个页表项映射到页目录的 768 - 895 这部分
        pgd_kern[i] = ((uint32_t)pte_kern[j] - PAGE_OFFSET) | PAGE_PRESENT | PAGE_WRITE;
    }

    uint32_t *pte = (uint32_t *)pte_kern;
    // PTE_COUNT * PTE_SIZE = 128 * 1024 = 131072
    for (i = 1;i < PTE_COUNT * PTE_SIZE;i ++)
    {
        // 填充页表项，映射物理内存
        pte[i] = (i << 12) | PAGE_PRESENT | PAGE_WRITE;
    }

    // 页目录的物理地址
    uint32_t pgd_kern_phy_addr = (uint32_t)pgd_kern - PAGE_OFFSET;

    // 注册页错误（#PF，异常号 14）的处理函数，确保当发生缺页或保护错误时，内核能被调用到 page_fault_handler 来处理（例如懒分配、内核 panic、杀死用户进程等）
    register_interrupt_handler(14,&page_fault_handler);

    // 把页面目录的物理地址写入 CR3（实现切换到这个页目录）
    // 使上面建立的页表生效，CPU 开始用新的页表做地址转换
    switch_pgd(pgd_kern_phy_addr);
}

// 将页目录表首地址的物理地址写入 CR3 寄存器，切换当前页目录
void switch_pgd(uint32_t pd)
{
    asm volatile ("mov %0, %%cr3" : : "r" (pd));
}

// 内核源码（C）需要能够直接读写页目录（比如 pgd_now[pgd_index] = ...），所以把页目录本身也放在可访问的内核虚拟空间里
// pgd_now 是 指向页目录表在内核虚拟地址空间的指针
// 把物理页 pa 映射到虚拟地址 va，并用 flags 指定权限
void map(pgd_t *pgd_now,uint32_t va,uint32_t pa,uint32_t flags)
{
    // 页目录索引（哪一张页表）
    uint32_t pgd_index = PGD_INDEX(va);
    // 页表索引（页表中的哪一项）
    uint32_t pte_index = PTE_INDEX(va);

    // 取出 PDE（页目录项）并屏蔽出高位的页表物理基址（& PAGE_MASK）
    pte_t *pte = (pte_t *)(pgd_now[pgd_index] & PAGE_MASK);

    // 如果 PDE 为 0（即尚未为该 pgd_index 分配页表页）
    if(!pte)
    {
        page_t *pt_page = alloc_pages(1);
        assert(pt_page,"map: alloc page for page table failed");
        pgd_now[pgd_index] = page2pa(pt_page) | flags | PAGE_PRESENT | PAGE_WRITE;

        pte = (pte_t *)page2kva(pt_page);
        bzero(pte,PAGE_SIZE);
    }
    else
    {
        // 转换到内核线性地址
        pte = (pte_t *)((uint32_t)pte + PAGE_OFFSET);
    }

    pte[pte_index] = (pa & PAGE_MASK) | flags;

    // 通知 CPU 更新页表缓存
    asm volatile ("invlpg (%0)" : : "a" (va));
}

// 删除虚拟地址 va 的 PTE（使该虚拟页不再映射物理页）
void unmap(pgd_t *pgd_now,uint32_t va)
{
    uint32_t pgd_index = PGD_INDEX(va);
    uint32_t pte_index = PTE_INDEX(va);

    pte_t *pte = (pte_t *)(pgd_now[pgd_index] & PAGE_MASK);

    if(!pte)
    {
        return;
    }

    // 转换到内核线性地址
    pte = (pte_t *)((uint32_t)pte + PAGE_OFFSET);

    pte[pte_index] = 0;

    // 通知 CPU 更新页表缓存
    asm volatile ("invlpg (%0)" : : "a" (va));

    // 如果该页表页已空，且不属于内核静态页表，则回收之
    int empty = 1;
    for (uint32_t i = 0; i < PTE_SIZE; i++) {
        if (pte[i] & PAGE_PRESENT) {
            empty = 0;
            break;
        }
    }

    if (empty) {
        uint32_t pte_phys = pgd_now[pgd_index] & PAGE_MASK;
        if (!is_kernel_pte_phys(pte_phys)) {
            pgd_now[pgd_index] = 0;
            free_pages(pa2page(pte_phys), 1);
        }
    }
}

// 检查 va 是否有有效映射；若有且 pa 非空，则把物理页基址写进 *pa
uint32_t get_mapping(pgd_t *pgd_now, uint32_t va, uint32_t *pa)
{
	uint32_t pgd_index = PGD_INDEX(va);
	uint32_t pte_index = PTE_INDEX(va);

	pte_t *pte = (pte_t *)(pgd_now[pgd_index] & PAGE_MASK);
	if (!pte) {
	      return 0;
	}
	
	// 转换到内核线性地址
	pte = (pte_t *)((uint32_t)pte + PAGE_OFFSET);

	// 如果地址有效而且指针不为NULL，则返回地址
	if (pte[pte_index] != 0 && pa) {
		 *pa = pte[pte_index] & PAGE_MASK;
		return 1;
	}

	return 0;
}
