BITS 64

SECTION .text

GLOBAL strchr

strchr:
    PUSH RBP
    MOV RBP, RSP
    MOV RAX, 0
    call looper

incre:
    inc rdi
    call looper

zero:
    mov rax, 0
    call ender
increment:
    cmp byte[RDI], 0
    je zero
    jne incre
fin:
    mov rax, rdi
    call ender
looper:
    cmp BYTE[rdi], sil
    je fin
    jne increment

ender:
    mov RSP, RBP
    pop RBP
    ret
