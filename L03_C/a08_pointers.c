#include <stdio.h>

int main(){
    int a = 5;

    printf("%d", a); // Prints 5
    printf("%p", &a); // Prints memory address of a

    // Creating a pointer
    // int* ptr = &a can also be used
    int *ptr = &a; // ptr is pointer which stores address of a

    // & is called referencing operator
    // * is called dereferencing operator

    // Printing out content from pointer
    printf("%d", *ptr);

    // In arrays, the name of array is pointer of first element in the array
    int nums[4] = {1, 2, 3, 4};
    printf("%d", nums[0]); // Prints 1
    printf("%d", *nums); // Also prints 1

    // Navigating through array
    // nth element in array is located at ptr + (n-1) location
    for(int i = 0; i < 4; i++){
        printf("%d ", *(ptr + i));
    }

    // Pointer arithmetic depends on type of array
    /* Assume integer array, each increment is 4 bits (0x00 -> 0x04)
    If we have character array, each increment is 1 bit (0x00 -> 0x01) */

    return 0;
}