/*
 * Ass3_Array1.c
 *
 *  Created on: Sep 2, 2020
 *      Author: Mai Mousa
 */

#include <stdio.h>

int main (void)
{
	float a[2][2], b[2][2];
	int i, j;

	printf("Enter the elements of 1st matrix\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("Enter a%d%d: ", i+1, j+1);
			fflush(stdin);		fflush(stdout);
			scanf("%f", &a[i][j]);
		}
	}
	printf("Enter the elements of 2nd matrix\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("Enter b%d%d: ", i+1, j+1);
			fflush(stdin);		fflush(stdout);
			scanf("%f", &b[i][j]);
		}
	}
	printf("Sum of matrix:\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("%.1f\t", a[i][j] + b[i][j]);
		}
		printf("\n");
	}
	return 0;
}

