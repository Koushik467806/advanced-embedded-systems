/*
 * stm32f407xx.h
 *
 *  Created on: 13-Jul-2026
 *      Author: def85
 */

#ifndef STM32F407XX_H_
#define STM32F407XX_H_

#include <stdint.h>

/* Register Structure Definition */
typedef struct {
    volatile uint32_t CR;         // 0x00 Clock Control Register
    volatile uint32_t PLLCFGR;    // 0x04 PLL Configuration Register
    volatile uint32_t CFGR;       // 0x08 Clock Configuration Register
    volatile uint32_t CIR;        // 0x0C Clock Interrupt Register
    volatile uint32_t AHB1RSTR;   // 0x10 AHB1 Peripheral Reset Register
    volatile uint32_t AHB2RSTR;   // 0x14 AHB2 Peripheral Reset Register
    volatile uint32_t AHB3RSTR;   // 0x18 AHB3 Peripheral Reset Register
    uint32_t RESERVED0;           // 0x1C Reserved
    volatile uint32_t APB1RSTR;   // 0x20 APB1 Peripheral Reset Register
    volatile uint32_t APB2RSTR;   // 0x24 APB2 Peripheral Reset Register
    uint32_t RESERVED1[2];        // 0x28 - 0x2C Reserved
    volatile uint32_t AHB1ENR;    // 0x30 AHB1 Peripheral Clock Enable Register
    volatile uint32_t AHB2ENR;    // 0x34 AHB2 Peripheral Clock Enable Register
    volatile uint32_t AHB3ENR;    // 0x38 AHB3 Peripheral Clock Enable Register
    uint32_t RESERVED2;           // 0x3C Reserved
    volatile uint32_t APB1ENR;    // 0x40 APB1 Peripheral Clock Enable Register
    volatile uint32_t APB2ENR;    // 0x44 APB2 Peripheral Clock Enable Register
    uint32_t RESERVED3[2];        // 0x48 - 0x4C Reserved
    volatile uint32_t AHB1LPENR;  // 0x50 AHB1 Peripheral Clock Enable in LP Mode
    volatile uint32_t AHB2LPENR;  // 0x54 AHB2 Peripheral Clock Enable in LP Mode
    volatile uint32_t AHB3LPENR;  // 0x58 AHB3 Peripheral Clock Enable in LP Mode
    uint32_t RESERVED4;           // 0x5C Reserved
    volatile uint32_t APB1LPENR;  // 0x60 APB1 Peripheral Clock Enable in LP Mode
    volatile uint32_t APB2LPENR;  // 0x64 APB2 Peripheral Clock Enabled in LP Mode
    uint32_t RESERVED5[2];        // 0x68 - 0x6C Reserved
    volatile uint32_t BDCR;       // 0x70 Backup Domain Control Register
    volatile uint32_t CSR;        // 0x74 Clock Control & Status Register
    uint32_t RESERVED6[2];        // 0x78 - 0x7C Reserved
    volatile uint32_t SSCGR;      // 0x80 Spread Spectrum Clock Generation Register
    volatile uint32_t PLLI2SCFGR; // 0x84 PLLI2S Configuration Register
} RCC_TypeDef;

/* Base Memory Address for STM32F407 RCC */
#define PERIPH_BASE         ((uint32_t)0x40000000)
#define AHB1PERIPH_BASE     (PERIPH_BASE + 0x00020000)
#define RCC_BASE            (AHB1PERIPH_BASE + 0x3800) // 0x40023800

/* Peripheral Instance Macro */
#define RCC                 ((RCC_TypeDef *) RCC_BASE)

/**
 * @brief General Purpose I/O (GPIO) Peripheral Register Structure
 * Based on Reference Manual Sections 8.4.1 to 8.4.10
 */
typedef struct {
    volatile uint32_t MODER;   // 0x00 (8.4.1)  GPIO port mode register
    volatile uint32_t OTYPER;  // 0x04 (8.4.2)  GPIO port output type register
    volatile uint32_t OSPEEDR; // 0x08 (8.4.3)  GPIO port output speed register
    volatile uint32_t PUPDR;   // 0x0C (8.4.4)  GPIO port pull-up/pull-down register
    volatile uint32_t IDR;     // 0x10 (8.4.5)  GPIO port input data register
    volatile uint32_t ODR;     // 0x14 (8.4.6)  GPIO port output data register
    volatile uint32_t BSRR;    // 0x18 (8.4.7)  GPIO port bit set/reset register
    volatile uint32_t LCKR;    // 0x1C (8.4.8)  GPIO port configuration lock register
    volatile uint32_t AFR[2];  // 0x20-0x24     Alternate function registers
                               // AFR[0] is AFRL (8.4.9)  Low Register (Pins 0-7)
                               // AFR[1] is AFRH (8.4.10) High Register (Pins 8-15)
} GPIO_TypeDef;

/* GPIO Peripheral Base Addresses */
#define GPIOA_BASE          (AHB1PERIPH_BASE + 0x0000) // 0x40020000
#define GPIOB_BASE          (AHB1PERIPH_BASE + 0x0400) // 0x40020400
#define GPIOC_BASE          (AHB1PERIPH_BASE + 0x0800) // 0x40020800
#define GPIOD_BASE          (AHB1PERIPH_BASE + 0x0C00) // 0x40020C00
#define GPIOE_BASE          (AHB1PERIPH_BASE + 0x1000) // 0x40021000
#define GPIOF_BASE          (AHB1PERIPH_BASE + 0x1400) // 0x40021400
#define GPIOG_BASE          (AHB1PERIPH_BASE + 0x1800) // 0x40021800
#define GPIOH_BASE          (AHB1PERIPH_BASE + 0x1C00) // 0x40021C00
#define GPIOI_BASE          (AHB1PERIPH_BASE + 0x2000) // 0x40022000
#define GPIOJ_BASE          (AHB1PERIPH_BASE + 0x2400) // 0x40022400
#define GPIOK_BASE          (AHB1PERIPH_BASE + 0x2800) // 0x40022800

/* Peripheral Instance Macros */
#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF               ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG               ((GPIO_TypeDef *) GPIOG_BASE)
#define GPIOH               ((GPIO_TypeDef *) GPIOH_BASE)
#define GPIOI               ((GPIO_TypeDef *) GPIOI_BASE)
#define GPIOJ               ((GPIO_TypeDef *) GPIOJ_BASE)
#define GPIOK               ((GPIO_TypeDef *) GPIOK_BASE)

/**
 * @brief Universal Synchronous Asynchronous Receiver Transmitter (USART)
 * Peripheral Register Structure based on Reference Manual Sections 30.6.1 to 30.6.7
 */
typedef struct {
    volatile uint32_t SR;   // 0x00 (30.6.1) Status register
    volatile uint32_t DR;   // 0x04 (30.6.2) Data register
    volatile uint32_t BRR;  // 0x08 (30.6.3) Baud rate register
    volatile uint32_t CR1;  // 0x0C (30.6.4) Control register 1
    volatile uint32_t CR2;  // 0x10 (30.6.5) Control register 2
    volatile uint32_t CR3;  // 0x14 (30.6.6) Control register 3
    volatile uint32_t GTPR; // 0x18 (30.6.7) Guard time and prescaler register
} USART_TypeDef;

/* USART Peripheral Base Addresses */
#define APB1PERIPH_BASE     (PERIPH_BASE + 0x00000000)
#define APB2PERIPH_BASE     (PERIPH_BASE + 0x00010000)

#define USART2_BASE         (APB1PERIPH_BASE + 0x4400) // 0x40004400
#define USART1_BASE         (APB2PERIPH_BASE + 0x3800) // 0x40013800

/* Peripheral Instance Macros */
#define USART2              ((USART_TypeDef *) USART2_BASE)
#define USART1              ((USART_TypeDef *) USART1_BASE)

#endif /* STM32F407XX_H_ */
