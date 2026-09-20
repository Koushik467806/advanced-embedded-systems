/*
 * gpio.c
 *
 *  Created on: 20-Sept-2026
 *      Author: def85
 */

#include "gpio.h"

void GPIO_ClockControl(GPIO_RegDef_t *GPIOx, uint8_t ED) {
    if (ED == 1) {
        if (GPIOx == GPIOA)      GPIOA_PCLK_EN();
        else if (GPIOx == GPIOB) GPIOB_PCLK_EN();
        else if (GPIOx == GPIOC) GPIOC_PCLK_EN();
        else if (GPIOx == GPIOD) GPIOD_PCLK_EN();
        else if (GPIOx == GPIOE) GPIOE_PCLK_EN();
        else if (GPIOx == GPIOF) GPIOF_PCLK_EN();
        else if (GPIOx == GPIOG) GPIOG_PCLK_EN();
        else if (GPIOx == GPIOH) GPIOH_PCLK_EN();
        else if (GPIOx == GPIOI) GPIOI_PCLK_EN();
    } else {
        if (GPIOx == GPIOA)      GPIOA_PCLK_DI();
        else if (GPIOx == GPIOB) GPIOB_PCLK_DI();
        else if (GPIOx == GPIOC) GPIOC_PCLK_DI();
        else if (GPIOx == GPIOD) GPIOD_PCLK_DI();
        else if (GPIOx == GPIOE) GPIOE_PCLK_DI();
        else if (GPIOx == GPIOF) GPIOF_PCLK_DI();
        else if (GPIOx == GPIOG) GPIOG_PCLK_DI();
        else if (GPIOx == GPIOH) GPIOH_PCLK_DI();
        else if (GPIOx == GPIOI) GPIOI_PCLK_DI();
    }
}

void GPIO_Init(GPIO_Handle_t *GPIOHandle){
	uint32_t temp = 0;

	// 1. Enable Clock
	GPIO_ClockControl(GPIOHandle->GPIOx, 1);

	// 2. Configure Pin Mode
	temp = (GPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * GPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	GPIOHandle->GPIOx->MODER &= ~(0b11UL << (2 * GPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); // Clear
	GPIOHandle->GPIOx->MODER |= temp; // Set

	// 3. Configure Pin Speed
	temp = (GPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * GPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	GPIOHandle->GPIOx->OSPEEDR &= ~(0b11UL << (2 * GPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); // Clear
	GPIOHandle->GPIOx->OSPEEDR |= temp; // Set

	// 4. Pull-Up or Pull-Down
	temp = (GPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * GPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	GPIOHandle->GPIOx->PUPDR &= ~(0b11UL << (2 * GPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); // Clear
	GPIOHandle->GPIOx->PUPDR |= temp; // Set

	// 5. Set Output Type (PP or OD)
	temp = (GPIOHandle->GPIO_PinConfig.GPIO_PinOPType << GPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	GPIOHandle->GPIOx->OTYPER &= ~(0b1UL << GPIOHandle->GPIO_PinConfig.GPIO_PinNumber); // Clear
	GPIOHandle->GPIOx->OTYPER |= temp;

	// 6. Set ALF Mode
	if (GPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_AF_MODE) {
	        uint8_t temp1 = GPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8; // Array index (0 or 1)
	        uint8_t temp2 = GPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8; // Bit shift multiplier (0 to 7)

	        GPIOHandle->GPIOx->AFR[temp1] &= ~(0xF << (4 * temp2));
	        GPIOHandle->GPIOx->AFR[temp1] |= (GPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2));
	    }
}

void GPIO_DeInit(GPIO_RegDef_t *GPIOx) {
    if (GPIOx == GPIOA)      GPIOA_REG_RESET();
    else if (GPIOx == GPIOB) GPIOB_REG_RESET();
    else if (GPIOx == GPIOC) GPIOC_REG_RESET();
    else if (GPIOx == GPIOD) GPIOD_REG_RESET();
    else if (GPIOx == GPIOE) GPIOE_REG_RESET();
    else if (GPIOx == GPIOF) GPIOF_REG_RESET();
    else if (GPIOx == GPIOG) GPIOG_REG_RESET();
    else if (GPIOx == GPIOH) GPIOH_REG_RESET();
    else if (GPIOx == GPIOI) GPIOI_REG_RESET();
}

uint8_t GPIO_ReadPin(GPIO_RegDef_t *GPIOx, uint8_t PinNum) {
    uint8_t value;

    value = (uint8_t)((GPIOx->IDR >> PinNum) & 0b1UL);
    return value;
}

uint16_t GPIO_ReadPort(GPIO_RegDef_t *GPIOx) {
    return (uint16_t)GPIOx->IDR;
}

void GPIO_WritePin(GPIO_RegDef_t *GPIOx, uint8_t PinNum, uint8_t value) {
    if (value == 1) {
        GPIOx->ODR |= (1 << PinNum);  // Set
    } else {
        GPIOx->ODR &= ~(1 << PinNum); // Clear
    }
}

void GPIO_WritePort(GPIO_RegDef_t *GPIOx, uint16_t value) {
    GPIOx->ODR = value;
}

void GPIO_ToggleOutputPin(GPIO_RegDef_t *GPIOx, uint8_t PinNum) {
    GPIOx->ODR ^= (1 << PinNum); // XOR inverts the target bit
}
