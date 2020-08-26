/*
 * Ass_5.c
 *
 *  Created on: Aug 25, 2020
 *      Author: Mai Mousa
 */


#include <stdio.h>

int main (void)
{
	char ch;

	printf("##########Console-output###\nEnter a character: ");
	fflush(stdin); fflush(stdout);
	scanf("%c", &ch);
	printf("ASCII value of %c = %d\n###########################", ch, ch);


	return 0;
}



