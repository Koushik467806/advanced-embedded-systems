**Registers** contain:

1. **Program Counter (PC):**  Stores memory address of current/next instruction
2. **Current Instruction Register (CIR):**  Stores content of current address ready to be executed
3. **Memory Address Register (MAR):** Stores memory location of data which may need to be fetched
4. **Memory Data Register (MDR):** THe fetched data is stored here
5. **Accumulator (ACC):** Input and results of instructions are put here



**Arithmetic and Logical Unit (ALU)**

Outputs:

1. Carry-out: Carry/Borrow value
2. Zero: All bits in output are 0
3. Negative: Result is negative
4. Overflow: Exceeds the numeric range of result
5. Parity: Indicated if total "1"s in result are even/odd



Functions:

1. Add/Subtract: Arithmetic addition/subtraction
2. Subtract with borrow: borrow value shows up at "carry-out"
3. 2's complement
4. Increment/Decrement
5. AND/OR/NOT/XOR: Bitwise operators
6. Arithmetic/Logical Shift
7. Rotate



**Volatile Memory:** Wiped after power is powered off

**Non-Volatile Memory:** Data is not lost when powered off



For 010110010010 (Divide as (0101)(1001)(0010)):

1. 0101 is opcode: Tells which opeartion to perform (last 0/1: increment value (INCI)/ increment address provided (INCA))
2. 1001 and 0010 are operand: Opeartions are performed on operands



**Status Register:** Checks the status of previous task

