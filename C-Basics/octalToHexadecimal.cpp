/*
OVERVIEW:
1)Write a function which takes a octal number as input and returns the hexadecimal number for 
  octalToHexadecimal().
E.g.: octalToHexadecimal(10) returns 8.

2)Write a function which takes a fractional octal number as input and returns the hexadecimal number for 
octalToHexadecimalFraction() until precision two
E.g.: octalToHexadecimal(6.01) returns 6.04

INPUTS: Single octal number num;

OUTPUT: hexadecimal value of the octal number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
int octalToHexadecimal(long int num)
{
	long int decimal = 0, k;
	int a, i = 0;
	char *str = (char*)malloc(0);
	if (num <= 0)
		return 0;
	else
	{
		while (num>0)
		{
			a = num % 10;
			decimal = decimal + (a*pow(8.0, i));
			num = num / 10;
			i++;
		}
		i = 0;
		while (decimal>0)
		{
			k = decimal % 16;
			decimal = decimal / 16;
			str[i] = k + '0';
			i++;
		}
		str[i] = '\0';
		_strrev(str);
		k = atoi(str);
		return k;
	}

}

float octalToHexadecimalFraction(float num)
{
	return 0.0;
}