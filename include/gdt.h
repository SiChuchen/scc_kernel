/* 全局描述符表（GDT）
 * Global Descriptor Table
 * 用于 x86 保护模式下的内存分段管理
 */

#ifndef INCLUDE_GDT_H_
#define INCLUDE_GDT_H_

#include "types.h"

// 全局描述符表项结构
// 每个描述符 8 字节，描述一个内存段的属性
typedef
struct gdt_entry_t {
    uint16_t limit_low;     // 段界限 0-15 位
    uint16_t base_low;      // 段基址 0-15 位
    uint8_t  base_middle;   // 段基址 16-23 位
    uint8_t  access;        // 访问权限标志
    uint8_t  granularity;   // 粒度和段界限 16-19 位
    uint8_t  base_high;     // 段基址 24-31 位
} __attribute__((packed)) gdt_entry_t;


// GDTR 寄存器结构
// 用于 lgdt 指令加载 GDT
typedef
struct gdt_ptr_t {
    uint16_t limit;         // GDT 表限长（字节数 - 1）
    uint32_t base;          // GDT 表的线性基址
} __attribute__((packed)) gdt_ptr_t;

// 初始化全局描述符表
void init_gdt();

// GDT 加载到 GDTR 的汇编实现
// 执行 lgdt 指令并刷新段寄存器
extern void gdt_flush(uint32_t);

#endif