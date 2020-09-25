/*
 * 1. Ass5_1.c
 *
 *  Created on: Sep 25, 2020
 *      Author: Mai Mousa
 */

#include <stdio.h>

struct SStudent
{
	char m_Name[50];
	unsigned int m_Roll;
	float m_Marks;
};

struct SStudent ReadStruct (void)
{
	struct SStudent student;

	printf("Enter information of students:\n\n");
	printf("Enter name: "); 	   fflush(stdin);	fflush(stdout);
	scanf("%s", student.m_Name);
	printf("Enter roll number: "); fflush(stdin);	fflush(stdout);
	scanf("%u", &student.m_Roll);
	printf("Enter marks: ");       fflush(stdin);	fflush(stdout);
	scanf("%f", &student.m_Marks);

	return student;
}

void DisplayStruct (struct SStudent student)
{
	printf("\nDisplaying Information\n");
	printf("Name: %s\nRoll: %d\nMarks: %.2f\n", student.m_Name,
			student.m_Roll, student.m_Marks);
}

int main (void)
{
	struct SStudent student = ReadStruct();
	DisplayStruct(student);
	return 0;
}
