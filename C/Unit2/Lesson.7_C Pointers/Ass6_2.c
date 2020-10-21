/*
 * Ass6_2.c
 *
 *  Created on: Oct 21, 2020
 *      Author: Mai Mousa
 */

#include <stdio.h>

int main (void)
{
	char alpha = 'A';
	char *pAlpha = &alpha;

	int i;

	for (i = 0; i < 26; i++)	printf("%c ", (*pAlpha)++);
	return 0;
}

