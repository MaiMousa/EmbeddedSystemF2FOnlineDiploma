/*
 * Ass3_Array5.c
 *
 *  Created on: Sep 2, 2020
 *      Author: Mai Mousa
 */

#include <stdio.h>

int main (void)
{
	int elements, num[100], i, search, location;

	printf("Enter no of elements: ");
	fflush(stdin);    fflush(stdout);
	scanf("%d", &elements);

	for (i = 0; i < elements; i++)
	{
		fflush(stdin); 	fflush(stdout);  scanf("%d", &num[i]);
	}

	printf("Enter the elements to be searched: ");
	fflush(stdin);	  fflush(stdout);     scanf("%d", &search);

	for (i = 0; i < elements; i++)
	{	if (num[i] == search)	   location = i;	}

	if (location >= 0 && location < elements)
		printf("Number found at the location = %d\n", location+1);
	else
		printf("Number not found");
	return 0;
}


