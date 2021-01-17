/*
 * LIFO.c
 *
 *  Created on: Jan 17, 2021
 *      Author: Mai Mousa
 */

#include <stdio.h>
#include <stdlib.h>
#define LIFO_Buffer_Length 5

typedef struct
{
	unsigned int   length;
	unsigned char* base;
	unsigned char* head;
	unsigned int   count;
} LIFO_Buff_t;

typedef enum
{
	LIFO_no_error,
	LIFO_full,
	LIFO_not_full,
	LIFO_empty,
	LIFO_not_empty,
	LIFO_null
} Buffer_Status;

Buffer_Status LIFO_IsFull   (LIFO_Buff_t* Buff);
Buffer_Status LIFO_PushItem (LIFO_Buff_t* Buff, unsigned char item);
Buffer_Status LIFO_PopItem  (LIFO_Buff_t* Buff, unsigned char* item);

int main (void)
{
	int i;
	Buffer_Status ret;
	unsigned char pret;

	/* Stack Alloction */
	LIFO_Buff_t* DynamicAllocation;		             /* Pointer for dynamic allocation */
	LIFO_Buff_t  StaticAllocation;                   /* Pointer for static  allocation */
	unsigned StaticBuffer [LIFO_Buffer_Length];      /* Buffer for static allocation   */
	

	/* 1. Dynamic allocation: Dynamic allocation APIs (malloc) */
	DynamicAllocation  = (LIFO_Buff_t*) malloc (sizeof(LIFO_Buff_t));
	DynamicAllocation -> length = LIFO_Buffer_Length;
	DynamicAllocation -> base = (unsigned char*) DynamicAllocation;
	DynamicAllocation -> head = DynamicAllocation -> base; 
	DynamicAllocation -> count = 0;


	/* Pushing operation */
	printf("First_buffer (Dynamic allocation) LIFO_PushItem = ");
	for (i = 0; i < 5; i++)	{  if (LIFO_PushItem (DynamicAllocation, i)    == LIFO_no_error) 	printf("%d  ", i);	}
	//for (i = 0; i < 5; i++)	{  LIFO_PushItem (DynamicAllocation, i);	printf("%d  ", i);	   }
	printf("\n");
	/* Poping operation  */
	printf("First_buffer (Dynamic allocation) LIFO_PopItem  = ");
	for (i = 0; i < 5; i++)	{  if (LIFO_PopItem (DynamicAllocation, &pret) == LIFO_not_empty) 	printf("%d  ", pret);	}
	//for (i = 0; i < 5; i++)	{  LIFO_PopItem (DynamicAllocation, &pret); 	printf("%d  ", pret);  }
	printf("\n");
	
	/* 2. Static allocation:  Array */
	StaticAllocation.length = LIFO_Buffer_Length; 
	StaticAllocation.base   = (unsigned char*) StaticBuffer;
	StaticAllocation.head   = StaticAllocation.base;
	StaticAllocation.count  = 0;

	/* Pushing operation */
	printf("Second_buffer (Static allocation) LIFO_PushItem = ");
	for (i = 0; i < 5; i++)	{  if (LIFO_PushItem (&StaticAllocation, i)    == LIFO_no_error) 	printf("%d  ", i);	}
	//for (i = 0; i < 5; i++)	{  LIFO_PushItem (&StaticAllocation, i);	     printf("%d  ", i);	    }
	printf("\n");	
	/* Poping operation  */
	printf("Second_buffer (Static allocation) LIFO_PopItem  = ");
	for (i = 0; i < 5; i++)	{  if (LIFO_PopItem (&StaticAllocation, &pret) == LIFO_not_empty) 	printf("%d  ", pret);	}
	//for (i = 0; i < 5; i++)	{  LIFO_PopItem (&StaticAllocation, &pret); 	 printf("%d  ", pret);	}
	return 0;
}


Buffer_Status LIFO_IsFull  (LIFO_Buff_t* Buff)
{
	/* Check if pointer is valid */
	if (!Buff || !(Buff -> base) || !(Buff -> head))	               return LIFO_null;

	/* Check if LIFO is full */
	if   ( (Buff -> head) == ( (Buff -> base) + (Buff -> length)) )	   return LIFO_full;       
	else                                                           	   return LIFO_not_full;   
}

Buffer_Status LIFO_PushItem (LIFO_Buff_t* Buff, unsigned char item)
{
	/* Check if pointer is valid */
	if (!Buff || !(Buff -> base) || !(Buff -> head))	return LIFO_null;

	/* Check if LIFO is full */
	if (LIFO_IsFull (Buff) == LIFO_full)	            return LIFO_full;
	
	/* Add Item */
	*(Buff -> head) = item;	//printf("*(Buff -> head): %d  ", *(Buff -> head));
	(Buff -> head) ++;
	(Buff -> count) ++; 
	return LIFO_no_error;
}

Buffer_Status LIFO_PopItem (LIFO_Buff_t* Buff, unsigned char* item)
{
	/* Check if pointer is valid */
	if (!Buff || !(Buff -> base) || !(Buff -> head))	return LIFO_null;

	/* Check if LIFO is empty */
	if (Buff -> head == Buff -> base)	  return LIFO_empty;

	/* Pop item */
	(Buff -> head) --;	
	*item = *(Buff -> head); 
	(Buff -> count) ++;
	return LIFO_not_empty;
}
