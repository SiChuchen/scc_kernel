; 将 GDT 加载到 GDTR
; 此函数执行 lgdt 指令加载 GDT，然后刷新所有段寄存器

[GLOBAL gdt_flush]

gdt_flush:
    mov eax, [esp + 4]  ; 从栈中获取 gdt_ptr 的地址（参数）
    lgdt [eax]          ; 执行 lgdt 指令，加载 GDT 到 GDTR 寄存器

    ; 更新所有数据段寄存器
    ; 0x10 是内核数据段选择子（GDT 第 2 项，索引 2，RPL=0）
    ; 选择子计算：2 * 8 = 0x10
    mov ax, 0x10        ; 加载我们的内核数据段描述符
    mov ds, ax          ; 更新数据段寄存器
    mov es, ax          ; 更新附加段寄存器
    mov fs, ax          ; 更新 FS 段寄存器
    mov gs, ax          ; 更新 GS 段寄存器
    mov ss, ax          ; 更新栈段寄存器

    ; 更新代码段寄存器（CS）
    ; 0x08 是内核代码段选择子（GDT 第 1 项，索引 1，RPL=0）
    ; 选择子计算：1 * 8 = 0x08
    ; 使用远跳转来同时更新 CS 和 EIP
    jmp 0x08:.flush     ; 远跳转，0x08 是我们的内核代码段描述符
                        ; 远跳目的是清空 CPU 流水线并串行化处理器

.flush:
    ret                 ; 返回到 C 代码