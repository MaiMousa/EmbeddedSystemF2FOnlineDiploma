#include "system.h"
#include "FIFO.h"

/* Creating enum and union to handle searching function */
enum DataType {INT, FLOAT, CHARPtr, INTPtr};

union TypeValue
{
	int   u_intValue;
	float u_floatValue;
	char* u_charPtrValue;
	int*  u_intPtrValue;
};

/* Global counter for number of students */
uint32 GCount = 0;

uint8  FIFO_Search (FIFO_Buff_t* Buff, union TypeValue value, enum DataType type);
uint32 FIFO_Delete_by_Key (FIFO_Buff_t* Buff, Element_Type* Buffer, int Data, uint32 Buff_Length);


/* System APIs Implementation */
void Add_Student_Manually (void)
{
	int i, fcount = 0;
	/* Create temporary structure for the student information */
	Element_Type* temp = (&VirtualBuffer) -> base;
	struct sinfo TempStudent;
	/* Get the roll number */
	printf("Enter the Roll Number: ");	fflush(stdin);	fflush(stdout);	scanf("%d", &(TempStudent.roll));
	/* Check if it is unique or not */
	/* Search for this roll number through the queue */		
	for (i = 0; (i < (&VirtualBuffer) -> length) && (fcount == 0) ; i++)
		{
			if  (temp -> roll == TempStudent.roll) 	fcount++;		
			else    								temp++;
		} 

	if(fcount) printf("[ERROR] Roll Number %d is already taken\n", TempStudent.roll);
	else
	{
		/* If unique then get the other fields */
		printf("Enter the first name of student: ");	fflush(stdin);	fflush(stdout);   gets(TempStudent.fname);
		printf("Enter the last name of student: ");	    fflush(stdin);	fflush(stdout);   gets(TempStudent.lname);
		printf("Enter the GPA you obtained: ");		    fflush(stdin);	fflush(stdout);   scanf("%f", &TempStudent.GPA);
		printf("Enter the course ID of each course\n");
		for (i = 0; i < 5; i++)
		{
			printf("Course %d id: ", i+1); fflush(stdin);	fflush(stdout);	scanf("%d", &TempStudent.cid[i]);
		}
	
		/* Enqueue */
		if (FIFO_Enqueue (&VirtualBuffer, &TempStudent) == FIFO_no_error)	 
			{  
//				printf("FIFO Enqueue ... DONE\n");
				printf("[INFO] Student's details are added successfully\n"); 
				GCount++;
				printf("----------------------------------------------\n");
				Total_Students();
			}
		else printf("Failed\n");
	}
}

void Add_Student_File(void)
{
	/* Open file in reading mode */
	FILE* ptrFile = fopen ("text.txt", "r");
	/* Check if NULL >> failed to open, else it is opened successfully */
//	if(!ptrFile)   printf("Failed\n");
//	else           printf("Done\n");

	char retChar;
	char tempArr[50] = {0};	
	int i = 0, j, k = 0;

	int z, tempPrint = 0; 
	int tempRollNum;
	Element_Type* temp = (&VirtualBuffer) -> head;

	while ((retChar = fgetc(ptrFile)) != EOF)
	{
		for (i = 0; i < 50; i++)
		tempArr[i] = 0;
		i = 0;
		int fcount = 0;

		Element_Type* tempSearch = (&VirtualBuffer) -> head;

		/* Get roll number */
		while ((retChar = fgetc(ptrFile)) != 32)
		{
			tempArr[i] = retChar;  
			i++;
		}
		i = 0;
		/* Check the uniqueness of the roll number */
		/* Get the roll number */
		tempRollNum = atoi(tempArr);

		for (z = 0; (z < (&VirtualBuffer) -> length) && (fcount == 0) ; z++)
		{
			if  ( (tempSearch -> roll == tempRollNum) ) 
			{ tempPrint++; fcount++;}		
			else    						   
			{ tempSearch++; }
		}
		if (tempPrint == 1)	{ printf("[ERROR] Roll number %d is already taken\n", tempRollNum); }
		if(fcount);
		else
		{
			temp -> roll = tempRollNum;
			GCount++;
			
			printf("[INFO] Roll number %d saved successfully\n", temp -> roll);

			/* Get first name */
			while ((retChar = fgetc(ptrFile)) != 32)
			{
				tempArr[i] = retChar;
				temp -> fname[i] = retChar;
				i++;
			} 
			i = 0;

			/* Get last name */
			while ((retChar = fgetc(ptrFile)) != 32)
			{
				tempArr[i] = retChar;
				temp -> lname[i] = retChar;
				i++;
			} 
			i = 0;

			/* Get GPA */
			while ((retChar = fgetc(ptrFile)) != 32)
			{
				tempArr[i] = retChar;
				i++;
			}
			i = 0;
			temp -> GPA = atof(tempArr);

			/* Get courses ID's */
			for(j = 0; j < 5; j++)
			{
				while ((retChar = fgetc(ptrFile)) != 32)
				{
					tempArr[i] = retChar;
					temp -> cid[j] = atoi(tempArr);
					i++;
				}
				i = 0;
			}
			k++;
			temp++;
		}
	}

	printf("[INFO] Students details are saved successfully\n");
	printf("----------------------------------------------\n");
	Total_Students();
}

void Find_by_Roll_Number(void)
{
	union TypeValue Temp;
	uint8 ret;
	printf("Enter the roll number of the student: ");	fflush(stdin);	fflush(stdout);	 scanf("%d", &(Temp.u_intValue));
	ret = FIFO_Search (&VirtualBuffer, Temp, INT);
	if (ret == 0)	printf("[ERROR] Roll number %d not found\n", Temp.u_intValue);
}

void Find_by_First_Name(void)
{
	union TypeValue Temp;
	uint8 ret;
	printf("Enter the first name of the student: ");	fflush(stdin);	fflush(stdout);	 gets(Temp.u_charPtrValue);
	ret = FIFO_Search (&VirtualBuffer, Temp, CHARPtr);
}

void Find_by_Course(void)
{
	union TypeValue Temp;
	uint8 ret;
	printf("Enter the course ID: ");	fflush(stdin);	fflush(stdout);	 scanf("%d", &(Temp.u_intValue));
	ret = FIFO_Search (&VirtualBuffer, Temp, INTPtr);
}

void Total_Students(void)
{
	printf("[INFO] The total number of students is %d\n", GCount);
	printf("[INFO] You can add up to %d students\n", Buffer_Length);
	printf("[INFO] You can add %d more students\n", Buffer_Length - GCount);
}

void Delete_Student_by_Roll_Number(void)
{
	int Data;
	uint32 ret;
	/* Get the roll number from the user */
	printf("Enter the roll number which you want to delete: ");	  fflush(stdin);	fflush(stdout);		scanf("%d", &Data);
	/* Call the function to delete */
	ret = FIFO_Delete_by_Key (&VirtualBuffer, st, Data, Buffer_Length); 
}

void Update_Student_by_Roll_Number(void)
{
	int i, fcount = 0, field, j;
	Element_Type* temp = (&VirtualBuffer) -> base;
	struct sinfo TempStudent;
	printf("Enter the roll number to update the entry: ");  fflush(stdin);	fflush(stdout);	scanf("%d", &(TempStudent.roll));

	for (i = 0; (i < (&VirtualBuffer) -> length) && (fcount == 0) ; i++)
		{
			if  (temp -> roll == TempStudent.roll) 	
			{	
				fcount++;
				printf("1. First name\n2. Last name\n3. Roll number\n4. GPA\n5. Courses\n");
				fflush(stdin);	fflush(stdout);	scanf("%d", &field);

				switch(field)
				{
					case 1:	printf("Enter the first name: ");     fflush(stdin);	fflush(stdout);	  gets(temp -> fname);	         break;
					case 2: printf("Enter the last name: ");      fflush(stdin);	fflush(stdout);	  gets(temp -> lname);           break;
					case 3: printf("Enter the roll number: ");    fflush(stdin);	fflush(stdout);	  scanf("%d", &(temp -> roll));  break;
					case 4: printf("Enter the GPA: ");            fflush(stdin);	fflush(stdout);	  scanf("%f", &(temp -> GPA));   break;
					case 5: printf("Enter the courses' IDs:\n");  fflush(stdin);	fflush(stdout);
							for (j = 0; j < 5; j++)
							{
								printf("Course %d ID is : ", (j+1));  fflush(stdin);  fflush(stdout);  scanf("%d", &(temp -> cid[j]));
							}  
					break;
				}

				printf("[INFO] UPDATED SUCCESSFULLY.\n");
				
			}		
			else    temp++;
		} 
	if (fcount == 0)	printf("[ERROR] This roll number %d not found\n", TempStudent.roll);
}

void Show_Students(void)	{	FIFO_Print (&VirtualBuffer);	}


/* FIFO manipulation APIs Implementation */
uint8 FIFO_Search (FIFO_Buff_t* Buff, union TypeValue value, enum DataType type)
{
	/* Input: 1. Pointer to buffer
			  2. Data to search for
			  3. Type of data
	*/
	Element_Type* temp = Buff -> base;
	uint32 i;
	int j, k, len, count = 0, fcount = 0;

	switch (type)
	{
		case INT:	/* Roll number */
				for (i = 0; i < Buff -> length; i++)
				{
					if   (temp -> roll == value.u_intValue)		
					{   
						/* Print the student's information */
						printf("The student details are:\nThe first name is %s\nThe last name is %s\n"
							   "The GPA is %.2f\nThe courses IDs are:",temp -> fname, temp -> lname, temp -> GPA);
						for (j = 0; j < 5; j++)	{ printf("%d ", temp -> cid[j]); }
						printf("\n");

						return 1;	/* Found */
					}
					else    									temp++;
				} 
		break; 
		case FLOAT: /* GPA */
				for (i = 0; i < Buff -> length; i++)
				{
					if   (temp -> GPA == value.u_floatValue)	return 1;	/* Found */
					else    									temp++;
				} 
		break; 
		case CHARPtr: /* First name */
				count = 0;
				len = strlen(value.u_charPtrValue);	/* get length to compare */

				for (i = 0; i < Buff -> length; i++)
				{
					for (j = 0; j < len; j++)
					{
						if   ( (temp -> fname[j]) == (value.u_charPtrValue[j]) )	count++;	
					}
					if (count == len)	
					{ 
					 	/* Found */
					 	fcount++;
					 	/* Print the students information */
						printf("The student's details are:\nThe first name is %s\nThe last name is %s\n"
							   "The roll number is %d\nThe GPA is %.2f\nThe courses IDs are:",
							   temp -> fname, temp -> lname, temp -> roll, temp -> GPA);
						for (k = 0; k < 5; k++)	{ printf("%d ", temp -> cid[k]); }
						printf("\n");
					}
					count = 0;  temp++;
				} 
				if (fcount == 0)	printf("[ERROR] First name %s not found\n", value.u_charPtrValue);
		break; 
		case INTPtr: /* Course ID, will send the course id in the roll number  */
				count = 0;
				for (i = 0; i < Buff -> length; i++)
				{
					for (j = 0; j < 5; j++)
					{
						if   (temp -> cid[j] == value.u_intValue)		
						{	
							count++;
							/* Print the students information */
							printf("The student's details are:\nThe first name is %s\nThe last name is %s\n"
								   "The roll number is %d\nThe GPA is %.2f\n",
								   temp -> fname, temp -> lname, temp -> roll, temp -> GPA);
						}
					}
					temp++;					
				}

				if (count == 0)		printf("[ERROR] course id %d not found\n", value.u_intValue);
				else 				printf("[INFO] Total number of students enrolled: %d\n", count);
		break;
	}
	return 0; /* Not found */
}

uint32 FIFO_Delete_by_Key (FIFO_Buff_t* Buff, Element_Type* Buffer, int Data, uint32 Buff_Length)
{
	/* &VirtualBuffer, st, roll_number from user, Buffer_Length*/ 

	uint32 i = 0, temp;
	
	while ( (Buffer[i].roll != Data) && (i <= Buff_Length) )	{ i++; }	
	if (i < Buff_Length)
	{
		Buff_Length = Buff_Length - 1;
		for (temp = i; temp < Buff_Length; temp++)	{  Buffer[temp] = Buffer[temp + 1];  }
		/* Decrement the buffer head */
		(Buff -> head) --;
		/* Decrease the global counter by one to decrease the number of students */
		GCount--;
		printf("[INFO] The roll number %d is removed successfully\n", Data);
	}
	else if (i == (Buff_Length+1))
		{
			printf("[ERROR] This roll number %d not found\n", Data);
		}
	return Buff_Length;
}
