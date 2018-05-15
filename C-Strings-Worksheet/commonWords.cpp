/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include<string.h>
#include <malloc.h>

#define SIZE 31

char ** commonWords(char *str1, char *str2) {
	char ajay1[SIZE][SIZE];
	int one, two;
	int i = 0, j, t,l;
	char **str3 = (char**)malloc(SIZE * sizeof(char *));
	int k = 0;
	char ajay2[SIZE][SIZE];
	if (str1 == NULL || str2 == NULL)
	{
		return NULL;
	}
	else
	{

		i = 0, j = 0;
		l = strlen(str1);
		while (i < l)
		{
			if (str1[i] != ' ')
			{
				j++;
			}
			i++;
		}
		if (j == 0)
		{
			return NULL;
		}
		else if (j != 0)
		{
			i = 0, j = 0;
			l = strlen(str2);
			while (i < l)
			{
				if (str1[i] != ' ')
				{
					j++;
				}
				i++;
			}
			if (j == 0)
				return NULL;
			else if (j != 0)
			{
				for (j = 0; str1[j] != '\0'; j++){
					if (str1[j] != ' ')
					{
						ajay1[i][k] = str1[j];
						k++;
					}
					else
					{
						ajay1[i][k] = '\0';
						i++;
						k = 0;
					}
				}
				ajay1[i][k] = '\0';
				if (i > 0)
				{
					i++;
				}
				one = i;
				i = 0; k = 0;

				for (j = 0; str2[j] != '\0'; j++){
					if (str2[j] != ' ')
					{
						ajay2[i][k] = str2[j];
						k++;
					}
					else
					{
						ajay2[i][k] = '\0';
						i++;
						k = 0;
					}
				}
				ajay2[i][k] = '\0';
				if (i > 0)
				{
					i++;
				}
				two = i;
				t = 0;
				for (i = 0; i <= one; i++)
				{

					for (j = 0; j <= two; j++)
					{
						if (strcmp(ajay1[i], ajay2[j]) == 0)
						{
							str3[t] = ajay1[i];
							t++;
						}
					}

				}
				str3[t] = '\0';
				if (t != 0)
					return  str3;
				else{
					return NULL;
				}
			}
		}
	}
}