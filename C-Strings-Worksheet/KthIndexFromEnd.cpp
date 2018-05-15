/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#include<string.h>
char KthIndexFromEnd(char *str, int K) {
	int l,i;
	if (str==""||str == NULL || K<0)
	{
		return '\0';
	}
	else
	{
		l = strlen(str);
		if (K > l)
		{
			return '\0';
		}
		else
		{
			i = l - 1 - K;
			return str[i];
		}
	}
}