/* 可变参数列表
 * 用于实现类似 printf 的可变参数函数
 * 使用 GCC 内置的可变参数宏
 */

#ifndef INCLUDE_VARGS_H_
#define INCLUDE_VARGS_H_

// 可变参数列表类型
typedef __builtin_va_list va_list;

// 初始化可变参数列表，last 是最后一个固定参数的名字
#define va_start(ap, last)         (__builtin_va_start(ap, last))

// 获取下一个可变参数，type 是参数的类型
#define va_arg(ap, type)           (__builtin_va_arg(ap, type))

// 结束可变参数列表的使用
#define va_end(ap)                 (__builtin_va_end(ap))

#endif 	// INCLUDE_VARGS_H_