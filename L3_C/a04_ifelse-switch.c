#include <stdio.h>

int main(){
    // if - elseif - else
    // Runs content in "if" if condition in the parenthesis is met
    // Else moves to "else if"
    // If all conditions are not met, it moves to content in "else"
    int a = 1, b = 2; // Change for different results

    if(a > b){
        printf("a is greater than b");
    }
    else if(a < b){
        printf("a is less than b");
    }
    else{
        printf("a is equal to b");
    }

    // Ternary Operator
    // variable = (condition) ? true_e : false_e
    int c = 5; // Change for different results
    (c < 3) ? printf("A") : printf("B"); // If c < 3, it will print "A" else "B"

    // Nested if
    if(3 > 2){
        printf("A");
        if(4 > 3){
            printf("B"); // Runs only if both "if"s are true
        }
    }


    // Switch
    // Selects one of many blocks to be executed
    int day = 4; // Change for different output

    switch (day) {
        case 1:
            printf("Monday");
            break; // Break makes sure you come out of "switch"
        case 2:
            printf("Tuesday");
            break;
        case 3:
            printf("Wednesday");
            break;
        case 4:
            printf("Thursday");
            break;
        case 5:
            printf("Friday");
            break;
        case 6:
            printf("Saturday");
            break;
        case 7:
            printf("Sunday");
            break;
        default: // Runs when all cases are false
            printf("Nothing");
        }
}