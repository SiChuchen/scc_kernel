// 提供一组本地 CPU（local）中断控制 + 自旋锁的 irqsave 变体：
// 能读取当前 EFLAGS（尤其是 IF 位）；
// 能保存当前中断开关状态并关闭中断；
// 能根据保存值恢复中断状态；
// 基于以上能力实现：
//     spin_lock_irqsave：关中断 + 加自旋锁
//     spin_unlock_irqrestore：放锁 + 按原状态恢复中断

// 目的：在内核里避免这种经典死锁：
//     当前线程拿着自旋锁 → 被中断打断 → 中断处理又尝试拿同一把锁 → 中断里自旋等待 → 线程无法继续释放锁 → 死锁。

#ifndef INCLUDE_SYNC_H_
#define INCLUDE_SYNC_H_

#include "types.h"
#include "spinlock.h"

// 中断使能位的掩码,IF（Interrupt Flag）是第 9 位,IF=1：允许外部可屏蔽中断
// 这个宏用于判断“之前中断是开还是关”，以便恢复
#define EFLAGS_IF 0x00000200

// 读取 EFLAGS
static inline uint32_t read_eflags()
{
    uint32_t eflags;
    // 在 32 位模式下 pushfl/popl 操作的是 32 位 EFLAGS
    __asm__ __volatile__("pushfl; popl %0" : "=r"(eflags));
    return eflags;
}

// 保存并关闭本地中断
static inline uint32_t local_intr_store()
{
    uint32_t flags = read_eflags();
    // 清 IF，关闭可屏蔽中断
    __asm__ __volatile__("cli" ::: "memory");
    return flags;
}

// 按保存状态恢复中断
static inline void local_intr_restore(uint32_t flags)
{
    // 判断保存的 EFLAGS 里 IF 位是否为 1：
    //     若为 1：说明进入临界区前，中断是开着的
    //     若为 0：说明进入前中断就是关的
    if (flags & EFLAGS_IF)
    {
        // 置 IF，打开可屏蔽中断
        __asm__ __volatile__("sti" ::: "memory");
    }
}

// 关中断 + 自旋锁
static inline uint32_t spin_lock_irqsave(spinlock_t *lock)
{
    // 保存当前中断状态并立即关中断
    uint32_t flags = local_intr_store();
    // 在关中断的前提下获取自旋锁
    spin_lock(lock);
    return flags;
}

// 放锁 + 恢复中断
static inline void spin_unlock_irqrestore(spinlock_t *lock,uint32_t flags)
{
    // 先解锁，再恢复中断状态
    spin_unlock(lock);
    local_intr_restore(flags);
}


#endif /* INCLUDE_SYNC_H_ */
