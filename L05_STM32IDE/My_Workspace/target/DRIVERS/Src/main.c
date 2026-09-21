/*
 * main.c
 * Application to test EXTI Interrupt Driver on STM32F407 Discovery
 * Hardware: Onboard Push Button (PA0) & Onboard Green LED (PD12)
 */

#include "stm32f4xx.h"
#include "gpio.h"
#include "exti.h"
#include "rcc.h"

#ifndef __NOP
#define __NOP() __asm__("nop")
#endif

// Software delay for debouncing
void delay_ms(uint32_t count) {
    for (uint32_t i = 0; i < count * 1000; i++) {
        __NOP();
    }
}

int main(void) {
    /* -------------------------------------------------------------
     * 1. Configure Onboard Green LED (PD12) as Digital Output
     * ------------------------------------------------------------- */
    GPIO_Handle_t GpioLed;
    GpioLed.GPIOx = GPIOD;
    GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
    GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_OUTPUT_MODE;
    GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
    GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_PP;
    GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NOPUPD;

    // Enable clock and initialize pin
    GPIO_ClockControl(GPIOD, 1);
    GPIO_Init(&GpioLed);

    /* -------------------------------------------------------------
     * 2. Configure Onboard User Button (PA0) as Input
     * ------------------------------------------------------------- */
    GPIO_Handle_t GpioBtn;
    GpioBtn.GPIOx = GPIOA;
    GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
    GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_INPUT_MODE;
    GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
    GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NOPUPD; // Pull-down on PA0 board hardware

    // Enable clock and initialize pin
    GPIO_ClockControl(GPIOA, 1);
    GPIO_Init(&GpioBtn);

    /* -------------------------------------------------------------
     * 3. Configure EXTI Line 0 for PA0
     * ------------------------------------------------------------- */
    EXTI_Handle_t ExtiBtn;
    ExtiBtn.GPIOx = GPIOA;
    ExtiBtn.EXTI_Config.EXTI_LineNumber = GPIO_PIN_NO_0;
    ExtiBtn.EXTI_Config.EXTI_Trigger = 0; // 0 = Rising Edge Trigger
    ExtiBtn.EXTI_Config.EXTI_LineCmd = 1; // 1 = Enable

    EXTI_Init(&ExtiBtn);

    /* -------------------------------------------------------------
     * 4. Configure NVIC for EXTI Line 0 (IRQ 6)
     * ------------------------------------------------------------- */
    EXTI_IRQPriorityConfig(IRQ_NO_EXTI0, 15); // Priority 15
    EXTI_IRQInterruptConfig(IRQ_NO_EXTI0, 1); // Enable IRQ in NVIC

    /* -------------------------------------------------------------
     * 5. Infinite Idle Loop
     * ------------------------------------------------------------- */
    while (1) {
        // CPU remains idle, waiting for PA0 interrupt
    }

    return 0;
}

/* -----------------------------------------------------------------
 * EXTI Line 0 Interrupt Service Routine (ISR)
 * Overrides weak definition in startup_stm32f407xx.s
 * ----------------------------------------------------------------- */
void EXTI0_IRQHandler(void) {
    // 1. Clear the pending bit FIRST to ignore initial bounce signals
    EXTI_ClearPendingBit(GPIO_PIN_NO_0);

    // 2. Wait for mechanical contacts to settle completely
    delay_ms(50);

    // 3. Confirm the button is STILL pressed before taking action
    if (GPIO_ReadPin(GPIOA, GPIO_PIN_NO_0) == 1) {
        GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
    }
}
