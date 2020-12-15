/*
	startup.c
	Mai Mousa
	Unit2_Lesson3_Lab2
*/

#include "Platform_Types.h"

extern int main (void);

extern uint32 _E_text;
extern uint32 _S_data;
extern uint32 _E_data;
extern uint32 _S_bss;
extern uint32 _E_bss;

extern uint32 _stack_top;

void Reset_Handler   (void);
void Default_Handler (void)	{ Reset_Handler(); }

void NMI_Handler         (void) __attribute__ ((weak, alias("Default_Handler")));;
void H_Fault_Handler     (void) __attribute__ ((weak, alias("Default_Handler")));;
void MM_Fault_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));;
void Bus_Fault_Handler   (void) __attribute__ ((weak, alias("Default_Handler")));;
void Usage_Fault_Handler (void) __attribute__ ((weak, alias("Default_Handler")));;

uint32 vectors [] __attribute__ ((section(".vectors"))) = {
	(uint32) &_stack_top,
	(uint32) &Reset_Handler,
	(uint32) &NMI_Handler,
	(uint32) &H_Fault_Handler,
	(uint32) &MM_Fault_Handler,
	(uint32) &Bus_Fault_Handler,
	(uint32) &Usage_Fault_Handler
};

void Reset_Handler   (void) 
{
	uint32 i;
	/* Copy data section from flash to ram */
	uint32 data_size = (uint8*)&_E_data - (uint8*)&_S_data;
	uint8* P_src = (uint8*)&_E_text;
	uint8* P_dst = (uint8*)&_S_data;

	for (i = 0; i < data_size; i++)
		*((uint8*)P_dst++) = *((uint8*)P_src++);

	/* Init .bss section in SRAM = 0 */
	uint32 bss_size = (uint8*)&_E_bss - (uint8*)&_S_bss;
	P_dst = (uint8*)&_S_bss;

	for (i = 0; i < bss_size; i++)
		*((uint8*)P_dst++) = (uint8) 0;

	/* Jump to main */ 
	main();          
}
