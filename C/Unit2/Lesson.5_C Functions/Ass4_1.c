/*
 * Ass4_1.c
 *
 *  Created on: Sep 6, 2020
 *      Author: Mai Mousa
 */

#include <stdio.h>

int primeNumber (int num)
{
	int prime, i, count = 0;

	for(i = 1; i <= num; i++) {  if(num % i == 0)	{ count++; }  }

	if (count == 2)	prime = 1;
	else            prime = 0;

	return prime;
}

int main (void)
{
	int a, b, prime, temp;

	printf("Enter two numbers (intervals): ");
	fflush(stdin);			   fflush(stdout);
	scanf("%d%d", &a, &b);

	if (a > b)  {  temp = a;  a = b;  b = temp;  }

	printf("Prime numbers between %d and %d are: ", a, b);
	while (a <= b)
	{
		prime = primeNumber (a);
		if (prime == 1)	printf("%d ", a);
		a++;
	}

	return 0;
}

