/*
 * gpio.h
 *
 *  Created on: 20-Sept-2026
 *      Author: def85
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "stm32f4xx.h"

/*
 * Configuration structure for a GPIO pin
 */
typedef struct {
    uint8_t GPIO_PinNumber;       /* Possible values from @GPIO_PIN_NUMBERS */
    uint8_t GPIO_PinMode;         /* Possible values from @GPIO_PIN_MODES */
    uint8_t GPIO_PinSpeed;        /* Possible values from @GPIO_PIN_SPEED */
    uint8_t GPIO_PinPuPdControl;  /* Possible values from @GPIO_PIN_PUPD */
    uint8_t GPIO_PinOPType;       /* Possible values from @GPIO_PIN_OP_TYPE */
    uint8_t GPIO_PinAltFunMode;   /* Configured when mode is set to ALT_FN */
} GPIO_PinConfig_t;

/*
 * Handle structure for a GPIO pin
 */
typedef struct {
    GPIO_RegDef_t *GPIOx;           /* Holds base address of the GPIO port (GPIOA, GPIOB, etc.) */
    GPIO_PinConfig_t GPIO_PinConfig; /* Holds GPIO pin configuration settings */
} GPIO_Handle_t;

/*
 * GPIO Pin Numbers
 */
#define GPIO_PIN_NO_0  0
#define GPIO_PIN_NO_1  1
#define GPIO_PIN_NO_2  2
#define GPIO_PIN_NO_3  3
#define GPIO_PIN_NO_4  4
#define GPIO_PIN_NO_5  5
#define GPIO_PIN_NO_6  6
#define GPIO_PIN_NO_7  7
#define GPIO_PIN_NO_8  8
#define GPIO_PIN_NO_9  9
#define GPIO_PIN_NO_10 10
#define GPIO_PIN_NO_11 11
#define GPIO_PIN_NO_12 12
#define GPIO_PIN_NO_13 13
#define GPIO_PIN_NO_14 14
#define GPIO_PIN_NO_15 15

/*
 * GPIO Modes
 */
#define GPIO_INPUT_MODE  0
#define GPIO_OUTPUT_MODE 1
#define GPIO_AF_MODE     2
#define GPIO_ANALOG_MODE 3

/*
 * GPIO Types
 */
#define GPIO_PP 0
#define GPIO_OD 1

/*
 * GPIO Speed
 */
#define GPIO_SPEED_LOW   0
#define GPIO_SPEED_MED   1
#define GPIO_SPEED_HIGH  2
#define GPIO_SPEED_VHIGH 3

/*
 * GPIO Pull-up Pull-down
 */
#define GPIO_NOPUPD 0
#define GPIO_PU     1
#define GPIO_PD     2

/**
 * @brief Enables or disables clock to GPIOx, x = A to I
 *
 * @param *GPIOx: GPIOx register pointer defined in stm32f4xx.h
 * @param ED: Enable or Disable the port
 */
void GPIO_ClockControl(GPIO_RegDef_t *GPIOx, uint8_t ED);

/**
 * @brief Initilaises the GPIOx Pin
 *
 * @param *GPIOHandle: GPIOx register pointer and pin configurations
 */
void GPIO_Init(GPIO_Handle_t *GPIOHandle);

/**
 * @brief Deinitilaises the GPIOx Pin (reset)
 *
 * @param *GPIOx: GPIOx register pointer
 */
void GPIO_DeInit(GPIO_RegDef_t *GPIOx);

/**
 * @brief Reads data from a specific pin (0 or 1) using IDR
 *
 * @param *GPIOx: GPIOx register pointer
 * @param PinNum: Pin Number from which data is to be read
 *
 * @return Data from IDR (0 or 1)
 */
uint8_t GPIO_ReadPin(GPIO_RegDef_t *GPIOx, uint8_t PinNum);

/**
 * @brief Reads data from a specific port (16-Bit) using IDR
 *
 * @param *GPIOx: GPIOx register pointer
 *
 * @return Data from IDR of all 16 pins
 */
uint16_t GPIO_ReadPort(GPIO_RegDef_t *GPIOx);

/**
 * @brief Writes data to a specific pin (0 or 1) using ODR
 *
 * @param *GPIOx: GPIOx register pointer
 * @param PinNum: Pin Number from which data is to be read
 * @param value: Data to be stored (0 or 1)
 */
void GPIO_WritePin(GPIO_RegDef_t *GPIOx, uint8_t PinNum, uint8_t value);

/**
 * @brief Writes data to a specific port (16-Bit) using ODR
 *
 * @param *GPIOx: GPIOx register pointer
 * @param value: 16-Bit Value to be stored
 */
void GPIO_WritePort(GPIO_RegDef_t *GPIOx, uint16_t value);

/**
 * @brief Toggles pin (inverts)
 *
 * @param *GPIOx: GPIO register pointer
 * @param PinNum: Pin Number to be toggled
 */
void GPIO_ToggleOutputPin(GPIO_RegDef_t *GPIOx, uint8_t PinNum);

#endif
