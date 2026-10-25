/*
 * timer.c
 *
 *  Created on: 24-Oct-2026
 *      Author: def85
 */

#include "timer.h"

/**
 * @brief Private helper to enable APB1 clock for TIM2-TIM5
 *
 * @param *TIMx: Pointer to timer peripheral
 * @param En: Boolean to enable/disable
 */
static void TIMER_ClockControl(TIM_RegDef_t *TIMx, uint8_t En){
    if(En == ENABLE){
        if(TIMx == TIM2)      RCC->APB1ENR |= (1UL << 0);
        else if(TIMx == TIM3) RCC->APB1ENR |= (1UL << 1);
        else if(TIMx == TIM4) RCC->APB1ENR |= (1UL << 2);
        else if(TIMx == TIM5) RCC->APB1ENR |= (1UL << 3);
    }
    else{
        if(TIMx == TIM2)      RCC->APB1ENR &= ~(1UL << 0);
        else if(TIMx == TIM3) RCC->APB1ENR &= ~(1UL << 1);
        else if(TIMx == TIM4) RCC->APB1ENR &= ~(1UL << 2);
        else if(TIMx == TIM5) RCC->APB1ENR &= ~(1UL << 3);
    }
}

void TIMER_InitUs(TIM_RegDef_t *TIMx, uint32_t apb1ClockFreq){
	// 1. ENable APB1 Clock for the timer
	TIMER_ClockControl(TIMx, ENABLE);

	// 2. Disable counter
	TIMx->CR1 &= ~(1UL << TIM_CR1_CEN_POS);

	// 3. Calculate Prescaler(PSC) for 1 micro-second
	uint32_t psc = (apb1ClockFreq/1000000) - 1;
	TIMx->PSC = (uint16_t)psc;

	// 4. Set ARR to max (to start counting till ARR)
	// TIM2 and TIM5 are 32-bit
	if(TIMx == TIM2 || TIMx == TIM5){
		TIMx->ARR = 0xFFFFFFFFUL;
	}
	// TIM3 and TIM4 are 16-bit
	if(TIMx == TIM3 || TIMx == TIM4){
		TIMx->ARR = 0x0000FFFFUL;
	}

	// 5. Update the prescaler
	TIMx->EGR |= (1UL << TIM_EGR_UG_POS);

	// 6. Clear interrupt flag
	TIMx->SR &= ~(1UL << TIM_SR_UIF_POS);
}

void TIMER_DelayUs(TIM_RegDef_t *TIMx, uint32_t us){
	// 1. Reset counter to 0
	TIMx->CNT = 0UL;

	// 2. Enable counter
	TIMx->CR1 |= (1UL << TIM_CR1_CEN_POS);

	// 3. Wait until CNT reaches required count
	while(TIMx->CNT < us){
		__asm__("nop");
	}

	// 4. Disable counter
	TIMx->CR1 &= ~(1UL << TIM_CR1_CEN_POS);
}

void TIMER_DelayMs(TIM_RegDef_t *TIMx, uint32_t ms){
	for(uint32_t i=0;i<ms;i++){
		TIMER_DelayUs(TIMx, 1000);
	}
}

void TIMER_EnableInterrupt(TIM_RegDef_t *TIMx){
	TIMx->DIER &= ~(1UL << TIM_DIER_UIE_POS);
	TIMx->DIER |= (1UL << TIM_DIER_UIE_POS);
}

void TIMER_ClearFlag(TIM_RegDef_t *TIMx){
	TIMx->SR &= ~(1UL << TIM_SR_UIF_POS);
}
