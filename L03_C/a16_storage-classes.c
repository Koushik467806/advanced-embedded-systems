// 4 main storage classes: auto, static, register, extern

// auto is basically useless and no one uses it

// static changes how a variable behaves
// static globval variables are not visible outside their file
// static local variables keep their value between function calls

// register keyword suggests compiler to put the variable in cpu register for faster access
// Not guaranteed, just a suggestion

// extern says compiler that variable is defined in another file

void count() {
    static int myNum = 0; // Keeps its value between calls
    myNum++;
    printf("num = %d\n", myNum);
}

int main(){
    auto int x = 50; // Same as int x = 50, completely useless

    register int a = 0;

    extern int shared; // Only declared here

    count(); // num = 1, = 1 without static
    count(); // num = 2, = 1 without static
    count(); // num = 3, = 1 without static

    return 0;
}

// Compile a16_storage-classes.c and a16_extern-use.c together