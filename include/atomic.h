// 提供一组32 位整数的原子操作（atomic primitives），用于并发场景下安全地更新共享变量
// 自旋锁（用 atomic_xchg）
// 引用计数、资源计数（用 atomic_fetch_add/sub、atomic_inc_return/dec_return）
// 无锁更新（用 atomic_cmpxchg 做 CAS 循环）

// 核心思想：把“读-改-写”变成CPU 级别不可分割的操作，避免两个执行流（不同 CPU 核或同核中断/抢占）同时修改同一个变量导致丢更新。
#ifndef INCLUDE_ATOMIC_H_
#define INCLUDE_ATOMIC_H_

#include "types.h"

/* 原子计数类型（volatile 保证编译器不优化掉并发访问） */
typedef struct {
    volatile int32_t counter;
} atomic_t;

/* 设置原子计数 */
static inline void atomic_set(atomic_t *v, int32_t i)
{
    v->counter = i;
}

/* 读取原子计数 */
static inline int32_t atomic_read(const atomic_t *v)
{
    return v->counter;
}

/* 原子交换，返回旧值 */
static inline int32_t atomic_xchg(volatile int32_t *addr, int32_t newval)
{
    __asm__ __volatile__("lock xchgl %0, %1"
                         : "+r"(newval), "+m"(*addr)
                         :
                         : "memory");
    return newval;
}

/* 原子比较交换，返回原值（调用者判断是否与 oldval 相等） */
static inline int32_t atomic_cmpxchg(volatile int32_t *addr, int32_t oldval, int32_t newval)
{
    int32_t prev;
    __asm__ __volatile__("lock cmpxchgl %2, %1"
                         : "=a"(prev), "+m"(*addr)
                         : "r"(newval), "0"(oldval)
                         : "memory");
    return prev;
}

/* 原子加减，返回修改前的值 */
static inline int32_t atomic_fetch_add(atomic_t *v, int32_t i)
{
    int32_t old = i;
    __asm__ __volatile__("lock xaddl %0, %1"
                         : "+r"(old), "+m"(v->counter)
                         :
                         : "memory");
    return old;
}

// 原子减（复用 fetch_add）
static inline int32_t atomic_fetch_sub(atomic_t *v, int32_t i)
{
    return atomic_fetch_add(v, -i);
}

/* 返回修改后的值，便于计数场景 */
// 自增并返回新值
static inline int32_t atomic_inc_return(atomic_t *v)
{
    return atomic_fetch_add(v, 1) + 1;
}

// 自减并返回新值
static inline int32_t atomic_dec_return(atomic_t *v)
{
    return atomic_fetch_add(v, -1) - 1;
}

#endif /* INCLUDE_ATOMIC_H_ */
