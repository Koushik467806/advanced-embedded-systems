# `scanf` and `printf` — Output Buffering

## Overview

In general, C sends strings to the screen only if the current buffer is full or it sees a `\n` (newline character).

---

## Flushing with `fflush()`

To make sure every `printf()` is immediately displayed, use:

```c
fflush(stdout);
```

This manually flushes the output buffer to the screen.

---

## Disabling Buffering with `setvbuf()`

You can also completely turn off buffering at the start of your program:

```c
setvbuf(stdout, NULL, _IONBF, 0);
```

### Example — Using `setvbuf()`

```c
int main() {
    setvbuf(stdout, NULL, _IONBF, 0);

    int num1;
    printf("Enter the value of num1: ");
    scanf("%d", &num1);

    printf("Value of num1: %d", num1);
    return 0;
}
```

---

## Example — Using `fflush()` with Multiple Inputs

```c
int main() {
    float num1, num2, num3;
    float avg;

    printf("First number: ");
    fflush(stdout);
    scanf("%f", &num1);

    printf("Second number: ");
    fflush(stdout);
    scanf("%f", &num2);

    printf("Third number: ");
    fflush(stdout);
    scanf("%f", &num3);

    avg = (num1 + num2 + num3) / 4;
    printf("Average is: %f", avg);
    fflush(stdout);

    return 0;
}
```
