# Timers

- Count clock pulses
- Used to measure time intervals, generate precise delays, or trigger events at specific intervals

---

## Timer Types

| Timer | Instances | Type |
|-------|-----------|------|
| TIM1, TIM8 | 2 | Advanced-control timers |
| TIM2, TIM3, TIM4, TIM5, TIM9–TIM14 | 8 | General-purpose timers |
| TIM6, TIM7 | 2 | Basic timers |

---

## Basic Timer

- 16-bit auto-reload up-counter
- 16-bit programmable prescaler used to divide (also "on the fly") the counter clock frequency by any factor between 1 and 65536
- Synchronization circuit to trigger the DAC
- Interrupt/DMA generation on the update event: counter overflow

---

## General-Purpose Timer

- 16-bit (TIM3 and TIM4) or 32-bit (TIM2 and TIM5) up, down, up/down auto-reload counter
- 16-bit programmable prescaler used to divide (also "on the fly") the counter clock frequency by any factor between 1 and 65536
- Up to four independent channels for:
  - Input capture
  - Output compare
  - PWM generation (edge- and center-aligned modes)
  - One-pulse mode output
- Synchronization circuit to control the timer with external signals and to interconnect several timers
- Interrupt/DMA generation on the following events:
  - Update: counter overflow/underflow, counter initialization (by software or internal/external trigger)
  - Trigger event (counter start, stop, initialization, or count by internal/external trigger)
  - Input capture
  - Output compare
- Supports incremental (quadrature) encoder and hall-sensor circuitry for positioning purposes
- Trigger input for external clock or cycle-by-cycle current management

---

## Advanced Timer

- 16-bit up, down, up/down auto-reload counter
- 16-bit programmable prescaler allowing dividing (also "on the fly") the counter clock frequency by any factor between 1 and 65536
- Up to 4 independent channels for:
  - Input capture
  - Output compare
  - PWM generation (edge- and center-aligned modes)
  - One-pulse mode output
- Complementary outputs with programmable dead-time
- Synchronization circuit to control the timer with external signals and to interconnect several timers together
- Repetition counter to update the timer registers only after a given number of cycles of the counter
- Break input to put the timer's output signals in reset state or in a known state
- Interrupt/DMA generation on the following events:
  - Update: counter overflow/underflow, counter initialization (by software or internal/external trigger)
  - Trigger event (counter start, stop, initialization, or count by internal/external trigger)
  - Input capture
  - Output compare
  - Break input
- Supports incremental (quadrature) encoder and hall-sensor circuitry for positioning purposes
- Trigger input for external clock or cycle-by-cycle current management

---

## Registers

### 1. Counter Register (TIMx_CNT)

- Holds the current counter value as it increments or decrements
- Can be written to at any time (unlike the SysTick counter)

```c
// Read current counter value
uint32_t count = TIM2->CNT;

// Reset counter manually
TIM2->CNT = 0;
```

---

### 2. Timer Prescaler (TIMx_PSC)

- Divides the counter clock, giving control over the counting rate
- Division factor ranges from 1 to 65535 (register value + 1)

```c
// Divide a 16 MHz clock by 16 → 1 MHz counter clock
// PSC value = divisor - 1
TIM2->PSC = 16 - 1;  // PSC = 15
```

---

### 3. Auto-Reload Register (TIMx_ARR)

- Sets the period of the counter (the value at which the counter resets)

```c
// Set period to 1000 counts
TIM2->ARR = 1000 - 1;  // ARR = 999
```

---

### 4. Status Register (TIMx_SR)

- Read-only flags that reflect the current state of the timer
- Flags must be **cleared manually** (write `0`) after handling, otherwise the interrupt fires repeatedly

| Bit | Name | Description |
|-----|------|-------------|
| 0 | UIF | Update Interrupt Flag — set when a UEV occurs (counter overflow/underflow) |
| 1 | CC1IF | Capture/Compare 1 Interrupt Flag |
| 2 | CC2IF | Capture/Compare 2 Interrupt Flag |
| 3 | CC3IF | Capture/Compare 3 Interrupt Flag |
| 4 | CC4IF | Capture/Compare 4 Interrupt Flag |
| 6 | TIF | Trigger Interrupt Flag — set when a trigger event occurs |
| 7 | BIF | Break Interrupt Flag — set when a break input event occurs (advanced timers only) |
| 9 | CC1OF | Capture/Compare 1 Overcapture Flag |
| 10 | CC2OF | Capture/Compare 2 Overcapture Flag |
| 11 | CC3OF | Capture/Compare 3 Overcapture Flag |
| 12 | CC4OF | Capture/Compare 4 Overcapture Flag |

```c
// Check if a UEV (update event) has occurred
if (TIM2->SR & (1 << 0)) {       // UIF set?
    // handle the update event
    TIM2->SR &= ~(1 << 0);       // clear UIF flag
}

// Check if Capture/Compare channel 1 fired
if (TIM2->SR & (1 << 1)) {       // CC1IF set?
    // handle capture/compare event
    TIM2->SR &= ~(1 << 1);       // clear CC1IF flag
}
```

---

## Update Event (UEV)

- A UEV occurs when the timer counter reaches the value in TIMx_ARR in up-counting mode

**Update Event Frequency formula:**

```
                      Timer Clock
f_UEV  =  ------------------------------------
           (Prescaler + 1) x (Period + 1)
```

| Term | Register |
|------|----------|
| Timer Clock | Clock frequency supplied to the timer |
| Prescaler | Value in TIMx_PSC |
| Period | Value in TIMx_ARR |

**Example — calculate UEV frequency:**

```c
// Timer Clock = 16 MHz, PSC = 15, ARR = 999
// f_UEV = 16,000,000 / (15 + 1) × (999 + 1)
//       = 16,000,000 / 16 × 1000
//       = 16,000,000 / 16,000
//       = 1000 Hz  →  UEV fires every 1 ms

TIM2->PSC = 15;    // divide 16 MHz by 16 → 1 MHz
TIM2->ARR = 999;   // count 0..999 → 1000 ticks at 1 MHz = 1 ms
```
