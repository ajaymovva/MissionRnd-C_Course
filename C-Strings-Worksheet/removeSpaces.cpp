/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

#include<string.h>
char removeSpaces(char *str) {
	int l,i,j,n;
	if (str=='\0')
		return '\0';
	else
	{
		l = strlen(str);
		n = l;
		i = 0;
		for (i = 0; i < l;i++)
		{
			if (str[i] == ' ')
			{
				j = i;
				for (j = i; j < l;j++)
				{
					str[j] = str[j+1];
				}
				i--;	
			}
		}
		return *str;

	}
}