/*
 * timer.h
 *
 *  Created on: 24-Oct-2026
 *      Author: def85
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "stm32f4xx.h"

/* Control Register 1 (CR1) */
#define TIM_CR1_CEN_POS         0U   /* Counter Enable */
#define TIM_CR1_UDIS_POS        1U   /* Update Disable */
#define TIM_CR1_URS_POS         2U   /* Update Request Source */
#define TIM_CR1_OPM_POS         3U   /* One-Pulse Mode */
#define TIM_CR1_DIR_POS         4U   /* Direction: 0 = Upcounter, 1 = Downcounter */
#define TIM_CR1_ARPE_POS        7U   /* Auto-Reload Preload Enable */

/* Status Register (SR) */
#define TIM_SR_UIF_POS          0U   /* Update Interrupt Flag */

/* DMA/Interrupt Enable Register (DIER) */
#define TIM_DIER_UIE_POS        0U   /* Update Interrupt Enable */

/* Event Generation Register (EGR) */
#define TIM_EGR_UG_POS          0U   /* Update Generation (forces re-evaluation of PSC/ARR) */

/**
 * @brief Initializes a general-purpose timer to tick at 1 us resolution.
 *
 * @param TIMx: Pointer to timer base peripheral (TIM2, TIM3, TIM4, or TIM5)
 * @param apb1ClockFreq: Current APB1 clock frequency in Hz (e.g. 16000000UL)
 */
void TIMER_InitUs(TIM_RegDef_t *TIMx, uint32_t apb1ClockFreq);

/**
 * @brief Precise blocking microsecond delay using an initialized hardware timer.
 *
 * @param TIMx: Pointer to timer peripheral
 * @param us: Time duration to wait in microseconds
 */
void TIMER_DelayUs(TIM_RegDef_t *TIMx, uint32_t us);

/**
 * @brief Precise blocking millisecond delay using an initialized hardware timer.
 *
 * @param TIMx: Pointer to timer peripheral
 * @param ms: Time duration to wait in milliseconds
 */
void TIMER_DelayMs(TIM_RegDef_t *TIMx, uint32_t ms);

/**
 * @brief Enables the timer Update Interrupt (fires when counter overflows ARR).
 *
 * @param TIMx: Pointer to timer peripheral
 */
void TIMER_EnableInterrupt(TIM_RegDef_t *TIMx);

/**
 * @brief Clears the Update Interrupt Flag (UIF) in status register.
 *
 * @param TIMx: Pointer to timer peripheral
 */
void TIMER_ClearFlag(TIM_RegDef_t *TIMx);

#endif /* TIMER_H_ */
