/* 通用端口 I/O 操作函数
 * 提供 x86 架构下的端口输入/输出指令封装
 * 用于与硬件设备（如 PIC、PIT、VGA 控制器等）通信
 */

#include "common.h"

// 向指定端口写入一个字节
// port - 端口号（16位）
// value - 要写入的值（8位）
//
// 使用 outb 指令：outb value, port
// 内联汇编约束：
// - "dN"(port): d表示使用DX寄存器，N表示0-255的立即数
// - "a"(value): 使用AL寄存器（accumulator的低8位）
inline void outb(uint16_t port, uint8_t value)
{
    asm volatile("outb %1,%0" : : "dN"(port), "a"(value));
}

// 从指定端口读取一个字节
// port - 端口号（16位）
// 返回：从端口读取的值（8位）
//
// 使用 inb 指令：inb port, %al
// 内联汇编约束：
// - "=a"(ret): 输出约束，将AL寄存器的值存入ret变量
// - "dN"(port): 输入约束，端口号可以是DX寄存器或0-255的立即数
inline uint8_t inb(uint16_t port)
{
    uint8_t ret;
    asm volatile("inb %1,%0" : "=a"(ret) : "dN"(port));
    return ret;
}

// 从指定端口读取一个字（2字节）
// port - 端口号（16位）
// 返回：从端口读取的值（16位）
//
// 使用 inw 指令：inw port, %ax
// 内联汇编约束：
// - "=a"(ret): 输出约束，将AX寄存器的值存入ret变量
// - "dN"(port): 输入约束，端口号可以是DX寄存器或0-255的立即数
inline uint16_t inw(uint16_t port)
{
    uint16_t ret;
    asm volatile("inw %1,%0" : "=a"(ret) : "dN"(port));
    return ret;
}


// 开启/关闭中断的接口在 include/common.h 中以 static inline 形式提供
