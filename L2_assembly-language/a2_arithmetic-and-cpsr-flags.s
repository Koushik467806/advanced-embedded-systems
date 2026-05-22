.global _start
_start:
	MOV r0, #37
	MOV r1, #15
	ADD r2, r0, r1 // r2 = r0 + r1
	SUB r3, r0, r1 // r3 = r0 - r1
	MUL r4, r0, r1 // r4 = r0 * r1
	SUBS r5, r0, r1 // SUBS does subtract and sets CPSR to show if its +ve or -ve
	ADC r6, r0, r1 // Will have "carry" | r6 = r0 + r1 + carry | carry if r6 reaches its max limit
	
	