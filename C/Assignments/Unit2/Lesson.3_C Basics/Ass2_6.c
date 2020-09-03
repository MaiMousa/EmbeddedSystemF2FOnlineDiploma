/*
 * Ass2_6.c
 *
 *  Created on: Aug 25, 2020
 *      Author: Mai Mousa
 */

#include <stdio.h>

int main (void)
{
	int num, i , sum = 0;

	printf("Enter an integer: ");
	fflush(stdin);   fflush(stdout);
	scanf("%d", &num);

	for (i = 0; i < num; i++)	{	sum = sum + i + 1;	}

	printf("Sum = %d", sum);

	return 0;
}


