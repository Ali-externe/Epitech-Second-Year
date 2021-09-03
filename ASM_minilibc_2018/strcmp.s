BITS 64

SECTION .text

GLOBAL strcmp

strcmp:
    PUSH RBP
    MOV RBP, RSP
    MOV RAX, 0
    call looper

incre:
    inc rdi
    inc rsi
    call looper

increment:
    cmp byte[RDI], 0
    je ender
    jne incre

greater:
    mov RAX, 1
    call ender

less:
    mov rax, -1
    call ender

looper:
    mov r8b, BYTE[RDI]
    mov r9b, BYTE[RSI]
    cmp r8b, r9b
    je increment
    jg greater
    jl less

ender:
    mov RSP, RBP
    pop RBP
    ret
