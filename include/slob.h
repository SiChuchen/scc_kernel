#ifndef INCLUDE_SLOB_H_
#define INCLUDE_SLOB_H_

#include "types.h"

/* 简易 SLOB 分配器接口：提供 kmalloc/kfree 替换现有堆实现 */

void *kmalloc(uint32_t size);
void kfree(void *p);

void init_slob();
void test_slob();

#endif /* INCLUDE_SLOB_H_ */
