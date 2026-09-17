/*
 * stm32f4xx.h
 *
 *  Created on: 16-Aug-2026
 *      Author: Koushik T
 */

#ifndef INC_STM32F4XX_H_
#define INC_STM32F4XX_H_

#include <stdint.h>

#define __IO volatile // Read/Write
#define __I volatile const // Read only
#define __O volatile // Write only

// Main Base
#define PERIPH_BASE (0x40000000UL)
#define FLASH_BASE  (0x08000000UL)
#define SRAM1_BASE  (0x20000000UL)

// Bus Domains
#define APB1_BASE (PERIPH_BASE)
#define APB2_BASE (PERIPH_BASE + 0x00007800UL)
#define AHB1_BASE (PERIPH_BASE + 0x00020000UL)
#define AHB2_BASE (PERIPH_BASE + 0x00080000UL)
#define AHB3_BASE (PERIPH_BASE + 0x20000000UL)

// Peripheral Base
#define GPIOA_BASE (AHB1_BASE)
#define GPIOB_BASE (AHB1_BASE + 0x00020400UL)
#define GPIOC_BASE (AHB1_BASE + 0x00020800UL)
#define GPIOD_BASE (AHB1_BASE + 0x00020C00UL)
#define GPIOE_BASE (AHB1_BASE + 0x00021000UL)
#define GPIOF_BASE (AHB1_BASE + 0x00021400UL)
#define GPIOG_BASE (AHB1_BASE + 0x00021800UL)
#define GPIOH_BASE (AHB1_BASE + 0x00021C00UL)
#define GPIOI_BASE (AHB1_BASE + 0x00022000UL)
#define RCC_BASE   (AHB1_BASE + 0x00023800UL)

// Peripheral Register
typedef struct{
	__IO uin32_t MODER;
	__IO uin32_t OTYPER;
	__IO uin32_t OSPEEDR;
	__IO uin32_t PUPDR;
	__IO uin32_t IDR;
	__IO uin32_t ODR;
	__IO uin32_t BSRR;
	__IO uin32_t LCKR;
	__IO uin32_t AFR[2];
} GPIO_Typedef;

typedef struct{

} RCC;

#endif /* INC_STM32F4XX_H_ */
