/*
 * Ass2_1.c
 *
 *  Created on: Aug 25, 2020
 *      Author: Mai Mousa
 */


#include <stdio.h>

int main (void)
{
	int num;

	printf("Enter an integer you want to check: ");
	fflush (stdin);     fflush(stdout);
	scanf("%d", &num);

	/* Checking if even or odd */
	if (num % 2 == 0) 	printf("%d is even.\n", num);
	else 				printf("%d is odd. \n", num);

	return 0;
}


