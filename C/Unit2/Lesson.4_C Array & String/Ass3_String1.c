/*
 * Ass3_String1.c
 *
 *  Created on: Sep 3, 2020
 *      Author: Mai Mousa
 */

#include <stdio.h>

int main (void)
{
	char text[30];
	char search;
	int i, j;

	printf("Enter a string: ");
	fflush(stdin);	fflush(stdout);
	gets(text);

	printf("Enter a character to find frequency: ");
	fflush(stdin);	fflush(stdout);
	search = getchar();

	i = 0;	j = 0;
	while(text[i] != 0)
	{
		if (search == text[i])	{ j++; }
		i++;
	}

	printf("Frequency of %c = %d\n", search, j);

	return 0;
}
