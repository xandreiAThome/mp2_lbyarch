section .data
zero dd 0.0

section .text
bits 64
default rel ; to handle address relocation

global sdot_asm
extern printf

sdot_asm:
	mov r10, rcx ; move the first vector ptr because rcx is needed for the loop
	xor rcx, rcx ; counter index
	mov r11, rdx ; 2nd vector ptr
	movss xmm2, [zero] ; initialize result to 0.0
	mov r12, r8  ; vector_size
.loop:
	cmp rcx, r12
	je .done
	movss xmm0, [r10 + rcx * 4]
	movss xmm1, [r11 + rcx * 4]
	mulss xmm0, xmm1
	addss xmm2, xmm0
	inc rcx
	jmp .loop

.done:
	movss xmm0, xmm2
	ret
