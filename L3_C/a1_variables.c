#include <stdio.h>

int main(){
    // General syntax: {type} {variable_name} = {value}

    int num1 = 9;
    float num2 = 10.8;
    char char1 = 'a'; // Single character

    /* Character Specifiers
    1. int: %d
    2. float: %f
    3. char: %c */
    printf("%d \n %f \n %c", num1, num2, char1);
    printf("\nWithout varibales: %d", 10);

    // We can perform operations on variables
    int a = 5, b = 10, c = 15;
    printf("%d", a + b + c);

    // We can assign same value to different variables at once
    int x, y, z;
    x = y = z = 100;

    /* General Rules when naming
    1. Can contain letters, digits, underscores
    2. Must begin with letter or underscore
    3. Case-sensitive
    4. Cannot use reserved words */

    return 0;
}