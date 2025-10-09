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

// 内核 C 入口函数
// 由 boot.s 中的 start 标签调用
// 负责按顺序初始化所有内核子系统
int kern_entry()
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
	init_timer(200);

	// 开启中断
	// 在初始化完 GDT、IDT 和定时器后，必须开启 CPU 的中断标志位
	// 否则即使硬件产生中断信号，CPU 也不会响应
	asm volatile ("sti");

	// 打印内核在内存中的位置信息
	// kern_start 和 kern_end 是链接器脚本（scripts/kernel.ld）中定义的符号
	printk("kernel in memory start: 0x%08X\n", kern_start);
	printk("kernel in memory end:   0x%08X\n", kern_end);
	printk("kernel in memory used:   %d KB\n\n", (kern_end - kern_start) / 1024);

	// 显示 BIOS 提供的物理内存布局
	// 遍历 multiboot 内存映射表，打印每个内存区域的信息
	show_memory_map();

	// 初始化物理内存管理器
	// 将所有可用的物理页框加入管理栈
	init_pmm();

	// 打印可用物理内存页的数量
	printk_color(rc_black, rc_red, "\nThe Count of Physical Memory Page is: %u\n\n", phy_page_count);

	// 测试物理内存分配
	// 连续分配 4 个物理页，打印它们的地址
	uint32_t allc_addr = NULL;
	printk_color(rc_black, rc_light_brown, "Test Physical Memory Alloc :\n");
	allc_addr = pmm_alloc_page();
	printk_color(rc_black, rc_light_brown, "Alloc Physical Addr: 0x%08X\n", allc_addr);
	allc_addr = pmm_alloc_page();
	printk_color(rc_black, rc_light_brown, "Alloc Physical Addr: 0x%08X\n", allc_addr);
	allc_addr = pmm_alloc_page();
	printk_color(rc_black, rc_light_brown, "Alloc Physical Addr: 0x%08X\n", allc_addr);
	allc_addr = pmm_alloc_page();
	printk_color(rc_black, rc_light_brown, "Alloc Physical Addr: 0x%08X\n", allc_addr);

	// 内核初始化完成，返回 0
	return 0;
}
