/*
 * Ass_2.c
 *
 *  Created on: Aug 25, 2020
 *      Author: Mai Mousa
 */


#include <stdio.h>

int main (void)
{
	int num;

	printf("##########Console-output###\nEnter an integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &num);
	printf("You entered: %d\n###########################", num);


	return 0;
}

