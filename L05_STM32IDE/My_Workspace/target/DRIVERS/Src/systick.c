/*
 * systick.c
 *
 *  Created on: 24-Oct-2026
 *      Author: def85
 */

#include "systick.h"

// Global millisecond tick counter (volatile because it is updated inside an ISR)
static __IO uint32_t g_tickCount = 0;

void SysTick_Init(uint32_t freq){
	// 1. Disable counter
	SYSTICK->CTRL &= ~(1UL << SYSTICK_CTRL_ENABLE_POS);

	// 2. Calculate the LOAD value
	uint32_t load = (freq/1000UL) - 1UL;

	// 3. Load the value
	if(load > 0x00FFFFFFUL) load = 0x00FFFFFFUL; // Max value
	SYSTICK->LOAD = load;

	// 4. Clear VAL register
	SYSTICK->VAL = 0UL;

	// 5. Default clock source as AHB
	SYSTICK->CTRL &= ~(1UL << SYSTICK_CTRL_CLKSOURCE_POS);
	SYSTICK->CTRL |= (1UL << SYSTICK_CTRL_CLKSOURCE_POS);

	// 6. Default to enable interrupts
	SYSTICK->CTRL &= ~(1UL << SYSTICK_CTRL_TICKINT_POS);
	SYSTICK->CTRL |= (1UL << SYSTICK_CTRL_TICKINT_POS);

	// 7. Turn on counter
	SYSTICK->CTRL |= (1UL << SYSTICK_CTRL_ENABLE_POS);
}

void SysTick_IncrementTick(void){
	// 1. Adds 1ms to time passed
	g_tickCount++;
}

uint32_t SysTick_GetTick(void){
	// 1. Return time passed since program started running
	return g_tickCount;
}

void SysTick_Delay(uint32_t delay){
	// 1. Get current time
	uint32_t start = SysTick_GetTick();

	// 2. Wait until delay
	while(SysTick_GetTick() - start < delay){
		// Do nothing
		__asm__("nop"); // Can leave the loop blank but it will get removed when optimised
	}
}

/**
 * @brief Adds 1ms when interrupt is seen
 *
 * MCU gets to handler automatically when countflag becomes zero.
 * This happens due to NVIC vector table, must use SysTick_Handler only (name)
 * Since it takes 1ms extra, we add it to g_tickCount
 */
void SysTick_Handler(void){
    SysTick_IncrementTick();
}
