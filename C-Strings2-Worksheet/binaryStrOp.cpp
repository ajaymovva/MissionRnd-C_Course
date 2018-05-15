/*

ProblemCODE : BINARYSTROP
Difficulty : Medium
Marks : 15

Given two binary numbers in form of strings and
a string representing "AND", "OR", "NOR" or "XOR". Return the output string which forms by doing the specified operation on those 2 strings .


Ex:	Input: "101", "111", op =  "OR"
Output: "111"


Ex:	Input: "10101", "1111", op =  "AND"
Output: "00101"

Ex:	Input: "0111", "1010", op =  "XOR"
Output: "0010"

Ex:	Input: "0011", "1010", op =  "NOR"
Output: "0100"

Note :
In the above representations ,Write those strings on a paper ,you will understand them better . [Align them to the Right]
If 1 string length is less than other ,you need to consider missing letters as 0's ie "1111" AND "1" is same as "1111" AND "0001".
Ie if a String is "" ,you should consider it as All 0's .This dosent not apply if String is NULL.

Reference : http://www.bristolwatch.com/pport/pics/logic_table.gif [For AND,OR,XOR]
For NOR : http://www.circuitstoday.com/wp-content/uploads/2010/04/2-Input-NOR-Gate-Truth-Table.jpg

Contraints :
String length < 50.
For 50% of TestCases ,only AND/OR operations will be given .

Difficulty : Medium

*/

#include <stdio.h>
#include <stdlib.h>


char *performOperation(char *str1, char *str2, char *operation){

	int l1=0, l2 = 0,x=0,i,k,j;
	char *str3; char *str4; char *str5;
	if (str1 == NULL || str2 == NULL || operation == NULL)
	{
		return NULL;
	}
	else
	{
		while (str1[l1] != '\0')
		{
			l1++;
		}
		while (str2[l2] != '\0')
		{
			l2++;
		}
		if (l1 > l2)
		{
			x = l1 + 1;
		}
		else
		{
			x = l2 + 1;
		}
		str3 = (char *)malloc(sizeof(char)*x);
		str4 = (char *)malloc(sizeof(char)*x);
		str5 = (char *)malloc(sizeof(char)*x);
		for (i = 0; i < x; i++)
		{
			str3[i] = '0';
		}
		for (i = 0; i < x; i++)
		{
			str4[i] = '0';
		}
		if (l1 <=x - 1)
		{
			k = x - 1 - l1; j = 0;
			for (i = k; i < x-1,j<l1; i++)
			{
				str3[i] = str1[j];
				j++;
			}
		}
		str3[i] = '\0';
		if (l2 <= x - 1)
		{
			k = x - 1 - l2; j = 0;
			for (i = k; i < x - 1,j<l2; i++)
			{
				str4[i] = str2[j];
				j++;
			}
		}
		str4[i] = '\0';
		if (operation[0] == 'A')
		{
			i = 0;
			while (i < x - 1)
			{
				str5[i] = ((str3[i] - 48)&(str4[i] - 48)) + '0';
				i++;
			}
		}
		else if (operation[0] == 'O')
		{
			i = 0;
			while (i < x - 1)
			{
				str5[i] = ((str3[i] - 48)|(str4[i] - 48)) + '0';
				i++;
			}
		}
		else if (operation[0] == 'X')
		{
			i = 0;
			while (i < x - 1)
			{
				str5[i] = ((str3[i] - 48)^(str4[i] - 48)) + '0';
				i++;
			}
		}
		else if (operation[0] == 'N')
		{
			i = 0;
			while (i < x - 1)
			{
				str5[i] =((str3[i] - 48)|(str4[i] - 48)) + '0';
				if (str5[i] == '0')
				{
					str5[i] = '1';
				}
				else if (str5[i] == '1')
				{
					str5[i] = '0';
				}
				i++;
			}
		}
		str5[x - 1] = '\0';
		return str5;
	}
}








