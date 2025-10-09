/* 基本数据类型定义 */

#ifndef INCLUDE_TYPES_H_
#define INCLUDE_TYPES_H_

#ifndef NULL
        #define NULL 0      // 空指针
#endif

#ifndef TRUE
        #define TRUE    1   // 真
        #define FALSE   0   // 假
#endif

// 无符号整型定义
typedef unsigned    int     uint32_t;   // 32位无符号整数
typedef             int     int32_t;    // 32位有符号整数
typedef unsigned    short   uint16_t;   // 16位无符号整数
typedef             short   int16_t;    // 16位有符号整数
typedef unsigned    char    uint8_t;    // 8位无符号整数
typedef             char    int8_t;     // 8位有符号整数

#endif      //INCLUDE_TYPES_H_