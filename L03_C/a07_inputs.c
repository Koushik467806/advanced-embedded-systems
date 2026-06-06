#include <stdio.h>

int main(){
    // Taking user inputs and storing them
    int myNum;
    char myLetter;
    // &myNum is a pointer pointing to address of myNum
    scanf("%d", &myNum);
    scanf("%c", &myLetter);

    // When working with strings, we m ust specify the size of string before taking input
    char N[10];
    scanf("%s", N); // No need to use &

    // scanf() considers space, tab space as terminating characters
    // We have to use fgets() to include those
    fgets(N, sizeof(N), stdin);

    // stdin for keyboard input
    // stdout for screen (output)
    // stderr for screen (error msgs)

    fprintf(stdout, "Some message"); // Saves this to output.txt
    fprintf(stderr, "Errorrrrrrrr"); // Saves only errors to errors.txt

    return 0;
}