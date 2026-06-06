.global _start
_start:
	LDR r0, =list // Loads stack data onto register
	LDR r1, [r0] // [r0] is first value in r0
	LDR r2, [r0, #4] // Second value in r0
	LDR r3, [r0, #4]! // ! is used here for pre-increment
	LDR r4, [r0], #4 // Post-increment

.data // To store in stack
list:
	.word 1, 2, -3, -6, 7, 8 // .word means 32-bit