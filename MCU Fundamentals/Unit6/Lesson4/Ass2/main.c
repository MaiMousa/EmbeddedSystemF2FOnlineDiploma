/* Functionality:
 INT0 : PD2 >> any logical change >> output PD5
 INT1 : PD3 >> rising edge        >> output PD6
 INT2 : PB2 >> falling edge       >> output PD7
 PD5, 6, 7 >> outputs
 PD2, 3 >> inputs
 PB2 >> input
 */

#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>


#define GICR	*(volatile uint8_t*)(0x5B)
#define SFIOR   *(volatile uint8_t*)(0x50)
#define MCUCR   *(volatile uint8_t*)(0x55)
#define MCUCSR  *(volatile uint8_t*)(0x54)
#define SREG    *(volatile uint8_t*)(0x5F)
#define DDRB    *(volatile uint8_t*)(0x38)
#define DDRD    *(volatile uint8_t*)(0x31)
#define PORTD   *(volatile uint8_t*)(0x32)
#define PIND    *(volatile uint8_t*)(0x30)



void GPIO_Init (void)
{
	/* PD2, 3 >> input,, PD5, 6, 7 >> output */
	DDRD |= 0xE0; /* 1110 0000 */
	/* PB2 >> input */
	DDRB &= ~(1 << 2);
}

void INT_Init (void)
{
	/* INT0 >> any logical change */
	/* INT1 >> rising edge */
	/* INT2 >> falling edge */

	/* Configure interrupt sense control for INT0, 1 */
	MCUCR |= 0x0D;	/* 0000 1101 */
	/* Configure interrupt sense control for INT2 */
	MCUCSR &= ~(1 << 6);
	/* Enable INT0, 1, 2 */
	GICR |= 0xE0;	/* 1110 0000 */
	/* Enable global interrupt register */
	SREG |= (1 << 7);
}

ISR(INT0_vect)
{
	/* Turn on LED for 1 sec */
	PORTD |= (1 << 5);
	_delay_ms(1000);
}

ISR(INT1_vect)
{
	/* Turn on LED for 1 sec */
	PORTD |= (1 << 6);
	_delay_ms(1000);
}

ISR(INT2_vect)
{
	/* Turn on LED for 1 sec */
	PORTD |= (1 << 7);
	_delay_ms(1000);
}

int main (void)
{
	GPIO_Init();
	INT_Init();

	while(1)
	{
		/* Turn off all LEDs */
		PORTD = 0x0;
	}
	return 0;
}
