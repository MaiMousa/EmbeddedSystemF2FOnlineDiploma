/*
 * Ass3_Array4.c
 *
 *  Created on: Sep 2, 2020
 *      Author: Mai Mousa
 */


#include <stdio.h>

int main (void)
{
	int num, a[100], i, insert, location, temp1, temp2;

	printf("Enter no of elements: ");
	fflush(stdin);	  fflush(stdout);
	scanf("%d", &num);

	for (i = 0; i < num; i++)
	{ fflush(stdin);	fflush(stdout);  scanf("%d", &a[i]); }

	printf("Enter the element to be inserted : ");
	fflush(stdin);	   fflush(stdout);     scanf("%d", &insert);
	printf("Enter the location : ");
	fflush(stdin);	   fflush(stdout);     scanf("%d", &location);

	temp1 = a[location -1];  a[location -1] = insert;

	for(i = location; i < num; i++)
	{
		temp2 = a[i];
		a[i] = temp1;
		temp1 = temp2;
	}   a[num] = temp1;

	for(i = 0; i <= num; i++)	{ printf("%d\t", a[i]); }
	return 0;
}


