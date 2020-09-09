/*
 * Ass3_Array3.c
 *
 *  Created on: Sep 2, 2020
 *      Author: Mai Mousa
 */

#include <stdio.h>

int main (void)
 {
	int m[100][100], t[100][100], row, col, i, j;

	printf("Enter rows and column of matrix: ");
	fflush(stdin);				 fflush(stdout);
	scanf("%d%d", &row, &col);

	printf("Enter elements of matrix: \n");
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			printf("Enter elements a%d%d: ", i+1, j+1);
			fflush(stdin);			    fflush(stdout);
			scanf("%d", &m[i][j]);
		}
	}
	printf("Entered matrix: \n");
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)	{ printf("%d\t", m[i][j]); }
		printf("\n");
	}
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)    { t[j][i] = m[i][j]; }
	}
	printf("Transpose of matrix: \n");
	for(i = 0; i < col; i++)
	{
		for(j = 0; j < row; j++)    { printf("%d\t", t[i][j]); }
		printf("\n");
	}

	return 0;
}



