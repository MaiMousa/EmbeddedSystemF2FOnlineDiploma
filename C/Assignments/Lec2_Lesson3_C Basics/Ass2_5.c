/*
 * Ass2_5.c
 *
 *  Created on: Aug 25, 2020
 *      Author: Mai Mousa
 */


#include <stdio.h>

int main (void)
{
	char c;

	printf("Enter a character: ");
	fflush(stdin);  fflush(stdout);
	scanf("%c", &c);

	if ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))  { printf("%c is an alphabet", c); }
	else                                                    { printf("%c is not an alphabet", c); }

	return 0;
}


