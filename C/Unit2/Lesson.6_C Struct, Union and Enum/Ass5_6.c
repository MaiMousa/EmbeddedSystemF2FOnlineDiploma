/*
 * Ass5_6.c
 *
 *  Created on: Sep 25, 2020
 *      Author: Mai Mousa
 */

#include <stdio.h>

union job
{
	char  name[32];
	float salary;
	int   worker_no;
} u;

struct job1
{
	char  name[32];
	float salary;
	int   worker_no;
} s;

int main(void)
{
	printf("size of union     = %d\n", sizeof(u));
	printf("size of structure = %d\n", sizeof(s));
	return 0;
}



