/* 调试相关功能
 * 提供内核panic、栈回溯、符号解析等调试功能
 * 使用 ELF 符号表实现地址到函数名的转换
 */

#include "debug.h"

// 静态函数声明
static void print_stack_trace();

// 内核 ELF 符号信息
// 在 init_debug() 中从 Multiboot 信息初始化
static elf_t kernel_elf;

// 初始化调试功能
// 从 GRUB 提供的 Multiboot 信息中获取内核的符号表和代码地址信息
void init_debug()
{
	// 从全局 Multiboot 指针提取 ELF 信息
	// glb_mboot_ptr 在 init/entry.c 中由 boot.s 传入的 ebx 寄存器初始化
	kernel_elf = elf_from_multiboot(glb_mboot_ptr);
}

// 打印当前的段寄存器状态
// 用于调试时查看特权级和段选择子
void print_cur_status()
{
	static int round = 0;	// 调用计数器
	uint16_t reg1, reg2, reg3, reg4;

	// 使用内联汇编读取段寄存器的值
	asm volatile ( 	"mov %%cs, %0;"		// 读取代码段寄存器
			"mov %%ds, %1;"		// 读取数据段寄存器
			"mov %%es, %2;"		// 读取附加段寄存器
			"mov %%ss, %3;"		// 读取栈段寄存器
			: "=m"(reg1), "=m"(reg2), "=m"(reg3), "=m"(reg4));

	// 打印当前的运行级别（Ring 0-3）
	// 段选择子的低 2 位（RPL）表示请求特权级
	printk("%d: @ring %d\n", round, reg1 & 0x3);
	printk("%d:  cs = %x\n", round, reg1);
	printk("%d:  ds = %x\n", round, reg2);
	printk("%d:  es = %x\n", round, reg3);
	printk("%d:  ss = %x\n", round, reg4);
	++round;
}

// 内核 panic 函数
// 当发生致命错误时调用，打印错误信息和栈回溯，然后停止
// msg - 错误信息字符串
void panic(const char *msg)
{
	printk_color(rc_black, rc_green, "%s", msg);
	printk("*** System panic: %s\n", msg);

	// 打印函数调用栈
	print_stack_trace();

	printk("***\n");
	printk_color(rc_black, rc_green, "end is here!\n");

	// 致命错误发生后，内核在此处无限循环（挂起）
	// 在实际系统中，这里可能会触发重启或进入调试器
	while(1);
}

// 打印函数调用栈
// 通过遍历栈帧链表，显示每个函数的返回地址和名称
static void print_stack_trace()
{
	uint32_t *ebp, *eip;

	// 获取当前的帧指针（EBP）
	// 帧指针指向当前函数栈帧的底部
	asm volatile ("mov %%ebp, %0" : "=r" (ebp));

	// 遍历栈帧链表
	// 每个栈帧的结构：
	// [ebp+0] = 上一个函数的 ebp
	// [ebp+4] = 返回地址（eip）
	while (ebp) {
		// 获取返回地址（保存在 ebp+4 的位置）
		eip = ebp + 1;

		// 打印返回地址和对应的函数名
		// elf_lookup_symbol 将地址转换为函数名
		printk("   [0x%x] %s\n", *eip, elf_lookup_symbol(*eip, &kernel_elf));

		// 移动到上一个栈帧
		// ebp 指向上一个函数的 ebp
		ebp = (uint32_t*)*ebp;
	}
}
