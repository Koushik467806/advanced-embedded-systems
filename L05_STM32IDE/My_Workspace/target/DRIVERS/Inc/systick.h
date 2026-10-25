/*
 * systick.h
 *
 *  Created on: 24-Oct-2026
 *      Author: def85
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "stm32f4xx.h"

/* Control Register Bit Definitions */
#define SYSTICK_CTRL_ENABLE_POS       0U     /* Starts counting when 1 */
#define SYSTICK_CTRL_TICKINT_POS      1U     /* 0: No interrupt, 1- Interrupt */
#define SYSTICK_CTRL_CLKSOURCE_POS    2U     /* Clock Source (0: AHB/8, 1: AHB) */
#define SYSTICK_CTRL_COUNTFLAG_POS    16U    /* Returns 1 if timer becomes 0 */

/* Clock Source */
#define SYSTICK_CLKSOURCE_AHB_DIV8    0U
#define SYSTICK_CLKSOURCE_AHB         1U

/**
 * @brief Initialises the systick clock
 *
 * @param freq System clock frequency
 *
 * Calculates LOAD = (freq/1000) - 1 and clears VAL register
 * Deafults to AHB, enable interrupts and turns on the counter
 */
void SysTick_Init(uint32_t freq);

/**
 * @brief Waits for some time
 *
 * @param delay Delay value in ms
 */
void SysTick_Delay(uint32_t delay);

/**
 * @brief Gets the time since the program has started running in milli-seconds
 *
 * @return Returns the time in ms
 */
uint32_t SysTick_GetTick(void);

/**
 * @brief Updates global time
 *
 * @param inc Increment value in ms
 */
void SysTick_IncrementTick(void);

#endif /* SYSTICK_H_ */
