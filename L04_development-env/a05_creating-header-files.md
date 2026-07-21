# Creating Header Files

- **Libraries**: Collection of software (precompiled or direct source)
  - **Static Library**: Directly linked to the executable
  - **Shared Library**: Linked dynamically at runtime with the executable
- **Modules**: Software organization where each module encapsulates certain functionality within a library
- **Include Guard**: A mechanism using preprocessor directives (`#ifndef`, `#define`, `#endif`) to prevent a header file from being included multiple times during compilation. Multiple inclusions can lead to duplicate definition/redefinition errors.

---

## How to Create a Header File

Creating a header file (`.h`) in C involves structuring interface declarations so that other source files (`.c`) can include and use them safely and cleanly.

### Steps to Create a Header File:

1. **Use Include Guards**: 
   Wrap the entire content of the header file between `#ifndef HEADER_NAME_H`, `#define HEADER_NAME_H`, and `#endif /* HEADER_NAME_H */`. This prevents macro redefinition errors when the file is included multiple times.
2. **Add File-Level Documentation**:
   Use Doxygen comment blocks (`/** ... */`) at the top of the file to specify `@file`, `@brief`, author info (`@author`), date (`@date`), and overall description of the header.
3. **Include Required Headers**:
   Include standard or library headers (e.g., `<stdint.h>`, `<stddef.h>`) needed by data types referenced in the prototypes.
4. **Declare Macros and Data Types**:
   Define shared `#define` constants, `typedef`s, `struct`s, `enum`s, or `union`s.
5. **Declare Function Prototypes & Document Them**:
   - Write function declarations terminating with `;`.
   - Provide Doxygen comments (`@brief`, `@param`, `@return`) preceding each function prototype to explain its functionality, parameters, and return values.

---

## Example: `stats.h` Header File

Below is a complete header file (`stats.h`) using include guards, file documentation, and function prototype annotations based on the 7 assessment functions:

```c
#ifndef STATS_H
#define STATS_H

/**
 * @file stats.h 
 * @brief This file declares all the required function for the assessment.
 *
 * It has 7 functions:
 * 1. print_statistics()
 * 2. print_array()
 * 3. find_median()
 * 4. find_mean()
 * 5. find_maximum()
 * 6. find_minimum()
 * 7. sort_array()
 * Each function has a specific use case which will be explained in the later 
 * parts of the file
 *
 * @author Koushik Thatavarthi
 * @date 08-06-2026
 */

/**
 * @brief Prints the statistics of an array including minimum, maximum, mean, and median
 *
 * @param ptr Pointer to the data array
 * @param length Size of the array
 */
void print_statistics(unsigned char *ptr, unsigned int length);

/**
 * @brief Prints the array given as parameter
 *
 * This function takes 2 inputs namely "size" and "name" of the array
 * Since the name of the array is the pointer, this function will then move 
 * the pointer "size - 1" times and print the value at the pointer each time
 *
 * @param name The pointer of the array
 * @param size The size of the array
 *
 * @return 1 If successful
 * @return 0 Any error
 */
unsigned char print_array(unsigned char *name, unsigned int size);

/**
 * @brief Finds the median of an array of numbers
 *
 * @param ptr Pointer to the data array
 * @param length Size of the array
 *
 * @return The median value
 */
unsigned char find_median(unsigned char *ptr, unsigned int length);

/**
 * @brief Finds the mean value of an array of numbers
 *
 * @param ptr Pointer to the data array
 * @param length Size of the array
 *
 * @return The calculated mean value
 */
unsigned char find_mean(unsigned char *ptr, unsigned int length);

/**
 * @brief Finds the maximum value in an array of numbers
 *
 * @param ptr Pointer to the data array
 * @param length Size of the array
 *
 * @return The maximum element in the array
 */
unsigned char find_maximum(unsigned char *ptr, unsigned int length);

/**
 * @brief Finds the minimum value in an array of numbers
 *
 * @param ptr Pointer to the data array
 * @param length Size of the array
 *
 * @return The minimum element in the array
 */
unsigned char find_minimum(unsigned char *ptr, unsigned int length);

/**
 * @brief Sorts an array from largest to smallest (descending order)
 *
 * @param ptr Pointer to the data array
 * @param length Size of the array
 */
void sort_array(unsigned char *ptr, unsigned int length);

#endif /* STATS_H */
```

