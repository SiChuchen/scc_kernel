/* 全局描述符表（GDT）实现
 * 设置保护模式下的内存分段
 * 采用 Intel 平坦模型：所有段基址为 0，段界限为 4GB
 */

#include "gdt.h"
#include "string.h"


// 全局描述符表长度
#define GDT_LENGTH 5

// 全局描述符表数组
gdt_entry_t gdt_entries[GDT_LENGTH];

// GDTR 寄存器的值
gdt_ptr_t gdt_ptr;

// 全局描述符表构造函数，根据下标构造
static void gdt_set_gate(int32_t num,uint32_t base,uint32_t limit,uint8_t access,uint8_t gran);

// 声明内核栈地址
extern uint32_t stack;

// 初始化全局描述符表
void init_gdt()
{
    // 设置 GDTR 的限长和基址
    gdt_ptr.limit = sizeof(gdt_entry_t) * GDT_LENGTH - 1;
    gdt_ptr.base = (uint32_t)&gdt_entries;

    // 采用 Intel 平坦模型
    gdt_set_gate(0, 0, 0, 0, 0);                    // Intel 文档要求，第一个 GDT 必须全为 0（空描述符）
    gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);     // 内核模式代码段，基址 0，界限 4GB，可执行，DPL=0
    gdt_set_gate(2, 0, 0xFFFFFFFF, 0X92, 0xCF);     // 内核模式数据段，基址 0，界限 4GB，可读写，DPL=0
    gdt_set_gate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF);     // 用户模式代码段，基址 0，界限 4GB，可执行，DPL=3
    gdt_set_gate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF);     // 用户模式数据段，基址 0，界限 4GB，可读写，DPL=3

    // 加载 GDT 地址到 GDTR 寄存器
    gdt_flush((uint32_t)&gdt_ptr);
}


// 全局描述符表构造函数，根据下标设置一个 GDT 表项
// 参数：num - 数组下标
//      base - 段基地址（32位）
//      limit - 段界限（20位）
//      access - 访问权限字节（P、DPL、S、Type 等标志）
//      gran - 粒度字节（G、D/B、L、AVL 标志和段界限高 4 位）
/* 结构体定义如下：
typedef struct
{
	uint16_t limit_low;     // 段界限   15～0
	uint16_t base_low;      // 段基地址 15～0
	uint8_t  base_middle;   // 段基地址 23～16
	uint8_t  access;        // 段存在位、描述符特权级、描述符类型、描述符子类别
	uint8_t  granularity; 	// 其他标志、段界限 19～16
	uint8_t  base_high;     // 段基地址 31～24
} __attribute__((packed)) gdt_entry_t;
*/
static void gdt_set_gate(int32_t num,uint32_t base,uint32_t limit,uint8_t access,uint8_t gran)
{
    // 设置段基址（32位分为3部分存储）
    gdt_entries[num].base_low     = (base & 0xFFFF);           // 基址 0-15 位
    gdt_entries[num].base_middle  = (base >> 16) & 0xFF;       // 基址 16-23 位
    gdt_entries[num].base_high    = (base >> 24) & 0xFF;       // 基址 24-31 位

    // 设置段界限（20位分为2部分存储）
    gdt_entries[num].limit_low    = (limit & 0xFFFF);          // 界限 0-15 位
    gdt_entries[num].granularity  = ((limit >> 16) & 0x0F);    // 界限 16-19 位
    gdt_entries[num].granularity |= (gran & 0xF0);             // 粒度标志位（高 4 位）
    gdt_entries[num].access       = access;                     // 访问权限标志
}