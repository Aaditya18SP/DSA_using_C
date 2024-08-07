	.text
	.file	"operations.c"
	.globl	createDoublyLL                  # -- Begin function createDoublyLL
	.p2align	4, 0x90
	.type	createDoublyLL,@function
createDoublyLL:                         # @createDoublyLL
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movabsq	$.L.str, %rdi
	movb	$0, %al
	callq	printf
	movabsq	$.L.str.1, %rdi
	leaq	-4(%rbp), %rsi
	movb	$0, %al
	callq	__isoc99_scanf
	movq	$0, -16(%rbp)
	movq	$0, -24(%rbp)
	movq	$0, -32(%rbp)
	movl	$16, %edi
	callq	malloc
	movq	%rax, -40(%rbp)
	movl	$0, -44(%rbp)
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	movl	-44(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jge	.LBB0_13
# %bb.2:                                #   in Loop: Header=BB0_1 Depth=1
	movabsq	$.L.str.2, %rdi
	movb	$0, %al
	callq	printf
	callq	getchar
	cmpl	$0, %eax
	je	.LBB0_11
# %bb.3:                                #   in Loop: Header=BB0_1 Depth=1
	callq	getchar
                                        # kill: def $al killed $al killed $eax
	movb	%al, -5(%rbp)
	movl	$24, %edi
	callq	malloc
	movq	%rax, -56(%rbp)
	movb	-5(%rbp), %cl
	movq	-56(%rbp), %rax
	movb	%cl, (%rax)
	movq	-56(%rbp), %rax
	movq	$0, 8(%rax)
	cmpq	$0, -16(%rbp)
	je	.LBB0_5
# %bb.4:                                #   in Loop: Header=BB0_1 Depth=1
	movq	-16(%rbp), %rcx
	movq	-56(%rbp), %rax
	movq	%rcx, 16(%rax)
	movq	-56(%rbp), %rcx
	movq	-16(%rbp), %rax
	movq	%rcx, 8(%rax)
	movq	-56(%rbp), %rax
	movq	%rax, -16(%rbp)
.LBB0_5:                                #   in Loop: Header=BB0_1 Depth=1
	cmpl	$0, -44(%rbp)
	jne	.LBB0_7
# %bb.6:                                #   in Loop: Header=BB0_1 Depth=1
	movq	-56(%rbp), %rax
	movq	$0, 16(%rax)
	movq	-56(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, -24(%rbp)
	jmp	.LBB0_10
.LBB0_7:                                #   in Loop: Header=BB0_1 Depth=1
	movl	-44(%rbp), %eax
	movl	-4(%rbp), %ecx
	subl	$1, %ecx
	cmpl	%ecx, %eax
	jne	.LBB0_9
# %bb.8:                                #   in Loop: Header=BB0_1 Depth=1
	movq	-56(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-56(%rbp), %rax
	movq	%rax, -32(%rbp)
.LBB0_9:                                #   in Loop: Header=BB0_1 Depth=1
	jmp	.LBB0_10
.LBB0_10:                               #   in Loop: Header=BB0_1 Depth=1
	jmp	.LBB0_11
.LBB0_11:                               #   in Loop: Header=BB0_1 Depth=1
	jmp	.LBB0_12
.LBB0_12:                               #   in Loop: Header=BB0_1 Depth=1
	movl	-44(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -44(%rbp)
	jmp	.LBB0_1
.LBB0_13:
	movq	-24(%rbp), %rcx
	movq	-40(%rbp), %rax
	movq	%rcx, (%rax)
	movq	-32(%rbp), %rcx
	movq	-40(%rbp), %rax
	movq	%rcx, 8(%rax)
	movq	-40(%rbp), %rax
	addq	$64, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	createDoublyLL, .Lfunc_end0-createDoublyLL
	.cfi_endproc
                                        # -- End function
	.globl	traverseDoublyLL                # -- Begin function traverseDoublyLL
	.p2align	4, 0x90
	.type	traverseDoublyLL,@function
traverseDoublyLL:                       # @traverseDoublyLL
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -40(%rbp)
	movl	$0, -44(%rbp)
	movl	$0, -48(%rbp)
	movl	$10, -52(%rbp)
	movslq	-52(%rbp), %rdi
	shlq	$0, %rdi
	callq	malloc
	movq	%rax, -64(%rbp)
	movslq	-52(%rbp), %rdi
	shlq	$0, %rdi
	callq	malloc
	movq	%rax, -72(%rbp)
.LBB1_1:                                # =>This Inner Loop Header: Depth=1
	xorl	%eax, %eax
                                        # kill: def $al killed $al killed $eax
	cmpq	$0, -32(%rbp)
	movb	%al, -73(%rbp)                  # 1-byte Spill
	je	.LBB1_3
# %bb.2:                                #   in Loop: Header=BB1_1 Depth=1
	cmpq	$0, -40(%rbp)
	setne	%al
	movb	%al, -73(%rbp)                  # 1-byte Spill
.LBB1_3:                                #   in Loop: Header=BB1_1 Depth=1
	movb	-73(%rbp), %al                  # 1-byte Reload
	testb	$1, %al
	jne	.LBB1_4
	jmp	.LBB1_7
.LBB1_4:                                #   in Loop: Header=BB1_1 Depth=1
	movl	-44(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jle	.LBB1_6
# %bb.5:                                #   in Loop: Header=BB1_1 Depth=1
	movq	-64(%rbp), %rdi
	movl	-52(%rbp), %eax
	addl	$10, %eax
	movslq	%eax, %rsi
	callq	realloc
	movq	%rax, -64(%rbp)
	movq	-72(%rbp), %rdi
	movl	-52(%rbp), %eax
	addl	$10, %eax
	movslq	%eax, %rsi
	callq	realloc
	movq	%rax, -72(%rbp)
	movl	-52(%rbp), %eax
	addl	$10, %eax
	movl	%eax, -52(%rbp)
.LBB1_6:                                #   in Loop: Header=BB1_1 Depth=1
	movq	-32(%rbp), %rax
	movb	(%rax), %dl
	movq	-64(%rbp), %rax
	movslq	-44(%rbp), %rcx
	movb	%dl, (%rax,%rcx)
	movq	-64(%rbp), %rax
	movl	-44(%rbp), %ecx
	addl	$1, %ecx
	movslq	%ecx, %rcx
	movb	$32, (%rax,%rcx)
	movq	-40(%rbp), %rax
	movb	(%rax), %dl
	movq	-72(%rbp), %rax
	movslq	-44(%rbp), %rcx
	movb	%dl, (%rax,%rcx)
	movq	-72(%rbp), %rax
	movl	-44(%rbp), %ecx
	addl	$1, %ecx
	movslq	%ecx, %rcx
	movb	$32, (%rax,%rcx)
	movq	-32(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -32(%rbp)
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -40(%rbp)
	movl	-44(%rbp), %eax
	addl	$2, %eax
	movl	%eax, -44(%rbp)
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	jmp	.LBB1_1
.LBB1_7:
	movq	-64(%rbp), %rsi
	movq	-72(%rbp), %rdx
	movabsq	$.L.str.3, %rdi
	movb	$0, %al
	callq	printf
	movl	-48(%rbp), %eax
	addq	$80, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end1:
	.size	traverseDoublyLL, .Lfunc_end1-traverseDoublyLL
	.cfi_endproc
                                        # -- End function
	.globl	insertAtBeginningOfDLL          # -- Begin function insertAtBeginningOfDLL
	.p2align	4, 0x90
	.type	insertAtBeginningOfDLL,@function
insertAtBeginningOfDLL:                 # @insertAtBeginningOfDLL
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movb	%sil, %al
	movq	%rdi, -8(%rbp)
	movb	%al, -9(%rbp)
	movl	$24, %edi
	callq	malloc
	movq	%rax, -24(%rbp)
	movb	-9(%rbp), %cl
	movq	-24(%rbp), %rax
	movb	%cl, (%rax)
	movq	-24(%rbp), %rax
	movq	$0, 16(%rax)
	movq	-8(%rbp), %rcx
	movq	-24(%rbp), %rax
	movq	%rcx, 8(%rax)
	movq	-24(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, 16(%rax)
	movq	-24(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end2:
	.size	insertAtBeginningOfDLL, .Lfunc_end2-insertAtBeginningOfDLL
	.cfi_endproc
                                        # -- End function
	.globl	insertAtTheEndOfDLL             # -- Begin function insertAtTheEndOfDLL
	.p2align	4, 0x90
	.type	insertAtTheEndOfDLL,@function
insertAtTheEndOfDLL:                    # @insertAtTheEndOfDLL
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movb	%sil, %al
	movq	%rdi, -8(%rbp)
	movb	%al, -9(%rbp)
	movl	$24, %edi
	callq	malloc
	movq	%rax, -24(%rbp)
	movb	-9(%rbp), %cl
	movq	-24(%rbp), %rax
	movb	%cl, (%rax)
	movq	-24(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-8(%rbp), %rcx
	movq	-24(%rbp), %rax
	movq	%rcx, 16(%rax)
	movq	-24(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, 8(%rax)
	movq	-24(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end3:
	.size	insertAtTheEndOfDLL, .Lfunc_end3-insertAtTheEndOfDLL
	.cfi_endproc
                                        # -- End function
	.globl	insertAfterAParticularElement   # -- Begin function insertAfterAParticularElement
	.p2align	4, 0x90
	.type	insertAfterAParticularElement,@function
insertAfterAParticularElement:          # @insertAfterAParticularElement
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movb	%dl, %al
	movb	%sil, %cl
	movq	%rdi, -8(%rbp)
	movb	%cl, -9(%rbp)
	movb	%al, -10(%rbp)
.LBB4_1:                                # =>This Inner Loop Header: Depth=1
	xorl	%eax, %eax
                                        # kill: def $al killed $al killed $eax
	cmpq	$0, -8(%rbp)
	movb	%al, -25(%rbp)                  # 1-byte Spill
	je	.LBB4_3
# %bb.2:                                #   in Loop: Header=BB4_1 Depth=1
	movq	-8(%rbp), %rax
	movsbl	(%rax), %eax
	movsbl	-10(%rbp), %ecx
	cmpl	%ecx, %eax
	setne	%al
	movb	%al, -25(%rbp)                  # 1-byte Spill
.LBB4_3:                                #   in Loop: Header=BB4_1 Depth=1
	movb	-25(%rbp), %al                  # 1-byte Reload
	testb	$1, %al
	jne	.LBB4_4
	jmp	.LBB4_5
.LBB4_4:                                #   in Loop: Header=BB4_1 Depth=1
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB4_1
.LBB4_5:
	cmpq	$0, -8(%rbp)
	jne	.LBB4_7
# %bb.6:
	movabsq	$.L.str.4, %rdi
	movb	$0, %al
	callq	printf
	jmp	.LBB4_8
.LBB4_7:
	movl	$24, %edi
	callq	malloc
	movq	%rax, -24(%rbp)
	movb	-9(%rbp), %cl
	movq	-24(%rbp), %rax
	movb	%cl, (%rax)
	movq	-8(%rbp), %rcx
	movq	-24(%rbp), %rax
	movq	%rcx, 16(%rax)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rcx
	movq	-24(%rbp), %rax
	movq	%rcx, 8(%rax)
	movq	-24(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rcx, 16(%rax)
	movq	-24(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, 8(%rax)
.LBB4_8:
	addq	$32, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end4:
	.size	insertAfterAParticularElement, .Lfunc_end4-insertAfterAParticularElement
	.cfi_endproc
                                        # -- End function
	.globl	insertIntoASortedDLL            # -- Begin function insertIntoASortedDLL
	.p2align	4, 0x90
	.type	insertIntoASortedDLL,@function
insertIntoASortedDLL:                   # @insertIntoASortedDLL
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movb	%dl, %al
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movb	%al, -25(%rbp)
	movl	$16, %edi
	callq	malloc
	movq	%rax, -40(%rbp)
	movsbl	-25(%rbp), %eax
	movq	-16(%rbp), %rcx
	movsbl	(%rcx), %ecx
	cmpl	%ecx, %eax
	jge	.LBB5_2
# %bb.1:
	movq	-16(%rbp), %rdi
	movsbl	-25(%rbp), %esi
	callq	insertAtBeginningOfDLL
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rcx
	movq	-40(%rbp), %rax
	movq	%rcx, (%rax)
	movq	-24(%rbp), %rcx
	movq	-40(%rbp), %rax
	movq	%rcx, 8(%rax)
	movq	-40(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB5_14
.LBB5_2:
	movsbl	-25(%rbp), %eax
	movq	-24(%rbp), %rcx
	movsbl	(%rcx), %ecx
	cmpl	%ecx, %eax
	jle	.LBB5_4
# %bb.3:
	movq	-24(%rbp), %rdi
	movsbl	-25(%rbp), %esi
	callq	insertAtTheEndOfDLL
	movq	%rax, -24(%rbp)
	movq	-16(%rbp), %rcx
	movq	-40(%rbp), %rax
	movq	%rcx, (%rax)
	movq	-24(%rbp), %rcx
	movq	-40(%rbp), %rax
	movq	%rcx, 8(%rax)
	movq	-40(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB5_14
.LBB5_4:
	jmp	.LBB5_5
.LBB5_5:
	movq	-16(%rbp), %rax
	movq	%rax, -48(%rbp)
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -56(%rbp)
.LBB5_6:                                # =>This Inner Loop Header: Depth=1
	xorl	%eax, %eax
                                        # kill: def $al killed $al killed $eax
	cmpq	$0, -56(%rbp)
	movb	%al, -65(%rbp)                  # 1-byte Spill
	je	.LBB5_8
# %bb.7:                                #   in Loop: Header=BB5_6 Depth=1
	movq	-56(%rbp), %rax
	movsbl	(%rax), %eax
	movsbl	-25(%rbp), %ecx
	cmpl	%ecx, %eax
	setl	%al
	movb	%al, -65(%rbp)                  # 1-byte Spill
.LBB5_8:                                #   in Loop: Header=BB5_6 Depth=1
	movb	-65(%rbp), %al                  # 1-byte Reload
	testb	$1, %al
	jne	.LBB5_9
	jmp	.LBB5_10
.LBB5_9:                                #   in Loop: Header=BB5_6 Depth=1
	movq	-48(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -48(%rbp)
	movq	-56(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -56(%rbp)
	jmp	.LBB5_6
.LBB5_10:
	cmpq	$0, -56(%rbp)
	jne	.LBB5_12
# %bb.11:
	movq	-24(%rbp), %rdi
	movsbl	-25(%rbp), %esi
	callq	insertAtTheEndOfDLL
	movq	%rax, -24(%rbp)
	jmp	.LBB5_13
.LBB5_12:
	movl	$24, %edi
	callq	malloc
	movq	%rax, -64(%rbp)
	movb	-25(%rbp), %cl
	movq	-64(%rbp), %rax
	movb	%cl, (%rax)
	movq	-56(%rbp), %rcx
	movq	-64(%rbp), %rax
	movq	%rcx, 8(%rax)
	movq	-48(%rbp), %rcx
	movq	-64(%rbp), %rax
	movq	%rcx, 16(%rax)
	movq	-64(%rbp), %rcx
	movq	-48(%rbp), %rax
	movq	%rcx, 8(%rax)
	movq	-64(%rbp), %rcx
	movq	-56(%rbp), %rax
	movq	%rcx, 16(%rax)
.LBB5_13:
	movq	-16(%rbp), %rcx
	movq	-40(%rbp), %rax
	movq	%rcx, (%rax)
	movq	-24(%rbp), %rcx
	movq	-40(%rbp), %rax
	movq	%rcx, 8(%rax)
	movq	-40(%rbp), %rax
	movq	%rax, -8(%rbp)
.LBB5_14:
	movq	-8(%rbp), %rax
	addq	$80, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end5:
	.size	insertIntoASortedDLL, .Lfunc_end5-insertIntoASortedDLL
	.cfi_endproc
                                        # -- End function
	.globl	deleteFromBeginningOfDLL        # -- Begin function deleteFromBeginningOfDLL
	.p2align	4, 0x90
	.type	deleteFromBeginningOfDLL,@function
deleteFromBeginningOfDLL:               # @deleteFromBeginningOfDLL
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$0, 16(%rax)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end6:
	.size	deleteFromBeginningOfDLL, .Lfunc_end6-deleteFromBeginningOfDLL
	.cfi_endproc
                                        # -- End function
	.globl	deleteFromEndOfDLL              # -- Begin function deleteFromEndOfDLL
	.p2align	4, 0x90
	.type	deleteFromEndOfDLL,@function
deleteFromEndOfDLL:                     # @deleteFromEndOfDLL
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -16(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB7_2
# %bb.1:
	movq	-16(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$0, 8(%rax)
.LBB7_2:
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end7:
	.size	deleteFromEndOfDLL, .Lfunc_end7-deleteFromEndOfDLL
	.cfi_endproc
                                        # -- End function
	.globl	deleteAParticularElement        # -- Begin function deleteAParticularElement
	.p2align	4, 0x90
	.type	deleteAParticularElement,@function
deleteAParticularElement:               # @deleteAParticularElement
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movb	%dl, %al
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movb	%al, -25(%rbp)
	movl	$16, %edi
	callq	malloc
	movq	%rax, -40(%rbp)
	movq	-16(%rbp), %rcx
	movq	-40(%rbp), %rax
	movq	%rcx, (%rax)
	movq	-24(%rbp), %rcx
	movq	-40(%rbp), %rax
	movq	%rcx, 8(%rax)
	movq	-16(%rbp), %rax
	movsbl	(%rax), %eax
	movsbl	-25(%rbp), %ecx
	cmpl	%ecx, %eax
	jne	.LBB8_2
# %bb.1:
	movq	-16(%rbp), %rdi
	callq	deleteFromBeginningOfDLL
	movq	%rax, %rcx
	movq	-40(%rbp), %rax
	movq	%rcx, (%rax)
	movq	-40(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB8_13
.LBB8_2:
	movq	-24(%rbp), %rax
	movsbl	(%rax), %eax
	movsbl	-25(%rbp), %ecx
	cmpl	%ecx, %eax
	jne	.LBB8_4
# %bb.3:
	movq	-24(%rbp), %rdi
	callq	deleteFromEndOfDLL
	movq	%rax, %rcx
	movq	-40(%rbp), %rax
	movq	%rcx, 8(%rax)
	movq	-40(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB8_13
.LBB8_4:
	jmp	.LBB8_5
.LBB8_5:                                # =>This Inner Loop Header: Depth=1
	xorl	%eax, %eax
                                        # kill: def $al killed $al killed $eax
	cmpq	$0, -16(%rbp)
	movb	%al, -49(%rbp)                  # 1-byte Spill
	je	.LBB8_7
# %bb.6:                                #   in Loop: Header=BB8_5 Depth=1
	movq	-16(%rbp), %rax
	movsbl	(%rax), %eax
	movsbl	-25(%rbp), %ecx
	cmpl	%ecx, %eax
	setne	%al
	movb	%al, -49(%rbp)                  # 1-byte Spill
.LBB8_7:                                #   in Loop: Header=BB8_5 Depth=1
	movb	-49(%rbp), %al                  # 1-byte Reload
	testb	$1, %al
	jne	.LBB8_8
	jmp	.LBB8_9
.LBB8_8:                                #   in Loop: Header=BB8_5 Depth=1
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
	jmp	.LBB8_5
.LBB8_9:
	cmpq	$0, -16(%rbp)
	jne	.LBB8_11
# %bb.10:
	movabsq	$.L.str.5, %rdi
	movb	$0, %al
	callq	printf
	jmp	.LBB8_12
.LBB8_11:
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -48(%rbp)
	movq	-48(%rbp), %rcx
	movq	-16(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rcx, 8(%rax)
	movq	-16(%rbp), %rax
	movq	16(%rax), %rcx
	movq	-48(%rbp), %rax
	movq	%rcx, 16(%rax)
	movq	-16(%rbp), %rdi
	callq	free
	movabsq	$.L.str.6, %rdi
	movb	$0, %al
	callq	printf
.LBB8_12:
	movq	-40(%rbp), %rax
	movq	%rax, -8(%rbp)
.LBB8_13:
	movq	-8(%rbp), %rax
	addq	$64, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end8:
	.size	deleteAParticularElement, .Lfunc_end8-deleteAParticularElement
	.cfi_endproc
                                        # -- End function
	.globl	mergeSortedDoublyLL             # -- Begin function mergeSortedDoublyLL
	.p2align	4, 0x90
	.type	mergeSortedDoublyLL,@function
mergeSortedDoublyLL:                    # @mergeSortedDoublyLL
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$8, %edi
	callq	malloc
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	$0, 16(%rax)
	movq	-24(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-24(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	$0, -40(%rbp)
	movq	$0, -48(%rbp)
	movl	$16, %edi
	callq	malloc
	movq	%rax, -56(%rbp)
.LBB9_1:                                # =>This Inner Loop Header: Depth=1
	xorl	%eax, %eax
                                        # kill: def $al killed $al killed $eax
	cmpq	$0, -8(%rbp)
	movb	%al, -57(%rbp)                  # 1-byte Spill
	je	.LBB9_3
# %bb.2:                                #   in Loop: Header=BB9_1 Depth=1
	cmpq	$0, -16(%rbp)
	setne	%al
	movb	%al, -57(%rbp)                  # 1-byte Spill
.LBB9_3:                                #   in Loop: Header=BB9_1 Depth=1
	movb	-57(%rbp), %al                  # 1-byte Reload
	testb	$1, %al
	jne	.LBB9_4
	jmp	.LBB9_12
.LBB9_4:                                #   in Loop: Header=BB9_1 Depth=1
	cmpq	$0, -32(%rbp)
	jne	.LBB9_6
# %bb.5:                                #   in Loop: Header=BB9_1 Depth=1
	movl	$24, %edi
	callq	malloc
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	$0, 8(%rax)
.LBB9_6:                                #   in Loop: Header=BB9_1 Depth=1
	movq	-8(%rbp), %rax
	movsbl	(%rax), %eax
	movq	-16(%rbp), %rcx
	movsbl	(%rcx), %ecx
	cmpl	%ecx, %eax
	jg	.LBB9_8
# %bb.7:                                #   in Loop: Header=BB9_1 Depth=1
	movq	-8(%rbp), %rax
	movb	(%rax), %cl
	movq	-32(%rbp), %rax
	movb	%cl, (%rax)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.LBB9_9
.LBB9_8:                                #   in Loop: Header=BB9_1 Depth=1
	movq	-16(%rbp), %rax
	movb	(%rax), %cl
	movq	-32(%rbp), %rax
	movb	%cl, (%rax)
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
.LBB9_9:                                #   in Loop: Header=BB9_1 Depth=1
	cmpq	$0, -40(%rbp)
	je	.LBB9_11
# %bb.10:                               #   in Loop: Header=BB9_1 Depth=1
	movq	-40(%rbp), %rcx
	movq	-32(%rbp), %rax
	movq	%rcx, 16(%rax)
	movq	-32(%rbp), %rcx
	movq	-40(%rbp), %rax
	movq	%rcx, 8(%rax)
.LBB9_11:                               #   in Loop: Header=BB9_1 Depth=1
	movq	-32(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	-32(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -32(%rbp)
	jmp	.LBB9_1
.LBB9_12:
	cmpq	$0, -8(%rbp)
	jne	.LBB9_21
# %bb.13:
	jmp	.LBB9_14
.LBB9_14:                               # =>This Inner Loop Header: Depth=1
	cmpq	$0, -16(%rbp)
	je	.LBB9_20
# %bb.15:                               #   in Loop: Header=BB9_14 Depth=1
	cmpq	$0, -32(%rbp)
	jne	.LBB9_17
# %bb.16:                               #   in Loop: Header=BB9_14 Depth=1
	movl	$24, %edi
	callq	malloc
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	$0, 8(%rax)
.LBB9_17:                               #   in Loop: Header=BB9_14 Depth=1
	movq	-16(%rbp), %rax
	movb	(%rax), %cl
	movq	-32(%rbp), %rax
	movb	%cl, (%rax)
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
	cmpq	$0, -40(%rbp)
	je	.LBB9_19
# %bb.18:                               #   in Loop: Header=BB9_14 Depth=1
	movq	-40(%rbp), %rcx
	movq	-32(%rbp), %rax
	movq	%rcx, 16(%rax)
	movq	-32(%rbp), %rcx
	movq	-40(%rbp), %rax
	movq	%rcx, 8(%rax)
.LBB9_19:                               #   in Loop: Header=BB9_14 Depth=1
	movq	-32(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	-32(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -32(%rbp)
	jmp	.LBB9_14
.LBB9_20:
	movq	-40(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-40(%rbp), %rax
	movq	%rax, -48(%rbp)
	jmp	.LBB9_31
.LBB9_21:
	cmpq	$0, -16(%rbp)
	jne	.LBB9_30
# %bb.22:
	jmp	.LBB9_23
.LBB9_23:                               # =>This Inner Loop Header: Depth=1
	cmpq	$0, -8(%rbp)
	je	.LBB9_29
# %bb.24:                               #   in Loop: Header=BB9_23 Depth=1
	cmpq	$0, -32(%rbp)
	jne	.LBB9_26
# %bb.25:                               #   in Loop: Header=BB9_23 Depth=1
	movl	$24, %edi
	callq	malloc
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	$0, 8(%rax)
.LBB9_26:                               #   in Loop: Header=BB9_23 Depth=1
	movq	-8(%rbp), %rax
	movb	(%rax), %cl
	movq	-32(%rbp), %rax
	movb	%cl, (%rax)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
	cmpq	$0, -40(%rbp)
	je	.LBB9_28
# %bb.27:                               #   in Loop: Header=BB9_23 Depth=1
	movq	-40(%rbp), %rcx
	movq	-32(%rbp), %rax
	movq	%rcx, 16(%rax)
	movq	-32(%rbp), %rcx
	movq	-40(%rbp), %rax
	movq	%rcx, 8(%rax)
.LBB9_28:                               #   in Loop: Header=BB9_23 Depth=1
	movq	-32(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	-32(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -32(%rbp)
	jmp	.LBB9_23
.LBB9_29:
	movq	-40(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-40(%rbp), %rax
	movq	%rax, -48(%rbp)
.LBB9_30:
	jmp	.LBB9_31
.LBB9_31:
	movq	-24(%rbp), %rcx
	movq	-56(%rbp), %rax
	movq	%rcx, (%rax)
	movq	-48(%rbp), %rcx
	movq	-56(%rbp), %rax
	movq	%rcx, 8(%rax)
	movq	-56(%rbp), %rax
	addq	$64, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end9:
	.size	mergeSortedDoublyLL, .Lfunc_end9-mergeSortedDoublyLL
	.cfi_endproc
                                        # -- End function
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	callq	createDoublyLL
	movq	%rax, -24(%rbp)
	callq	createDoublyLL
	movq	%rax, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rdi
	movq	-32(%rbp), %rax
	movq	(%rax), %rsi
	callq	mergeSortedDoublyLL
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rdi
	callq	traverseDoublyLL
	callq	getchar
	xorl	%eax, %eax
	addq	$48, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end10:
	.size	main, .Lfunc_end10-main
	.cfi_endproc
                                        # -- End function
	.type	.L.str,@object                  # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"Enter the number of elements you want in the LL:"
	.size	.L.str, 49

	.type	.L.str.1,@object                # @.str.1
.L.str.1:
	.asciz	"%d"
	.size	.L.str.1, 3

	.type	.L.str.2,@object                # @.str.2
.L.str.2:
	.asciz	"enter value:"
	.size	.L.str.2, 13

	.type	.L.str.3,@object                # @.str.3
.L.str.3:
	.asciz	"\nFrom the head side: %s\nAnd from the tail side: %s\n"
	.size	.L.str.3, 52

	.type	.L.str.4,@object                # @.str.4
.L.str.4:
	.asciz	"Couldn't locate the element after which the new element needs to be inserted\n"
	.size	.L.str.4, 78

	.type	.L.str.5,@object                # @.str.5
.L.str.5:
	.asciz	"The element you wanted to delete couldnot be found\n"
	.size	.L.str.5, 52

	.type	.L.str.6,@object                # @.str.6
.L.str.6:
	.asciz	"deleted successfully\n"
	.size	.L.str.6, 22

	.ident	"clang version 17.0.6 (Fedora 17.0.6-2.fc39)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym createDoublyLL
	.addrsig_sym printf
	.addrsig_sym __isoc99_scanf
	.addrsig_sym malloc
	.addrsig_sym getchar
	.addrsig_sym traverseDoublyLL
	.addrsig_sym realloc
	.addrsig_sym insertAtBeginningOfDLL
	.addrsig_sym insertAtTheEndOfDLL
	.addrsig_sym deleteFromBeginningOfDLL
	.addrsig_sym deleteFromEndOfDLL
	.addrsig_sym free
	.addrsig_sym mergeSortedDoublyLL
