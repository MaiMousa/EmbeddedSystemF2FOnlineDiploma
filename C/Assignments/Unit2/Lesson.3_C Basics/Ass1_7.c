/*
 * Ass_7.c
 *
 *  Created on: Aug 25, 2020
 *      Author: Mai Mousa
 */

#include <stdio.h>

int main (void)
{
	int a, b;

	printf("##########Console-output###\nEnter value of a: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &a);
	printf("Enter value of b: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &b);

	/* Swapping Code */
	/* Method 1 */
//	a = a + b;
//	b = a - b;
//	a = a - b;

	/* Method 2 */
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;

	printf("\nAfter swapping, value of a = %d\nAfter swapping, "
		   "value of b = %d\n###########################", a, b);

	return 0;
}



