/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int compare2(char *str, char *str1, int len)
{
	int i, k = 0,j;
	i = 6, j = 10;
	while (i < j)
	{
		if (str[i] > str1[i])
		{
			k = 2;
			break;
		}
		else if (str[i] < str1[i])
		{
			k = 3;
			break;
		}
		i++;
	}
	if (k != 0)
	{
		return k;
	}
	else
	{
		i = 3; j = 5;
		while (i < j)
		{
			if (str[i] > str1[i])
			{
				k = 2;
				break;
			}
			else if (str[i] < str1[i])
			{
				k = 3;
				break;
			}
			i++;
		}
		if (k != 0)
		{
			return k;
		}
		else
		{
			i = 0; j = 2;
			while (i < j)
			{
				if (str[i] > str1[i])
				{
					k = 2;
					break;
				}
				else if (str[i] < str1[i])
				{
					k = 3;
					break;
				}
				i++;
			}
			if (k != 0)
			{
				return k;
			}
			else
			{
				return 1;
			}
		}

	}

}

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	struct transaction *std1;
	struct transaction *std2;
	int i=0, j=0,k1=0,k=0,p=-1;
	char *str1 = (char*)malloc(sizeof(char*) * 11);
	char *str2 = (char*)malloc(sizeof(char*) * 11);
	std1 = (struct transaction *)malloc((ALen+BLen)*sizeof(struct transaction));
	std2 = (struct transaction *)malloc((ALen+BLen)*sizeof(struct transaction));
	if (A == NULL || B == NULL)
	{
		return NULL;
	}
	else
	{
		i = ALen - 1, j = BLen - 1;
		k = 0;
		while (i >= 0 && j >= 0)
		{
			str1 = A[i].date;
			str2 = B[j].date;
			p = compare2(str1, str2, 11);
			if (p == 1)
			{
				std1[k] = A[i];
				k++;
				std1[k] = B[j];
				i--;
				j--;
				k++;
			}
			else if (p == 2)
			{
				std1[k] = A[i];
				i--;
				k++;
			}
			else if (p == 3)
			{
				std1[k] = B[j];
				j--;
				k++;
			}
		}
		while (i >= 0)
		{
			std1[k] = A[i];
			i--;
			k++;
		}
		while (j >= 0)
		{
			std1[k] = B[j];
			j--;
			k++;
		}
		j = 0;
		for (i = k - 1; i >= 0; i--)
		{
			std2[j] = std1[i];
			j++;
		}
		return std2;
	}
}