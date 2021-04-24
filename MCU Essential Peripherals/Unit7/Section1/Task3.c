 /* ATMEGA32 MCU */
 /* Turn on 3 LEDs but not incrementally on each key press */
 /*	LED1 LED2 LED3
     1    0    0
     0    1    0
     0    0    1
 */
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
 			_delay_ms(200);
 		}
 		
 		if      (flag == 1)	 { PORTD = (0b001 << 5); 	_delay_ms(100); }
 		else if (flag == 2)  { PORTD = (0b010 << 5);	_delay_ms(100); }
 		else if (flag == 3)  { PORTD = (0b100 << 5);	_delay_ms(100); }
 		else                   flag = 0;
 	}
 	return 0;
 }