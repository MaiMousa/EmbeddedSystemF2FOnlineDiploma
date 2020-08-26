/*
 * Ass2_4.c
 *
 *  Created on: Aug 25, 2020
 *      Author: Mai Mousa
 */

#include <stdio.h>

int main (void)
{
	float num, mul;
	printf("Enter a number: ");
	fflush(stdin);    fflush(stdout);
	scanf("%f", &num);

	/* Checking */
	mul = num * -1;
	if      (mul > 0) printf("%.2f is negative.", num);
	else if (mul < 0) printf("%.2f is positive.", num);
	else              printf("You entered zero.");

	return 0;
}


