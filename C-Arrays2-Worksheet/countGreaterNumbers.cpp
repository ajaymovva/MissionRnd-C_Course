/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int compare(char *str, char *date, int len)
{
	int i,k=0;
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

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i = 0, k = 0,p;
	char *str=(char*)malloc(sizeof(char*)*11);
	if (date == NULL || len <= 0)
	{
		return NULL;
	}
	else
	{
		while (i < len)
		{
			str = Arr[i].date;
			k = 0;
			p = compare(str, date, 11);
			if (p==1 && i < len - 1)
			{
				str = Arr[i + 1].date;
				p = compare(str, date, 11);
				if (p!= 1)
				{
					k = 1;
					break;
				}
			}
			i++;

		}
		if (k == 1)
		{
			k = len - 1 - i;
			return k;
		}
		else
		{
			return 0;
		}
	}
	
}
