BITS 64

SECTION .text

GLOBAL strncmp

strncmp:
    PUSH RBP
    MOV RBP, RSP
    MOV RAX, 0
    MOV rcx, 1
    call looper

incre:
    inc rdi
    inc rsi
    inc rcx
    call looper

fin:
    cmp byte[RDI], 0
    je ender
    jne incre

increment:
    cmp rcx, rdx
    je ender
    jne fin

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
