# CMSIS

## Implementing Peripheral Structures

```c
typedef struct {
    volatile uint32_t MODER;    // 0x00 (8.4.1)  GPIO port mode register
    volatile uint32_t OTYPER;   // 0x04 (8.4.2)  GPIO port output type register
    volatile uint32_t OSPEEDR;  // 0x08 (8.4.3)  GPIO port output speed register
    volatile uint32_t PUPDR;    // 0x0C (8.4.4)  GPIO port pull-up/pull-down register
    volatile uint32_t IDR;      // 0x10 (8.4.5)  GPIO port input data register
    volatile uint32_t ODR;      // 0x14 (8.4.6)  GPIO port output data register
    volatile uint32_t BSRR;     // 0x18 (8.4.7)  GPIO port bit set/reset register
    volatile uint32_t LCKR;     // 0x1C (8.4.8)  GPIO port configuration lock register
    volatile uint32_t AFR[2];   // 0x20-0x24     Alternate function registers
                                // AFR[0] is AFRL (8.4.9)  Low Register  (Pins 0-7)
                                // AFR[1] is AFRH (8.4.10) High Register (Pins 8-15)
} GPIO_TypeDef;
```

```c
typedef struct {
    volatile uint32_t CR;          // 0x00         Clock Control Register
    volatile uint32_t PLLCFGR;     // 0x04         PLL Configuration Register
    volatile uint32_t CFGR;        // 0x08         Clock Configuration Register
    volatile uint32_t CIR;         // 0x0C         Clock Interrupt Register
    volatile uint32_t AHB1RSTR;    // 0x10         AHB1 Peripheral Reset Register
    volatile uint32_t AHB2RSTR;    // 0x14         AHB2 Peripheral Reset Register
    volatile uint32_t AHB3RSTR;    // 0x18         AHB3 Peripheral Reset Register
    uint32_t          RESERVED0;   // 0x1C         Reserved
    volatile uint32_t APB1RSTR;    // 0x20         APB1 Peripheral Reset Register
    volatile uint32_t APB2RSTR;    // 0x24         APB2 Peripheral Reset Register
    uint32_t          RESERVED1[2];// 0x28 - 0x2C  Reserved
    volatile uint32_t AHB1ENR;     // 0x30         AHB1 Peripheral Clock Enable Register
    volatile uint32_t AHB2ENR;     // 0x34         AHB2 Peripheral Clock Enable Register
    volatile uint32_t AHB3ENR;     // 0x38         AHB3 Peripheral Clock Enable Register
    uint32_t          RESERVED2;   // 0x3C         Reserved
    volatile uint32_t APB1ENR;     // 0x40         APB1 Peripheral Clock Enable Register
    volatile uint32_t APB2ENR;     // 0x44         APB2 Peripheral Clock Enable Register
    uint32_t          RESERVED3[2];// 0x48 - 0x4C  Reserved
    volatile uint32_t AHB1LPENR;   // 0x50         AHB1 Peripheral Clock Enable in LP Mode
    volatile uint32_t AHB2LPENR;   // 0x54         AHB2 Peripheral Clock Enable in LP Mode
    volatile uint32_t AHB3LPENR;   // 0x58         AHB3 Peripheral Clock Enable in LP Mode
    uint32_t          RESERVED4;   // 0x5C         Reserved
    volatile uint32_t APB1LPENR;   // 0x60         APB1 Peripheral Clock Enable in LP Mode
    volatile uint32_t APB2LPENR;   // 0x64         APB2 Peripheral Clock Enable in LP Mode
    uint32_t          RESERVED5[2];// 0x68 - 0x6C  Reserved
    volatile uint32_t BDCR;        // 0x70         Backup Domain Control Register
    volatile uint32_t CSR;         // 0x74         Clock Control & Status Register
    uint32_t          RESERVED6[2];// 0x78 - 0x7C  Reserved
    volatile uint32_t SSCGR;       // 0x80         Spread Spectrum Clock Generation Register
    volatile uint32_t PLLI2SCFGR;  // 0x84         PLLI2S Configuration Register
    volatile uint32_t PLLSAICFGR;  // 0x88         PLLSAI Configuration Register
    volatile uint32_t DCKCFGR;     // 0x8C         Dedicated Clock Configuration Register
} RCC_TypeDef;
```

- **`typedef`** — Used to create an alias for the structure.
- **`volatile`** — Indicates every variable can change at any time due to hardware changes.

---

## Creating Pointers for RCC and GPIO Base Addresses

```c
#define RCC_BASE    0x40023800
#define GPIOA_BASE  0x40020000

#define RCC         ((RCC_TypeDef *)  RCC_BASE)
#define GPIOA       ((GPIO_TypeDef *) GPIOA_BASE)
```

---

## What is CMSIS?

CMSIS is a vendor-independent HAL that standardizes software interfaces across various Arm-based platforms.

### Benefits

1. Standardization
2. Portability
3. Efficiency

---

## Core Components

1. **CMSIS-Core** — Provides standardized APIs for configuration of the processor core and peripherals.
   1. It has standard files and device files.
   2. Device files include CMSIS system, clock config, device startup, and interrupt vectors.
   3. Standard files include CMSIS CPU, core access, architecture and feature attributes, instruction access, and peripheral functions.
2. **CMSIS-Driver** — Provides general driver interfaces for middleware.
3. **CMSIS-DSP** — Has a library of over 60 functions optimized for Single Instruction Multiple Data (SIMD) instructions.
4. **CMSIS-NN** — For neural networks.
5. **CMSIS-RTOS** — Provides an API for RTOS (Real-Time Operating Systems).
6. **CMSIS-Pack** — Outlines a delivery system for software components.
7. **CMSIS-SVD** — System Viewer Description files maintained by the silicon vendor.

---

## CMSIS Access Specifiers

CMSIS uses the following qualifiers:

1. `__I` — For read-only variables.
2. `__O` — For write-only variables.
3. `__IO` — For read and write variables.

CMSIS defines data types using the `<stdint.h>` library for consistency.

---

## CMSIS-Core Standard Files

Provided by Arm and typically do not require modifications:

| File | Description |
|---|---|
| `core_<cpu>.h` | Provides access to the CPU and core-specific functionalities |
| `cmsis_compiler.h` | Contains core peripheral functions, CPU instruction access, and SIMD instruction access |
| `<arch>_<feature>.h` | Defines architecture-specific attributes and features |
| `cmsis_<compiler>_m.h` | A toolchain-specific file that aids in compiler compatibility and optimization |

---

## CMSIS-Core Device Files

Provided by silicon vendors (such as STMicroelectronics) and may require application-specific modifications:

| File | Description |
|---|---|
| `system_<Device>.c` | Handles system and clock configuration |
| `partition_<Device>.h` | Manages secure attributes and interrupt assignments |
| `startup_<Device>.c` | Contains the device startup interrupt vectors |
| `<Device>.h` | Provides access to the CMSIS device peripheral functionalities |
| `system_<Device>.h` | Assists in system and clock configuration |
