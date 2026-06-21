# Makefiles

It automates preprocessing, assembling, compiling, linking and relocating.
It helps generate dependencies.

1. 1 or more files can be used to tell **make** how to build particular project
2. Makefiles have build rules
3. Targets can have dependencies or prerequisites

---

### Build Rule Syntax

```makefile
target: prerequisite1 prerequisite2 prerequisite3
	command1
	command2
```

* **Recipe**: All commands together are called recipe.
* **Prerequisites**: Prerequisites are the dependencies.
* **Execution**: Recipe can be executed only if dependencies are met.

---

### Basic Example

```makefile
file.o: imp.c imp.h
	gcc -c file.c -o file.o
```

---

### Makefile Features & Rules

1. Comments start with `#`
2. Can include other makefiles
3. Line continuation using `\`
4. Can create and use variables
5. Can have multiple rules
6. Command lines should start with a tab
7. Targets can depend on another targets

---

### Makefile Variables

1. Variables can be set to strings of text and can include another variables
2. They can be used to hold compiler flags (CFLAGS) and linker flags (LFLAGS)
   ```makefile
   CFLAGS = -g -std=$(CSTD) -mcpu=$(CPU) -mthumb
   ```
3. Can be used to control what directories and source files are used for building
   ```makefile
   INCLUDES =    \
       -I./libs  \
       -I./modem \
       -I./uart  \
       -I./arch

   SRCS =         \
       ./main.c   \
       ./memory.c \
       ./uart.c   \
       ./data.c
   ```

There are 2 types:

#### Recursively Expanded Variables (`=`)
1. Expands whenever used
2. Example:
   ```makefile
   CSTD = c89
   CPU = cortex-m0plus
   CC = arm-none-eabi-gcc
   ```

#### Simply Expanded Variables (`:=`)
1. Expands once at the time of definition
2. Example:
   ```makefile
   ARCH := $(shell arch)
   CWD := $(shell pwd)
   OS := $(shell uname)
   ```

#### Automatic Variables
Example:
```makefile
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $@ $^
```

* `$@` is used for **target**
* `$^` is used for **all prerequisites**

#### Pattern Matching Operator (`%`)
Example:
```makefile
%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)
```

* `$<` is used for **prerequisite name**

**How it works (e.g., running `make main.o`):**
1. `make` matches `main.o` with the pattern `%.o`, setting the stem `%` to `main`.
2. It replaces `%` in `%.c` with `main`, identifying `main.c` as the prerequisite.
3. It executes the recipe command, expanding the automatic variables:
   * `$<` becomes `main.c`
   * `$@` becomes `main.o`
4. The actual command executed is:
   ```bash
   $(CC) -c main.c -o main.o $(CFLAGS)
   ```

#### Overriding Variables
Pass input parameters to alter the build:
```bash
make all PLATFORM=msp432
make all CPU=cortex-m4
```

---

### PHONY

A **phony target** is a target that is not the name of an actual file. We declare it using `.PHONY` so that:
1. **`make` doesn't get confused** if a file with the same name exists in the directory (e.g. a file named `clean`).
2. **It always executes** the recipe commands, bypassing filesystem checks for whether the target file is up-to-date.

```makefile
.PHONY: all
all: main.out
main.out: $(OBJS)
	gcc $(CFLAGS) -o main.out $(OBJS)

.PHONY: clean
clean:
	rm main.map $(OBJS) main.out
```

---

### Functions & Conditionals

1. **`shell`**: Gather data from system outside of `make`
   ```makefile
   OS := $(shell uname)
   ```
2. **`ifeq`**: Similar to an `if` statement
   ```makefile
   ifeq ($(OS), Linux)
       CPU = cortex-m4
   endif
   ```

---

### Comprehensive Example

```makefile
# This is a comment

# This includes a file
include source.mk

# Variables and Continuance
FLAGS = -g      \
        -Werror \
        -std=c99

# MyFile Target binary
MyFile.o: myFile.h myFile.c
	gcc $(FLAGS) -c -o myFile.o myFile.c

# main.o target binary
main.o: myFile.h
	gcc $(FLAGS) -c -o main.o main.c

# Main target executable
main.out: main.o myFile.o
	gcc -o main.out main.o myFile.o
```
