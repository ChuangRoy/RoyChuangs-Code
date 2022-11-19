    .intel_syntax noprefix
.HelloWorldLabel:
    .ascii "Hello World !\0"
    .global    main
main:
    mov    rbp, rsp
    sub    rsp, 32
    call    __main
    lea    rax, .HelloWorldLabel[rip]
    mov    rcx, rax
    call    printf
    mov    eax, 0
    add    rsp, 32
    ret
