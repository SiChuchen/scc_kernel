#ifndef INCLUDE_STRING_H_
#define INCLUDE_STRING_H_

#include "types.h"

// 将 src 的 len 个字节拷贝到 dest
static inline void memcpy(uint8_t *dest, const uint8_t *src, uint32_t len)
{
    for( ;len != 0;len --)
    {
        *dest++ = *src++;
    }
}

// 将长度为 len 的内存区域 dest 的值设置为 val，是把每个值都设置为 val，也就是重复的设置，填充字符
static inline void memset(void *dest,uint8_t val,uint32_t len)
{
    uint8_t *dst = (uint8_t *)dest;

    for( ;len != 0;len --)
    {
        *dst++ = val;
    }
}

// 将长度为 len 的内存区域 dest 的值设置为 0
static inline void bzero(void *dest,uint32_t len)
{
    memset(dest,0,len);
}

// 比较字符串 str1 和 str2，返回 0 表示相等，负值表示 str1 小于 str2，正值表示 str1 大于 str2
static inline int strcmp(const char *str1,const char *str2)
{
    while (*str1 && *str2 && *str1 == *str2)
    {
        str1 ++;
        str2 ++;
    }
    return *str1 - *str2;
}

// 将 src 字符串复制到 dest 中，返回 dest
// const 保证了在函数内部源字符串不被修改
static inline char *strcpy(char *dest,const char *src)
{
    char *tmp = dest; // tmp 存储 dest 的起始地址

    while (*src)
    {
        *dest ++ = *src ++;
        // *dest = *src;
        // dest ++;
        // src ++;
    }
    *dest = '\0';
    return tmp;
}

// 拼接字符串 src 到 dest 的后面，返回 dest
static inline char *strcat(char *dest,const char *src)
{
    char *cp = dest;

    while (*cp)
    {
        cp ++;
    }
    // * ++ cp  ++ *cp
    while ((*cp ++ = *src ++))
        ;

    return dest;
}

// 计算字符串 str 的长度，返回长度值
static inline int strlen(const char *str)
{
    const char *eos = str;

    while (*eos)
    {
        eos ++;
    }
    return (eos - str);
    // 这种写法指向 0 之后 eos 不再进行 ++ ，所以并不需要再多减 1
    // return (eos - str - 1);
}

// 这里将 ++ 放入 while 中，所以当循环判断 为空时，仍然会执行 ++ ，所以要多减 1
// static inline int strlen(const char *src)
// {
// 	const char *eos = src;

//         while (*eos++)
// 	      ;

// 	return (eos - src - 1);
// }

#endif