/*
 * Ass4_4.c
 *
 *  Created on: Sep 9, 2020
 *      Author: Mai Mousa
 */

#include <stdio.h>

int power (int base, int expo)
{
	int pow;

	if   (expo == 0)	{ pow = 1; }
	else                { pow = base * power(base, expo-1); }

	return pow;
}

int main (void)
{
	int base, expo;

	printf("Enter base number: ");
	fflush(stdin);		fflush(stdout);
	scanf("%d", &base);

	printf("Enter power number (positive integer): ");
	fflush(stdin);		fflush(stdout);
	scanf("%d", &expo);

	printf("%d^%d = %d\n", base, expo, power (base, expo));
	return 0;
}


