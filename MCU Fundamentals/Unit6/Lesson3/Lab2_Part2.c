/* Unit6_Lesson3_Lab2_Part2 */
/*
 * APB1 >> 16 MHZ
 * APB2 >> 8 MHZ
 * AHB  >> 32 MHZ
 * SYSCLK >> 32 MHZ
 * Internal HSI_RC
 *
 * Clock tree:
 * PLLSRC >> HSI / 2
 * PLLMUL >> *8
 * SW >> PLLCLK
 * AHB prescaler >> 1
 * APB1 prescaler >> 2
 * APB2 prescaler >> 4
 */


#define RCC_BASE   0x40021000
#define RCC_CR	 *(volatile unsigned int* )(RCC_BASE + 0x00)
#define RCC_CFGR *(volatile unsigned int* )(RCC_BASE + 0x04)

void clock_init()
{
  /* PLLSRC: PLL entry clock source
   * Set and cleared by software to select PLL clock source. This bit can be written only when
	PLL is disabled.
	0: HSI oscillator clock / 2 selected as PLL input clock
	1: HSE oscillator clock selected as PLL input clock
   */
	/* Kept on reset value */

  /* PLLMUL: PLL multiplication factor
   * These bits are written by software to define the PLL multiplication factor. These bits can be
	written only when PLL is disabled.
	Caution: The PLL output frequency must not exceed 72 MHz.
	0110: PLL input clock x 8

   */
	RCC_CFGR |= (0b0110 << 18);

  /* PLL enable
   * PLLON: PLL enable
   * Set and cleared by software to enable PLL.
	Cleared by hardware when entering Stop or Standby mode. This bit can not be reset if the
	PLL clock is used as system clock or is selected to become the system clock.
	0: PLL OFF
	1: PLL ON
   */
	RCC_CR |= (0b1 << 24);

  /* SW: System clock switch
   * Set and cleared by software to select SYSCLK source.
	Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of
	failure of the HSE oscillator used directly or indirectly as system clock (if the Clock Security
	System is enabled).
	00: HSI selected as system clock
	01: HSE selected as system clock
	10: PLL selected as system clock
	11: not allowed
   */
	RCC_CFGR |= (0b10);

  /* AHB prescaler
   * Set and cleared by software to control the division factor of the AHB clock.
	0xxx: SYSCLK not divided
	1000: SYSCLK divided by 2
	1001: SYSCLK divided by 4
	1010: SYSCLK divided by 8
	1011: SYSCLK divided by 16
	1100: SYSCLK divided by 64
	1101: SYSCLK divided by 128
	1110: SYSCLK divided by 256
	1111: SYSCLK divided by 512
  */
   /* Kept on reset value */

  /*
  * PPRE1: APB low-speed prescaler (APB1)
  * Set and cleared by software to control the division factor of the APB low-speed clock
  	(PCLK1).
	Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
	0xx: HCLK not divided
	100: HCLK divided by 2
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16
  */
  RCC_CFGR |= (0b100 << 8);
  /*
  * PPRE2: APB high-speed prescaler (APB2)
  * Set and cleared by software to control the division factor of the APB high-speed clock
	(PCLK2).
	0xx: HCLK not divided
	100: HCLK divided by 2
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16
  */
  RCC_CFGR |= (0b101 << 11);
}

int main(void)
{
	clock_init();
	while(1)
	{}
}


