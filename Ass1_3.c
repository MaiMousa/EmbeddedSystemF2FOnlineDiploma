/*
 * Ass_3.c
 *
 *  Created on: Aug 25, 2020
 *      Author: Mai Mousa
 */


#include <stdio.h>

int main (void)
{
	int num1, num2, sum = 0;

	printf("##########Console-output###\nEnter two integers: ");
	fflush(stdin); fflush(stdout);
	scanf("%d%d", &num1, &num2);
	sum = num1 + num2;
	printf("Sum: %d\n###########################", sum);


	return 0;
}


