#include "uart.h"
#include "Platform_Types.h"

uint8 string_buffer[100] = "Learn-in-depth: Mai";
uint8 const string_buffer2[100] = "Hello";

void main (void)
{
	Uart_Send_String (string_buffer);
}