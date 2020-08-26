/*
 * Ass_4.c
 *
 *  Created on: Aug 25, 2020
 *      Author: Mai Mousa
 */


#include <stdio.h>

int main (void)
{
	float num1, num2, mul;

	printf("##########Console-output###\n\n###########################\nEnter two numbers: ");
	fflush(stdin); fflush(stdout);
	scanf("%f%f", &num1, &num2);
	mul = num1 * num2;
	printf("Product: %f", mul);


	return 0;
}


