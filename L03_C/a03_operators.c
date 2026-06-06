#include <stdio.h>

int main(){
    // Arithmetic Operators: +, -, *, /, %, ++, --
    int x = 10, y = 5;

    printf("%d\n", x + y);
    printf("%d\n", x - y);
    printf("%d\n", x * y);
    printf("%d\n", x / y);
    printf("%d\n", x % y);
    printf("%d\n", ++x); // Increments then prints (11)
    printf("%d\n", --x); // Decrements then prints (10)
    printf("%d\n", x++); // Prints then increments (10), x becomes 11
    printf("%d\n", x--); // Prints then decrements (11), x becomes 10
    
    // Assignment Operators: =, +=, -=, *=, /=, %=, &=, |=, ^=, >>=, <<=
    int a = 5;
    a += 5; // a = a + 5
    a -= 5; // a = a - 5

    // Comparision Operators: ==, !=, >, <, <=, >=
    int num1 = 1, num2 = 2; // Edit for different results
    if(x == y){
        printf("x is equal to y");
    }
    if(x != y){
        printf("x is not equal to y");
    }
    if(x < y){
        printf("x is less than y");
    }
    if(x > y){
        printf("x is greater than y");
    }

    // Logical Operators: &&, ||, !
    if(x < 5 && x < 10){
        printf("True"); // Runs only if both conditions are met
    }
    if(x < 5 || x > 10){
        printf("False"); // Runs if either of the statements is correct
    }

    // Bitwise Operators: &, |, ^, ~, <<, >>
    int a = 6, b = 5; // a = 0110, b = 0011 in binary
    printf("%d", a & b); // AND: 0010
    printf("%d", a | b); // OR: 0111
    printf("%d", a ^ b); // XOR: 0101
    printf("%d", ~a); // NOT: ..1001
    printf("%d", a << 1); // Left Shift (* 2)
    printf("%d", a >> 1); // Right Shift (/ 2)

    // Opertor Precedence
    /*
    1. ()
    2. *, / %
    3. +, -
    4. >, <, >=, <=
    5. ==, !=
    6. &&
    7. ||
    8. =
    */

    return 0;
}