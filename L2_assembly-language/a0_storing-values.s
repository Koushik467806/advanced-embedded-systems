.global _start // Tells this is start
_start: // Label (Like a function)
	MOV r0, #30 // 30 is placed in r0 (Can use #0x0A for hex)
	MOV r7, #1 // 1 Ends program (This just puts in r7, not anctually terminate)
	SWI 0 // Interrupts the program and lets OS takeover
	