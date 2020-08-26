/*
 * Ass2_8.c
 *
 *  Created on: Aug 25, 2020
 *      Author: Mai Mousa
 */

#include <stdio.h>

int main (void)
{
	char op;
	float num1, num2;

	printf("Enter operator either + or - or * or divide : ");
	fflush(stdin);    fflush(stdout);
	scanf("%c", &op);

	printf("Enter two operands: ");
	fflush(stdin);    fflush(stdout);
	scanf("%f%f", &num1, &num2);

	if (num2 == 0 && op == '/') printf("Division by zero is invalid.");
	else
	{
		switch(op)
		{
		case '+':	printf("%.1f + %.1f = %.1f", num1, num2, num1 + num2);		break;
		case '-':	printf("%.1f - %.1f = %.1f", num1, num2, num1 - num2);		break;
		case '*':	printf("%.1f * %.1f = %.1f", num1, num2, num1 * num2);		break;
		case '/':	printf("%.1f / %.1f = %.1f", num1, num2, num1 / num2);		break;
		default:                                                                break;
		}
	}
	return 0;
}


