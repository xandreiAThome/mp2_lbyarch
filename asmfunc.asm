section .data
sdot dd 0.0
i dd 0

section .text
bits 64
default rel
global dotproduct

dotproduct:
	MOV EAX, [i]
	MOVSS XMM0, [sdot]

	L1:
	CMP EAX, ECX
	JGE DONE

	MOVSS XMM1, [RDX + RAX*4]
	MOVSS XMM2, [R8 + RAX*4]

	VMULSS XMM6, XMM1, XMM2
	ADDSS XMM0, XMM6

	INC EAX
	JMP L1

	DONE:
	MOVSS [sdot], XMM0
	ret