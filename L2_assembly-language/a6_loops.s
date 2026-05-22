// To iterate through lists or stringsm we generally use some known characters such as "\0"
// This helps us know if we have reached the end of the list/string
// In this example, we are assuming ideal case where uninitialised data is not touched

.global _start

.equ endlist, 0xaaaaaaaa // Constants

_start:
	LDR r0, =list // Storing list pointer in r0
	LDR r3, =endlist
	LDR r1, [r0]
	ADD r2, r2, r1 // r2 += r1
loop:
	LDR r1, [r0, #4]! // r1++
	CMP r1, r3 // Comparing for end of the list
	BEQ exit // Exit if end is reached
	ADD r2, r2, r1 // r2 += r1
	BAL loop

exit:

.data
list:
	.word 1, 2, 3, 4, 5, 6, ,7 , 8, 9, 10