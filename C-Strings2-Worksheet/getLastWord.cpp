/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>

char * get_last_word(char * str){
	int i,j,k=0;
	char *str1;
	char *str2;
	if (str == NULL)
	{
		return NULL;
	}
	else
	{
		i = 0;
		while (str[i] != '\0')
		{
			i++;
		}
			j = i - 1;
			str1 = (char *)malloc(sizeof(char*)*i);
			if (i == 0)
			{
				str1[i] = '\0';
				return str1;
			}
			else
			{
			i = 0;
			while (j >= 0)
			{
				if (str[j] != ' ')
				{
					k = 1;
					str1[i] = str[j];
					i++;
				}
				else if (k == 1)
				{
					break;
				}
				j--;

			}
			str1[i] = '\0';
				str2 = (char *)malloc(sizeof(char *)*i);
				j = 0;
				k = i - 1;
				while (k>=0)
				{
					str2[j] = str1[k];
					k--;
					j++;
				}
				str2[j] = '\0';
				return str2;
		}
		
	}
}
