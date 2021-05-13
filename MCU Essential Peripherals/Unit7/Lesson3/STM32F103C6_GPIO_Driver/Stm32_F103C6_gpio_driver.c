/*
 * Stm32_F103C6_gpio_driver.c
 *
 *  Created on: May 5, 2021
 *      Author: Mai Mousa
 */

#include "Stm32_F103C6_gpio_driver.h"

uint8_t Get_CRLH_Position (uint16_t PinNumber)
{
	switch (PinNumber)
	{
	case GPIO_PIN_0:     return 0;     break;
	case GPIO_PIN_1:     return 4;     break;
	case GPIO_PIN_2:     return 8;     break;
	case GPIO_PIN_3:     return 12;    break;
	case GPIO_PIN_4:     return 16;    break;
	case GPIO_PIN_5:     return 20;    break;
	case GPIO_PIN_6:     return 24;    break;
	case GPIO_PIN_7:     return 28;    break;
	case GPIO_PIN_8:     return 0;     break;
	case GPIO_PIN_9:     return 4;     break;
	case GPIO_PIN_10:    return 8;     break;
	case GPIO_PIN_11:    return 12;    break;
	case GPIO_PIN_12:    return 16;    break;
	case GPIO_PIN_13:    return 20;    break;
	case GPIO_PIN_14:    return 24;    break;
	case GPIO_PIN_15:    return 28;    break;
	}
	return 0;
}


/*
 * @Fn         - MCAL_GPIO_Init
 * @brief      - Initializes the GPIOx PINy according to the specified parameters in the PinConfig
 * @param [in] - GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
 * @param [in] - PinConfig: pointer to a GPIO_PinConfig_t structure that contains the configuration
                            information for the specified GPIO pin
 * @retval     - None
 * Note        - STM32F103C6 MCU has GPIO A,B,C,D,E modules but LQFP48 package has only GPIO A,B,
                 part of C,D exported as external pins from the MCU
*/
void MCAL_GPIO_Init (GPIO_Typedef* GPIOx, GPIO_PinConfig_t* PinConfig)
{
	/* Port configuration register low  (GPIOx_CRL) configures pins from 0 >>> 7  */
	/* Port configuration register high (GPIOx_CRH) configures pins from 8 >>> 15 */
	volatile uint32_t* configregister = NULL;
	uint8_t PIN_Config = 0;

	/* Select CRL or CRH to configure */
	configregister = (PinConfig->GPIO_PinNumber < GPIO_PIN_8)? &GPIOx->CRL : &GPIOx->CRH ;

	/* Clear CNF[1:0] MODE[1:0] */
	(*configregister) &= ~(0xf << Get_CRLH_Position(PinConfig->GPIO_PinNumber));

	/* If pin is output */
	if((PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP))
	{
		/* Set CNF[1:0] MODE[1:0] */
		PIN_Config = ( (((PinConfig->GPIO_MODE - 4) << 2) | (PinConfig->GPIO_Output_Speed)) & 0x0f );
		/* Write on CRL or CRH */
		(*configregister) |= ( (PIN_Config) << Get_CRLH_Position(PinConfig->GPIO_PinNumber) );
	}
	/* If pin is input */
	else /* MODE = 00: input mode (reset state) */
	{
		if ((PinConfig->GPIO_MODE == GPIO_MODE_ANALOG) || (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO))
		{
			/* Set CNF[1:0] MODE[1:0] */
			PIN_Config = ( (((PinConfig->GPIO_MODE) << 2) | 0x0) & 0x0f );
			/* Write on CRL or CRH */
			(*configregister) |= ( (PIN_Config) << Get_CRLH_Position(PinConfig->GPIO_PinNumber) );
		}
		else if (PinConfig->GPIO_MODE == GPIO_MODE_AF_INPUT) /* Consider it as input floating */
		{
			/* Set CNF[1:0] MODE[1:0] */
			PIN_Config = ( (((GPIO_MODE_INPUT_FLO) << 2) | 0x0) & 0x0f );
			/* Write on CRL or CRH */
			(*configregister) |= ( (PIN_Config) << Get_CRLH_Position(PinConfig->GPIO_PinNumber) );
		}
		else /* PU or PD Input */
		{
			/* Set CNF[1:0] MODE[1:0] */
			PIN_Config = ( (((GPIO_MODE_INPUT_PU) << 2) | 0x0) & 0x0f );
			/* Write on CRL or CRH */
			(*configregister) |= ( (PIN_Config) << Get_CRLH_Position(PinConfig->GPIO_PinNumber) );

			if (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
			{
				/* PxODR = 1 Input pull-up: Table 20. Port bit configuration table */
				GPIOx->ODR |= PinConfig->GPIO_PinNumber;
			}
			else
			{
				/* PxODR = 0 Input pull-down: Table 20. Port bit configuration table */
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
			}
		}
	}
}


/*
 * @Fn         - MCAL_GPIO_DeInit
 * @brief      - Resets all the GPIO registers
 * @param [in] - GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
 * @retval     - None
 * Note        - None
*/
void MCAL_GPIO_DeInit (GPIO_Typedef* GPIOx)
{
/*	GPIOx->BRR  = 0x00000000;
	GPIOx->BSRR = 0x00000000;
	GPIOx->CRL  = 0x44444444;
	GPIOx->CRH  = 0x44444444;
	// GPIOx->IDR; Read only
	GPIOx->LCKR = 0x00000000;
	GPIOx->ODR  = 0x00000000;
*/
	/* Or you can use the reset controller */
	/* APB2 peripheral reset register (RCC_APB2RSTR) */
	/* Set and cleared by software */

	if (GPIOx == GPIOA)
	{
		RCC->APB2RSTR |= (1<<2);  /* Bit 2 IOPARST: IO port A reset */
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if (GPIOx == GPIOB)
	{
		RCC->APB2RSTR |= (1<<3);  /* Bit 3 IOPBRST: IO port B reset */
		RCC->APB2RSTR &= ~(1<<3);
	}
	else if (GPIOx == GPIOC)
	{
		RCC->APB2RSTR |= (1<<4);  /* Bit 4 IOPCRST: IO port C reset */
		RCC->APB2RSTR &= ~(1<<4);
	}
	else if (GPIOx == GPIOD)
	{
		RCC->APB2RSTR |= (1<<5);  /* Bit 5 IOPDRST: IO port D reset */
		RCC->APB2RSTR &= ~(1<<5);
	}
	else if (GPIOx == GPIOE)
	{
		RCC->APB2RSTR |= (1<<6);  /* Bit 6 IOPERST: IO port D reset */
		RCC->APB2RSTR &= ~(1<<6);
	}
}

/*
 * @Fn         - MCAL_GPIO_ReadPin
 * @brief      - Reads specific pin
 * @param [in] - GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
 * @param [in] - PinNumber: set pin number according to @ref GPIO_PINS_define
 * @retval     - The input pin value (two values based on @ref GPIO_PIN_state)
 * Note        - None
*/
uint8_t MCAL_GPIO_ReadPin (GPIO_Typedef* GPIOx, uint16_t PinNumber)
{
	uint8_t bitstatus;
	if( ((GPIOx->IDR) & PinNumber) != (uint32_t)GPIO_PIN_RESET)
	{
		bitstatus = GPIO_PIN_SET;
	}
	else
	{
		bitstatus = GPIO_PIN_RESET;
	}
	return bitstatus;
}

/*
 * @Fn         - MCAL_GPIO_ReadPort
 * @brief      - Reads the input port value
 * @param [in] - GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
 * @retval     - The input port value
 * Note        - None
*/
uint16_t MCAL_GPIO_ReadPort (GPIO_Typedef* GPIOx)
{
	uint16_t port_value;
	port_value = (uint16_t) (GPIOx->IDR);
	return port_value;
}

/*
 * @Fn         - MCAL_GPIO_WritePin
 * @brief      - Writes on specific input pin
 * @param [in] - GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
 * @param [in] - PinNumber: specifies the port bit to read and set by @ref GPIO_PINS_define
 * @param [in] - Value: pin value
 * @retval     - None
 * Note        - None
*/
void MCAL_GPIO_WritePin (GPIO_Typedef* GPIOx, uint16_t PinNumber, uint8_t Value)
{
	if (Value != GPIO_PIN_RESET)
	{
		/* GPIOx->ODR |= PinNumber; */
		/* Or */
		/*
		Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
		These bits are write-only and can be accessed in Word mode only.
		0: No action on the corresponding ODRx bit
		1: Set the corresponding ODRx bit
		*/
		GPIOx->BSRR = (uint32_t)PinNumber;
	}
	else
	{
		/* GPIOx->ODR &= ~(PinNumber); */
		/* Or */
		/*
		Bits 15:0 BRy: Port x Reset bit y (y= 0 .. 15)
		These bits are write-only and can be accessed in Word mode only.
		0: No action on the corresponding ODRx bit
		1: Reset the corresponding ODRx bit
		*/
		GPIOx->BRR = (uint32_t)PinNumber;
	}
}

/*
 * @Fn         - MCAL_GPIO_WritePort
 * @brief      - Writes on output port
 * @param [in] - GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
 * @param [in] - Value: port value
 * @retval     - None
 * Note        - None
*/
void MCAL_GPIO_WritePort (GPIO_Typedef* GPIOx, uint16_t Value)
{
	GPIOx->ODR = (uint32_t) Value;
}

/*
 * @Fn         - MCAL_GPIO_TogglePin
 * @brief      - Toggles the specified GPIO pin
 * @param [in] - GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
 * @param [in] - PinNumber: specifies the port bit to toggle and set by @ref GPIO_PINS_define
 * @retval     - None
 * Note        - None
*/
void MCAL_GPIO_TogglePin (GPIO_Typedef* GPIOx, uint16_t PinNumber)
{
	GPIOx->ODR ^= (PinNumber);
}

/*
 * @Fn         - MCAL_GPIO_LockPin
 * @brief      - The locking mechanism allows the IO configuration to be frozen
 * @param [in] - GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral
 * @param [in] - PinNumber: specifies the port bit to lock and set by @ref GPIO_PINS_define
 * @retval     - OK if pin config is locked or ERROR if pin is not locked
                 (OK & ERROR are defined @ref GPIO_RETURN_LOCK)
 * Note        - None
*/
uint8_t MCAL_GPIO_LockPin (GPIO_Typedef* GPIOx, uint16_t PinNumber)
{
	/*
	Bit 16 LCKK[16]: Lock key
	This bit can be read any time. It can only be modified using the Lock Key Writing Sequence.
	0: Port configuration lock key not active
	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.

	LOCK key writing sequence:
	* Write 1	* Write 0	* Write 1	* Read 0	* Read 1 (this read is optional but confirms that the lock is active)
	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	Any error in the lock sequence will abort the lock.

	Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
	These bits are read write but can only be written when the LCKK bit is 0.
	0: Port configuration not locked
	1: Port configuration locked.
	*/

	/* Set LCKK[16] */
	volatile uint32_t tmp = 1<<16;
	/* Set LCKy */
	tmp |= PinNumber;
	/* Write 1 */
	GPIOx->LCKR = tmp;
	/* Write 0 */
	GPIOx->LCKR = PinNumber;
	/* Write 1 */
	GPIOx->LCKR = tmp;
	/* Read 0  */
	tmp = GPIOx->LCKR;
	/* Read 1 (this read is optional but confirms that the lock is active) */
	if((uint32_t)(GPIOx->LCKR & 1<<16))
	{
		return GPIO_RETURN_LOCK_ENABLED;
	}
	else
	{
		return GPIO_RETURN_LOCK_ERROR;
	}
}
