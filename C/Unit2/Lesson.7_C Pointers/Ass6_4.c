/*
 * Ass6_4.c
 *
 *  Created on: Oct 21, 2020
 *      Author: Mai Mousa
 */

#include <stdio.h>

void reverse (int *arr, int size)
{
	int i = 0, j = size - 1, temp;
	while (i < j)
	{
		temp = arr[i];	 arr[i] = arr[j];	arr[j] = temp;
		i++; j--;
	}
}
int main (void)
{
	int arr[100], elements, i;

	printf("Enter the number of elements to store in\n");
	printf("the array (max 15): ");
	fflush(stdin);		fflush(stdout);		 scanf("%d", &elements);

	printf("\nInput %d number of elements in the array:\n", elements);
	for(i = 0; i < elements; i++)
	{
		printf("element - %d: ", i+1);
		fflush(stdin);		fflush(stdout);      scanf("%d", arr+i);
	}

	reverse (arr, elements);
	printf("\nThe elements of array in reverse order are: \n");
	for(i = 0; i < elements; i++)
	{	printf("element - %d: %d\n", 5-i, arr[i]);	 }

	return 0;
}

