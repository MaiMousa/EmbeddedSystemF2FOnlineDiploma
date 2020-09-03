/*
 * Ass2_3.c
 *
 *  Created on: Aug 25, 2020
 *      Author: Mai Mousa
 */

#include <stdio.h>

int main (void)
{
	float num1, num2, num3, largest;

	printf("Enter three numbers: ");
	fflush(stdin);   fflush(stdout);
	scanf("%f%f%f", &num1, &num2, &num3);

	/* Finding the largest number */
	if      (num1 >= num2 && num1 >= num3)  largest = num1;
	else if (num2 >= num1 && num2 >= num3)  largest = num2;
	else if (num3 >= num1 && num3 >= num2)  largest = num3;

	printf("Largest number = %.2f", largest);

	return 0;
}



