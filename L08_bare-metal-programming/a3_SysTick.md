# System Tick Timer

- Used for task scheduling, system monitoring, and time tracking

---

## Registers

### 1. STK_CTRL

- Controls the timer's operation and provides status information

| Bit | Name | Description |
|-----|------|-------------|
| 0 | ENABLE | Enables or disables the SysTick counter |
| 1 | TICKINT | Enables or disables the SysTick interrupt |
| 2 | CLKSOURCE | Selects the clock source (`0` = external reference clock, `1` = processor clock) |
| 16 | COUNTFLAG | Indicates whether the counter has reached zero since the last read (`1` = yes, `0` = no) |

```c
// Enable SysTick with processor clock and interrupt enabled
STK_CTRL |= (1 << 0);  // ENABLE     - start the counter
STK_CTRL |= (1 << 1);  // TICKINT    - trigger interrupt on reaching zero
STK_CTRL |= (1 << 2);  // CLKSOURCE  - use processor clock

// Check if counter has reached zero
if (STK_CTRL & (1 << 16)) {
    // COUNTFLAG is set — counter wrapped around
}
```

---

### 2. STK_LOAD

- Specifies the start value to load
- 24-bit timer: `0x00000001` to `0x00FFFFFF`

**Example — triggering every k seconds:**

- Clock cycles = (core frequency) × k
- RELOAD = Clock cycles − 1

```c
// Trigger every 1 second with a 16 MHz core clock
#define CORE_FREQ_HZ  16000000UL
#define INTERVAL_S    1

uint32_t clock_cycles = CORE_FREQ_HZ * INTERVAL_S;  // = 16,000,000
STK_LOAD = clock_cycles - 1;                         // RELOAD = 15,999,999
```

---

### 3. STK_VAL

- Holds the current value of the SysTick counter
- Bits [23:0] hold the current value; remaining bits are reserved

```c
// Read the current SysTick counter value
uint32_t current_count = STK_VAL & 0x00FFFFFF;  // mask bits [23:0]
```

---

## Full Example — Enable SysTick at 1 ms Interval

```c
// Register base addresses (ARM Cortex-M)
#define SysTick_BASE  0xE000E010UL
#define STK_CTRL      (*(volatile uint32_t *)(SysTick_BASE + 0x00))
#define STK_LOAD      (*(volatile uint32_t *)(SysTick_BASE + 0x04))
#define STK_VAL       (*(volatile uint32_t *)(SysTick_BASE + 0x08))

#define CORE_FREQ_HZ  16000000UL   // 16 MHz

void SysTick_Init_1ms(void) {
    STK_LOAD = (CORE_FREQ_HZ / 1000) - 1;  // RELOAD for 1 ms = 15,999
    STK_VAL  = 0;                           // clear current value
    STK_CTRL = (1 << 2)                     // CLKSOURCE = processor clock
             | (1 << 1)                     // TICKINT   = enable interrupt
             | (1 << 0);                    // ENABLE    = start counter
}

// SysTick interrupt handler — called every 1 ms
void SysTick_Handler(void) {
    // place periodic task here
}
```
