/*
 * exti.c
 *
 *  Created on: 21-Sept-2026
 *      Author: def85
 */

#include "exti.h"
#include "gpio.h"

void EXTI_Init(EXTI_Handle_t *EXTIHandle){
	// 1. Enable Clock for SYSCFG
	SYSCFG_PCLK_EN();

	// 2. Select Port
	uint8_t pinNum = EXTIHandle->EXTI_Config.EXTI_LineNumber;
	uint8_t regIndex = pinNum / 4;
	uint8_t bitShift = (pinNum % 4) * 4;
	uint8_t portCode = GPIO_BASE_TO_CODE(EXTIHandle->GPIOx);

	// 3. Write port code
	SYSCFG->EXTICR[regIndex] &= ~(0xFUL << bitShift);
	SYSCFG->EXTICR[regIndex] |=  ((uint32_t)portCode << bitShift);

	// 4. Configure Edge Trigger
	uint8_t trig = EXTIHandle->EXTI_Config.EXTI_Trigger;
	if(trig == 0) EXTI->RTSR |= (0x1UL << pinNum);
	else if(trig == 1) EXTI->FTSR |= (0x1UL << pinNum);
	else {
		EXTI->RTSR |= (0x1UL << pinNum);
		EXTI->FTSR |= (0x1UL << pinNum);
	}

	// 5. Unmask interrupt (enable/ disable)
	if (EXTIHandle->EXTI_Config.EXTI_LineCmd == 1) EXTI->IMR |= (1UL << pinNum);  // Unmask (Enable)
	else EXTI->IMR &= ~(1UL << pinNum); // Mask (Disable)
}

void EXTI_DeInit(uint8_t lineNum) {
	if (lineNum > 15) return; // STM32F4 GPIO EXTI lines range from 0 to 15

	// 1. Disable Interrupt and Event Masking
	EXTI->IMR &= ~(1UL << lineNum);
	EXTI->EMR &= ~(1UL << lineNum);

	// 2. Clear Edge Trigger Selections
	EXTI->RTSR &= ~(1UL << lineNum);
	EXTI->FTSR &= ~(1UL << lineNum);

	// 3. Clear Pending Flag if set
	if (EXTI->PR & (1UL << lineNum)) EXTI->PR |= (1UL << lineNum); // Write 1 to clear
}

void EXTI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t state){
	// 1. Find regIndex and bitShift values
	uint8_t regIndex = IRQNumber / 32;
	uint8_t bitShift = IRQNumber % 32;

	// 2. Enabling NVIC (NVIC Set-Enable Register, Clear-Enable Register)
	if(state == 1) NVIC->ISER[regIndex] |= (0x1UL << bitShift);
	else NVIC->ICER[regIndex] |= (0x1UL << bitShift);
}

void EXTI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority){
	// 1. Set priority (NVIC Interrupt Priority Register)
	NVIC->IPR[IRQNumber] &= ~(0b1111 << 4);
	NVIC->IPR[IRQNumber] |= (IRQPriority << 4); // (0 to 15)
}

void EXTI_ClearPendingBit(uint8_t lineNum){
	// 1. Check and clear the pending bit
	if (EXTI->PR & (1UL << lineNum)) {
	    EXTI->PR |= (1UL << lineNum);
	}
}
