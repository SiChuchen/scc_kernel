/* 内核 C 入口点
 * boot.s 汇编代码设置好栈后会跳转到这里
 * 负责初始化所有内核子系统
 */

#include "types.h"
#include "console.h"
#include "debug.h"
#include "gdt.h"
#include "idt.h"
#include "timer.h"
#include "pmm.h"
#include "vmm.h"
#include "heap.h"
#include "slob.h"
#include "sched.h"
#include "task.h"
#include "common.h"
#include "mm.h"
#include "pmm.h"
// 内核初始化函数
void kern_init();

// 开启分页机制之后的 Multiboot 指针
multiboot_t *glb_mboot_ptr;

// 开启分页机制之后的内核栈
char kern_stack[STACK_SIZE];

// 内核栈的栈顶
uint32_t kern_stack_top;

// 内核使用的临时页表和页目录
// 该地址必须是页对齐的地址，内存的 0 - 640KB 肯定是空闲的
__attribute__((section(".init.data"))) pgd_t *pgd_tmp  = (pgd_t *)0x1000;
__attribute__((section(".init.data"))) pgd_t *pte_low  = (pgd_t *)0x2000;
__attribute__((section(".init.data"))) pgd_t *pte_hign = (pgd_t *)0x3000;


// 内核入口函数
// 未开启分页之前，我们要让这个函数运行在低地址
__attribute__((section(".init.text"))) void kern_entry()
{
	// PDE0 = 0x2000 | P | W
	pgd_tmp[0] = (uint32_t)pte_low | PAGE_PRESENT | PAGE_WRITE;
	// pgd_tmp[768] = 0x3000 | P | W;  // 指向页表 pte_hign
	pgd_tmp[PGD_INDEX(PAGE_OFFSET)] = (uint32_t)pte_hign | PAGE_PRESENT | PAGE_WRITE;

	// 映射内核虚拟地址 4MB 到物理地址的前 4MB
	int i;
	for (i = 0; i < 1024; i++) {
		pte_low[i] = (i << 12) | PAGE_PRESENT | PAGE_WRITE;
	}

	// 映射 0x00000000-0x00400000 的物理地址到虚拟地址 0xC0000000-0xC0400000
	for (i = 0; i < 1024; i++) {
		pte_hign[i] = (i << 12) | PAGE_PRESENT | PAGE_WRITE;
	}
	
	// 设置临时页表
	asm volatile ("mov %0, %%cr3" : : "r" (pgd_tmp));

	uint32_t cr0;

	// 启用分页，将 cr0 寄存器的分页位置为 1 就好
	asm volatile ("mov %%cr0, %0" : "=r" (cr0));
	cr0 |= 0x80000000;
	asm volatile ("mov %0, %%cr0" : : "r" (cr0));
	
	// 切换内核栈
	kern_stack_top = ((uint32_t)kern_stack + STACK_SIZE) & 0xFFFFFFF0;
	asm volatile ("mov %0, %%esp\n\t"
			"xor %%ebp, %%ebp" : : "r" (kern_stack_top));

	// 更新全局 multiboot_t 指针
	// 只是让指针转换到了高的虚拟地址，但是由于双重映射的关系，其实其物理地址并没有变化
	glb_mboot_ptr = mboot_ptr_tmp + PAGE_OFFSET;

	// 调用内核初始化函数
	kern_init();
}

int flag = 0;

int thread(void *arg)
{
	while(1)
	{
		if (flag == 1)
		{
			printk_color(rc_black, rc_light_green, "In thread: %s\n", (char *)arg);
			flag = 0;
		}
	}

	return 0;
}


// 调用这个函数的时候已经开启了分页，所以使用这个函数的时候已经运行在分页机制下了
// 所以此时函数已经位于高地址了
// 负责按顺序初始化所有内核子系统
void kern_init()
{
	// 初始化调试功能
	// 从 multiboot 信息中提取 ELF 符号表，用于栈回溯时显示函数名
	init_debug();

	// 初始化全局描述符表（GDT）
	// 设置内核代码段、数据段、用户代码段、用户数据段
	init_gdt();

	// 初始化中断描述符表（IDT）
	// 设置 CPU 异常处理、硬件中断（IRQ）处理
	// 重新映射 8259A PIC 中断向量
	init_idt();

	// 清屏，准备输出内核启动信息
	console_clear();

	// 打印 GDT/IDT 初始化成功信息
	printk_color(rc_black, rc_green, "Hello, OS kernel!\n");

	// 初始化定时器（PIT）
	// 设置为 200 Hz，即每秒产生 200 次时钟中断
	printk_color(rc_black, rc_green, "Initialize PIT\n");
	init_timer(200);

	// 开启中断
	// 在初始化完 GDT、IDT 和定时器后，必须开启 CPU 的中断标志位
	// 否则即使硬件产生中断信号，CPU 也不会响应
	// asm volatile ("sti");

	// 打印内核在内存中的位置信息
	// kern_start 和 kern_end 是链接器脚本（scripts/kernel.ld）中定义的符号
	printk("kernel in memory start: 0x%08X\n", kern_start);
	printk("kernel in memory end:   0x%08X\n", kern_end);
	printk("kernel in memory used:   %d KB\n\n", (kern_end - kern_start) / 1024);

	// 显示 BIOS 提供的物理内存布局
	// 遍历 multiboot 内存映射表，打印每个内存区域的信息
	// show_memory_map();

	// 初始化物理内存管理器
    // 将所有可用的物理页框加入管理栈
	init_pmm();
	init_vmm();
	init_slob();

#ifdef SLOB_TEST
    test_slob();
#endif



	// 打印可用物理内存页的数量
	printk_color(rc_black, rc_red, "\nThe Count of Physical Memory Page is: %u\n\n", phy_page_count);

	// test_heap(); // 旧堆测试暂时关闭，可改为 SLOB 自测

	// 测试物理内存分配
	// 连续分配 4 个物理页，打印它们的地址
	// uint32_t allc_addr = NULL;
	// printk_color(rc_black, rc_light_brown, "Test Physical Memory Alloc :\n");
	// allc_addr = pmm_alloc_page();
	// printk_color(rc_black, rc_light_brown, "Alloc Physical Addr: 0x%08X\n", allc_addr);
	// allc_addr = pmm_alloc_page();
	// printk_color(rc_black, rc_light_brown, "Alloc Physical Addr: 0x%08X\n", allc_addr);
	// allc_addr = pmm_alloc_page();
	// printk_color(rc_black, rc_light_brown, "Alloc Physical Addr: 0x%08X\n", allc_addr);
	// allc_addr = pmm_alloc_page();
	// printk_color(rc_black, rc_light_brown, "Alloc Physical Addr: 0x%08X\n", allc_addr);

	sched_init();

	kernel_thread(thread, "B");

	// 开启中断
	enable_intr();

	while (1) {
		if (flag == 0) {
			printk_color(rc_black, rc_red, "IN KERNEL A\n");
			flag = 1;
		}
	}

	while (1) {
		asm volatile ("hlt");
	}
}
