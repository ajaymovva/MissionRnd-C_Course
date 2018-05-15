/*
OVERVIEW: Given a string, Count the number of consonants and vowels and copy them to 'consonants' and 'vowels' respectively
Notes : Neglect Space and Other Symbols .Consider Capital Letters too

E.g.: Input: "aB c" , Output: consonants should contain 2 and vowels 1

INPUTS: A string and two int pointers

OUTPUT: Modify the consonants and vowels pointers accordingly with their counts (*consonants=?? ;*vowels=??)

INPUT2: Dont Forget they are pointers ;consonants and vowels are addresses of two variables .

Output: consonants should be ??,vowels should be ??

??:Count them :)

NOTES: Don't create new string , Dont return anything ,you have been given two pointers ,copy values into those .
*/

#include <stddef.h>

void count_vowels_and_consonants(char *str, int *consonants, int *vowels){
	int i=0,k,k1=0,k2=0;
	if (str == NULL)
	{
		*consonants = 0;
		*vowels = 0;
	}
	else
	{
		while (str[i] != '\0')
		{
			k = str[i];
			if ((k >= 65 && k <= 90) || (k >= 97 && k <= 122))
			{
				if (k == 65 ||k == 69 || k==73 || k==79 ||k== 85 || k==97 || k==101 || k==105 ||k== 111 ||k== 117)
				{
					k1++;
				}
				else
				{
					k2++;
				}
			}
			i++;
		}
		*vowels = k1;
		*consonants = k2;

	}
}
