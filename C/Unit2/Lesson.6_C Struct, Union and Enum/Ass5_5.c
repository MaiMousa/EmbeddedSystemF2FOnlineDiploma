/*
 * Ass5_5.c
 *
 *  Created on: Sep 25, 2020
 *      Author: Mai Mousa
 */

#include <stdio.h>

#define PI 3.1415
#define area(r) (PI*r*r)

int main (void)
{
	float radius;

	printf("Enter the radius: ");
	fflush(stdin);		fflush(stdout);
	scanf("%f", &radius);

	printf("Area = %.2f\n", area(radius));
	return 0;
}

