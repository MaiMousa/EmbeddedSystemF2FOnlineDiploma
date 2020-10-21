/*
 * Ass6_5.c
 *
 *  Created on: Oct 21, 2020
 *      Author: Mai Mousa
 */

#include <stdio.h>

struct employee		{ char *empname; 	int empid; };

int main (void)
{
	static struct employee emp1 = {"Jhon"  , 1001},
			               emp2 = {"Alex"  , 1002},
						   emp3 = {"Taylor", 1003};

	struct employee (*arr[]) = {&emp1, &emp2, &emp3};
	struct employee (*(*pt)[3]) = &arr;

	printf("Employee name: %s\n", (**(*pt+1)).empname);
	printf("Employee ID: %d\n", (*(*pt)+1)->empid);

	return 0;
}
