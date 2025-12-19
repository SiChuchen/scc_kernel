#include "sched.h"
#include "heap.h"
#include "debug.h"

// 可调度进程链表
struct task_struct *running_proc_head = NULL;

// 等待进程链表
struct task_struct *wait_proc_head = NULL;

// 当前运行的任务
struct task_struct *current = NULL;

// 初始化任务调度
void sched_init()
{
    // 为当前得执行流创建信息结构体，该结构体位域当前执行流的栈得最低端
    current = (struct task_struct *)(kern_stack_top - STACK_SIZE);

    current -> state = TASK_RUNNABLE;
    current -> pid = now_pid ++;
    current -> kern_stack = current;
    current -> mm = NULL;

    // 单向循环链表
    current -> next = current;

    running_proc_head = current;
}

void change_task_to(struct task_struct * next)
{
    if (current != next)
    {
        struct task_struct *prev = current;
        current = next;
        switch_to(&(prev -> context), &(current -> context));
    }
}

// 任务调度
void schedule()
{
    if (current)
    {
        change_task_to(current -> next);
    }
}

