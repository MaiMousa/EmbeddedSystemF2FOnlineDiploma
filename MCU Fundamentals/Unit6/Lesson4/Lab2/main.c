/* Functionality:
 Toggle LED on PD7 on any logical change on INT0
 PD7 >> output
 PD2 >> input and external interrupt 0
 */

#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>


#define GICR	*(volatile uint8_t*)(0x5B)
#define SFIOR   *(volatile uint8_t*)(0x50)
#define MCUCR   *(volatile uint8_t*)(0x55)
#define SREG    *(volatile uint8_t*)(0x5F)
#define DDRD    *(volatile uint8_t*)(0x31)  /* RW */
#define PORTD   *(volatile uint8_t*)(0x32)  /* RW */
#define PIND    *(volatile uint8_t*)(0x30)	/* Read only */


void GPIO_Init (void)
{
	/* PD7 >> output >> write '1' on DDRD */
	DDRD |= (1 << 7);
	/* PD2 >> input >> write '0' on DDRD & INT0 (Alternative) */
	DDRD &= ~(1 << 2);
}

void INT0_Init (void)
{
	/* Configure interrupt sense control for INT0 (any logical change) */
	MCUCR |= 0x01;
	/* Enable INT0 */
	GICR |= (1 << 6);
	/* Enable global interrupt register */
	SREG |= (1 << 7);
}

ISR(INT0_vect)
{
	PORTD |= (1 << 7);
	_delay_ms(1000);
	PORTD &= ~(1 << 7);
	_delay_ms(1000);
}

int main (void)
{
	GPIO_Init();
	INT0_Init();

	while(1);
	return 0;
}
