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
    

}