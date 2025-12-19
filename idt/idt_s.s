; 中断描述符表（IDT）汇编支持代码
; 提供 IDT 加载、中断处理函数入口和通用中断处理桩

; ============================================================================
; 加载 IDT 到 IDTR 寄存器
; ============================================================================

[GLOBAL idt_flush]
idt_flush:
    mov eax, [esp + 4]  ; 从栈中获取 idt_ptr 的地址（参数）
    lidt [eax]          ; 执行 lidt 指令，加载 IDT 到 IDTR 寄存器
    ret
.end:

; ============================================================================
; 中断服务程序（ISR）宏定义
; ============================================================================

; 定义两个构造中断处理函数的宏
; 因为有些中断会压入错误代码，有些不会，需要统一栈帧格式

; 用于没有错误代码的中断
; 参数 %1 是中断号
%macro ISR_NOERRCODE 1
[GLOBAL isr%1]
isr%1:                  ; 这里变量和中断向量组合成了函数名，这里就成为了每个中断服务函数的最开始的实现的位置
    cli                 ; 关闭中断，防止嵌套中断
    push 0              ; 压入一个伪造的错误代码（占位），保持栈帧统一
    push %1             ; 压入中断号
    jmp isr_common_stub ; 跳转到通用中断处理桩
%endmacro

; 用于有错误代码的中断
; 参数 %1 是中断号
; CPU 在触发这些中断时会自动压入错误代码，所以不需要手动压入占位符
%macro ISR_ERRCODE 1
[GLOBAL isr%1]
isr%1:
    cli                 ; 关闭中断
    push %1             ; 压入中断号（错误代码已由 CPU 压入）
    jmp isr_common_stub ; 跳转到通用中断处理桩
%endmacro

; ============================================================================
; 定义 0-31 号中断处理函数（CPU 异常）
; ============================================================================

ISR_NOERRCODE  0 	; 0 #DE 除 0 异常
ISR_NOERRCODE  1 	; 1 #DB 调试异常
ISR_NOERRCODE  2 	; 2 NMI（不可屏蔽中断）
ISR_NOERRCODE  3 	; 3 #BP 断点异常
ISR_NOERRCODE  4 	; 4 #OF 溢出异常
ISR_NOERRCODE  5 	; 5 #BR 边界检查异常
ISR_NOERRCODE  6 	; 6 #UD 无效操作码异常
ISR_NOERRCODE  7 	; 7 #NM 设备不可用异常（无数学协处理器）
ISR_ERRCODE    8 	; 8 #DF 双重故障异常（有错误代码）
ISR_NOERRCODE  9 	; 9 协处理器段超越异常（保留）
ISR_ERRCODE   10 	; 10 #TS 无效 TSS 异常（有错误代码）
ISR_ERRCODE   11 	; 11 #NP 段不存在异常（有错误代码）
ISR_ERRCODE   12 	; 12 #SS 栈段错误异常（有错误代码）
ISR_ERRCODE   13 	; 13 #GP 常规保护异常（有错误代码）
ISR_ERRCODE   14 	; 14 #PF 页故障异常（有错误代码）
ISR_NOERRCODE 15 	; 15 CPU 保留
ISR_NOERRCODE 16 	; 16 #MF x87 浮点异常
ISR_ERRCODE   17 	; 17 #AC 对齐检查异常（有错误代码）
ISR_NOERRCODE 18 	; 18 #MC 机器检查异常
ISR_NOERRCODE 19 	; 19 #XM SIMD 浮点异常

; 20-31：Intel 保留，用于将来扩展
ISR_NOERRCODE 20
ISR_NOERRCODE 21
ISR_NOERRCODE 22
ISR_NOERRCODE 23
ISR_NOERRCODE 24
ISR_NOERRCODE 25
ISR_NOERRCODE 26
ISR_NOERRCODE 27
ISR_NOERRCODE 28
ISR_NOERRCODE 29
ISR_NOERRCODE 30
ISR_NOERRCODE 31

; 255：用户自定义中断（将来用于系统调用）
ISR_NOERRCODE 255

; ============================================================================
; 通用中断处理桩（所有 ISR 都会跳转到这里）
; ============================================================================

[GLOBAL isr_common_stub]
[EXTERN isr_handler]            ; 声明外部 C 函数 isr_handler
isr_common_stub:
    ; 保存所有通用寄存器（构造 pt_regs 结构）
    pusha                       ; 依次压入：EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI

    ; 保存数据段描述符
    mov ax, ds
    push eax

    ; 加载内核数据段描述符
    ; 0x10 是内核数据段选择子（GDT 第 2 项，索引 2，RPL=0）
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    ; 调用 C 语言的中断处理函数
    ; 此时栈顶 ESP 指向完整的寄存器状态（pt_regs 结构）
    push esp                    ; 将 pt_regs* 作为参数传递
    call isr_handler            ; 调用 C 函数 isr_handler(pt_regs *regs)
    add esp, 4                  ; 清理参数

    ; 恢复原来的数据段描述符
    pop ebx
    mov ds, bx
    mov es, bx
    mov fs, bx
    mov gs, bx
    mov ss, bx

    ; 恢复所有通用寄存器
    popa                        ; 依次弹出：EDI, ESI, EBP, ESP, EBX, EDX, ECX, EAX

    ; 清理栈中的错误代码和中断号
    add esp, 8

    ; 中断返回
    ; iret 指令会依次弹出：EIP, CS, EFLAGS, ESP, SS（如果发生特权级切换）
    iret
.end:

; ============================================================================
; 硬件中断请求（IRQ）宏定义
; ============================================================================

; 构造 IRQ 处理函数的宏
; 参数 %1 是 IRQ 号（0-15）
; 参数 %2 是中断号（32-47）
%macro IRQ 2
[GLOBAL irq%1]
irq%1:
    cli                         ; 关闭中断
    push 0                      ; 压入伪造的错误代码（占位）
    push %2                     ; 压入中断号
    jmp irq_common_stub         ; 跳转到通用 IRQ 处理桩
%endmacro

; ============================================================================
; 定义 IRQ0-IRQ15 硬件中断处理函数
; ============================================================================

IRQ   0,    32 	; 电脑系统计时器（PIT）
IRQ   1,    33 	; 键盘
IRQ   2,    34 	; 级联（连接到从 PIC）
IRQ   3,    35 	; 串口 COM2
IRQ   4,    36 	; 串口 COM1
IRQ   5,    37 	; LPT2（并口）或声卡
IRQ   6,    38 	; 软驱控制器
IRQ   7,    39 	; LPT1（并口）
IRQ   8,    40 	; CMOS 实时时钟
IRQ   9,    41 	; 空闲（可用于其他设备）
IRQ  10,    42 	; 空闲（建议网卡使用）
IRQ  11,    43 	; 空闲（建议 AGP 显卡使用）
IRQ  12,    44 	; PS/2 鼠标
IRQ  13,    45 	; 数学协处理器
IRQ  14,    46 	; 主 IDE 控制器
IRQ  15,    47 	; 从 IDE 控制器

; ============================================================================
; 通用 IRQ 处理桩（所有 IRQ 都会跳转到这里）
; ============================================================================

[GLOBAL irq_common_stub]
[EXTERN irq_handler]            ; 声明外部 C 函数 irq_handler
irq_common_stub:
    ; 保存所有通用寄存器
    pusha                       ; 依次压入：EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI

    ; 保存数据段描述符
    mov ax, ds
    push eax

    ; 加载内核数据段描述符
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    ; 调用 C 语言的 IRQ 处理函数
    push esp                    ; 将 pt_regs* 作为参数传递
    call irq_handler            ; 调用 C 函数 irq_handler(pt_regs *regs)
    add esp, 4                  ; 清理参数

    ; 恢复原来的数据段描述符
    pop ebx
    mov ds, bx
    mov es, bx
    mov fs, bx
    mov gs, bx
    mov ss, bx

    ; 恢复所有通用寄存器
    popa

    ; 清理栈中的错误代码和中断号
    add esp, 8

    ; 中断返回
    iret
.end:
