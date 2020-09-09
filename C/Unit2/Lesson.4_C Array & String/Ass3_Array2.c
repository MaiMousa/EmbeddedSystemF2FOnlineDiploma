/*
 * Ass3_Array2.c
 *
 *  Created on: Sep 2, 2020
 *      Author: Mai Mousa
 */

#include <stdio.h>

int main (void)
{
	float num[100], sum;
	int i, data;

	printf("Enter the numbers of data: ");
	fflush(stdin);		   fflush(stdout);
	scanf("%d", &data);

	for (i = 0, sum = 0; i < data; i++)
	{
		printf("%d.Enter number: ", i+1);
		fflush(stdin);	  fflush(stdout);
		scanf("%f", &num[i]);
		sum += num[i];
	}

	printf("Average = %.2f\n", sum / data);

	return 0;
}

