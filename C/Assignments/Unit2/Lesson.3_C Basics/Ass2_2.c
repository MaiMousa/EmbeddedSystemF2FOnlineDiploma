/*
 * Ass2_2.c
 *
 *  Created on: Aug 25, 2020
 *      Author: Mai Mousa
 */

#include <stdio.h>

int main (void)
{
	char ch;
	printf("Enter an alphabet: ");
	fflush (stdin);   fflush (stdout);
	scanf("%c", &ch);

//	if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'I' || ch == 'i' || ch == 'O' || ch == 'o' || ch == 'u' || ch == 'U')
//	printf("%c is a vowel.", ch);
//	else printf("%c is a consonant.", ch);

	switch (ch)
	{
	case 'A':	case 'a':
	case 'E':	case 'e':
	case 'I':	case 'i':
	case 'O':	case 'o':
	case 'U':	case 'u':
		printf("%c is a vowel.", ch);  break;
	default:
		printf("%c is a consonant.", ch);
	}

	return 0;
}




