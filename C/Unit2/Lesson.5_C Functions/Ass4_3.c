/*
 * Ass4_3.c
 *
 *  Created on: Sep 7, 2020
 *      Author: Mai Mousa
 */


#include <stdio.h>

/* 1st method */
void reverse (char *text);

int main (void)
{
	char text [100];
	printf("Enter a sentence: ");
	fflush(stdin);    fflush(stdout);
	gets(text);
	reverse (text);
	return 0;
}

void reverse (char *text)
{
	if (*text)
	{
		reverse(text+1);
		printf("%c", *text);
	}
}


/* 2nd method */
/*
void reverse ();

int main (void)
{
	printf("Enter a sentence: ");
	fflush(stdin);    fflush(stdout);
	reverse ();
	return 0;
}

void reverse ()
{
	char c;
	scanf("%c", &c);

	if (c != '\n')
	{
		reverse();
		printf("%c", c);
	}
}
*/









