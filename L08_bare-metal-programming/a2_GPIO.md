# GPIO

GPIO is divided into GPIOA, GPIOB, GPIOC, ... GPIOJ.

Pins are referred to by port name followed by pin number.

**Example:**
- `PA1` — Port A, Pin 1
- `PD7` — Port D, Pin 7

---

## Features

1. **I/O Control** — Can manage up to 16 input/output pins per port.
2. **Output States** — Pins can be configured for push-pull or open-drain modes.
3. **Output Data** — Driven by the ODR register.
4. **Speed** — Operating speed can be set for each individual pin.
5. **Input States** — Configured as floating, pull-up, pull-down, or analog inputs.
6. **Configuration Locking** — LCKR can be used to lock configurations.
7. **Alternate Function** — Up to 16 alternate functions per pin can be configured.

---

## GPIO Registers

### 1. `GPIOx_MODER`

Used to configure the mode of each pin. It is a 32-bit register where each pair of bits corresponds to one pin.

**4 Modes:**

| Bits | Mode | Description |
|---|---|---|
| `00` | Input | Read signals from an external device |
| `01` | GP Output | Output; used to drive signals or LEDs |
| `10` | Alternate Function | Allows interfacing with peripherals (UART, SPI, etc.) |
| `11` | Analog | Analog input |

**Example:** Configure PA5 as a general-purpose output.
```c
GPIOA->MODER &= ~(0x3 << (5 * 2));   // Clear bits for pin 5
GPIOA->MODER |=  (0x1 << (5 * 2));   // Set pin 5 to GP Output mode (01)
```

---

### 2. `GPIOx_ODR` and `GPIOx_IDR`

These are used for reading/setting the state of pins to interact with external devices.

Both are 32-bit registers, but only the lower 16 bits are used — each bit corresponds to one pin in the GPIO port.

- **`GPIOx_IDR`** (Input Data Register) — Used to read the current state of the GPIO pins.
- **`GPIOx_ODR`** (Output Data Register) — Written to in order to set the logic level (high or low) of each output pin.

A bit value of `1` indicates the corresponding pin is at a high logic level; a bit value of `0` indicates it is at a low logic level.

**Example:** Set PA5 high and read the state of PA0.
```c
GPIOA->ODR |= (1 << 5);              // Set PA5 high
uint32_t state = GPIOA->IDR & (1 << 0); // Read state of PA0
```

---

### 3. `GPIOx_BSRR`

Used to set pins to high or low atomically.

- Writing `1` to bits **31:16** sets the corresponding pins **low**.
- Writing `1` to bits **15:0** sets the corresponding pins **high**.

BSRR is atomic and completes in a single step, whereas setting/clearing bits through ODR takes 3 steps (read, modify, write).

**Example:** Set PA5 high and clear (set low) PA5 using BSRR.
```c
GPIOA->BSRR = (1 << 5);             // Set PA5 high (bit 5)
GPIOA->BSRR = (1 << (5 + 16));      // Set PA5 low  (bit 21)
```

---

### 4. `GPIOx_AFRL` and `GPIOx_AFRH`

- **AFRL** — Configures alternate functions for pins 0–7.
- **AFRH** — Configures alternate functions for pins 8–15.

Each pin uses 4 bits since it can have up to 16 alternate functions.

**Example:** Configure PA2 for AF7 (USART2 TX).
```c
GPIOA->AFR[0] &= ~(0xF << (2 * 4)); // Clear AF bits for pin 2
GPIOA->AFR[0] |=  (0x7 << (2 * 4)); // Set AF7 for pin 2
```

---

### 5. `GPIOx_OTYPER`

Controls the output type of each pin.

| Bit Value | Push-Pull Mode | Open-Drain Mode |
|---|---|---|
| `0` | Pulls current from the circuit | GND |
| `1` | Pushes current to the circuit | Floating (disconnected) |

**Example:** Configure PA5 as open-drain.
```c
GPIOA->OTYPER |= (1 << 5);          // Set PA5 to open-drain
```

---

### 6. `GPIOx_OSPEEDR`

Uses 2 bits per pin to set the output speed.

| Bits | Speed |
|---|---|
| `00` | Low speed |
| `01` | Medium speed |
| `10` | High speed |
| `11` | Very high speed |

**Example:** Set PA5 to very high speed.
```c
GPIOA->OSPEEDR |= (0x3 << (5 * 2)); // Set PA5 to very high speed (11)
```

---

### 7. `GPIOx_PUPDR`

Sets the pull-up/pull-down configuration for each pin.

| Bits | Configuration |
|---|---|
| `00` | Floating (none) |
| `01` | Pull-up (resistor connected to Vdd) |
| `10` | Pull-down (resistor connected to GND) |

**Example:** Configure PA0 with a pull-up resistor.
```c
GPIOA->PUPDR &= ~(0x3 << (0 * 2));  // Clear bits for pin 0
GPIOA->PUPDR |=  (0x1 << (0 * 2));  // Set pull-up for pin 0 (01)
```

---

### 8. `GPIOx_LCKR`

Used to lock the configuration of GPIO pins so that any attempts to write new values are ignored by hardware.

Locking allows reading `IDR` and toggling `ODR`, but prevents changes to mode, speed, or pull-up/pull-down settings.

**Example:** Lock the configuration of PA5.
```c
uint32_t tmp = (1 << 16) | (1 << 5); // Set LCKK bit and pin 5
GPIOA->LCKR = tmp;                   // Write LCKK=1, LCK5=1
GPIOA->LCKR = (1 << 5);             // Write LCKK=0, LCK5=1
GPIOA->LCKR = tmp;                   // Write LCKK=1, LCK5=1
tmp = GPIOA->LCKR;                   // Read to confirm lock
```
