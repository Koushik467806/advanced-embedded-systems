/*
 * stm32f407xx.h
 *
 * Driver Development - Device Header File for STM32F407xx Microcontrollers
 * Board: STM32F407G-DISC1
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>

#define __IO volatile
#define __I  volatile const
#define __O  volatile

/* Port Code */
#define GPIO_BASE_TO_CODE(GPIOx) ( (GPIOx == GPIOA) ? 0 : \
                                   (GPIOx == GPIOB) ? 1 : \
                                   (GPIOx == GPIOC) ? 2 : \
                                   (GPIOx == GPIOD) ? 3 : \
                                   (GPIOx == GPIOE) ? 4 : \
                                   (GPIOx == GPIOF) ? 5 : \
                                   (GPIOx == GPIOG) ? 6 : \
                                   (GPIOx == GPIOH) ? 7 : \
                                   (GPIOx == GPIOI) ? 8 : 0 )


/* ================================================================================= */
/*                           1. Core & Memory Base Addresses                         */
/* ================================================================================= */

#define FLASH_BASE          0x08000000UL
#define SRAM1_BASE          0x20000000UL /* 112 KB Main SRAM */
#define SRAM2_BASE          0x2001C000UL /* 16 KB Aux SRAM */
#define ROM_BASE            0x1FFF0000UL /* System Memory */
#define SRAM_BASE           SRAM1_BASE

#define PERIPH_BASE         0x40000000UL
#define APB1_BASE           PERIPH_BASE
#define APB2_BASE           (PERIPH_BASE + 0x00010000UL)
#define AHB1_BASE           (PERIPH_BASE + 0x00020000UL)
#define AHB2_BASE           (PERIPH_BASE + 0x10000000UL)

/* Core Peripherals */
#define SCS_BASE            (0xE000E000UL)
#define NVIC_BASE           (SCS_BASE + 0x0100UL)
#define PWR_BASE            (APB1_BASE + 0x7000UL)
#define FLASH_R_BASE        (AHB1_BASE + 0x3C00UL)

/* ================================================================================= */
/*                        2. AHB1 & APB Peripheral Bases                             */
/* ================================================================================= */

/* AHB1 Peripherals */
#define GPIOA_BASE          (AHB1_BASE + 0x0000UL)
#define GPIOB_BASE          (AHB1_BASE + 0x0400UL)
#define GPIOC_BASE          (AHB1_BASE + 0x0800UL)
#define GPIOD_BASE          (AHB1_BASE + 0x0C00UL)
#define GPIOE_BASE          (AHB1_BASE + 0x1000UL)
#define GPIOF_BASE          (AHB1_BASE + 0x1400UL)
#define GPIOG_BASE          (AHB1_BASE + 0x1800UL)
#define GPIOH_BASE          (AHB1_BASE + 0x1C00UL)
#define GPIOI_BASE          (AHB1_BASE + 0x2000UL)
#define RCC_BASE            (AHB1_BASE + 0x3800UL)

/* APB1 Peripherals */
#define SPI2_BASE           (APB1_BASE + 0x3800UL)
#define SPI3_BASE           (APB1_BASE + 0x3C00UL)
#define USART2_BASE         (APB1_BASE + 0x4400UL)
#define USART3_BASE         (APB1_BASE + 0x4800UL)
#define I2C1_BASE           (APB1_BASE + 0x5400UL)
#define I2C2_BASE           (APB1_BASE + 0x5800UL)
#define I2C3_BASE           (APB1_BASE + 0x5C00UL)

/* APB2 Peripherals */
#define USART1_BASE         (APB2_BASE + 0x1000UL)
#define USART6_BASE         (APB2_BASE + 0x1400UL)
#define SPI1_BASE           (APB2_BASE + 0x3000UL)
#define SYSCFG_BASE         (APB2_BASE + 0x3800UL)
#define EXTI_BASE           (APB2_BASE + 0x3C00UL)

/* ================================================================================= */
/*                           3. Register Structure Maps                              */
/* ================================================================================= */

typedef struct {
    __IO uint32_t MODER;    /* 0x00 Mode register */
    __IO uint32_t OTYPER;   /* 0x04 Output type register */
    __IO uint32_t OSPEEDR;  /* 0x08 Output speed register */
    __IO uint32_t PUPDR;    /* 0x0C Pull-up/pull-down register */
    __I  uint32_t IDR;      /* 0x10 Input data register */
    __IO uint32_t ODR;      /* 0x14 Output data register */
    __O  uint32_t BSRR;     /* 0x18 Bit set/reset register */
    __IO uint32_t LCKR;     /* 0x1C Lock register */
    __IO uint32_t AFR[2];   /* 0x20-0x24 Alternate function registers [0]=Low, [1]=High */
} GPIO_RegDef_t;

typedef struct {
    __IO uint32_t CR;       /* 0x00 Clock control register */
    __IO uint32_t PLLCFGR;  /* 0x04 PLL configuration register */
    __IO uint32_t CFGR;     /* 0x08 Clock configuration register */
    __IO uint32_t CIR;      /* 0x0C Clock interrupt register */
    __IO uint32_t AHB1RSTR; /* 0x10 AHB1 peripheral reset register */
    __IO uint32_t AHB2RSTR; /* 0x14 AHB2 peripheral reset register */
    __IO uint32_t AHB3RSTR; /* 0x18 AHB3 peripheral reset register */
    uint32_t      RESERVED0;
    __IO uint32_t APB1RSTR; /* 0x20 APB1 peripheral reset register */
    __IO uint32_t APB2RSTR; /* 0x24 APB2 peripheral reset register */
    uint32_t      RESERVED1[2];
    __IO uint32_t AHB1ENR;  /* 0x30 AHB1 peripheral clock enable register */
    __IO uint32_t AHB2ENR;  /* 0x34 AHB2 peripheral clock enable register */
    __IO uint32_t AHB3ENR;  /* 0x38 AHB3 peripheral clock enable register */
    uint32_t      RESERVED2;
    __IO uint32_t APB1ENR;  /* 0x40 APB1 peripheral clock enable register */
    __IO uint32_t APB2ENR;  /* 0x44 APB2 peripheral clock enable register */
    uint32_t      RESERVED3[2];
    __IO uint32_t AHB1LPENR;
    __IO uint32_t AHB2LPENR;
    __IO uint32_t AHB3LPENR;
    uint32_t      RESERVED4;
    __IO uint32_t APB1LPENR;
    __IO uint32_t APB2LPENR;
    uint32_t      RESERVED5[2];
    __IO uint32_t BDCR;
    __IO uint32_t CSR;
    uint32_t      RESERVED6[2];
    __IO uint32_t SSCGR;
    __IO uint32_t PLLI2SCFGR;
} RCC_RegDef_t;

typedef struct {
    __IO uint32_t IMR;   /* 0x00 Interrupt mask register */
    __IO uint32_t EMR;   /* 0x04 Event mask register */
    __IO uint32_t RTSR;  /* 0x08 Rising trigger selection register */
    __IO uint32_t FTSR;  /* 0x0C Falling trigger selection register */
    __IO uint32_t SWIER; /* 0x10 Software interrupt event register */
    __IO uint32_t PR;    /* 0x14 Pending register */
} EXTI_RegDef_t;

typedef struct {
    __IO uint32_t MEMRMP;    /* 0x00 Memory remap register */
    __IO uint32_t PMC;       /* 0x04 Peripheral mode configuration register */
    __IO uint32_t EXTICR[4]; /* 0x08-0x14 EXTI configuration registers */
    uint32_t      RESERVED[2];
    __IO uint32_t CMPCR;     /* 0x20 Compensation cell control register */
} SYSCFG_RegDef_t;


typedef struct {
    __IO uint32_t CR;   /* 0x00: PWR Power Control Register */
    __IO uint32_t CSR;  /* 0x04: PWR Power Control/Status Register */
} PWR_RegDef_t;

typedef struct {
    __IO uint32_t ACR;     /* 0x00: Flash access control register */
    __IO uint32_t KEYR;    /* 0x04: Flash key register */
    __IO uint32_t OPTKEYR; /* 0x08: Flash option key register */
    __IO uint32_t SR;      /* 0x0C: Flash status register */
    __IO uint32_t CR;      /* 0x10: Flash control register */
    __IO uint32_t OPTCR;   /* 0x14: Flash option control register */
} FLASH_RegDef_t;

typedef struct {
    __IO uint32_t ISER[8]; /* 0x000 - 0x01C: Interrupt Set Enable Registers */
    uint32_t      RESERVED0[24];
    __IO uint32_t ICER[8]; /* 0x080 - 0x09C: Interrupt Clear Enable Registers */
    uint32_t      RESERVED1[24];
    __IO uint32_t ISPR[8]; /* 0x100 - 0x11C: Interrupt Set Pending Registers */
    uint32_t      RESERVED2[24];
    __IO uint32_t ICPR[8]; /* 0x180 - 0x19C: Interrupt Clear Pending Registers */
    uint32_t      RESERVED3[24];
    __IO uint32_t IABR[8]; /* 0x200 - 0x21C: Interrupt Active Bit Registers */
    uint32_t      RESERVED4[56];
    __IO uint8_t  IPR[240];/* 0x300 - 0x3EF: Interrupt Priority Registers (Byte Accessible) */
} NVIC_RegDef_t;

/* ================================================================================= */
/*                         4. Peripheral Instance Definitions                        */
/* ================================================================================= */

#define GPIOA               ((GPIO_RegDef_t *) GPIOA_BASE)
#define GPIOB               ((GPIO_RegDef_t *) GPIOB_BASE)
#define GPIOC               ((GPIO_RegDef_t *) GPIOC_BASE)
#define GPIOD               ((GPIO_RegDef_t *) GPIOD_BASE)
#define GPIOE               ((GPIO_RegDef_t *) GPIOE_BASE)
#define GPIOF               ((GPIO_RegDef_t *) GPIOF_BASE)
#define GPIOG               ((GPIO_RegDef_t *) GPIOG_BASE)
#define GPIOH               ((GPIO_RegDef_t *) GPIOH_BASE)
#define GPIOI               ((GPIO_RegDef_t *) GPIOI_BASE)

#define RCC                 ((RCC_RegDef_t *)  RCC_BASE)
#define EXTI                ((EXTI_RegDef_t *) EXTI_BASE)
#define SYSCFG              ((SYSCFG_RegDef_t *) SYSCFG_BASE)
#define PWR                 ((PWR_RegDef_t *) PWR_BASE)
#define FLASH               ((FLASH_RegDef_t *) FLASH_R_BASE)
#define NVIC                ((NVIC_RegDef_t *) NVIC_BASE)

/* ================================================================================= */
/*                     5. Clock Enable / Disable Macros                              */
/* ================================================================================= */

/* Clock Enable Macros for GPIO Peripherals */
#define GPIOA_PCLK_EN()     (RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()     (RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()     (RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()     (RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()     (RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN()     (RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN()     (RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN()     (RCC->AHB1ENR |= (1 << 7))
#define GPIOI_PCLK_EN()     (RCC->AHB1ENR |= (1 << 8))

/* Clock Enable Macros for System Config */
#define SYSCFG_PCLK_EN()    (RCC->APB2ENR |= (1 << 14))

/* Generic Utilities */
#define ENABLE              1
#define DISABLE             0
#define SET                 ENABLE
#define RESET               DISABLE
#define GPIO_PIN_SET        SET
#define GPIO_PIN_RESET      RESET

/* ================================================================================= */
/*                     6. Clock Disable & Reset Macros                               */
/* ================================================================================= */

/* Clock Disable Macros for GPIO Peripherals */
#define GPIOA_PCLK_DI()     (RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()     (RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()     (RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()     (RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()     (RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_PCLK_DI()     (RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DI()     (RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_PCLK_DI()     (RCC->AHB1ENR &= ~(1 << 7))
#define GPIOI_PCLK_DI()     (RCC->AHB1ENR &= ~(1 << 8))

/* GPIO Peripheral Reset Macros (Toggle set/reset bits) */
#define GPIOA_REG_RESET()   do { (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); } while(0)
#define GPIOB_REG_RESET()   do { (RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1)); } while(0)
#define GPIOC_REG_RESET()   do { (RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2)); } while(0)
#define GPIOD_REG_RESET()   do { (RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3)); } while(0)
#define GPIOE_REG_RESET()   do { (RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4)); } while(0)
#define GPIOF_REG_RESET()   do { (RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5)); } while(0)
#define GPIOG_REG_RESET()   do { (RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR &= ~(1 << 6)); } while(0)
#define GPIOH_REG_RESET()   do { (RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7)); } while(0)
#define GPIOI_REG_RESET()   do { (RCC->AHB1RSTR |= (1 << 8)); (RCC->AHB1RSTR &= ~(1 << 8)); } while(0)

/* ================================================================================= */
/*                     7. IRQ (Interrupt) Numbers for STM32F407                      */
/* ================================================================================= */

#define IRQ_NO_EXTI0        6
#define IRQ_NO_EXTI1        7
#define IRQ_NO_EXTI2        8
#define IRQ_NO_EXTI3        9
#define IRQ_NO_EXTI4        10
#define IRQ_NO_EXTI9_5      23
#define IRQ_NO_EXTI15_10    40

#endif /* INC_STM32F407XX_H_ */
