/*
ProblemCode : STRMATCH
Marks : 10
Difficulty :Easy.

A String(which only has small case a-z letters) is said to be corrupted if some of the charecters are removed and replaced by the number of characters removed .
Like : apple can be converted into a3e (ppl removed), or a4 (pple removed),ap2e (pl removed) .

helloworld can be modified as hello5 , h9 , 9d , etc , There is no limit on the number of characters that can be removed , or number of different times they can be
removed .

Some more examples are ,abcdefghijkl can be modified as a2d2g4l , a10l .
If 2 or more numbers occured consecutively , you should consider them as a whole , like a23re , is not a "2Chars removed" "3Chars Removed" re ,
it is a "23 Chars removed" re .

Your Task is , Given two corrupted Strings , you need to find whether a common word can be formed from those both corrupted strings
, If Yes ,return 1 , If no word can formed return 0 , -1 For invalid inputs .

Ex Input : s1= "a3e" and s2="4e" , Example Output : 1 .

This is because , apple word can be formed from both .

Ex Input 2 : s1= "k2e2f" and s2="k1fr3" , Returns 0 . No common word can be formed from those both Strings .
Ex Input 3: "5e3" and "abcdeej2" returns 1 , where as if s1 is 5e3i and s2 is abcdeekoll returns 0

Constraints :
A String will only have letters from "a-z and 0-9" ;
0<=Len Of Str1,Str2 <=10000
Numbers occuring in the String can be anything from 1 till 999 .

You can implement the helper functions ,if you want ,Although its optional .Dont worry about space for this question .

Note : Only 25% of Cases ,will have numbers >9 in the Strings .
*/
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int isSTRMatched(char *str1, char *str2){

	int l1 = 0, l2 = 0, k1 = 0, k2 = 0, p, i, p1, p2, sum1 = 0, sum = 0, x = 0;
	if (str1 == NULL || str2 == NULL)
	{
		return 1;
	}
	else
	{
		while (str1[l1] != '\0')
		{
			p = str1[l1];
			if ((p >= 122 || p <= 97))
			{
				if (p >= 48 || p <= 57)
				{
				}
				else
				{
					k1 = 1;
				}
			}
			l1++;
		}
		while (str2[l2] != '\0')
		{
			p = str2[l2];
			if ((p >= 122 || p <= 97))
			{
				if (p >= 48 || p <= 57)
				{
				}
				else
				{
					k2 = 1;
				}
			}
			l2++;
		}
		if (l1 > 10000 || l2 > 10000 || k1 == 1 || k2 == 1)
		{
			return -1;
		}
		else
		{
			i = 0, p = 0;
			while (i < l1 - 1)
			{
				k1 = str1[i];
				k2 = str1[i + 1];
				if ((k1 >= 48 && k1 <= 57) && (k2 >= 48 && k2 <= 57))
				{
					p = 1;
					break;
				}
				i++;
			}
			i = 0, p1 = 0;
			while (i < l2 - 1)
			{
				k1 = str2[i];
				k2 = str2[i + 1];
				if ((k1 >= 48 && k1 <= 57) && (k2 >= 48 && k2 <= 57))
				{
					p1 = 1;
					break;
				}
				i++;
			}
			if (p == 0&&p1==0)
			{
				k1 = 0; k2 = 0; p1 = 0; p2 = 0;
				while (k1 < l1)
				{
					i = str1[k1];
					if (i >= 48 && i <= 57)
					{
						p1 = p1 + (i - 48);
					}
					else
					{
						p1++;
					}
					k1++;
				}
				while (k2 < l2)
				{
					i = str2[k2];
					if (i >= 48 && i <= 57)
					{
						p2 = p2 + (i - 48);
					}
					else
					{
						p2++;
					}
					k2++;
				}
				if (p1 != p2)
				{
					return 0;
				}
				else
				{
					k1 = 0; k2 = 0; p1 = 0; p2 = 0, i = 0;
					while (k1 < l1&&k2 < l2)
					{
						p1 = str1[k1];
						p2 = str2[k2];
						if ((p1 >= 97 && p1 <= 122) && (p2 >= 97 && p2 <= 122))
						{
							if (str1[k1] != str2[k2])
							{
								i = 1;
								break;
							}
							else
							{
								k1++;
								k2++;
							}
						}
						else if ((p1 >= 48 && p1 <= 57) || (p2 >= 48 && p2 <= 57))
						{
							if (p2 >= 48 && p2 <= 57)
							{
								k1 = k1 + p2 - 48;
							}
							if (p1 >= 48 && p1 <= 57)
							{
								k2 = k2 + p1 - 48;
							}
						}
						else
						{
							k1++;
							k2++;
						}

					}
					if (i == 0)
					{
						return 1;
					}
					else
					{
						return 0;
					}
				}
			}
			else
			{
				k1 = 0, k2 = 0; p1 = 0, p2 = 0; sum = 0, sum1 = 0; x = 0; i = 0;
				while (k1 < l1||k2 < l2)
				{
					p1 = str1[k1];
					p2 = str2[k2]; x = 0;
					if (sum1 == sum && (p1 >= 97 && p1 <= 122) && (p2 >= 97 && p2 <= 122)&&(k1<l1&&k2<l2))
					{
						if (p1 != p2)
						{
							i = 1;
							break;
						}
					}
					
					 if ((p1 >= 48 && p1 <= 57))
					{
						while ((p1 >= 48 && p1 <= 57) && k1 < l1)
						{
							x = (x * 10) + (p1 - 48);
							k1++;
							p1 = str1[k1];
						}
						sum = sum + x;
						x = 0;
					}
					 else if ((p1 >= 97 && p1 <= 122)&&k1<l1)
					 {
						 k1++;
						 sum = sum + 1;
					 }
					 if ((p2 >= 48 && p2 <= 57))
					 {
						while ((p2 >= 48 && p2 <= 57) && k2 < l2)
						{
							x = (x * 10) + (p2 - 48);
							k2++;
							p2 = str2[k2];
						}
						sum1 = sum1 + x;
					}
					 else if ((p2 >= 97 && p2 <= 122) && (k2<l2))
					{
						k2++;
						sum1 = sum1 + 1;
					}
					 
				}
				if (sum1 != sum)
				{
					return 0;
				}
				else
				{
					if (i == 0)
					{
						return 1;
					}
					else
					{
						return 0;
					}
				}
			}
		}
	}
}
