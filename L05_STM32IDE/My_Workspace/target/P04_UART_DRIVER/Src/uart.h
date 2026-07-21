#ifndef _UART_H
#define _UART_H

/**
 * @file uart.h
 * @brief This file declares all the functions necessary for uart.
 *
 * It has 3 functions:
 * 1. USART2_init()
 * 2. USART2_write()
 * 3. USART2_read()
 * Each function has a specific use case which will be explained in the later
 * parts of the file
 *
 * @author Koushik Thatavarthi
 * @date 21-07-2026
 */


#include "stm32f407xx.h"
#include <stdio.h>

/**
 * @brief Initialises all the necessary hardware for USART
 *
 * It does the following:
 * 1. Enables Clock access for USART2
 * 2. Configure GPIO pins to RX and TX
 * 3. Sets baud rate to 9600
 * 4. Enables RX and TX
 * 5. Sets stop bit as 1 bit
 * 5. Enables USART2
 */
void USART2_init(void);

/**
 * @brief Writes data to register bit by bit
 *
 * @param ch: Character to write on console
 *
 * @return ch
 */
int USART2_write(int ch);

/**
 * @brief Reads data in the register bit by bit
 *
 * @return Bits read
 */
int USART2_read(void);

/**
 * @brief Basic test function which tests print() and scanf()
 */
void test(void);

#endif
