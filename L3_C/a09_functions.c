#include <stdio.h>
#include <math.h>

// Creating a function
void myFunc(){
    printf("Hello! This is my function");
}

// Taking in parameters
// num1 and num2 are parameters of type int
void sum_n(int num1, int num2, char a[2]){
    printf("%d", num1 + num2);
    printf("%s", a);
}

int main(){
    myFunc(); // Calling the function
    sum_n(2, 3, "ab"); // Gives 5
    return 0;
}

// If a variable is defined inside a function, it cannot be used outside the function (local)
// It will be detroyed right after the function is computed

// If a variable is defined outside a function, it is called global
// It can be accessed anywhere

// Some Math Functions - math.h
void maths(){
    printf("%f", sqrt(16)); // sqrt() is square root of a function
    printf("%f", ceil(1.4)); // Ceiling function
    printf("%f", floor(1.4)); // Floor function
    printf("%f", pow(4, 3)); // 4^3
}

int (*ptr)(int, char); // takes 2 inputs - int and char, returns int

// Callback
// When you use a function to call another function
void greetMorning() { printf("Good morning!\n"); }
void greetEvening() { printf("Good evening!\n"); }

void greet(void (*func)()) {
    func();
}

int main() {
    greet(greetMorning);
    greet(greetEvening);
    return 0;
}