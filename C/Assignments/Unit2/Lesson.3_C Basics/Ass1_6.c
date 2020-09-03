/*
 * Ass_6.c
 *
 *  Created on: Aug 25, 2020
 *      Author: Mai Mousa
 */

#include <stdio.h>

int main (void)
{
	float a, b, temp;

	printf("##########Console-output###\nEnter value of a: ");
	fflush(stdin); fflush(stdout);
	scanf("%f", &a);
	printf("Enter value of b: ");
	fflush(stdin); fflush(stdout);
	scanf("%f", &b);

	/* Swapping Code */
	temp = a;
	a = b;
	b = temp;

	printf("\nAfter swapping, value of a = %.2f\nAfter swapping, "
		   "value of b = %.2f\n###########################", a, b);

	return 0;
}



