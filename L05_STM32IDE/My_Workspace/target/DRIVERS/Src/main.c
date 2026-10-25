/*
 * main.c
 * Application to test EXTI Interrupt Driver on STM32F407 Discovery
 * Hardware: Onboard Push Button (PA0) & Onboard Green LED (PD12)
 */

#include "stm32f4xx.h"
#include "gpio.h"
#include "systick.h"

int main(void) {
    /* 1. Configure Green LED (PD12) */
    GPIO_Handle_t GpioLed;
    GpioLed.GPIOx = GPIOD;
    GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
    GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_OUTPUT_MODE;
    GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;
    GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_PP;
    GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NOPUPD;

    GPIO_ClockControl(GPIOD, ENABLE);
    GPIO_Init(&GpioLed);

    /* 2. Initialize SysTick for 16 MHz HSI default clock */
    SysTick_Init(16000000UL);

    while (1) {
        /* Toggle LED every 1000 ms (1 second) */
        GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
        SysTick_Delay(1000);
    }

    return 0;
}
