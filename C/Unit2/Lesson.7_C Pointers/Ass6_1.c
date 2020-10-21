/*
 * Ass6_1.c
 *
 *  Created on: Oct 21, 2020
 *      Author: Mai Mousa
 */


#include <stdio.h>

int main (void)
{
	int m = 29;
	int *ab = &m;

	printf("Address of m: 0x%p\nValue of m: %d\n", &m, m);
	printf("\n");

	printf("Now ab is assigned with the address of m.\n");
	printf("Address of pointer ab: 0x%p\n",  ab);
	printf("Content of pointer ab: %d  \n", *ab);
	printf("\n");

	m = 34;
	printf("The value of m assigned to 34 now.\n");
	printf("Address of pointer ab: 0x%p\n",  ab);
	printf("Content of pointer ab: %d  \n", *ab);
	printf("\n");

	*ab = 7;
	printf("The pointer variable ab is assigned with\n");
	printf("the value 7 now.\n");
	printf("Address of m: 0x%p\nValue of m: %d\n", &m, m);
	printf("\n");

	return 0;
}

