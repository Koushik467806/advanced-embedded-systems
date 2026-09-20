/*
 * main.c
 *
 *  Created on: 20-Sept-2026
 *      Author: def85
 */

#include "gpio.h"

// Simple software delay loop
void delay(void) {
    for (volatile uint32_t i = 0; i < 250000; i++);
}

int main(void) {
    GPIO_Handle_t GpioLed;

    // 1. Assign base address for Port D
    GpioLed.GPIOx = GPIOD;

    // 2. Configure Green LED pin settings (PD12) using exact macro names from gpio.h
    GpioLed.GPIO_PinConfig.GPIO_PinNumber      = GPIO_PIN_NO_12;
    GpioLed.GPIO_PinConfig.GPIO_PinMode        = GPIO_OUTPUT_MODE;
    GpioLed.GPIO_PinConfig.GPIO_PinSpeed       = GPIO_SPEED_HIGH;
    GpioLed.GPIO_PinConfig.GPIO_PinOPType      = GPIO_PP;
    GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NOPUPD;

    // 3. Initialize the GPIO hardware
    GPIO_Init(&GpioLed);

    // 4. Super loop to blink the LED
    while (1) {
        GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
        delay();
    }

    return 0;
}
