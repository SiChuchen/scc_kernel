#ifndef INCLUDE_HEAP_H_
#define INCLUDE_HEAP_H_

#include "types.h"

// 堆的起始地址
#define HEAP_START 0XE0000000

// 内存块管理结构体，每块内核堆内存的头部
typedef struct header
{
    // 前后内存块管理指针
    struct header *prev;
    struct header *next;

    // 这里使用位域来创建以下两个变量
    // 该内存块是否已经申请
    uint32_t allocated : 1;
    // 当前内存块的长度
    uint32_t length : 31;
} header_t;

// 初始化堆
// 为兼容旧接口，声明 kmalloc/kfree，但实际实现由 SLOB 提供
void init_heap();

// 内存申请
void *kmalloc(uint32_t len);

// 内存释放
void kfree(void *p);

// 测试内核堆的申请和释放
void test_heap();

#endif  // INCLUDE_HEAP_H_
