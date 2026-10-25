/*
 * spi.h
 *
 *  Created on: 25-Oct-2026
 *      Author: def85
 */

#ifndef SPI_H_
#define SPI_H_

#include "stm32f4xx.h"

typedef struct {
    uint8_t SPI_DeviceMode;     /* @SPI_DeviceMode: Master or Slave */
    uint8_t SPI_BusConfig;      /* @SPI_BusConfig: Full-Duplex, Half-Duplex, or Simplex Rx */
    uint8_t SPI_SclkSpeed;      /* @SPI_SclkSpeed: Clock Prescaler (fPCLK / 2 to 256) */
    uint8_t SPI_DFF;            /* @SPI_DFF: Data Frame Format (8-bit or 16-bit) */
    uint8_t SPI_CPOL;           /* @SPI_CPOL: Clock Polarity (0: Idle LOW, 1: Idle HIGH) */
    uint8_t SPI_CPHA;           /* @SPI_CPHA: Clock Phase (0: 1st Edge, 1: 2nd Edge) */
    uint8_t SPI_SSM;            /* @SPI_SSM: Software Slave Management (Enable/Disable) */
} SPI_Config_t;

typedef struct {
    SPI_RegDef_t  *pSPIx;        /* Base address of SPI1, SPI2, or SPI3 */
    SPI_Config_t SPIConfig;     /* SPI configuration parameters */
} SPI_Handle_t;

/* Device Mode */
#define SPI_MODE_SLAVE        0UL
#define SPI_MODE_MASTER       1UL

/* Clock Polarity */
#define SPI_CPOL_ACTIVE_HIGH  0UL
#define SPI_CPOL_ACTIVE_LOW   1UL

/* Clock Phase */
#define SPI_CPHA_LEADING      0UL
#define SPI_CPHA_TRAILING     1UL

/* Software Slave Management */
#define SPI_SSM_ENABLE        1UL
#define SPI_SSM_DISABLE       0UL

/* Clock Prescaler */
#define SPI_SCLK_SPEED_DIV2         0UL
#define SPI_SCLK_SPEED_DIV4         1UL
#define SPI_SCLK_SPEED_DIV8         2UL
#define SPI_SCLK_SPEED_DIV16        3UL
#define SPI_SCLK_SPEED_DIV32        4UL
#define SPI_SCLK_SPEED_DIV64        5UL
#define SPI_SCLK_SPEED_DIV128       6UL
#define SPI_SCLK_SPEED_DIV256       7UL

/* Data Frame Format */
#define SPI_DFF_8BIT     0UL
#define SPI_DFF_16BIT    1UL

/* Control Register 1 (SPI_CR1) */
#define SPI_CR1_CPHA_POS            0UL
#define SPI_CR1_CPOL_POS            1UL
#define SPI_CR1_MSTR_POS            2UL
#define SPI_CR1_BR_POS              3UL    /* Bits 3:5 */
#define SPI_CR1_SPE_POS             6UL    /* SPI Enable */
#define SPI_CR1_LSBFIRST_POS        7UL
#define SPI_CR1_SSI_POS             8UL    /* Internal Slave Select */
#define SPI_CR1_SSM_POS             9UL    /* Software Slave Management */
#define SPI_CR1_RXONLY_POS          10UL
#define SPI_CR1_DFF_POS             11UL   /* Data Frame Format */
#define SPI_CR1_BIDIMODE_POS        15UL   /* Bidirectional Data Mode */

/* Control Register 2 (SPI_CR2) */
#define SPI_CR2_SSOE_POS            2UL

/* Status Register (SPI_SR) */
#define SPI_SR_RXNE_POS             0UL    /* Rx buffer not empty */
#define SPI_SR_TXE_POS              1UL    /* Tx buffer empty */
#define SPI_SR_BSY_POS              7UL    /* Busy flag */

/* Bus Configuration */
#define SPI_BUS_CONFIG_FD                1U    /* Full Duplex */
#define SPI_BUS_CONFIG_HD                2U    /* Half Duplex */
#define SPI_BUS_CONFIG_SIMPLEX_RXONLY    3U    /* Simplex Receive Only */

/* Functions */

/**
 * @brief Enables/Disables the clock for SPIx
 *
 * @param *pSPIx: Base address of SPIx
 * @param En: Enable/Disable (1/0)
 */
void SPI_ClockControl(SPI_RegDef_t *pSPIx, uint8_t En);

/**
 * @brief Initialises SPIx
 *
 * @param *pSPIHandle: Base address of SPIx and pointer to its attributes
 */
void SPI_Init(SPI_Handle_t *pSPIHandle);

/**
 * @brief De initialises SPIx
 *
 * @param *pSPIx: Base address of SPIx
 */
void SPI_DeInit(SPI_RegDef_t *pSPIx);

/**
 * @brief Enables SPIx for use
 *
 * @param *pSPIx: Base address of SPIx
 * @param En: Enable/Disable (1/0)
 */
void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t En);

/**
 * @brief When Software Slave Management is enables, SSI should be changed using this
 *
 * @param *pSPIx: Base address of SPIx
 * @param En: Enable/Disable (1/0)
 */
void SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t En);

/**
 * @brief To configure master
 *
 * If disabled, can work in multi-master mode
 * If enabled, cannot work in multi-master mode
 *
 * @param *pSPIx: Base address of SPIx
 * @param En: Enable/Disable (1/0) (Enable- Master)
 */
void SPI_SSOEConfig(SPI_RegDef_t *pSPIx, uint8_t En);

/**
 * @brief Sends data
 *
 * Warning!: Works only when SSM = 1
 *
 * @param *pSPIx: Base address of SPIx
 * @param *pTxBuffer: Pointer to sent data array
 * @param Len: Length of data being sent
 */
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t Len);

/**
 * @brief Receives data
 *
 * @param *pSPIx: Base address of SPIx
 * @param *pRxBuffer: Pointer to received data array
 * @param Len: Length of data being received
 */
void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len);

#endif /* SPI_H_ */
