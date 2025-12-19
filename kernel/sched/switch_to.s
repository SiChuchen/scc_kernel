[GLOBAL switch_to]

; 具体得线程切换操作，重点在于保存和恢复寄存器
switch_to:
    ; 保存旧任务的上下文
    mov eax, [esp + 4]  ;这里拿到的是函数的第一个参数，也就是当前任务的上下文结构体的指针

    ; 所以这里就是将这些寄存器的值依次放回结构体保存起来
    mov [eax + 0], esp
    mov [eax + 4], ebp
    mov [eax + 8], ebx
    mov [eax +12], esi
    mov [eax +16], edi

    pushf               ; 把当前 EFLAGS 压栈
    pop ecx             ; 将其弹出到 ecx 寄存器
    mov [eax +20], ecx  ; 保存 EFLAGS 到结构体中

    ; 下面开始恢复下一个任务的寄存器值

    mov eax, [esp + 8]  ; 这里拿到的是函数的第二个参数，也就是下一个任务的上下文结构体的指针

    mov esp, [eax + 0]  ; 一旦 esp 被切到 next 的栈，这个函数后续的 ret 就会从 next 的栈上弹返回地址——执行流自然就转到 next 线程去了
    mov ebp, [eax + 4]
    mov ebx, [eax + 8]
    mov esi, [eax +12]
    mov edi, [eax +16]
    ; 这里先将 EFLAGS 存到 eax，然后再利用 push/pop 恢复
    ; 因为 x86 里不能直接 mov 读写 EFLAGS，通常就是用 pushf/popf 这种方式转存
    mov eax, [eax +20]
    push eax
    popf

    ret