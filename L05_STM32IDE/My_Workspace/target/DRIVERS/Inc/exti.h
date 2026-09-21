/*
 * exti.h
 *
 *  Created on: 21-Sept-2026
 *      Author: def85
 */

#include "stm32f4xx.h"

/* EXTI Trigger Modes */
#define EXTI_TRIGGER_RISING         0
#define EXTI_TRIGGER_FALLING        1
#define EXTI_TRIGGER_RISING_FALLING 2 /* Trigger on both edges */

typedef struct {
    uint8_t EXTI_LineNumber;   /* Pin / EXTI line (GPIO_PIN_NO_0 to 15) */
    uint8_t EXTI_Trigger;      /* Values from @EXTI_TRIGGER_MODES */
    uint8_t EXTI_LineCmd;      /* ENABLE (1) or DISABLE (0) */
} EXTI_Config_t;

typedef struct {
    GPIO_RegDef_t *GPIOx;      /* Base address of Port (GPIOA, GPIOB, etc.) */
    EXTI_Config_t EXTI_Config; /* EXTI Pin settings */
} EXTI_Handle_t;

/**
 * @brief Initialises the EXTI Pointer
 *
 * @param EXTIHandle: Pointer to EXTI Register
 */
void EXTI_Init(EXTI_Handle_t *EXTIHandle);

/**
 * @brief De-initialises (or resets) the pointer to default
 *
 * @param lineNum: Line to deinitialize (EXTI->IMR)
 */
void EXTI_DeInit(uint8_t lineNum);

/**
 * @brief Enables/Disables IMQ line inside the NVIC
 *
 * @param IRQNumber: Line Number to enable/disable
 * @param state: ENable/Disable (0/1)
 */
void EXTI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t state);

/**
 * @brief Sets priority of IMQ line
 *
 * @param IRQNumber: Line number to give priority
 * @param IRQPriority: The priority to give (low value -> high priority)
 */
void EXTI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);

/**
 * @brief Writes 1 to line after interrupt is finished
 *
 * @param lineNum: Line number to write 1 to
 */
void EXTI_ClearPendingBit(uint8_t lineNum);
