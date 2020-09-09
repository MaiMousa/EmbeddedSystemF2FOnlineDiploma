/*
 * Ass3_String3.c
 *
 *  Created on: Sep 3, 2020
 *      Author: Mai Mousa
 */

#include <stdio.h>

int main (void)
{
	char text[30], temp;
	int length = 0, i;

	printf("Enter the string: ");
	fflush(stdin);	fflush(stdout);
	gets(text);

	while(text[length] != 0)		{ length++; }

	for(i = 0; i < length/2; i++)
	{
		temp = text[i];
		text[i] = text[length - (i + 1)];
		text[length - (i + 1)] = temp;
	}

	printf("Reverse string is: %s", text);

	return 0;
}

