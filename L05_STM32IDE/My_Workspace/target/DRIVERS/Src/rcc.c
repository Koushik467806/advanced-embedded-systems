/*
 * rcc.c
 *
 *  Created on: 20-Sept-2026
 *      Author: def85
 */

uint8_t RCC_SetSysClockFrequency(uint32_t targetFreq){
	// 1. Conditions for hardware to work
	if(targetFreq < 24000000UL || targetFreq > 168000000UL ) return 0;

	uint32_t N = (targetFreq * 2)/1000000UL;
	if(N < 50 || N > 432) return 0;

	// 2. Wait Stae
	uint32_t WS = targetFreq / 30000000UL;
	if (WS > 5) WS = 5;

	// 3. Determining AHB, APB1 and APB2 frequencies
	uint32_t AHBFreq = targetFreq;

	uint32_t APB1Freq = 0; // PPRE1
	if(targetFreq >= 84000000UL) APB1Freq = targetFreq / 4;
	else if(targetFreq >= 42000000UL && targetFreq < 84000000) APB1Freq = targetFreq/2;
	else APB1Freq = targetFreq;

	uint32_t APB2Freq = 0; // PPRE2
	if(targetFreq > 84000000UL) APB2Freq = targetFreq / 2;
	else APB2Freq = targetFreq;

	// 4. Enabling HSE
	RCC->CR |= (1UL << 16); // ENable Bit
	while(!(RCC->CR & (1U << 17))); // Wait till ready

	// 5. Configure PLL
	PWR_PCLK_EN(); // Enable Power Controller Clock
	PWR->CR &= ~(0x3UL << 14); // Reset
	PWR->CR |= (0x3UL << 14); // Give Power

	FLASH->ACR &= ~0x7U;                 // Clear Latency bits [2:0]
	FLASH->ACR |= WS;                    // Set calculated Wait States
	FLASH->ACR |= (1U << 8) | (1U << 9) | (1U << 10); // Enable Prefetch, I-Cache, D-Cache

	// 6. Configure RCC->CFGR (Prescalers for AHB, APB1, APB2)
	RCC->CFGR &= ~((0xFUL << 4) | (0x7UL << 10) | (0x7UL << 13)); // Clear

	if(targetFreq > 84000000UL) RCC->CFGR |= (0x5UL << 10); // DIV4 (APB1)
	else if(targetFreq > 42000000UL) RCC->CFGR |= (0x4UL << 10); // DIV2 (APB1)

	if(targetFreq > 84000000UL) RCC->CFGR |= (0x4UL << 13); // DIV2 (APB2)

	// 7. Configure RCC->PLLCFGR
	// P = 2 for max speed, 8 for min
	// M = 8 (fixed for this 8MHz)
	// N is calculated above
	RCC->PLLCFGR &= ~((0x1UL << 22) | (0x7FFFUL << 0) | (0x3UL << 16)); // Clear
	RCC->PLLCFGR |= ((0x1UL << 22) | (0x1UL << 3) | (N << 6) | (0x00UL << 16)); // 0 for HSI, 1 for HSE

	// 8. Enable PLL
	RCC->CR |= (1UL << 24); // Enable PLL (PLLON)
	while (!(RCC->CR & (1UL << 25))); // Wait until PLL is locked (PLLRDY)

	RCC->CFGR &= ~(0x3UL << 0); // Clear SW bits [1:0]
	RCC->CFGR |=  (0x2UL << 0); // Set SW bits to 10 (Select PLL as SYSCLK)

	while (((RCC->CFGR >> 2) & 0x3UL) != 0x2UL); // Wait until SWS bits [3:2] read 10

	return 1;
}

// AHB Prescaler division factors indexed by (HPRE bitfield value)
const uint16_t AHBPrescalerTable[16] = {1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 8, 16, 64, 128, 256, 512};

// APB Prescaler division factors indexed by (PPRE bitfield value)
const uint8_t APBPrescalerTable[8] = {1, 1, 1, 1, 2, 4, 8, 16};

uint32_t RCC_GetSysClockValue(void){
	uint8_t clkSource = (RCC->CFGR >> 2) & 0x3UL; // Checking source

	uint32_t pclk1, sysclk;
	    uint8_t temp, ahbp, apb1p;

	    // 1. Get current SYSCLK
	    sysclk = RCC_GetSysClockValue();

	    // 2. Read AHB Prescaler (HPRE: bits 7:4 in RCC_CFGR)
	    temp = (RCC->CFGR >> 4) & 0xFUL;
	    ahbp = AHBPrescalerTable[temp];

	    // 3. Read APB1 Prescaler (PPRE1: bits 12:10 in RCC_CFGR)
	    temp = (RCC->CFGR >> 10) & 0x7UL;
	    apb1p = APBPrescalerTable[temp];

	    // 4. Calculate PCLK1
	    pclk1 = (sysclk / ahbp) / apb1p;
	    return pclk1;
}

uint32_t RCC_GetPCLK2Value(void) {
    uint32_t pclk2, sysclk;
    uint8_t temp, ahbp, apb2p;

    // 1. Get current SYSCLK
    sysclk = RCC_GetSysClockValue();

    // 2. Read AHB Prescaler (HPRE: bits 7:4 in RCC_CFGR)
    temp = (RCC->CFGR >> 4) & 0xFUL;
    ahbp = AHBPrescalerTable[temp];

    // 3. Read APB2 Prescaler (PPRE2: bits 15:13 in RCC_CFGR)
    temp = (RCC->CFGR >> 13) & 0x7UL;
    apb2p = APBPrescalerTable[temp];

    // 4. Calculate PCLK2
    pclk2 = (sysclk / ahbp) / apb2p;
    return pclk2;
}

void RCC_AHB1_ClockControl(uint8_t bitPos, uint8_t state){
    if(state == 1) RCC->AHB1ENR |= (1UL << bitPos);
    else RCC->AHB1ENR &= ~(1UL << bitPos);
}

void RCC_APB1_ClockControl(uint8_t bitPos, uint8_t state){
    if(state == 1) RCC->AHP1ENR |= (1UL << bitPos);
    else RCC->APB1ENR &= ~(1UL << bitPos);
}

void RCC_APB2_ClockControl(uint8_t bitPos, uint8_t state){
    if(state == 1) RCC->APB2ENR |= (1UL << bitPos);
    else RCC->APB2ENR &= ~(1UL << bitPos);
}
