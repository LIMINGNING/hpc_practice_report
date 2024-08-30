	.file	"dgemm_naive.c"
	.text
	.globl	dgemm
	.type	dgemm, @function
dgemm:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -52(%rbp)
	movl	%esi, -56(%rbp)
	movl	%edx, -60(%rbp)
	movl	%ecx, -64(%rbp)
	movq	%r8, -72(%rbp)
	movq	%r9, -80(%rbp)
	movl	-60(%rbp), %edx
	movslq	%edx, %rax
	subq	$1, %rax
	movq	%rax, -24(%rbp)
	movl	-56(%rbp), %ecx
	movslq	%ecx, %rax
	subq	$1, %rax
	movq	%rax, -16(%rbp)
	movl	-56(%rbp), %eax
	movslq	%eax, %rsi
	subq	$1, %rsi
	movq	%rsi, -8(%rbp)
	movl	$0, -36(%rbp)
	jmp	.L2
.L7:
	movl	$0, -32(%rbp)
	jmp	.L3
.L6:
	pxor	%xmm1, %xmm1
	cvtsi2sdl	-64(%rbp), %xmm1
	movl	-36(%rbp), %esi
	movslq	%esi, %rdi
	movslq	%eax, %rsi
	imulq	%rdi, %rsi
	leaq	0(,%rsi,8), %rdi
	movq	16(%rbp), %rsi
	addq	%rsi, %rdi
	movl	-32(%rbp), %esi
	movslq	%esi, %rsi
	movsd	(%rdi,%rsi,8), %xmm0
	movl	-36(%rbp), %esi
	movslq	%esi, %rdi
	movslq	%eax, %rsi
	imulq	%rdi, %rsi
	leaq	0(,%rsi,8), %rdi
	movq	16(%rbp), %rsi
	addq	%rsi, %rdi
	mulsd	%xmm1, %xmm0
	movl	-32(%rbp), %esi
	movslq	%esi, %rsi
	movsd	%xmm0, (%rdi,%rsi,8)
	movl	$0, -28(%rbp)
	jmp	.L4
.L5:
	movl	-36(%rbp), %esi
	movslq	%esi, %rdi
	movslq	%edx, %rsi
	imulq	%rdi, %rsi
	leaq	0(,%rsi,8), %rdi
	movq	-72(%rbp), %rsi
	addq	%rsi, %rdi
	movl	-28(%rbp), %esi
	movslq	%esi, %rsi
	movsd	(%rdi,%rsi,8), %xmm1
	movl	-28(%rbp), %esi
	movslq	%esi, %rdi
	movslq	%ecx, %rsi
	imulq	%rdi, %rsi
	leaq	0(,%rsi,8), %rdi
	movq	-80(%rbp), %rsi
	addq	%rsi, %rdi
	movl	-32(%rbp), %esi
	movslq	%esi, %rsi
	movsd	(%rdi,%rsi,8), %xmm0
	mulsd	%xmm0, %xmm1
	movl	-36(%rbp), %esi
	movslq	%esi, %rdi
	movslq	%eax, %rsi
	imulq	%rdi, %rsi
	leaq	0(,%rsi,8), %rdi
	movq	16(%rbp), %rsi
	addq	%rsi, %rdi
	movl	-32(%rbp), %esi
	movslq	%esi, %rsi
	movsd	(%rdi,%rsi,8), %xmm0
	movl	-36(%rbp), %esi
	movslq	%esi, %rdi
	movslq	%eax, %rsi
	imulq	%rdi, %rsi
	leaq	0(,%rsi,8), %rdi
	movq	16(%rbp), %rsi
	addq	%rsi, %rdi
	addsd	%xmm1, %xmm0
	movl	-32(%rbp), %esi
	movslq	%esi, %rsi
	movsd	%xmm0, (%rdi,%rsi,8)
	addl	$1, -28(%rbp)
.L4:
	movl	-28(%rbp), %esi
	cmpl	-60(%rbp), %esi
	jl	.L5
	addl	$1, -32(%rbp)
.L3:
	movl	-32(%rbp), %esi
	cmpl	-56(%rbp), %esi
	jl	.L6
	addl	$1, -36(%rbp)
.L2:
	movl	-36(%rbp), %esi
	cmpl	-52(%rbp), %esi
	jl	.L7
	nop
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	dgemm, .-dgemm
	.section	.rodata
.LC0:
	.string	"%lf "
.LC1:
	.string	"\n"
	.text
	.globl	printf_matrix
	.type	printf_matrix, @function
printf_matrix:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movl	%edi, -36(%rbp)
	movl	%esi, -40(%rbp)
	movq	%rdx, -48(%rbp)
	movl	-40(%rbp), %ebx
	movslq	%ebx, %rax
	subq	$1, %rax
	movq	%rax, -24(%rbp)
	movl	$0, -32(%rbp)
	jmp	.L9
.L12:
	movl	$0, -28(%rbp)
	jmp	.L10
.L11:
	movl	-32(%rbp), %eax
	movslq	%eax, %rdx
	movslq	%ebx, %rax
	imulq	%rdx, %rax
	leaq	0(,%rax,8), %rdx
	movq	-48(%rbp), %rax
	addq	%rax, %rdx
	movl	-28(%rbp), %eax
	cltq
	movq	(%rdx,%rax,8), %rax
	movq	%rax, %xmm0
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf@PLT
	addl	$1, -28(%rbp)
.L10:
	movl	-28(%rbp), %eax
	cmpl	-40(%rbp), %eax
	jl	.L11
	movl	$10, %edi
	call	putchar@PLT
	addl	$1, -32(%rbp)
.L9:
	movl	-32(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jl	.L12
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	nop
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	printf_matrix, .-printf_matrix
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$176, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movsd	.LC2(%rip), %xmm0
	movsd	%xmm0, -176(%rbp)
	movsd	.LC3(%rip), %xmm0
	movsd	%xmm0, -168(%rbp)
	movsd	.LC4(%rip), %xmm0
	movsd	%xmm0, -160(%rbp)
	movsd	.LC5(%rip), %xmm0
	movsd	%xmm0, -152(%rbp)
	movsd	.LC2(%rip), %xmm0
	movsd	%xmm0, -144(%rbp)
	movsd	.LC6(%rip), %xmm0
	movsd	%xmm0, -136(%rbp)
	movsd	.LC2(%rip), %xmm0
	movsd	%xmm0, -128(%rbp)
	movsd	.LC4(%rip), %xmm0
	movsd	%xmm0, -120(%rbp)
	movsd	.LC2(%rip), %xmm0
	movsd	%xmm0, -112(%rbp)
	movsd	.LC3(%rip), %xmm0
	movsd	%xmm0, -104(%rbp)
	movsd	.LC5(%rip), %xmm0
	movsd	%xmm0, -96(%rbp)
	movsd	.LC6(%rip), %xmm0
	movsd	%xmm0, -88(%rbp)
	movsd	.LC7(%rip), %xmm0
	movsd	%xmm0, -80(%rbp)
	movsd	.LC7(%rip), %xmm0
	movsd	%xmm0, -72(%rbp)
	movsd	.LC7(%rip), %xmm0
	movsd	%xmm0, -64(%rbp)
	movsd	.LC7(%rip), %xmm0
	movsd	%xmm0, -56(%rbp)
	movsd	.LC7(%rip), %xmm0
	movsd	%xmm0, -48(%rbp)
	movsd	.LC7(%rip), %xmm0
	movsd	%xmm0, -40(%rbp)
	movsd	.LC7(%rip), %xmm0
	movsd	%xmm0, -32(%rbp)
	movsd	.LC7(%rip), %xmm0
	movsd	%xmm0, -24(%rbp)
	movsd	.LC7(%rip), %xmm0
	movsd	%xmm0, -16(%rbp)
	leaq	-128(%rbp), %rcx
	leaq	-176(%rbp), %rdx
	subq	$8, %rsp
	leaq	-80(%rbp), %rax
	pushq	%rax
	movq	%rcx, %r9
	movq	%rdx, %r8
	movl	$2, %ecx
	movl	$2, %edx
	movl	$3, %esi
	movl	$3, %edi
	call	dgemm
	addq	$16, %rsp
	leaq	-176(%rbp), %rax
	movq	%rax, %rdx
	movl	$2, %esi
	movl	$3, %edi
	call	printf_matrix
	leaq	-128(%rbp), %rax
	movq	%rax, %rdx
	movl	$3, %esi
	movl	$2, %edi
	call	printf_matrix
	leaq	-80(%rbp), %rax
	movq	%rax, %rdx
	movl	$3, %esi
	movl	$3, %edi
	call	printf_matrix
	nop
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L14
	call	__stack_chk_fail@PLT
.L14:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC2:
	.long	0
	.long	1072693248
	.align 8
.LC3:
	.long	0
	.long	-1073217536
	.align 8
.LC4:
	.long	0
	.long	1073741824
	.align 8
.LC5:
	.long	0
	.long	1074790400
	.align 8
.LC6:
	.long	0
	.long	-1074790400
	.align 8
.LC7:
	.long	0
	.long	1071644672
	.ident	"GCC: (Ubuntu 13.2.0-23ubuntu4) 13.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
