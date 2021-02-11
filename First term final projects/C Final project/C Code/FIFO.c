#include "FIFO.h"
#include "system.h"

/* FIFO APIs Implementation */
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
	/* Decrease count */
	Buff -> count --;
	return FIFO_no_error;
}

void FIFO_Print (FIFO_Buff_t* Buff)
{	
	Element_Type* temp = Buff -> base;
	uint32 i;

	for(i = 0; i < GCount; i++)	/*GCount or Buff -> count*/
		{	
			printf("\n");
			printf("Student first name: %s\n"
				   "Student last name:  %s\n"
				   "Student roll number: %d\n"
				   "Student GPA number: %.2f\n"
				   "The courses IDs are: %d %d %d %d %d\n"
				   "----------------------------------------------\n",
				   temp -> fname, temp -> lname, temp -> roll, temp -> GPA, temp -> cid[0], temp -> cid[1], temp -> cid[2], 
				   temp -> cid[3], temp -> cid[4]);	
			temp++;	  
		}
}

