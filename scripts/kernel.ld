/*
 *      kernel.ld -- 针对 kernel 格式所写的链接脚本
 *		关键 ：
 *				. 是 虚拟地址（VMA），AT(...) 控制 物理加载地址（LMA）
 *
 *
 *		.init.text / .init.data：
 *				在 1MB 左右物理地址，VMA=LMA，
 *				用来放 早期启动/初始化代码，通常只在内核启动阶段用，之后可以丢弃或不再依赖。
 *
 *		.text / .data / .bss 以及后面的调试段：
 *				链接到 0xC0000000 以上的虚拟地址（高半部分），
 *				是真正意义上 长期运行的内核代码和数据。
 */

ENTRY(start)
SECTIONS
{
	PROVIDE( kern_start = 0xC0100000);
	. = 0x100000; 
	.init.text : 
	{
		*(.init.text)
		. = ALIGN(4096);
	}
	.init.data : 
	{
		*(.init.data)
		. = ALIGN(4096);
	}

	. += 0xC0000000;
	.text : AT(ADDR(.text) - 0xC0000000)
	{
		*(.text)
		. = ALIGN(4096);
	}
	.data : AT(ADDR(.data) - 0xC0000000)
	{
		*(.data)
		*(.rodata)
		. = ALIGN(4096);
	}
	.bss : AT(ADDR(.bss) - 0xC0000000)
	{
		*(.bss)
		. = ALIGN(4096);
	}
	.stab : AT(ADDR(.stab) - 0xC0000000)
	{
		*(.stab)
		. = ALIGN(4096);
	}
	.stabstr : AT(ADDR(.stabstr) - 0xC0000000)
	{
		*(.stabstr)
	 	. = ALIGN(4096);
	}
	PROVIDE( kern_end = . );
	
	/DISCARD/ : { *(.comment) *(.eh_frame) }
}


