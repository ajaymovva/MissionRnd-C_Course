/*
OVERVIEW: Given a string, Return the substring of the main string from i index to j index
Indexes start from 0,ith letter and jth letter are included
E.g.: Input: "get_sub_string("abcdefgh",2,5) , Output: "cdef"

INPUTS: A string.

OUTPUT: return substring from [i,j]

INPUT2: I will Code for Mission RnD , 2,10
OUTPUT2:will Code

NOTES: Check Null Strings ,Include stddef for NULL if needed.Create a New string and return it ,dont modfiy
original String
*/

#include <stddef.h>
#include <stdlib.h>

char * get_sub_string(char *str, int i, int j){
	int k,k1,p;
	k = j - i + 1;
	if (k < 0)
	{
		k = -k;
	}
	char *str1 = (char *)malloc(sizeof(char*)*k);
	if (str == NULL)
	{
		return NULL;
	}
	else if (i > j)
	{
		return NULL;
	}
	else
	{
		
		k1 = 0, p = 0;
		while (str[k1] != '\0')
		{
			if (k1 >= i&&k1 <= j)
			{
				str1[p] = str[k1];
				p++;
			}
			k1++;
		}
		return str1;
	}
}
