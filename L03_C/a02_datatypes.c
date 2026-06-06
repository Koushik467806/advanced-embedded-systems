#include <stdio.h>
#include <stdbool.h>

int main(){
    /* Basic Datatypes
    1. int - 4 bytes (Only integers)
    2. float - 4 bytes (Can have decimal points)
    3. double - 8 bytes (Can have decimal points)
    4. char - 1 byte (Single alphanumeral or ASCII value) */

    /* Format Specifiers
    1. int: %d or %i
    2. float: %f or %F
    3. double: %lf
    4. char: %c
    5. string: %s */

    char mychar = 'a'; // In single quotes
    printf("%c", mychar);

    char mystring[] = "hello"; // For strings
    printf("%s", mystring);

    int num1 = 10;
    printf("%d", num1);

    float num2 = 11.8;
    printf("%f", num2);

    double num3 = 10.99999999;
    printf("%lf", num3);

    // For scientific numbers, use "e" or "E"
    // 10e5 = 10 * 10^5

    // In float, it defaults to 6 decimal places
    //  Use printf("%.{num}f", number) for num decimal places
    printf("%.2f", num2); // Displays 11.80

    /* sizeof() 
    Used to get the size of datatypes
    We use %zu as the format specifier
    Use printf("%zu", mydatatype); */
    printf("%zu", num1);

    /* More datatypes
    short int: 2 bytes, %hd
    unsigned int: 4 bytes, %u
    long int: 4-8 bytes, %ld
    unsigned long int: 4-8 bytes, %lu
    unsigned long long int: 8 bytes, %llu
    long double: 8, 12, 16 bytes, %Lf */

    int normalInt = 1000;                       // standard int 
    double normalDouble = 3.14;                 // standard double

    short int small = -100;                     // smaller int
    unsigned int count = 25;                    // only positive int
    long int big = 1234567890;                  // larger int
    long long int veryBig = 9223372036854775807; // very large int
    unsigned long long int huge = 18446744073709551615U; // very large, only positive
    long double precise = 3.141592653589793238L; // extended precision

    printf("Normal int: %d\n", normalInt);
    printf("Normal double: %lf\n", normalDouble);
    printf("Small: %hd\n", small);
    printf("Count: %u\n", count);
    printf("Big: %ld\n", big);
    printf("Very Big: %lld\n", veryBig);
    printf("Huge: %llu\n", huge);
    printf("Precise: %Lf\n", precise);

    // Explicit Conversion
    float sum1 = (float) 5 / 2; // This gives sum1 = 2.5
    float sum2 = 5 / 2; // This gives sum2 = 2 (integer division)
    return 0;

    // Use of const
    // Used to declare read-only variables
    // Always assign value when declaring
    const int MYNUM = 10;

    // Bool - Yes or No
    bool isHappy = true;
    bool isSad = false;

    return 0;
}