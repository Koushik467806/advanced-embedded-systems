// GPIOA to AHB1
// USART2 to APB1

// PA2 TX
// PA3 RX

#include "uart.h"

void USART2_init(void)
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
	USART2->BRR = 0x0683; // Using formula in reference manual on baud rate (baud_rate = f_ck/(16 * BRR)
	USART2->CR1 |= (3 << 2); // Enabling RX and TX
	USART2->CR2 &= ~(3 << 12); // Stop bit is 1 bit
	USART2->CR1 |= (1 << 13); // Enables USART
}

int USART2_write(int ch){
	while(!(USART2->SR & (1 << 7))); // Wait till buffer is empty

	USART2->DR = (ch & 0xFF); // To send 8-bits

	return ch;
}

int USART2_read(void){
	while(!(USART2->SR & (1 << 5))); // Wait till content is ready to be read

	return USART2->DR;
}

// For <stdio.h> to work
#define ITM_STIM0_U8      (*((volatile uint8_t  *) 0xE0000000))
#define ITM_STIM0_U32     (*((volatile uint32_t *) 0xE0000000))
#define ITM_TER           (*((volatile uint32_t *) 0xE0000E00))
#define ITM_TCR           (*((volatile uint32_t *) 0xE0000E80))

// Custom ITM_SendChar function equivalent to ARM CMSIS
int32_t ITM_SendChar(int32_t ch) {
    // Check if ITM is enabled (TCR.ITMENENA) AND Port 0 is enabled (TER.STIM0ENA)
    if ((ITM_TCR & (1UL << 0)) && (ITM_TER & (1UL << 0))) {
        // Wait until ITM STIM0 FIFO is ready to accept a byte
        while (ITM_STIM0_U32 == 0);
        // Write byte to Port 0 register
        ITM_STIM0_U8 = (uint8_t)ch;
    }
    return ch;
}

// Redirect printf's output to use ITM_SendChar
int __io_putchar(int ch) {
    ITM_SendChar(ch);
    return ch;
}

int n;
char str[80];

void test(void){
	printf("Enter a number: ");
	scanf("%d", &n);
	printf("Entered number: %d\r\n", n);
	printf("Enter a string: ");
	gets(str);
	printf("Entered character: ");
	puts(str);
	printf("\r\n");
}
