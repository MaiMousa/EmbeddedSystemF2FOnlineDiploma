#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "Platform_Types.h"

#define Element_Type struct sinfo

extern uint32 GCount;

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

FIFO_Buff_t VirtualBuffer;

/* FIFO APIs */
Buffer_Status FIFO_Init    (FIFO_Buff_t* Buff, Element_Type* Buffer, uint32 Buff_Length);
Buffer_Status FIFO_IsFull  (FIFO_Buff_t* Buff);
Buffer_Status FIFO_Enqueue (FIFO_Buff_t* Buff, Element_Type* ENQ_Data);
Buffer_Status FIFO_Dequeue (FIFO_Buff_t* Buff, Element_Type* DEQ_Data);
void   FIFO_Print  (FIFO_Buff_t* Buff);

#endif