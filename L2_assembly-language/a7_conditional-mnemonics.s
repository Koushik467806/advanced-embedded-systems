// These work only on 32-bit ARM

.global _start
_start:
	MOV r0, #2
	MOV r1, #4
	CMP r0, r1
	
	ADDLT r2, #1 // Add if less than (based on CMP r0, r1)
	MOVGE r2, #1 // Move if greater than or equal to
	
	// More conditional instructions
	// Mnemonic{cond}{s}
	// Mnemonic can be ADD, MOV, SUB, MUL, etc
	// cond can be EQ, NE, LT, GT, etc
	// S is optional suffix if we want to add a flag