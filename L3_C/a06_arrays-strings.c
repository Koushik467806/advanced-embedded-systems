#include <stdio.h>

int main(){
    // Array is used to store multiple values in single variable
    int nums[] = {1, 2, 3, 4}; // Array of size 4

    // Accessing the element
    // Starts at 0, goes till (size - 1)
    // Accessing a value in array is called indexing
    printf("%d", nums[0]);

    // Changing value of element
    nums[3] = 5;

    // Declaring the size of array
    int nums_p[4]; // 4 elements
    
    // Storing values
    for(int i = 0; i < 4; i++){
        nums[i] = i + 1; // Stores 1, 2, 3, 4
    }

    // For length of array, we use something different
    // We divide total bytes with element bytes
    printf("\nSize of array is %d", sizeof(nums)/sizeof(nums[0]));

    // Multi-dimensional Arrays
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}}; // 2 rows, 3 columns

    // Accessing elements
    printf("Element of 2D array: %d", matrix[0][0]);

    // Changing elements
    matrix[1][1] = 100;

    // Looping through 2D array
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Strings
    
}