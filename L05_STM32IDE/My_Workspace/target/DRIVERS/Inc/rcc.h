/*
 * rcc.h
 *
 *  Created on: 20-Sept-2026
 *      Author: def85
 */

#ifndef RCC_H_
#define RCC_H_

#include "stm32f4xx.h"

#define HSI 16000000UL
#define HSE 8000000UL
#define LSI 32000UL
#define LSE 32768UL

/*
 * Source Clocks
 */
#define RCC_SRC_HSI 0
#define RCC_SRC_HSE 1
#define RCC_SRC_PLL 2

/*
 * Reset Values (AHB1)
 */
#define GPIOAReset  0
#define GPIOBReset  1
#define GPIOCReset  2
#define GPIODReset  3
#define GPIOEReset  4
#define GPIOFReset  5
#define GPIOGReset  6
#define GPIOHReset  7
#define GPIOIReset  8
#define CRCReset    12
#define DMA1Reset   21
#define DMA2Reset   22
#define ETHMACReset 25
#define OTGHSReset  29

/*
 * Reset Values (APB1)
 */
#define TIM2Reset   0
#define TIM3Reset   1
#define TIM4Reset   2
#define TIM5Reset   3
#define TIM6Reset   4
#define TIM7Reset   5
#define TIM12Reset  6
#define TIM13Reset  7
#define TIM14Reset  8
#define SPI2Reset   14
#define SPI3Reset   15
#define USART2Reset 17
#define USART3Reset 18
#define USART4Reset 19
#define USART5Reset 20
#define I2C1Reset   21
#define I2C2Reset   22
#define I2C3Reset   23
#define PWRReset    28
#define DACReset    29

/*
 * Reset Values (APB2)
 */
#define TIM1Reset   0
#define TIM8Reset   1
#define USART1Reset 4
#define USART6Reset 5
#define SPI1Reset   12
#define TIM9Reset   16
#define TIM10Reset  17
#define TIM11Reset  18

/*
 * AHB1 Peripheral Clock Enable Macros
 */
#define GPIOA_PCLK_EN()    (RCC->AHB1ENR |= (1U << GPIOAReset))
#define GPIOB_PCLK_EN()    (RCC->AHB1ENR |= (1U << GPIOBReset))
#define GPIOC_PCLK_EN()    (RCC->AHB1ENR |= (1U << GPIOCReset))
#define GPIOD_PCLK_EN()    (RCC->AHB1ENR |= (1U << GPIODReset))
#define GPIOE_PCLK_EN()    (RCC->AHB1ENR |= (1U << GPIOEReset))
#define GPIOF_PCLK_EN()    (RCC->AHB1ENR |= (1U << GPIOFReset))
#define GPIOG_PCLK_EN()    (RCC->AHB1ENR |= (1U << GPIOGReset))
#define GPIOH_PCLK_EN()    (RCC->AHB1ENR |= (1U << GPIOHReset))
#define GPIOI_PCLK_EN()    (RCC->AHB1ENR |= (1U << GPIOIReset))
#define CRC_PCLK_EN()      (RCC->AHB1ENR |= (1U << CRCReset))
#define DMA1_PCLK_EN()     (RCC->AHB1ENR |= (1U << DMA1Reset))
#define DMA2_PCLK_EN()     (RCC->AHB1ENR |= (1U << DMA2Reset))
#define ETHMAC_PCLK_EN()   (RCC->AHB1ENR |= (1U << ETHMACReset))
#define OTGHS_PCLK_EN()    (RCC->AHB1ENR |= (1U << OTGHSReset))

/*
 * APB1 Peripheral Clock Enable Macros
 */
#define TIM2_PCLK_EN()     (RCC->APB1ENR |= (1U << TIM2Reset))
#define TIM3_PCLK_EN()     (RCC->APB1ENR |= (1U << TIM3Reset))
#define TIM4_PCLK_EN()     (RCC->APB1ENR |= (1U << TIM4Reset))
#define TIM5_PCLK_EN()     (RCC->APB1ENR |= (1U << TIM5Reset))
#define TIM6_PCLK_EN()     (RCC->APB1ENR |= (1U << TIM6Reset))
#define TIM7_PCLK_EN()     (RCC->APB1ENR |= (1U << TIM7Reset))
#define TIM12_PCLK_EN()    (RCC->APB1ENR |= (1U << TIM12Reset))
#define TIM13_PCLK_EN()    (RCC->APB1ENR |= (1U << TIM13Reset))
#define TIM14_PCLK_EN()    (RCC->APB1ENR |= (1U << TIM14Reset))
#define SPI2_PCLK_EN()     (RCC->APB1ENR |= (1U << SPI2Reset))
#define SPI3_PCLK_EN()     (RCC->APB1ENR |= (1U << SPI3Reset))
#define USART2_PCLK_EN()   (RCC->APB1ENR |= (1U << USART2Reset))
#define USART3_PCLK_EN()   (RCC->APB1ENR |= (1U << USART3Reset))
#define UART4_PCLK_EN()    (RCC->APB1ENR |= (1U << USART4Reset))
#define UART5_PCLK_EN()    (RCC->APB1ENR |= (1U << USART5Reset))
#define I2C1_PCLK_EN()     (RCC->APB1ENR |= (1U << I2C1Reset))
#define I2C2_PCLK_EN()     (RCC->APB1ENR |= (1U << I2C2Reset))
#define I2C3_PCLK_EN()     (RCC->APB1ENR |= (1U << I2C3Reset))
#define PWR_PCLK_EN()      (RCC->APB1ENR |= (1U << PWRReset))
#define DAC_PCLK_EN()      (RCC->APB1ENR |= (1U << DACReset))

/*
 * APB2 Peripheral Clock Enable Macros
 */
#define TIM1_PCLK_EN()     (RCC->APB2ENR |= (1U << TIM1Reset))
#define TIM8_PCLK_EN()     (RCC->APB2ENR |= (1U << TIM8Reset))
#define USART1_PCLK_EN()   (RCC->APB2ENR |= (1U << USART1Reset))
#define USART6_PCLK_EN()   (RCC->APB2ENR |= (1U << USART6Reset))
#define SPI1_PCLK_EN()     (RCC->APB2ENR |= (1U << SPI1Reset))
#define TIM9_PCLK_EN()     (RCC->APB2ENR |= (1U << TIM9Reset))
#define TIM10_PCLK_EN()    (RCC->APB2ENR |= (1U << TIM10Reset))
#define TIM11_PCLK_EN()    (RCC->APB2ENR |= (1U << TIM11Reset))

/*
 * AHB1 Peripheral Clock Disable Macros
 */
#define GPIOA_PCLK_DI()    (RCC->AHB1ENR &= ~(1U << GPIOAReset))
#define GPIOB_PCLK_DI()    (RCC->AHB1ENR &= ~(1U << GPIOBReset))
#define GPIOC_PCLK_DI()    (RCC->AHB1ENR &= ~(1U << GPIOCReset))
#define GPIOD_PCLK_DI()    (RCC->AHB1ENR &= ~(1U << GPIODReset))
#define GPIOE_PCLK_DI()    (RCC->AHB1ENR &= ~(1U << GPIOEReset))
#define GPIOF_PCLK_DI()    (RCC->AHB1ENR &= ~(1U << GPIOFReset))
#define GPIOG_PCLK_DI()    (RCC->AHB1ENR &= ~(1U << GPIOGReset))
#define GPIOH_PCLK_DI()    (RCC->AHB1ENR &= ~(1U << GPIOHReset))
#define GPIOI_PCLK_DI()    (RCC->AHB1ENR &= ~(1U << GPIOIReset))
#define CRC_PCLK_DI()      (RCC->AHB1ENR &= ~(1U << CRCReset))
#define DMA1_PCLK_DI()     (RCC->AHB1ENR &= ~(1U << DMA1Reset))
#define DMA2_PCLK_DI()     (RCC->AHB1ENR &= ~(1U << DMA2Reset))
#define ETHMAC_PCLK_DI()   (RCC->AHB1ENR &= ~(1U << ETHMACReset))
#define OTGHS_PCLK_DI()    (RCC->AHB1ENR &= ~(1U << OTGHSReset))

/*
 * APB1 Peripheral Clock Disable Macros
 */
#define TIM2_PCLK_DI()     (RCC->APB1ENR &= ~(1U << TIM2Reset))
#define TIM3_PCLK_DI()     (RCC->APB1ENR &= ~(1U << TIM3Reset))
#define TIM4_PCLK_DI()     (RCC->APB1ENR &= ~(1U << TIM4Reset))
#define TIM5_PCLK_DI()     (RCC->APB1ENR &= ~(1U << TIM5Reset))
#define TIM6_PCLK_DI()     (RCC->APB1ENR &= ~(1U << TIM6Reset))
#define TIM7_PCLK_DI()     (RCC->APB1ENR &= ~(1U << TIM7Reset))
#define TIM12_PCLK_DI()    (RCC->APB1ENR &= ~(1U << TIM12Reset))
#define TIM13_PCLK_DI()    (RCC->APB1ENR &= ~(1U << TIM13Reset))
#define TIM14_PCLK_DI()    (RCC->APB1ENR &= ~(1U << TIM14Reset))
#define SPI2_PCLK_DI()     (RCC->APB1ENR &= ~(1U << SPI2Reset))
#define SPI3_PCLK_DI()     (RCC->APB1ENR &= ~(1U << SPI3Reset))
#define USART2_PCLK_DI()   (RCC->APB1ENR &= ~(1U << USART2Reset))
#define USART3_PCLK_DI()   (RCC->APB1ENR &= ~(1U << USART3Reset))
#define UART4_PCLK_DI()    (RCC->APB1ENR &= ~(1U << USART4Reset))
#define UART5_PCLK_DI()    (RCC->APB1ENR &= ~(1U << USART5Reset))
#define I2C1_PCLK_DI()     (RCC->APB1ENR &= ~(1U << I2C1Reset))
#define I2C2_PCLK_DI()     (RCC->APB1ENR &= ~(1U << I2C2Reset))
#define I2C3_PCLK_DI()     (RCC->APB1ENR &= ~(1U << I2C3Reset))
#define PWR_PCLK_DI()      (RCC->APB1ENR &= ~(1U << PWRReset))
#define DAC_PCLK_DI()      (RCC->APB1ENR &= ~(1U << DACReset))

/*
 * APB2 Peripheral Clock Disable Macros
 */
#define TIM1_PCLK_DI()     (RCC->APB2ENR &= ~(1U << TIM1Reset))
#define TIM8_PCLK_DI()     (RCC->APB2ENR &= ~(1U << TIM8Reset))
#define USART1_PCLK_DI()   (RCC->APB2ENR &= ~(1U << USART1Reset))
#define USART6_PCLK_DI()   (RCC->APB2ENR &= ~(1U << USART6Reset))
#define SPI1_PCLK_DI()     (RCC->APB2ENR &= ~(1U << SPI1Reset))
#define TIM9_PCLK_DI()     (RCC->APB2ENR &= ~(1U << TIM9Reset))
#define TIM10_PCLK_DI()    (RCC->APB2ENR &= ~(1U << TIM10Reset))
#define TIM11_PCLK_DI()    (RCC->APB2ENR &= ~(1U << TIM11Reset))

/**
 * @brief  Configures the system clock to a custom target frequency in Hz
 *
 * @param  targetFreq: Desired SYSCLK in Hz
 *
 * @return 0 on success, 1 if requested frequency is out of valid range
 */
uint8_t RCC_SetSysClockFrequency(uint32_t targetFreq);

/*
 * @brief Calculates SYSCLK frequency
 *
 * @return Active SYSCLK frequency
 */
uint32_t RCC_GetSysClockValue(void);

/*
 * @brief Calculates PCLK1 value (APB1)
 *
 * @return PCLK1 clock frequency
 */
uint32_t RCC_GetPCLK1Value(void);

/*
 * @brief Calculates PCLK2 value (APB2)
 *
 * @return PCLK2 clock frequency
 */
uint32_t RCC_GetPCLK2Value(void);

/**
 * @brief  Enables or disables peripheral clock on the AHB1 bus
 *
 * @param  bitPos: Bit offset macro from rcc.h
 * @param  state: 1 to Enable, 0 to Disable
 */
void RCC_AHB1_ClockControl(uint8_t bitPos, uint8_t state);

/**
 * @brief  Enables or disables peripheral clock on the APB1 bus
 *
 * @param  bitPos: Bit offset macro from rcc.h
 * @param  state: 1 to Enable, 0 to Disable
 */
void RCC_APB1_ClockControl(uint8_t bitPos, uint8_t state);

/**
 * @brief  Enables or disables peripheral clock on the APB2 bus
 *
 * @param  bitPos: Bit offset macro from rcc.h
 * @param  state: 1 to Enable, 0 to Disable
 */
void RCC_APB2_ClockControl(uint8_t bitPos, uint8_t state);

#endif /* RCC_H_ */
