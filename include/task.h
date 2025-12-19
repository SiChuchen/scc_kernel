#ifndef INCLUDE_TASK_H_
#define INCLUDE_TASK_H_

#include "types.h"
#include "pmm.h"
#include "vmm.h"


//进程状态描述
typedef 
enum task_state {
    TASK_UNINIT = 0,    // 未初始化,PCB 刚创建但还没准备好运行（栈没建好 / 上下文没初始化 / 没加入队列等）
    TASK_SLEEPING,      // 休眠中,任务主动睡眠或等待某事件（例如等待 I/O、等待锁、等待定时器）
    TASK_RUNNABLE,      // 可运行,表示可以被调度器选中上 CPU
    TASK_ZOMBIE,        // 僵尸状态,任务已经结束执行，但其资源（比如退出码、统计信息）还没被“回收/收尸”
} task_state;


// 内核线程的上下文切换保存的信息
// 上下文切换（context switch）：从任务 A 切换到任务 B 时，要保存 A 的 CPU 现场，并恢复 B 的 CPU 现场
struct context
{
    uint32_t esp;       // 栈指针。最关键，因为切换栈就等于切换“正在执行的函数调用链和局部变量环境”。
    uint32_t ebp;       // 栈帧基址（传统帧指针），用于函数调用栈回溯和局部变量访问（取决于编译器优化）。
    
    // 通用寄存器。很多 ABI 里它们属于“被调用者保存寄存器（callee-saved）”，所以线程切换时通常要保存它们，保证切回来后任务继续执行不被破坏。
    uint32_t ebx;       
    uint32_t esi;
    uint32_t edi;

    uint32_t eflags;    // 标志寄存器，里面有中断使能位 IF、算术标志位等。切换时恢复它可以保证任务的执行状态一致（例如是否允许中断）。
};

// 进程内存地址结构
struct mm_struct
{
    // 当发生进程切换时，如果切换到不同地址空间，内核需要把 CR3（页表基址寄存器）切换到 next->mm->pgd_dir 指向的页表根，从而实现地址空间切换
    pgd_t *pgd_dir;               // 进程页表
};

// 进程控制块
struct task_struct
{
    // volatile 的意图：告诉编译器“这个值可能在你看不到的地方变化”，不要过度优化缓存到寄存器里,避免某些优化导致读不到最新值
    volatile task_state state;      // 进程状态
    pid_t pid;                     // 进程ID
    void *kern_stack;              // 进程内核栈指针
    struct mm_struct *mm;            // 进程内存地址结构
    struct context context;        // 进程上下文切换保存的信息
    struct task_struct *next;      // 用于链表连接下一个 PCB
};

// 全局 PID 值,通常用于分配新 pid：创建新线程时 now_pid++ 并赋给 task->pid
extern pid_t now_pid;

// 内核线程创建
// fn：线程入口函数，签名 int fn(void*),函数指针

// 创建线程通常要做的事
//      分配 task_struct
//      分配/初始化内核栈
//      初始化 context，让它看起来像“将来被恢复时会从 fn(arg) 开始执行”
//      设置 state = TASK_RUNNABLE
//      把它挂到 runnable 队列（next）
int32_t kernel_thread(int (*fn)(void *), void *arg);

// 线程退出函数
void kthread_exit();

#endif  // INCLUDE_TASK_H_