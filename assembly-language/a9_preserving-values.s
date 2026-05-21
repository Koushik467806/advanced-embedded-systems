.global _start
_start:
	MOV r0, #1
	MOV r1, #3
	PUSH {r0, r1} // Places these values onto the stack
	BL get_value
	POP {r0, r1} // Puts back the values
	B end
	
get_value:
	MOV r0, #5
	MOV r1, #7
	ADD r2, r0, r1
	BX lr
	
end: