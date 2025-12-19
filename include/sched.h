#ifndef INCLUDE_SCHED_H_
#define INCLUDE_SCHED_H_

#include "task.h"

extern uint32_t kern_stack_top;

// 可调度进程链表
extern struct task_struct *running_proc_head;

// 等待进程链表
extern struct task_struct *wait_proc_head;

// 当前运行的任务
extern struct task_struct *current;

// 初始化任务调度
void sched_init();

// 任务调度
void schedule();

// 任务切换准备
void switch_task_to(struct task_struct *next);

// 任务切换
void switch_to(struct context *prev,struct context *next);

#endif  // INCLUDE_SCHED_H_