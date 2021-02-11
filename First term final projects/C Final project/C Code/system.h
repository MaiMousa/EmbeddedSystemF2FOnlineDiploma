#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Platform_Types.h"

/* Total available number of students */
#define Buffer_Length 55 


/* System Units */
struct sinfo
{
	char fname[50];	/* First name  */
	char lname[50]; /* Last name   */
	int roll;       /* Roll number */
	float GPA;      /* GPA         */
	int cid[5];     /* Course ID   */
} st[55];           /* Array of structures (55 structure) */


/* Students Management system APIs */

/* FUNCTIONALITY:                              */ 
/* Print the number of registered students,    */ 
/* the total number that can be added and      */
/* the empty available places for new students */
void Total_Students(void);

/* FUNCTIONALITY:                              */ 
/* Add a student manually after checking the   */ 
/* uniqueness of the roll number If the roll   */
/* number is not unique, error message will    */
/* appear and nothing will be saved            */
void Add_Student_Manually(void);

/* FUNCTIONALITY:                              */ 
/* Add the information of a group of students  */
/* automatically from a text file after        */
/* checking the uniqueness of the roll number  */
/* of each student                             */
void Add_Student_File(void);

/* FUNCTIONALITY:                              */
/* Find a student by the unique roll number    */
void Find_by_Roll_Number(void);

/* FUNCTIONALITY:                              */
/* Find a student the first name               */
void Find_by_First_Name(void);

/* FUNCTIONALITY:                              */
/* Find the students enrolled in a certain     */
/* course (by the course ID)                   */
void Find_by_Course(void);

/* FUNCTIONALITY:                              */
/* Delete a students who has a certain roll    */
/* number                                      */
void Delete_Student_by_Roll_Number(void);

/* FUNCTIONALITY:                              */
/* Update one of the fields of the student     */
/* information                                 */
void Update_Student_by_Roll_Number(void);

/* FUNCTIONALITY:                              */
/* Print all the information of all students   */
void Show_Students(void);

#endif