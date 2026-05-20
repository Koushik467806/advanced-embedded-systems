.global _start
_start:
	
	MOV r0, #10 // 0000 0000 0000 0000 0000 0000 0000 1010
	 
	// Left-Shift Logical
	LSL r0, #1 // 0000 0000 0000 0000 0000 0000 0001 0100
	 
	// Right-Shift Logical (Assuming LSL not performed yet, output in the comments is written
	LSR r0, #1 // 0000 0000 0000 0000 0000 0000 0000 0101
	 
	// MOV and LSL in 1 single command
	// 1. Duplicates r0 and puts in r1
	// 2. Left-shifts r1 (essentially multiplying by 2)
	MOV r1, r0, LSL #1
	
	// Rotating the number
	// There is only Rotate right (ROR)
	// Use 32 - n (31 in this case) with ROR to get Left rotation by n times
	MOV r2, #15 // 0000 0000 0000 0000 0000 0000 0000 1111
	ROR r2, #1 // 1000 0000 0000 0000 0000 0000 0000 0111
	
	