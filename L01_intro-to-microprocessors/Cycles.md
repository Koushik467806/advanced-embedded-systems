**IPO (Input-Process-Output)**

1. Input is fed to ALU
2. Operand and opcodes are fed to ALU
3. The ALU performs the necessary tasks
4. The output is stored



**FDE (Fetch-Decode-Execute)**

1. Fetches the data and updates MAR by 1
2. Stores the data in MDR
3. Sends it to CIR for instructions
4. Splits it and send corresponding data to the processor for execution
5. If any interrupt, these values are copied to stack and interrupt is dealt with before copying back the stack and continuing the process



**FDEMW (Fetch-Decode-Execute-Memory-Write)**

Same as FDE but any memory needed is completed in **memory** part of the cycle

Any writing involved in finished in **write** part of the cycle





