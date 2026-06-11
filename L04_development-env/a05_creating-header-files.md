# Creating Header Files

- **Libraries**: Collection of software (precompiled or direct source)
  - **Static Library**: Directly linked to the executable
  - **Shared Library**: Linked dynamically at runtime with the executable
- **Modules**: Software organization where each module encapsulates certain functionality within a library
- **Include Guard**: A mechanism using preprocessor directives (`#ifndef`, `#define`, `#endif`) to prevent a header file from being included multiple times during compilation. Multiple inclusions can lead to duplicate definition/redefinition errors.
  - **Example**:
    ```c
    #ifndef MY_HEADER_H
    #define MY_HEADER_H

    // Declarations (structs, functions, macros)
    typedef struct {
        int x;
        int y;
    } Point;

    void print_point(Point p);

    #endif /* MY_HEADER_H */
    ```
