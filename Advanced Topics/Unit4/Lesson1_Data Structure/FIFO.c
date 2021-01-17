/*
 * FIFO.c
 *
 *  Created on: Jan 17, 2021
 *      Author: Mai Mousa
 */

#include <stdio.h>
#include "Platform_Types.h"

/* User configuration */
/* Select the element type ... */
#define Element_Type uint8
/* Create a static buffer ...  */
#define Buffer_Length 5
Element_Type Buffer[Buffer_Length];


/* FIFO data types */
typedef struct 
{
	uint32 length;
	Element_Type* base;
	Element_Type* head;
	Element_Type* tail;
	uint32 count;
} FIFO_Buff_t;

typedef enum
{
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_null
} Buffer_Status;

/* FIFO APIs */
Buffer_Status FIFO_Init    (FIFO_Buff_t* Buff, Element_Type* Buffer, uint32 Buff_Length);
Buffer_Status FIFO_IsFull  (FIFO_Buff_t* Buff);
Buffer_Status FIFO_Enqueue (FIFO_Buff_t* Buff, Element_Type* ENQ_Data);
Buffer_Status FIFO_Dequeue (FIFO_Buff_t* Buff, Element_Type* DEQ_Data);
void FIFO_Print (FIFO_Buff_t* Buff);


int main (void)
{
	FIFO_Buff_t VirtualBuffer;
	Element_Type i;
	Element_Type* temp;
	uint8 t1;
	/* Initialize */
	if (FIFO_Init (&VirtualBuffer, Buffer, Buffer_Length) == FIFO_no_error)	            printf("FIFO initialization ... DONE\n");
	
	/* Enqueue */
	for (i = 0; i < 7; i++)	
	{ 
		if       (FIFO_Enqueue (&VirtualBuffer, &i) == FIFO_no_error)	printf("FIFO Enqueue (%d) ... DONE\n", i);
		else if  (FIFO_Enqueue (&VirtualBuffer, &i) == FIFO_full)       printf("FIFO Enqueue (%d) ... FAILED ... Full FIFO\n", i);
	}
	/* Print */
	printf("\n\nFIFO print: \n");
	FIFO_Print (&VirtualBuffer);
	printf("\n\n");
	/* Dequeue */
	for (i = 0; i < 2; i++)
	{
		if       (FIFO_Dequeue (&VirtualBuffer, &t1) == FIFO_no_error)	  printf("FIFO Dequeue (%d) ... DONE\n", t1); 
		else if  (FIFO_Dequeue (&VirtualBuffer, &t1) == FIFO_empty)	      printf("FIFO Dequeue ... FAILED ... Empty FIFO\n");
	}
	/* Enqueue */
	for (i = 5; i < 7; i++)	
	{ 
		if       (FIFO_Enqueue (&VirtualBuffer, &i) == FIFO_no_error)	 printf("FIFO Enqueue (%d) ... DONE\n", i);
		else if  (FIFO_Enqueue (&VirtualBuffer, &i) == FIFO_full)        printf("FIFO Enqueue (%d) ... FAILED ... Full FIFO\n", i);
	}
	/* Print */
	printf("\n\nFIFO print: \n");
	FIFO_Print (&VirtualBuffer);
	
	return 0;
}

Buffer_Status FIFO_Init (FIFO_Buff_t* Buff, Element_Type* Buffer, uint32 Buff_Length)
{
	Buff -> base = Buffer;	
	Buff -> head = Buff -> base;
	Buff -> tail = Buff -> base;
	Buff -> length = Buff_Length;
	Buff -> count = 0;
	return FIFO_no_error;
}

Buffer_Status FIFO_IsFull  (FIFO_Buff_t* Buff)
{
	if (!Buff -> base || !Buff -> head || !Buff -> tail)	   return FIFO_null;  /* Check if FIFO is valid */	
	if (Buff -> count >= Buff -> length)					   return FIFO_full;
	else 													   return FIFO_no_error;
}

Buffer_Status FIFO_Enqueue (FIFO_Buff_t* Buff, Element_Type* ENQ_Data)
{
	if (!Buff -> base || !Buff -> head || !Buff -> tail)	return FIFO_null;  /* Check if FIFO is valid */	
	if (FIFO_IsFull(Buff) == FIFO_full)						return FIFO_full;  /* Check if FIFO is full  */
	/* Enqueue */
	/* Assign data */
	*(Buff -> head) = *ENQ_Data;	
	/* Check if head reached the end of the buffer or not */
	if ( (Buff -> head) == ( (Buff -> base) + ((Buff -> length) * (sizeof(Element_Type)))) )	    Buff -> head = Buff -> base; 
	else 
	{
		Buff -> head ++; 
		if ( (Buff -> head) == ( (Buff -> base) + ((Buff -> length) * (sizeof(Element_Type)))) )	Buff -> head = Buff -> base;  
	}
	/* Increase count */
	Buff -> count ++; 
	return FIFO_no_error;
}

Buffer_Status FIFO_Dequeue (FIFO_Buff_t* Buff, Element_Type* DEQ_Data)
{
	if (!Buff -> base || !Buff -> head || !Buff -> tail)	return FIFO_null;   /* Check if FIFO is valid  */	
	if (FIFO_IsFull(Buff) == FIFO_empty)					return FIFO_empty;  /* Check if FIFO is empty  */  
	/* Dequeue */
	/* Get data */
	*DEQ_Data = *(Buff -> tail);  
	/* Check if tail reached the end of the buffer or not */
	if ( (Buff -> tail) == ( (Buff -> base) + ((Buff -> length) * (sizeof(Element_Type)))) )	{Buff -> tail = Buff -> base; }
	else Buff -> tail ++;
	/* Increase count */
	Buff -> count --;
	return FIFO_no_error;
}

void FIFO_Print (FIFO_Buff_t* Buff)
{	
	Element_Type* temp = Buff -> base;
	uint32 i;

	for(i = 0; i < Buff -> length; i++)	{	printf("%d: %d\n", i, *temp);	temp++;	  }
}
