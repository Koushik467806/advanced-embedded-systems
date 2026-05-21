.global _start
_start:
	MOV r0, #1
	MOV r1, #3
	BL add2 // Stores address of command after a function in LR register
	
add2:
	ADD r2, r0, r1
	BX lr // Goes back to next command | Like a return command
	
	