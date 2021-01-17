/*
 * LinkedList.c
 *
 *  Created on: Jan 17, 2021
 *      Author: Mai Mousa
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct SNode
{
	struct SNode* Pnext;
	unsigned int ID;
	char Name[20];
	float Height;
} Node;

Node* GHead = NULL;

void  Add                 (Node** Head);
unsigned Delete (Node** Head);
void  View                (Node*  Head);
void  DeleteAll           (Node** Head);
Node* GetNode             (Node*  Head, unsigned int index);
int   NumofNodes          (Node*  Head);
int   NumofNodesRecursive (Node*  Head);
Node* GetEndNode          (Node*  Head, unsigned int index);
Node* GetEndNodeM2        (Node*  Head, unsigned int index);
Node* GetMiddle           (Node*  Head);
void  ReverseList         (Node** Head);
int   LoopDetection       (Node*  Head);
Node* GetMiddleM2         (Node*  Head);

void AddStudent             (void);
void DeleteStudent          (void);	
void ViewStudents           (void);	            
void DeleteAllStudents      (void);				
void GetStudentbyIndex      (void);
void ListLengthIterative    (void);
void ListLengthRecursive    (void);
void GetStudentbyEndIndex   (void);
void GetStudentbyEndIndexM2 (void);
void GetMiddleofList        (void);
void GetMiddleofListM2      (void);
void ListReverse            (void);
void LoopChecking           (void);

int main (void)
{
	int OpNum;
	unsigned int ID;
	char Name [20];
	float Height;

	do 
	{
		printf("========================\n	Choose one of the following options\n\n"
		   "1:  Add_Student\n"
		   "2:  Delete_Student\n"
		   "3:  View_Students\n"
		   "4:  Delete_All\n"
		   "5:  Get_Student_by_Index\n"
		   "6:  List_Length_Iteratively\n"
		   "7:  List_Length_Recursively\n"
		   "8:  Get_Student_by_Index_from_End\n"
		   "9:  Get_Student_by_Index_from_EndM2\n"
		   "10: Get_Middle_of_List\n"
		   "11: Get_Middle_of_ListM2\n"
		   "12: Check_Loops_in_List\n"
		   "13: Reverse_List\n"
		   "Enter option number: ");
	
		fflush(stdin);		fflush(stdout);
		scanf("%d", &OpNum);
		printf("\n========================\n");

		switch(OpNum)
		{
			case 1 :  AddStudent             ();		break;
			case 2 :  DeleteStudent          ();        break;
			case 3 :  ViewStudents           ();	    break;
			case 4 :  DeleteAllStudents      ();		break;
			case 5 :  GetStudentbyIndex      ();	    break;
			case 6 :  ListLengthIterative    ();		break;
			case 7 :  ListLengthRecursive    ();		break;
			case 8 :  GetStudentbyEndIndex   ();		break;
			case 9 :  GetStudentbyEndIndexM2 ();        break;
			case 10:  GetMiddleofList        ();	    break;
			case 11:  GetMiddleofListM2	     ();        break;
			case 12:  LoopChecking           ();		break;
			case 13:  ListReverse            ();		break;
			default: printf("Not Valid Option !!!\n");  break;
		}

	} while (OpNum != -1);
	
	return 0;
}

void AddStudent        (void)	   { Add       (&GHead); }
void DeleteStudent     (void)	   
{ 
	unsigned int Ret = Delete (&GHead);
	if  (Ret)	printf("Not Found.\n");
	else        printf("Deleted.\n");
}
void ViewStudents      (void)	   { View      (GHead);	 }
void DeleteAllStudents (void)	   { DeleteAll (&GHead); }
void GetStudentbyIndex (void)	
{
	unsigned int index;
	printf("Enter Student Index: ");	fflush(stdin);	fflush(stdout);		scanf("%d", &index);
	Node* Ret = GetNode (GHead, index);
	printf("ID: %d\nName: %s\nHeight: %f\n", Ret -> ID, Ret -> Name, Ret -> Height);  
}
void ListLengthIterative (void)		{ printf("List length Iteratively: %d\n", NumofNodes (GHead)); }
void ListLengthRecursive (void)     { printf("List length Recursively: %d\n", NumofNodesRecursive (GHead)); }
void GetStudentbyEndIndex (void)
{
	unsigned int index;
	printf("Enter Student End Index: ");	fflush(stdin);	fflush(stdout);		scanf("%d", &index);
	Node* Ret = GetEndNode (GHead, index);
	printf("ID: %d\nName: %s\nHeight: %f\n", Ret -> ID, Ret -> Name, Ret -> Height);  	
}
void GetStudentbyEndIndexM2 (void)
{
	unsigned int index;
	printf("Enter Student End Index: ");	fflush(stdin);	fflush(stdout);		scanf("%d", &index);
	Node* Ret = GetEndNodeM2 (GHead, index);
	printf("ID: %d\nName: %s\nHeight: %f\n", Ret -> ID, Ret -> Name, Ret -> Height);  	
}

void GetMiddleofList (void)
{
	Node* Ret = GetMiddle (GHead);
	printf("ID: %d\nName: %s\nHeight: %f\n", Ret -> ID, Ret -> Name, Ret -> Height);  	
}

void GetMiddleofListM2 (void)
{
	Node* Ret = GetMiddleM2 (GHead);	
	printf("ID: %d\nName: %s\nHeight: %f\n", Ret -> ID, Ret -> Name, Ret -> Height);  	
}

void LoopChecking (void)
{
	int ret = LoopDetection (GHead);
	if (ret)	printf("Loop detected\n\n"); 
	else		printf("No loop\n\n");
}

void ListReverse (void)			   { ReverseList (&GHead); }


void Add (Node** Head)
{
	Node* head = *Head;
	Node* prev;

	/* New node memory allocation */
	Node* NewNode = (Node*) malloc (sizeof (Node));
	printf("Enter the ID: ");						fflush(stdin);	fflush(stdout);		scanf("%d", &(NewNode -> ID));
	printf("Enter student full name: ");			fflush(stdin);	fflush(stdout);		gets((NewNode -> Name));
	printf("Enter height: ");						fflush(stdin);	fflush(stdout);		scanf("%f", &(NewNode -> Height));

	/* If the list is empty */
	if (*Head == NULL)
	{
		*Head = NewNode;
		NewNode -> Pnext = NULL;
	}
	else
	{
		while (head != NULL)
		{
			prev = head;
			head = head -> Pnext;
		}
		prev -> Pnext = NewNode;
		NewNode -> Pnext = NULL;
	}
}

unsigned Delete (Node** Head)
{
	unsigned int ID;
	printf("Enter student ID to be deleted : ");	fflush(stdin);	fflush(stdout);		scanf("%d", &ID);

	Node* head = *Head;
	Node* prev;

	if (head != NULL)
	{
		if(head -> ID == ID)
		{
			if (head -> Pnext == NULL)	{ *Head = NULL;           free(head); }
			else						{ *Head = head -> Pnext;  free(head); }
		}
		else
		{	
			while (head != NULL && head -> ID != ID )
			{
				prev = head;
				head = head -> Pnext;
			}
			
			/* Element is not existing */
			if (head == NULL)	{ return 1; }

			prev -> Pnext = head -> Pnext;
			free(head);
		}
	}
	return 0;
}

void View (Node* Head)
{
	unsigned int i = 1;

	if (Head == NULL) 	printf("Empty List\n");
	while (Head != NULL)
	{
		printf("Record Number %d\nID: %d\nName: ", i, Head -> ID);
		puts(Head -> Name);
		printf("Height: %f\n", Head -> Height);
		i++;
		Head = Head -> Pnext;
	}
}

void DeleteAll (Node** Head)
{
	Node* head = *Head;

	while (head != NULL)
	{
		head = head -> Pnext;
		free (*Head);
		*Head = head;
	}
}

Node* GetNode (Node* Head, unsigned int index)
{
	unsigned int count = 1;
	Node* Temp = Head;

	while (count < index)
	{
		Temp = Temp -> Pnext;
		count++;
	}

	return Temp; 
}

int NumofNodes (Node* Head)
{
	unsigned int count = 0;

	while(Head != NULL)
	{
		Head = Head -> Pnext;
		count++;
	}
	return count;
}

int NumofNodesRecursive (Node* Head)
{
	if   (Head == NULL)	 return 0;
	else				 return (1 + NumofNodesRecursive(Head -> Pnext));
}

Node* GetEndNode (Node* Head, unsigned int index)
{
	/* Get list length */
	int length = NumofNodes (GHead);
	/* Calculate the new index */
	int NewIndex = length - index + 1;
	/* Get the node data */
	return  (GetNode (GHead, NewIndex));
}

Node* GetEndNodeM2 (Node* Head, unsigned int index)
{
	Node *ref_p = Head, *main_p = Head;
	unsigned int i;
	/* Move ref_p to n nodes  from head */
	for (i = 0; i < index; i++)	{ ref_p = ref_p -> Pnext; }
	/* Move both pointers one by one */
	while(ref_p != NULL)
	{
		ref_p  = ref_p  -> Pnext;
		main_p = main_p -> Pnext;
	}
	return main_p;
}

Node* GetMiddle (Node* Head)
{
	/* Get list length */
	int length = NumofNodes (GHead);
	/* Calculate the middle node's index */
	int NewIndex = (length / 2) + 1;
	/* Get the node data */
	return  (GetNode (GHead, NewIndex));
}

Node* GetMiddleM2 (Node* Head)
{
	Node *slow_p = Head, *fast_p = Head;

	while (fast_p != NULL && fast_p -> Pnext != NULL)
	{
		slow_p = slow_p -> Pnext;
		fast_p = fast_p -> Pnext -> Pnext;
	}

	return slow_p;
}

int LoopDetection (Node* Head)
{
	Node *slow_p, *fast_p;
	slow_p = Head;
	fast_p = Head;
	int ret = 0;

	while(slow_p && fast_p && fast_p -> Pnext)
	{
		slow_p = slow_p -> Pnext;
		fast_p = fast_p -> Pnext -> Pnext;

		if (slow_p == fast_p)	return 1;
	}

	return 0;
}

void ReverseList (Node** Head)
{
	/* Initialize three pointers prev = NULL, current = Head and next = NULL */
	Node *next, *current, *prev;
	current = *Head;
	prev = NULL;
	next = NULL;

	/* Iterate through the linked list */
	while(current != NULL)
	{
		/* Before changing next of current, store nexr node */
		next = current -> Pnext;
		/* Now change next of current. This is where actual reversing happens */
		current -> Pnext = prev;
		/* Move prev and current one step forward */
		prev = current;
		current = next;
	} 
	*Head = prev;
}
