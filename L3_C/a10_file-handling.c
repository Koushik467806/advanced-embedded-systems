#include <stdio.h>

// Type FILE
int main(){
    // Open/Create
    FILE *fptr;
    // Opens it if it exsists
    // Else creates a new file
    fptr = fopen("something.txt", "w");
    fclose(fptr);

    // Write
    fptr = fopen("something.txt", "w");
    fprintf(fptr, "some text");
    fclose(fptr);

    // Append
    // Creates new file if it doesnt exsist
    fptr = fopen("something.txt", "a"); // a: append at the end
    fprintf(fptr, "appended something");
    fclose(fptr);

    // Read Mode
    fptr = fopen("something.txt", "r");
    // Storing
    char myContent[100];
    fgets(myContent, 100, fptr);
    printf("%s", myContent);
    fclose(fptr);
}