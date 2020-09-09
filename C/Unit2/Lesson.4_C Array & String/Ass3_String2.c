/*
 * Ass3_String2.c
 *
 *  Created on: Sep 3, 2020
 *      Author: Mai Mousa
 */


#include <stdio.h>

int main (void)
{
	char text[100];
	int i;

	printf("Enter a string: ");
	fflush(stdin);	fflush(stdout);
	gets(text);

	i = 0;
	while(text[i] != '\0')		{ i++; }

	printf("Length of string: %d", i);
	return 0;
}


