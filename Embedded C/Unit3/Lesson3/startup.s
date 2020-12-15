/*
	startup_CortexM3.s
	Mai Mousa
	Unit2_Lesson3_Lab2
*/


/* SRAM 0x20000000 */

.section	.vectors
.word		0x20001000			/* stack top address */
.word		_reset				/* Reset             */
.word		Vector_handler      /* NMI               */
.word		Vector_handler      /* Hard Fault        */
.word		Vector_handler      /* MM Fault          */
.word		Vector_handler      /* Bus Fault         */
.word		Vector_handler      /* Usage Fault       */
.word		Vector_handler      /* Reserved          */
.word		Vector_handler      /* Reserved          */
.word		Vector_handler      /* Reserved          */
.word		Vector_handler      /* Reserved          */
.word		Vector_handler      /* SV Call           */
.word		Vector_handler      /* Debug Monitor     */
.word		Vector_handler      /* Reserved          */
.word		Vector_handler      /* PendSV            */
.word		Vector_handler      /* SysTick           */
.word		Vector_handler      /* PendSV            */
.word		Vector_handler      /* WWDG              */
.word		Vector_handler      /* PVD               */
.word		Vector_handler      /* TAMPER            */
.word		Vector_handler      /* RTC               */
.word		Vector_handler      /* FLASH             */
.word		Vector_handler      /* RCC               */
.word		Vector_handler      /* EXTI0             */
.word		Vector_handler      /* EXTI1             */
.word		Vector_handler      /* EXTI2             */


.section	.text
_reset:
	bl main
	b  .

.thumb_func
Vector_handler:
	b _reset
