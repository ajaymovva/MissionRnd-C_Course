/*

Problem : Return the Count of how many times the word occurred in given string in two ways
Way1: Not using Recursion
Way2:Using Recursion [Optional]

Input : "Hello HelloAgain HelloAGAINAGAIN commonItsHelloagain","Hello"
Output : 4

Note: Dont modify original str or word,Just return count ,Spaces can also be part of words like "ab cd" in "ab cd ab cd" returns 2
*/

#include <stdlib.h>

int count_word_in_str_way_1(char *str, char *word){
	int i, l1, l2, j = 0, count = 0, count1, k;
	if (str == NULL || word == NULL)
	{
		return 0;
	}
	else
	{
		i = 0;
		while (str[i] != '\0')
		{
			i++;
		}
		l1 = i;
		i = 0;
		while (word[i] != '\0')
		{
			i++;
		}
		l2 = i;
		for (i = 0; i < l1;)
		{
			j = 0, count1 = 0; k = i;
			while ((str[k] == word[j]) && j<l2)
			{
				count1++;
				k++;
				j++;
			}
			if (count1 == l2)
			{
				count++;
				count1 = 0;
				i++;
			}
			else
			{
				i++;
			}
		}
		return count;
	}
}

int count_word_int_str_way_2_recursion(char *str, char *word){
	return 0;
}

