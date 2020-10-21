/*
 * Ass6_3.c
 *
 *  Created on: Oct 21, 2020
 *      Author: Mai Mousa
 */


#include <stdio.h>
#include <string.h>

void reverse (char * text, int length)
{
	int i = 0, j = length - 1;
	char temp;

	while (i < j)
	{
		temp = text[i];	 text[i] = text[j];	text[j] = temp;
		i++; j--;
	}
}

int main (void)
{
	char text [30];

	printf("Input a string: ");
	fflush(stdin);	fflush(stdout);	  gets(text);

	reverse (text, strlen(text));

	printf("Reverse of the string is: %s", text);
	return 0;
}
