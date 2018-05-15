/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: 
A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int compare1(char *str, char *date, int len)
{
	int i, k = 0;
	for (i = 0; i < len; i++)
	{
		if (str[i] != date[i])
		{
			k = 1;
			break;
		}
	}
	if (k == 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}

}
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i,j,p=0,k=0,k1=0;
	struct transaction *swap;
	swap = (struct transaction *)malloc(ALen*sizeof(struct transaction));
	char *str1 = (char*)malloc(sizeof(char*) * 10);
	char *str2 = (char*)malloc(sizeof(char*) * 10);
	if (A == NULL || B == NULL)
		return NULL;
	else
	{
		for (i = 0; i < ALen; i++)
		{
			k1 = 0;
			for (j = 0; j < BLen; j++)
			{
				str1 = A[i].date;
				str2 = B[j].date;
				p = compare1(str1, str2, 11);
				if (p == 1)
				{
					k1 = 1;
					break;
				}
			}
			if (k1 == 1)
			{
				swap[k] = A[i];
				k++;
			}
		}
		if (k != 0)
		{
			return swap;
		}
		else
		{
			return NULL;
		}
	}
}