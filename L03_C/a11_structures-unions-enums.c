#include <stdio.h>

// Structure is like a block that stores information
struct A{
    int a;
    char b;
    char c[10];
};

// Nested Struct
struct B{
    int na;
    char nb;
    struct A a;
};

struct C{
    int ka;
    char kb;
};

// Union creates shared space for all the variables
// In this case, it creates a 10bit space (whichever is longer (int - 4bits, string - 10bits))
// Can store only 1 possible type at a time
union UA{
    int a;
    char b[10];
};

// Enumerations - represents a group of constants
enum Level{
    LOW = 20, // 0 by default
    MEDIUM = 70, // 1 by default
    HIGH = 100 // 2 by default
};

int main(){
    struct A s1; // s1 is of the type A

    //Assigning when defining
    struct A s2 = {1, 'a', "ABC"};

    // Copy structure
    // s3 is not affected if values in s2 are changed
    struct A s3;
    s3 = s2;

    // Accessing/Assigning values
    s1.a = 5;
    s1.b = 'c';
    strcpy(s1.c, "something"); // Use strcpy() for strings

    // Modify values
    s3.b = 'k';
    s3.a = 100;

    // Structure Pointer
    struct C s4 = {1, "a"};
    struct C *ptr = &s4;

    // To access
    printf("%d", ptr->ka);

    // Pass struct pointers into function rather than structures
    // This helps save memory

    // Creating a union u1
    union UA u1;
    u1.a = 10; // Initially it has 10
    strcpy(u1.b, "A"); // Now it has "A" and 10 is removed

    // Typedef keyword
    // It lets you create an alias
    typedef float f1; // Now we can use f1 instead of float
    f1 a = 1.111; // Same as float a = 1.111;

    // Always define variables which take up more space at the top
    // This prvents compiler to use padding
    // This will save space

    // Creating enum and assign value
    enum Level l1 = MEDIUM;
    printf("%d", l1); // Prints 70
}