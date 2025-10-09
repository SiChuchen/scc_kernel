/* 定时器驱动
 * 使用 8253/8254 PIT (Programmable Interval Timer) 芯片
 * 产生周期性的时钟中断
 */

#ifndef INCLUDE_TIMER_H_
#define INCLUDE_TIMER_H_

#include "types.h"

// 初始化定时器，参数 frequency 指定中断频率（Hz）
void init_timer(uint32_t frequency);

#endif 	// INCLUDE_TIMER_H_