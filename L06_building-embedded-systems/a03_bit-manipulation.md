# Bit Manipulation

## 1. Setting a Bit
To set a specific bit to 1, use the OR operator with a bitmask.

```c
int n = 0b1010;
int bit = 1;
n = n | (1 << bit);
```

---

## 2. Clearing a Bit
To clear a specific bit to 0, use the AND operator with a bitmask.

```c
int n = 0b1111;
int bit = 2;
n = n & ~(1 << bit);
```

---

## 3. Toggling a Bit
To toggle a specific bit, use the XOR operator with a bitmask.

```c
int n = 0b1010;
int bit = 1;
n = n ^ (1 << bit);
```

---

## 4. Odd/Even
You can use the AND operator to check the least significant bit (LSB) to determine if a number is even or odd.

```c
int n = 7;
if (n & 1)
    printf("Odd");
else
    printf("Even");
```

---

## 5. Swapping
You can swap two numbers without using a temporary variable by using XOR.

```c
int a = 5, b = 9;
a = a ^ b;
b = a ^ b;
a = a ^ b;
```

---

## 6. Multiply/Divide
You can use left and right shift operators to multiply and divide by powers of two.

```c
int n = 4;
int multiplied = n << 1;
int divided = n >> 1;
```

---

## 7. Check k-th Bit
Evaluates if a specific bit is active.

```c
int n = 0b1010;
int k = 1;
int bit = (n >> k) & 1;
```
