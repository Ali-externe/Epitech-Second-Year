    BITS 64

    SECTION .text

    GLOBAL strlen

strlen:
    PUSH RBP
    MOV RBP, RSP
    MOV RAX, 0
    call looper

increment:
    inc RDI
    inc rax
    call looper
looper:
    cmp BYTE[RDI], 0
    je ender
    jne increment
ender:
    mov RSP, RBP
    pop RBP
    ret
