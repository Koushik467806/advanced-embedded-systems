#include <stdio.h> // This is standard C library
#include "a00_basic.c" // This is any other file to be included

// Creating a Macro
// Created using #define
#define PI 3.14
// Everytime there is PI in code, it will be replaced by 3.14 before compilation

#define SQUARE(x) ((x) * (x)) // This is a square function

// ifdef and ifndef
// Used for conditional compilation

#define DEBUG // DEBUG is defined here
#define MGT // MGT is defined here

int main(){
    printf("%d", SQUARE(2));

    // This section will run only if DEBUG is defined
    #ifdef DEBUG
        printf("DEBUG");
    #endif

    // This section will run only if MGT is not defined
    #ifndef MGT
        printf("MGT is not defined");
    #endif

    return 0;
}