/*

 * Ass3_continue.c
 *
 *  Created on: Aug 31, 2020
 *      Author: Mai Mousa
 */

#include <stdio.h>

int main (void)
{
	int i, product, num;

	for (i = 1, product = 1; i <= 4; i++)
	{
		printf("Enter num%d: ", i);
		fflush(stdin);		fflush(stdout);
		scanf("%d", &num);

		if (num == 0)		continue;
		product *= num;
	}

	printf("product = %d\n", product);

	return 0;
}

