 /* ATMEGA32 MCU */
 /* Turn on 3 LEDs incrementally on each key press */
 #include "MemMap.h"
 #include "Utils.h"
 #define F_CPU 8000000UL
 #include <util/delay.h>
 
 
 int main (void)
 {
 	unsigned int flag = 0;
 	/* Configure portD pins 5, 6, 7 as output */
	DDRD |= (0b111 << 5);
    /* Configure portD pins 0 as input */
	DDRD &= ~(1 << 0);
 	
 	while(1)
 	{
 		if (GetBit(PIND,0) == 1)
 		{
 			flag++;
 			while (GetBit(PIND,0) == 1);
 		}
 		
 		if      (flag == 1)	 { SetBit(PORTD,5);	_delay_ms(100); }
 		else if (flag == 2)  { SetBit(PORTD,6);	_delay_ms(100); }
 		else if (flag == 3)  { SetBit(PORTD,7);	_delay_ms(100); }
 		else                 flag = 0;
 	}
 	return 0;
 }