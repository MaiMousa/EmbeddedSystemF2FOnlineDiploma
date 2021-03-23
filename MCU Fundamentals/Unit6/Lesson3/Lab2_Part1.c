/* Unit6_Lesson3_Lab2_Part1 */
/*
 * APB1 >> 4 MHZ
 * APB2 >> 2 MHZ
 * AHB  >> 8 MHZ
 * SYSCLK >> 8 MHZ
 * Internal HSI_RC
 *
 * Clock tree:
 * SW >> HSI
 * AHB prescaler >> 1
 * APB1 prescaler >> 2
 * APB2 prescaler >> 4
 */

#define RCC_BASE   0x40021000
#define RCC_CR	 *(volatile unsigned int* )(RCC_BASE + 0x00)
#define RCC_CFGR *(volatile unsigned int* )(RCC_BASE + 0x04)

void clock_init()
{

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
	/* Kept on reset value */

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


