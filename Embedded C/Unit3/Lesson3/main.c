/* Lab2: Toogle LED on STM32F103Cx */
/* Mai Mousa */
/* Unit2_Lesson3_Lab2 */


#include "Platform_Types.h"

#define RCC_BASE     0x40021000
#define GPIOA_BASE   0x40010800

extern void NMI_Handler         (void) { }
extern void Bus_Fault_Handler   (void) { }

typedef union 
{
	vuint32_t RCC_Reg;
	struct
	{
		vuint32_t        : 2;
		vuint32_t IOPAEN : 1;
	} RCC_Bit;
} RCC_Reg_t;

typedef union 
{
	vuint32_t GPIOA_Reg;
	struct
	{
		vuint32_t     : 13;
		vuint32_t ODR : 1;
		vuint32_t     : 6;
		vuint32_t CRH : 4;
	} GPIOA_Bit;
} GPIOA_Reg_t;

volatile RCC_Reg_t*   RCC_APB2ENR = (volatile RCC_Reg_t*  ) (RCC_BASE   + 0x18); 
volatile GPIOA_Reg_t* GPIOA_CRH   = (volatile GPIOA_Reg_t*) (GPIOA_BASE + 0x04); 
volatile GPIOA_Reg_t* GPIOA_ODR   = (volatile GPIOA_Reg_t*) (GPIOA_BASE + 0x0C);

uint8 g_variables[3] = {1, 2, 3};
uint8 const const_variables[3] = {1, 2, 3};
volatile uint8 gu_var [3];


int main (void)
{
	int i;
	RCC_APB2ENR->RCC_Bit.IOPAEN = 1;
	GPIOA_CRH->GPIOA_Bit.CRH = 2;

	while(1)
	{
		GPIOA_ODR->GPIOA_Bit.ODR = 1;
		for (i = 0; i < 5000; i++); 
		GPIOA_ODR->GPIOA_Bit.ODR = 0;
		for (i = 0; i < 5000; i++);
	}
}
