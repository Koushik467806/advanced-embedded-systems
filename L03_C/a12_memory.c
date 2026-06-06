#include <stdio.h>'

typedef struct{
    char a;
    int b;
} A;

int main(){
    // Static Memory: Reserved for variables before the program runs
    // Dynamic Memory: Allocated after the program starts running

    // Malloc: malloc(size)
    // Calloc: calloc(amount, size) (for many items of same size)

    // malloc() data is unpredictable
    // calloc() data is filled with zeros (slightly inefficient)

    int *ptr1, *ptr2;

    ptr1 = malloc(sizeof(*ptr1)); // *ptr1 is int - 4 bytes
    ptr2 = calloc(1, sizeof(*ptr2)); // *ptr2 is int - 4 bytes

    // Create an array
    int *a;
    int num_a = 10;
    a = calloc(num_a, sizeof(*a)); // 10 * 4 = 40 bytes

    // Accessing it
    a[0] = 1;
    a[1] = 2;

    char *ptr3 = (char*) ptr1; // Converting int data to char
    ptr1[0] = 1684234849; // In char, 1234567 -> 0x64636261 -> 64, 63, 62, 61 (ASCII Values) -> d, c, b, a (Stored in reverse)

    // Resizing/Reallocating memory
    int *ptr4, *ptr5, size;
    size = 4 * sizeof(*ptr1); // 4 int
    ptr4 = malloc(size);
    size *= 2;
    ptr5 = realloc(ptr4, size); // ptr4 is not safe to use anymore
    // When increasing size, data is kept
    // When size is shrinked, only data which fits is stored

    // realloc() returns NULL if it fails to allocate more memory
    // Use pointer == NULL to check

    // Always free() all the pointers after using them
    // Makes it more efficient and maintanable
    // This is called Deallocation
    free(ptr1, ptr2, ptr3, ptr4, ptr5);

    // Good practice to set all free pointers to NULL to prevent accidental uses
    ptr1 = ptr2 = ptr3 = ptr4 = ptr5 = NULL;

    // Allocating memory for structures
    A *ptr = (A*) malloc(3 * sizeof(A)); // ptr is 3 A
    // Access
    ptr[0].a = 'A';
    ptr[1].b = 5;
    printf("%c, %d", ptr[0].a, ptr[1].b);
    
    free(ptr);
    ptr = NULL;

    return 0;
}