/* 中断描述符表（IDT）实现
 * Interrupt Descriptor Table
 * 用于设置和管理 x86 保护模式下的中断和异常处理
 */

#include "common.h"
#include "string.h"
#include "debug.h"
#include "idt.h"

// 中断描述符表数组，支持 256 个中断向量
idt_entry_t idt_entries[256];

// IDTR 寄存器的值
idt_ptr_t idt_ptr;

// 中断处理函数的指针数组
// 每个中断号对应一个处理函数
interrupt_handler_t interrupt_handlers[256];

// 设置中断描述符（内部函数）
static void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags);

// 声明加载 IDTR 的函数（汇编实现）
extern void idt_flush(uint32_t);

// 初始化中断描述符表
void init_idt()
{
	// 重新映射 IRQ 表
	// 因为 IBM PC 默认将 IRQ0-7 映射到中断 8-15，与 CPU 异常冲突
	// 我们需要将 IRQ0-15 重新映射到中断 32-47
	//
	// 使用两片级联的 Intel 8259A 可编程中断控制器（PIC）
	// 主片端口：0x20（命令）、0x21（数据）
	// 从片端口：0xA0（命令）、0xA1（数据）

	// 初始化主片、从片
	// ICW1：0x11 = 0001 0001b（边沿触发、级联、需要ICW4）
	outb(0x20, 0x11);		// 初始化主片
	outb(0xA0, 0x11);		// 初始化从片

	// ICW2：设置中断向量偏移
	// 设置主片 IRQ0-7 映射到中断 32-39（0x20-0x27）
	outb(0x21, 0x20);

	// 设置从片 IRQ8-15 映射到中断 40-47（0x28-0x2F）
	outb(0xA1, 0x28);

	// ICW3：设置主从片级联
	// 设置主片 IR2 引脚连接从片（二进制 0000 0100）
	outb(0x21, 0x04);

	// 告诉从片输出引脚和主片 IR2 号相连（从片标识为 2）
	outb(0xA1, 0x02);

	// ICW4：设置工作模式
	// 0x01 = 8086 模式（非自动 EOI，非缓冲，非特殊全嵌套）
	outb(0x21, 0x01);		// 主片按 8086 模式工作
	outb(0xA1, 0x01);		// 从片按 8086 模式工作

	// OCW1：设置中断屏蔽寄存器（IMR）
	// 0x0 = 允许所有中断（所有位都是 0）
	outb(0x21, 0x0);		// 主片允许所有中断
	outb(0xA1, 0x0);		// 从片允许所有中断

	// 清空中断处理函数指针数组
	bzero((uint8_t *)&interrupt_handlers, sizeof(interrupt_handler_t) * 256);

	// 设置 IDTR 寄存器的值
	idt_ptr.limit = sizeof(idt_entry_t) * 256 - 1;	// IDT 限长
	idt_ptr.base  = (uint32_t)&idt_entries;			// IDT 基址

	// 清空 IDT 数组
	bzero((uint8_t *)&idt_entries, sizeof(idt_entry_t) * 256);

	// 0-31：CPU 异常中断
	// sel=0x08 是内核代码段选择子，flags=0x8E 是 32 位中断门，DPL=0
	idt_set_gate( 0, (uint32_t)isr0,  0x08, 0x8E);	// 除法错误
	idt_set_gate( 1, (uint32_t)isr1,  0x08, 0x8E);
	idt_set_gate( 2, (uint32_t)isr2,  0x08, 0x8E);
	idt_set_gate( 3, (uint32_t)isr3,  0x08, 0x8E);
	idt_set_gate( 4, (uint32_t)isr4,  0x08, 0x8E);
	idt_set_gate( 5, (uint32_t)isr5,  0x08, 0x8E);
	idt_set_gate( 6, (uint32_t)isr6,  0x08, 0x8E);
	idt_set_gate( 7, (uint32_t)isr7,  0x08, 0x8E);
	idt_set_gate( 8, (uint32_t)isr8,  0x08, 0x8E);
	idt_set_gate( 9, (uint32_t)isr9,  0x08, 0x8E);
	idt_set_gate(10, (uint32_t)isr10, 0x08, 0x8E);
	idt_set_gate(11, (uint32_t)isr11, 0x08, 0x8E);
	idt_set_gate(12, (uint32_t)isr12, 0x08, 0x8E);
	idt_set_gate(13, (uint32_t)isr13, 0x08, 0x8E);
	idt_set_gate(14, (uint32_t)isr14, 0x08, 0x8E);
	idt_set_gate(15, (uint32_t)isr15, 0x08, 0x8E);
	idt_set_gate(16, (uint32_t)isr16, 0x08, 0x8E);
	idt_set_gate(17, (uint32_t)isr17, 0x08, 0x8E);
	idt_set_gate(18, (uint32_t)isr18, 0x08, 0x8E);
	idt_set_gate(19, (uint32_t)isr19, 0x08, 0x8E);
	idt_set_gate(20, (uint32_t)isr20, 0x08, 0x8E);
	idt_set_gate(21, (uint32_t)isr21, 0x08, 0x8E);
	idt_set_gate(22, (uint32_t)isr22, 0x08, 0x8E);
	idt_set_gate(23, (uint32_t)isr23, 0x08, 0x8E);
	idt_set_gate(24, (uint32_t)isr24, 0x08, 0x8E);
	idt_set_gate(25, (uint32_t)isr25, 0x08, 0x8E);
	idt_set_gate(26, (uint32_t)isr26, 0x08, 0x8E);
	idt_set_gate(27, (uint32_t)isr27, 0x08, 0x8E);
	idt_set_gate(28, (uint32_t)isr28, 0x08, 0x8E);
	idt_set_gate(29, (uint32_t)isr29, 0x08, 0x8E);
	idt_set_gate(30, (uint32_t)isr30, 0x08, 0x8E);
	idt_set_gate(31, (uint32_t)isr31, 0x08, 0x8E);

	// 32-47：IRQ 硬件中断（重新映射后）
	idt_set_gate(32, (uint32_t)irq0, 0x08, 0x8E);	// 时钟中断
	idt_set_gate(33, (uint32_t)irq1, 0x08, 0x8E);
	idt_set_gate(34, (uint32_t)irq2, 0x08, 0x8E);
	idt_set_gate(35, (uint32_t)irq3, 0x08, 0x8E);
	idt_set_gate(36, (uint32_t)irq4, 0x08, 0x8E);
	idt_set_gate(37, (uint32_t)irq5, 0x08, 0x8E);
	idt_set_gate(38, (uint32_t)irq6, 0x08, 0x8E);
	idt_set_gate(39, (uint32_t)irq7, 0x08, 0x8E);
	idt_set_gate(40, (uint32_t)irq8, 0x08, 0x8E);
	idt_set_gate(41, (uint32_t)irq9, 0x08, 0x8E);
	idt_set_gate(42, (uint32_t)irq10, 0x08, 0x8E);
	idt_set_gate(43, (uint32_t)irq11, 0x08, 0x8E);
	idt_set_gate(44, (uint32_t)irq12, 0x08, 0x8E);
	idt_set_gate(45, (uint32_t)irq13, 0x08, 0x8E);
	idt_set_gate(46, (uint32_t)irq14, 0x08, 0x8E);
	idt_set_gate(47, (uint32_t)irq15, 0x08, 0x8E);

	// 255：将来用于实现系统调用（int 0x80 风格）
	idt_set_gate(255, (uint32_t)isr255, 0x08, 0x8E);

	// 更新设置中断描述符表，加载到 IDTR 寄存器
	idt_flush((uint32_t)&idt_ptr);
}


// 设置中断描述符（内部函数）
// 参数：num - 中断号（0-255）
//      base - 中断处理函数的地址
//      sel - 代码段选择子（通常是 0x08，内核代码段）
//      flags - 标志字节（类型、DPL、P 位等）
static void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags)
{
	// 设置中断处理函数地址（分为低 16 位和高 16 位）
	idt_entries[num].base_low  = base & 0xFFFF;			// 函数地址低 16 位
	idt_entries[num].base_high = (base >> 16) & 0xFFFF;	// 函数地址高 16 位

	// 设置代码段选择子
	idt_entries[num].sel       = sel;
	// 此字段必须为 0
	idt_entries[num].always0   = 0;

	// 设置标志字节
	// 如果要允许用户态触发此中断，可以 OR 上 0x60（DPL=3）
	// flags | 0x60 可以设置中断门的特权级别为 3（用户态可访问）
	idt_entries[num].flags = flags;
}

// 调用中断处理函数（由汇编中断入口调用）
// regs 包含了中断发生时的所有寄存器状态
void isr_handler(pt_regs *regs)
{
    // 如果注册了处理函数，则调用
    if (interrupt_handlers[regs -> int_no])
    {
        interrupt_handlers[regs -> int_no](regs);
    }
    else
    {
        // 未处理的中断，打印警告信息
        printk_color(rc_black, rc_light_green, "unhandled interrupt: %d\n", regs -> int_no);
    }
}

// 注册一个中断处理函数
// n - 中断号
// h - 处理函数指针
void register_interrupt_handler(uint8_t n, interrupt_handler_t h)
{
    interrupt_handlers[n] = h;
}


// IRQ 处理函数（由汇编 IRQ 入口调用）
// 处理硬件中断请求（IRQ0-15，映射到中断 32-47）
void irq_handler(pt_regs *regs)
{
	// 发送中断结束信号（EOI）给 8259A PIC
	// 按照我们的设置，从 32 号中断起为 IRQ 硬件中断
	// 因为单片的 Intel 8259A 芯片只能处理 8 级中断（IRQ0-7）
	// 故中断号 >= 40 (IRQ8-15) 是由从片处理的
	if (regs->int_no >= 40) {
		// 发送 EOI 信号给从片（端口 0xA0）
		outb(0xA0, 0x20);
	}
	// 发送 EOI 信号给主片（端口 0x20）
	// 无论是主片还是从片中断，都需要通知主片
	outb(0x20, 0x20);

	// 调用注册的中断处理函数（如果有的话）
	if (interrupt_handlers[regs->int_no]) {
		interrupt_handlers[regs->int_no](regs);
	}
}