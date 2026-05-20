.global _start
_start:
	MOV r0, #1
	MOV r1, #2
	
	// CMP compares two arguments provided
	// CMP Gives r0 - r1 and sets CPSR register
	CMP r0, r1
	BGT greator // If r0 > r1, it moves to "greator" (Branch if Greator Than)
	BAL default // Branch Always run this
	
	// Some available brances
	// 1. BGT: >
	// 2. BGE: >=
	// 3. BLT: <
	// 4. BLE: <=
	// 5. BEQ: =
	// 6. BNE: !=
	// 7. BLO: Branch if lower ( < for signed integers)
	// 8. BLI: Branch if lower ( > for signed integers)

greater:
	MOV r2, #1
	
default:
	MOV r2, #2