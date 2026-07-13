// GPIOA to AHB1
// USART2 to APB1

#include "stm32f407xx.h"

// PA2 TX
// PA3 RX

void usart2_init(void)
{
	// 1. Enable clock access to UART
	RCC->APB1ENR |= (1 << 17);

	// 2. Enable clock access to port
	RCC->AHB1ENR |= (1 << 0);

	// 3. Enable pins for alternate functions
	// Clear the bits for Pin 2 [5:4] and Pin 3 [7:6]
	GPIOA->MODER &= ~((3 << 4) | (3 << 6));
	// Set them to Alternate Function Mode (binary 10)
	GPIOA->MODER |=  ((2 << 4) | (2 << 6));

	// // 4. Configure type of alternate function
	// Clear the 4-bit slots for Pin 2 [11:8] and Pin 3 [15:12]
	GPIOA->AFR[0] &= ~((0xF << 8) | (0xF << 12));
	// Write 7 (AF7) into both slots
	GPIOA->AFR[0] |=  ((7 << 8)   | (7 << 12));

	// Configure UART
	USART2->BRR = 0x683; // Using formula in reference manual on baud rate
}
