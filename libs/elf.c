/* ELF 格式解析相关函数
 * 从 Multiboot 信息中提取 ELF 符号表和字符串表
 * 用于内核调试时的符号解析（如栈回溯时显示函数名）
 */

#include "common.h"
#include "string.h"
#include "elf.h"
#include "vmm.h"

// 从 multiboot_t 结构获取 ELF 信息
// 解析 GRUB 提供的 ELF section header table，提取符号表和字符串表
// mb - Multiboot 信息结构指针
// 返回：包含符号表和字符串表信息的 elf_t 结构
elf_t elf_from_multiboot(multiboot_t *mb)
{
	int i;
	elf_t elf;

	// 获取 section header table
	// mb->addr 是 section header table 的物理地址
	// mb->num 是 section header 的数量
	// mb->size 是每个 section header 的大小
	elf_section_header_t *sh = (elf_section_header_t*)mb->addr;

	// 获取 section 名称字符串表的地址
	// mb->shndx 是 .shstrtab section 的索引
	// sh[mb->shndx].addr 是 .shstrtab section 的地址
	uint32_t shstrtab = sh[mb->shndx].addr;

	// 遍历所有 section header，查找符号表和字符串表
	for (i = 0; i < mb->num; i++) {
		// 获取当前 section 的名称
		// shstrtab + sh[i].name 得到指向名称字符串的指针	+ PAGE_OFFSET 转到高虚拟地址
		const char *name = (const char *)(shstrtab + sh[i].name) + PAGE_OFFSET;

		// 查找 .strtab section（字符串表）
		// .strtab 存储所有符号的名称字符串
		if (strcmp(name, ".strtab") == 0) {
			// + PAGE_OFFSET 转到高虚拟地址
			elf.strtab = (const char *)sh[i].addr + PAGE_OFFSET;	// 字符串表的起始地址
			elf.strtabsz = sh[i].size;				// 字符串表的大小
		}

		// 查找 .symtab section（符号表）
		// .symtab 存储所有符号的信息（名称、地址、大小等）
		if (strcmp(name, ".symtab") == 0) {
			// + PAGE_OFFSET 转到高虚拟地址
			elf.symtab = (elf_symbol_t*)(sh[i].addr + PAGE_OFFSET);	// 符号表的起始地址
			elf.symtabsz = sh[i].size;				// 符号表的大小
		}
	}

	return elf;
}

// 查看 ELF 的符号信息
// 根据地址查找对应的符号名称（通常是函数名）
// addr - 要查找的地址（通常是函数调用地址）
// elf - ELF 信息结构指针
// 返回：符号名称字符串，如果找不到则返回 NULL
const char *elf_lookup_symbol(uint32_t addr, elf_t *elf)
{
	int i;

	// 遍历符号表中的所有符号
	// 符号表是一个数组，每个元素是一个 elf_symbol_t 结构
	for (i = 0; i < (elf->symtabsz / sizeof(elf_symbol_t)); i++) {
		// 只查找函数符号
		// ELF32_ST_TYPE 提取符号类型，0x2 表示 STT_FUNC（函数）
		if (ELF32_ST_TYPE(elf->symtab[i].info) != 0x2) {
		      continue;
		}

		// 检查地址是否在该函数的代码段范围内
		// symtab[i].value 是函数的起始地址
		// symtab[i].size 是函数的大小（字节数）
		if ((addr >= elf->symtab[i].value) &&
		    (addr < (elf->symtab[i].value + elf->symtab[i].size))) {
			// 找到了！返回符号名称
			// symtab[i].name 是名称在字符串表中的偏移量
			// strtab + symtab[i].name 得到指向名称字符串的指针
			return (const char *)((uint32_t)elf->strtab + elf->symtab[i].name);
		}
	}

	// 没有找到对应的符号
	return NULL;
}
