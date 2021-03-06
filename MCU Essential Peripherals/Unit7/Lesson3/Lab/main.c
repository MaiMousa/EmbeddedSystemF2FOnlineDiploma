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

/* Functionality */
/*
 * Single-pressing on PA1 >> Toggle LED on PB1,,  PA1  >> Pulled-up externally
 * Multi-pressing on PA13 >> Toggle LEd on PB13,, PA13 >> Pulled-down externally
*/

#include "stm32f103x6.h"
#include "Stm32_F103C6_gpio_driver.h"

void Clock_Init (void)
{
	/* GPIOA clock enable */
	RCC_GPIOA_CLK_EN();
	/* GPIOB clock enable */
	RCC_GPIOB_CLK_EN();
}

void GPIO_Init (void)
{
	/* PA1  >> floating input   */
	GPIO_PinConfig_t PA1_Config = {GPIO_PIN_1, GPIO_MODE_INPUT_FLO};
	MCAL_GPIO_Init (GPIOA, &PA1_Config);

	/* PA13 >> floating input   */
	GPIO_PinConfig_t PA13_Config = {GPIO_PIN_13, GPIO_MODE_INPUT_FLO};
	MCAL_GPIO_Init (GPIOA, &PA13_Config);

	/* PB1  >> push-pull output */
	GPIO_PinConfig_t PB1_Config = {GPIO_PIN_1, GPIO_MODE_OUTPUT_PP, GPIO_SPEED_10M};
	MCAL_GPIO_Init (GPIOB, &PB1_Config);

	/* PB13 >> push-pull output */
	GPIO_PinConfig_t PB13_Config = {GPIO_PIN_13, GPIO_MODE_OUTPUT_PP, GPIO_SPEED_10M};
	MCAL_GPIO_Init (GPIOB, &PB13_Config);
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
	/* Clock enable */
	Clock_Init ();
	GPIO_Init ();

	while(1)
	{
		/* Single-pressing on PA1 >> Toggle LED on PB1,,  PA1  >> Pulled-up externally */
		/* Get PA1 */
		if(MCAL_GPIO_ReadPin (GPIOA, GPIO_PIN_1) == 0)
		{
			/* Toggle PB1 */
			MCAL_GPIO_TogglePin (GPIOB, GPIO_PIN_1);
			while (MCAL_GPIO_ReadPin (GPIOA, GPIO_PIN_1) == 0);
		}

		/* Multi-pressing on PA13 >> Toggle LEd on PB13,, PA13 >> Pulled-down externally */
		/* Get PA13 */
		if(MCAL_GPIO_ReadPin (GPIOA, GPIO_PIN_13) == 1)
		{
			/* Toggle PB13 */
			MCAL_GPIO_TogglePin (GPIOB, GPIO_PIN_13);
		}
		Wait_ms (1);
	}
}

