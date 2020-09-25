/*
 * Ass5_2.c
 *
 *  Created on: Sep 25, 2020
 *      Author: Mai Mousa
 */

#include <stdio.h>
struct SDistance	{	float m_Foot;	float m_Inch;	};

struct SDistance ReadDistance (char* number)
{
	struct SDistance distance;
	printf("Enter information for %s distance\n", number);
	printf("Enter feet: ");	 fflush(stdin);	 fflush(stdout);
	scanf("%f", &distance.m_Foot);
	printf("Enter inch: ");	 fflush(stdin);	 fflush(stdout);
	scanf("%f", &distance.m_Inch);
	return distance;
}

struct SDistance AddDistance (struct SDistance D1, struct SDistance D2)
{
	struct SDistance sum;                 int increase;
	sum.m_Foot = D1.m_Foot + D2.m_Foot;	  sum.m_Inch = D1.m_Inch + D2.m_Inch;

	if (sum.m_Inch >= 12)
	{
		increase = (int) sum.m_Inch / 12;
		sum.m_Foot += increase;
		sum.m_Inch -= (increase * 12);
	}
	return sum;
}
int main (void)
{
	struct SDistance D1, D2, D;
	D1 = ReadDistance ("1st");	D2 = ReadDistance ("2nd");
	D  = AddDistance (D1, D2);
	printf("Sum of distances = %.0f'-%.1f\"\n", D.m_Foot, D.m_Inch);
	return 0;
}
