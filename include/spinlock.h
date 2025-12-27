// 实现了一个最简单的自旋锁（spinlock）：
// 锁只有两种状态：空闲 locked=0，持有 locked=1
// 获取锁时如果别人持有，就在 CPU 上“原地忙等”（spin），直到锁释放
// 通过 atomic_xchg（原子交换）保证“抢锁”的过程没有竞态
// 通过 pause 降低忙等对 CPU/总线/功耗的压力
// 释放锁时用一个编译器屏障避免重排序导致的可见性问题

// 自旋锁适合保护很短的临界区（比如更新一个链表指针、递增计数等），不适合保护耗时操作（例如 IO、长循环），否则会浪费 CPU。
#ifndef INCLUDE_SPINLOCK_H_
#define INCLUDE_SPINLOCK_H_

#include "types.h"
#include "atomic.h"

/* 自旋锁，locked=0 表示空闲，=1 表示持有 */
typedef struct {
    volatile uint32_t locked;
} spinlock_t;

#define SPINLOCK_INIT { 0 }

static inline void spinlock_init(spinlock_t *lock)
{
    lock->locked = 0;
}

/* 忙等获取锁，使用 xchg + pause 减少总线争用 */
static inline void spin_lock(spinlock_t *lock)
{
    while (atomic_xchg((volatile int32_t *)&lock->locked, 1)) {
        __asm__ __volatile__("pause");
    }
}

/* 尝试获取锁，成功返回 1，失败返回 0 */
static inline int spin_try_lock(spinlock_t *lock)
{
    return atomic_xchg((volatile int32_t *)&lock->locked, 1) == 0;
}

/* 释放锁，加入内存屏障避免重排序 */
static inline void spin_unlock(spinlock_t *lock)
{
    // 防止编译器级别的重排序
    __asm__ __volatile__("" ::: "memory");
    lock->locked = 0;
}

#endif /* INCLUDE_SPINLOCK_H_ */
