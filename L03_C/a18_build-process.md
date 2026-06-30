# Build Process

## Source Code
1. `.i` file for every `.c` file
2. Hash includes will be resolved
3. All macros will be resolved
4. `.i` file will be created

## Parsing Stage
1. Parse `.i` file for syntax against standard code
2. Code converted into `.s` file using code generator
3. Higher level C is converted into assembly language
4. Assembler will convert this into machine codes
5. Produces `.o` file

## Linking Stage
1. `.o` files will be converted into one executable file
2. `.c` + `.o` files = `.elf` file
