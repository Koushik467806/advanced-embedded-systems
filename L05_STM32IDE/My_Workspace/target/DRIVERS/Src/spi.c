/*
 * spi.c
 *
 *  Created on: 25-Oct-2026
 *      Author: def85
 */

#include "spi.h"

void SPI_ClockControl(SPI_RegDef_t *pSPIx, uint8_t En){
	// 1. Give clock access to SPIx
	if(En == 1){
		if(pSPIx == SPI2) RCC->APB1ENR |= (1UL << 14);
		else if(pSPIx == SPI3) RCC->APB1ENR |= (1UL << 15);
		else if(pSPIx == SPI1) RCC->APB2ENR |= (1UL << 12);
	}
	else{
		if(pSPIx == SPI2) RCC->APB1ENR &= ~(1UL << 14);
		else if(pSPIx == SPI3) RCC->APB1ENR &= ~(1UL << 15);
		else if(pSPIx == SPI1) RCC->APB2ENR &= ~(1UL << 12);
	}
}

void SPI_Init(SPI_Handle_t *pSPIHandle){
	// 1. Define a temporary register
	uint16_t tempSPI = 0;

	// 2. Give clock access
	SPI_ClockControl(pSPIHandle->pSPIx, 1);

	// 3. Select Master/Slave
	tempSPI |= (pSPIHandle->SPIConfig.SPI_DeviceMode << SPI_CR1_MSTR_POS);

	// 4. Select Mode
	if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_FD) tempSPI &= ~(1UL << SPI_CR1_BIDIMODE_POS); // Full duplex
	else if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HD) tempSPI |= (1UL << SPI_CR1_BIDIMODE_POS); // Half Duplex
	else if(pSPIHandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_SIMPLEX_RXONLY){
		tempSPI &= ~(1UL << SPI_CR1_BIDIMODE_POS); // Clear HD
		tempSPI |= (1UL << SPI_CR1_RXONLY_POS); // Receive only
	}

	// 5. Prescaler
	tempSPI |= (pSPIHandle->SPIConfig.SPI_SclkSpeed << SPI_CR1_BR_POS);

	// 6. Data Frame Format
	tempSPI |= (pSPIHandle->SPIConfig.SPI_DFF << SPI_CR1_DFF_POS);

	// 7. Polarity
	tempSPI |= (pSPIHandle->SPIConfig.SPI_CPOL << SPI_CR1_CPOL_POS);

	// 8. Phase
	tempSPI |= (pSPIHandle->SPIConfig.SPI_CPHA << SPI_CR1_CPHA_POS);

	// 9. Software Slave Management
	tempSPI |= (pSPIHandle->SPIConfig.SPI_SSM << SPI_CR1_SSM_POS);

	// 10. Load tempSPI into SPI register (CR1)
	// We do this to change configurations of the whole register at once to avoid issues
	pSPIHandle->pSPIx->CR1 = tempSPI;
}

void SPI_DeInit(SPI_RegDef_t *pSPIx){
	// 1. Reset clock access
	if(pSPIx == SPI1){
		RCC->APB2RSTR |= (1UL << 12);  // Reset
		RCC->APB2RSTR &= ~(1UL << 12); // Start again free
	}
	else if (pSPIx == SPI2){
		RCC->APB1RSTR |= (1UL << 14);
		RCC->APB1RSTR &= ~(1UL << 14);
	}
	else if(pSPIx == SPI3){
		RCC->APB1RSTR |= (1UL << 15);
		RCC->APB1RSTR &= ~(1UL << 15);
	}
}

void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t En){
	// 1. Enable SPI for communication
	if(En == ENABLE) pSPIx->CR1 |= (1UL << SPI_CR1_SPE_POS);
	else pSPIx->CR1 &= ~(1UL << SPI_CR1_SPE_POS);
}

void SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t En){
	// 1. If SSI = 1, it is Master
	// Warning: This function only works when SSM =1
	if(En == ENABLE) pSPIx->CR1 |= (1UL << SPI_CR1_SSI_POS);
	else pSPIx->CR1 &= ~(1UL << SPI_CR1_SSI_POS);
}

void SPI_SSOEConfig(SPI_RegDef_t *pSPIx, uint8_t En){
	if(En == ENABLE) pSPIx->CR2 |= (1UL << SPI_CR2_SSOE_POS);
	else pSPIx->CR2 &= ~(1UL << SPI_CR2_SSOE_POS);
}

void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len){
	while(Len > 0){
		// 1. Wait until buffer is empty
		while(!(pSPIx->SR & (1UL<< SPI_SR_TXE_POS)));

		// 2. Check if DFF is 8/16-Bit and send data (SPI_DR)
		if(pSPIx->CR1 & (1UL << SPI_CR1_DFF_POS)){
			pSPIx->DR = *((uint16_t *)pTxBuffer);
			Len -= 2;
			pTxBuffer += 2;
		}
		else{
			pSPIx->DR = *pTxBuffer;
			Len -= 1;
			pTxBuffer++;
		}
	}
}

void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len){
	while(Len > 0){
	    // 1. Wait until buffer is not empty
	    while (!(pSPIx->SR & (1UL << SPI_SR_RXNE_POS)));

	    // 2. Check if DFF is 8/16-Bit and receive the data (SPI_DR)
	    if(pSPIx->CR1 & (1UL << SPI_CR1_DFF_POS)){
	        *((uint16_t *)pRxBuffer) = (uint16_t)pSPIx->DR;
	        Len -= 2;
	        pRxBuffer += 2;
	    }
	    else{
	        *pRxBuffer = (uint8_t)pSPIx->DR;
	        Len--;
	        pRxBuffer++;
	    }
	}
}
