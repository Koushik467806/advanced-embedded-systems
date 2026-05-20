.global _start
_start:
	// Boolean Algebra is used anywhere applicable
	
	// Always pad +ve number with 0s (0xFF should be 0x000000FF if its +ve)
	// Always pad -ve number with 1s (0xFF should be 0x111111FF if its -ve)
	
	MOV r0, #0xFF
	MOV r1, #22
	AND r2, r0, r1 // r2 = r0 * r1
	ORR r3, r0, r1 // r3 = r0 + r1
	EOR r4, r0, r1 // r4 = r0'r1 + r0r1'
	MVN r5, r0 // It negates the 32-bit s0 0xFF = 0x000000FF which becomes 0xFFFFFF00
	
	