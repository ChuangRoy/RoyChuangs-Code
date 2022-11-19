	.intel_syntax noprefix
	.text
	.section .rdata,"dr"
.LC0:
	.ascii "hello, world\0"
	.text
	.global	main
main:
	push	rbp
	mov	rbp, rsp
	sub	rsp, 32
	call	__main
	lea	rax, .LC0[rip]
	mov	rcx, rax
	call	puts
	nop
	add	rsp, 32
	pop	rbp
	ret
