#include <stdio.h>

int main(){
    // While Loop
    // Keeps running till the condition in () is false
    int a = 5;
    while(a > 0){ // Prints 5 4 3 2 1 then exits
        printf("%d ", a);
        a--;
    }

    // Do While
    // Loop will execute once before checking condition
    int i = 0;
    do {
        printf("%d ", i);
        i++;
    }
    while(i < 5);

    // For Loop
    // Keeps running till condition is met
    // Can specify operation to perform after every iteration in ()
    for(int j = 0; j < 5; j++){ // Starts at j = 0, Goes till j < 5, j is incremented after every iteration
        printf("j");
    }

    return 0;
}