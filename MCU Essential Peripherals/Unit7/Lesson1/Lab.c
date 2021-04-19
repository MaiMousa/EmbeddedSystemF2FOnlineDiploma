/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#include <stdint.h>

/* Registers */
/* RCC */
#define RCC_BASE     0x40021000
#define RCC_APB2ENR  *(volatile uint32_t *)(RCC_BASE + 0x18)
/* GPIOA */
#define GPIOA_BASE	 0x40010800
#define GPIOA_CRL    *(volatile uint32_t*)(GPIOA_BASE + 0x00)
#define GPIOA_CRH    *(volatile uint32_t*)(GPIOA_BASE + 0x04)
#define GPIOA_IDR    *(volatile uint32_t*)(GPIOA_BASE + 0x08)
#define GPIOA_ODR    *(volatile uint32_t*)(GPIOA_BASE + 0x0C)
/* GPIOB */
#define GPIOB_BASE	 0x40010C00
#define GPIOB_CRL    *(volatile uint32_t*)(GPIOB_BASE + 0x00)
#define GPIOB_CRH    *(volatile uint32_t*)(GPIOB_BASE + 0x04)
#define GPIOB_IDR    *(volatile uint32_t*)(GPIOB_BASE + 0x08)
#define GPIOB_ODR    *(volatile uint32_t*)(GPIOB_BASE + 0x0C)



void Clock_Init (void)
{
	/* GPIOA clock enable */
	RCC_APB2ENR |= (1 << 2);
	/* GPIOB clock enable */
	RCC_APB2ENR |= (1 << 3);
}

void GPIO_Init (void)
{
	/* PA1  >> floating input   */
	/* 00: Input mode (reset state) */
	GPIOA_CRL |= (0b00 << 4);
	/* 01: Floating input (reset state) */
	GPIOA_CRL |= (0b01 << 6);

	/* PA13 >> floating input   */
	/* 00: Input mode (reset state) */
	GPIOA_CRH |= (0b00 << 20);
	/* 01: Floating input (reset state) */
	GPIOA_CRH |= (0b01 << 22);

	/* PB1  >> push-pull output */
	/* 01: Output mode, max speed 10 MHz */
	GPIOB_CRL |= (0b01 << 4);
	/* 00: General purpose output push-pull */
	GPIOB_CRL &= ~(0b11 << 6);

	/* PB13 >> push-pull output */
	/* 01: Output mode, max speed 10 MHz */
	GPIOB_CRH |= (0b01 << 20);
	/* 00: General purpose output push-pull */
	GPIOB_CRH &= ~(0b11 << 22);

}

void Wait_ms (uint32_t time)
{
	uint32_t i, j;
	for(i = 0; i < time; i++)
		for(j = 0; j < 255; j++);
}

int main(void)
{
	/* Call initialization functions */
	Clock_Init();
	GPIO_Init ();

	/* Functionality */
	/*
	 * Single-pressing on PA1 >> Toggle LED on PB1,,  PA1  >> Pulled-up externally
	 * Multi-pressing on PA13 >> Toggle LEd on PB13,, PA13 >> Pulled-down externally
	*/
	while(1)
	{
		/* Single-pressing on PA1 >> Toggle LED on PB1,,  PA1  >> Pulled-up externally */
		/* Get PA1 */
		if (((GPIOA_IDR & (1 << 1)) >> 1) == 0)
		{
			/* Toggle PB1 */
			GPIOB_ODR ^= (1 << 1);
			while (((GPIOA_IDR & (1 << 1)) >> 1) == 0);
		}

		/* Multi-pressing on PA13 >> Toggle LEd on PB13,, PA13 >> Pulled-down externally */
		/* Get PA13 */
		if (((GPIOA_IDR & (1 << 13)) >> 13) == 1)
		{
			/* Toggle PB13 */
			GPIOB_ODR ^= (1 << 13);
		}

		Wait_ms (1);
	}
}

