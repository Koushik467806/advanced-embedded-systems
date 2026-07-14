# Bare-Metal C

## Types of Firmware Development

### 1. HAL (Hardware Abstraction Layer)
Offers high-level APIs and is written in a high-level language.

| Property | Details |
|---|---|
| Level of abstraction | High |
| Ease of use | Easier for beginners due to its high-level abstraction |
| Code verbosity | More verbose, with several lines of code required for simple tasks |
| Portability | Excellent across different STM32 devices |
| Performance | Slightly slower due to additional abstraction layers |

---

### 2. LL (Low Layer)
An alternative to HAL that is faster and expert-oriented.

| Property | Details |
|---|---|
| Level of abstraction | Medium |
| Ease of use | Moderate, with a balance between abstraction and direct control |
| Code verbosity | Less verbose than HAL, offering a more straightforward approach to hardware interaction |
| Portability | Good, but slightly less than HAL |
| Performance | Faster than HAL, as it's closer to the hardware |

---

### 3. C (Bare-Metal)
We directly access registers using the C language.

| Property | Details |
|---|---|
| Level of abstraction | Low |
| Ease of use | Challenging for beginners, as it requires in-depth hardware knowledge |
| Code verbosity | Less verbose, direct |
| Portability | Limited, as the code is often specific to a particular hardware setup |
| Performance | Very high, as it allows for direct and optimized hardware manipulation |

---

### 4. Assembly
Similar to bare-metal C, but using assembly language instead.

| Property | Details |
|---|---|
| Level of abstraction | Lowest |
| Ease of use | Most challenging, requiring a thorough understanding of the microcontroller's architecture |
| Code verbosity | Can be verbose for complex tasks due to its low-level nature |
| Portability | Very limited, as it is highly specific to the microcontroller's architecture |
| Performance | Highest, as it allows for the most optimized and direct control possible |

---

## Peripherals

1. **GPIO Ports** — Used to connect to LEDs, switches, sensors, etc.
2. **Communication Interfaces** — UART/USART (Universal Asynchronous Receiver-Transmitter), SPI (Serial Peripheral Interface), I2C (Inter-Integrated Circuit); used to communicate with other devices.
3. **Timers and Counters** — Timers for measuring time intervals; counters for counting pulses/events.
4. **ADCs** — Convert analog signals from sensors to digital values.

---

## Buses

Peripherals are connected to either AHB or APB.

- **AHB (Advanced High-Performance Bus)** — High-speed data transfer.
- **APB (Advanced Peripheral Bus)** — Lower bandwidth, used for devices that do not need high speeds.

---

## Clock Gating

1. It involves turning off the clock signal to certain parts of the microcontroller.
2. It is a power-saving technique.
3. We need to enable clock access to peripherals before using them.

---

## Setting and Clearing Bits

### Setting a Bit — Using OR (`|`) Operation

```c
register |= (1 << bit_position);
```

**Example:** Enable bit 5 of a register.
```c
RCC->AHB1ENR |= (1 << 5);  // Enable clock for GPIOF (bit 5)
```

---

### Clearing a Bit — Using AND (`&`) Operation

```c
register &= ~(1 << bit_position);
```

**Example:** Clear bit 5 of a register.
```c
RCC->AHB1ENR &= ~(1 << 5);  // Disable clock for GPIOF (bit 5)
```

---

## UL Suffix

- **U** — Unsigned: indicates the value is a positive number and cannot be negative.
- **L** — Long: indicates it is a long integer (32/64-bit, depending on the processor).

**Example:**
```c
uint32_t mask = (1UL << 5);  // UL ensures the shift is performed as an unsigned long
```

---

## Use of `volatile unsigned int`

- **`volatile`** — Tells the compiler that the value can change at any time without any action taken by the code. This happens with hardware registers, where values can change due to hardware events.
- Without it, the compiler might optimize the code and certain reads/writes would not work properly.

**Example:**
```c
volatile unsigned int *pReg = (volatile unsigned int *)0x40020C00;
*pReg = 0x01;  // Write to hardware register; volatile prevents compiler from optimizing this away
```
