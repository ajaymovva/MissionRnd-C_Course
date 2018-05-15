/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void str_words_in_rev(char *input, int len){
	int k, j, i = 0;
	char c;
	_strrev(input);
	while (i<len)
	{
		if (input[i] != ' ')
		{
			j = i;
			while (input[j] != ' '&&j<len)
			{
				j++;
			}
			k = i;
			//printf("j:%d", j);
			i = j;
			j = j - 1;
			while (k<j)
			{
				c = input[j];
				input[j] = input[k];
				input[k] = c;
				k++;
				j--;
			}

		}
		else
		{
			i++;
		}
	}
	//printf("\n%s", input);
	
}
