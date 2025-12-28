/* 定时器驱动实现
 * 使用 Intel 8253/8254 PIT (Programmable Interval Timer) 芯片
 * 产生周期性的时钟中断（IRQ0）
 * PIT 的输入频率固定为 1193180 Hz
 */

#include "timer.h"
#include "debug.h"
#include "common.h"
#include "idt.h"
#include "sched.h"
#include "spinlock.h"
#include "sync.h"

static spinlock_t ticks_lock = SPINLOCK_INIT;
static uint32_t ticks = 0;

// 时钟中断的回调函数
// 每次时钟中断触发时被调用
// regs - 中断发生时的寄存器状态
void timer_callback(pt_regs *regs)
{
	// static uint32_t tick = 0;  // 时钟滴答计数器
	// printk_color(rc_black, rc_red, "Tick: %d\n", tick++);
	// schedule();  // 调用调度函数，切换任务

	uint32_t flags = spin_lock_irqsave(&ticks_lock);
	ticks ++;
	spin_unlock_irqrestore(&ticks_lock, flags);
}

// 初始化定时器
// frequency - 期望的中断频率（Hz），即每秒触发多少次中断
void init_timer(uint32_t frequency)
{
	// 注册时钟中断（IRQ0）的处理函数
	register_interrupt_handler(IRQ0, timer_callback);

	// Intel 8253/8254 PIT 芯片端口地址：
	// 0x40 - 通道 0 数据端口（连接到 IRQ0）
	// 0x41 - 通道 1 数据端口（用于 DRAM 刷新，已废弃）
	// 0x42 - 通道 2 数据端口（连接到 PC 喇叭）
	// 0x43 - 模式/命令寄存器

	// PIT 的输入频率固定为 1193180 Hz
	// 分频器 = 输入频率 / 期望频率
	// 例如：频率为 100 Hz，则分频器 = 1193180 / 100 = 11931
	uint32_t divisor = 1193180 / frequency;

	// 向命令寄存器写入控制字
	// 控制字格式（8 位）：
	// D7 D6 | D5 D4 | D3 D2 D1 | D0
	//  0  0 |  1  1 |  0  1  1 |  0
	//
	// D7-D6: 选择通道（00 = 通道 0）
	// D5-D4: 访问模式（11 = 先写低字节，再写高字节）
	// D3-D1: 工作模式（011 = 模式 3，方波发生器）
	// D0:    计数格式（0 = 二进制计数）
	//
	// 0x36 = 0011 0110 = 通道 0，先低后高，模式 3，二进制
	outb(0x43, 0x36);

	// 将分频器的值写入通道 0
	// 必须先写低字节，再写高字节
	uint8_t low = (uint8_t)(divisor & 0xFF);        // 低 8 位
	uint8_t high = (uint8_t)((divisor >> 8) & 0xFF); // 高 8 位

	// 写入低字节
	outb(0x40, low);
	// 写入高字节
	outb(0x40, high);

	// 此时 PIT 开始以指定频率产生中断
	// 每次中断会调用 timer_callback 函数
}
