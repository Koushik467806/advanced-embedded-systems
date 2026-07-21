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
struct __FILE {  int handle;  };
FILE __stdin = {0};
FILE __stdout = {1};
FILE __stderr = {2};

int fgetc(FILE *f){
	int c;
	c = USART2_read();

	if(c == '\r'){
		USART2_write(c);
		c = '\n';
	}

	USART2_write(c);
	return c;
}

int fputc(int c, FILE *f){
	return USART2_write(c);
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
