/*
 * Ass2_7.c
 *
 *  Created on: Aug 25, 2020
 *      Author: Mai Mousa
 */

#include <stdio.h>

int main (void)
{
	int num, i, fact = 1;

	printf("Enter an integer: ");
	fflush(stdin);   fflush(stdout);
	scanf("%d", &num);

	if (num < 0) 	printf("Error!!! Factorial of negative number doesn't exist.");
	else
	{
		/* Calculate factorial */
		for (i = 0; i < num; i++)	{	fact = fact * (i+1);	}
		printf("Factorial = %d", fact);
	}

	return 0;
}

