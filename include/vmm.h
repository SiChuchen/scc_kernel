#ifndef INCLUDE_VMM_H
#define INCLUDE_VMM_H

#include "types.h"
#include "idt.h"
#include "vmm.h"

// 内核偏移地址
// 内核在编译/链接时使用的虚拟起点，内核地址 = 物理地址 + PAGE_OFFSET（针对低端物理区的双重映射情形）
#define PAGE_OFFSET 	0xC0000000

/**
 * P--位0是存在（Present）标志，用于指明表项对地址转换是否有效。P=1表示有效；P=0表示无效。
 * 在页转换过程中，如果说涉及的页目录或页表的表项无效，则会导致一个异常。
 * 如果P=0，那么除表示表项无效外，其余位可供程序自由使用。
 * 例如，操作系统可以使用这些位来保存已存储在磁盘上的页面的序号。
 */
#define PAGE_PRESENT 	0x1

/** 
 * R/W--位1是读/写（Read/Write）标志。如果等于1，表示页面可以被读、写或执行。
 * 如果为0，表示页面只读或可执行。
 * 当处理器运行在超级用户特权级（级别0、1或2）时，则R/W位不起作用。
 * 页目录项中的R/W位对其所映射的所有页面起作用。
 */
#define PAGE_WRITE 	0x2

/**
 * U/S--位2是用户/超级用户（User/Supervisor）标志。
 * 如果为1，那么运行在任何特权级上的程序都可以访问该页面。
 * 如果为0，那么页面只能被运行在超级用户特权级（0、1或2）上的程序访问。
 * 页目录项中的U/S位对其所映射的所有页面起作用。
 */
#define PAGE_USER 	0x4

// 虚拟分页大小
#define PAGE_SIZE 	4096

// 页掩码，用于 4KB 对齐
#define PAGE_MASK      0xFFFFF000

// 获取一个地址的页目录项
// 从 32 位虚拟地址 x 取出高 10 位（bits 22..31）作为页目录索引（0..1023）
#define PGD_INDEX(x) (((x) >> 22) & 0x3FF)

// 获取一个地址的页表项
// 取中间 10 位（bits 12..21）作为页表项索引（0..1023）
#define PTE_INDEX(x) (((x) >> 12) & 0x3FF)

// 取低 12 位作为页内偏移（0..4095）
#define OFFSET_INDEX(x) ((x) & 0xFFF)

// 页目录数据类型
typedef uint32_t pgd_t;

// 页表数据类型
typedef uint32_t pte_t;

// 计算页目录项个数：4096/4 = 1024。即每个页目录页能容纳 1024 个 PDE。
#define PGD_SIZE (PAGE_SIZE / sizeof(pte_t))

// PTE 每页项数也是 4096/4 = 1024。即每个页表能索引 1024 个 4KB 页面 = 4MB。
#define PTE_SIZE (PAGE_SIZE / sizeof(uint32_t))

// 映射 512MB 内存所需要的页表数,每个页表映射 4MB，128 × 4MB = 512MB
#define PTE_COUNT 128

// 内核使用的页目录数组（通常是 1024 个 pgd_t），就是内核级别的页目录（PGD）
// 这个数组代表了内核的页目录（通常是内核链接时准备好的 pgd_kern），它的物理地址会写进 CR3 以启用该页表
extern pgd_t pgd_kern[PGD_SIZE];

// 初始化虚拟内存管理
void init_vmm();

// 更换当前的页目录
void switch_pgd(uint32_t pd);

// 使用 flags 指出的页权限，把物理地址 pa 映射到虚拟地址 va
void map(pgd_t *pgd_now, uint32_t va, uint32_t pa, uint32_t flags);

// 取消虚拟地址 va 的物理映射
void unmap(pgd_t *pgd_now, uint32_t va);

// 如果虚拟地址 va 映射到物理地址则返回 1，否则返回 0
// 同时如果 pa 不是空指针，则将映射的物理地址存入 *pa
uint32_t get_mapping(pgd_t *pgd_now, uint32_t va, uint32_t *pa);

// 页错误中断处理函数
void page_fault_handler(pt_regs *regs);


#endif 	// INCLUDE_VMM_H