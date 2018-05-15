/*
OVERVIEW: 
1)Write a function which takes a decimal number as input and returns the octal number for decimalToOctal().
E.g.: decimalToOctal(10) returns 12.

2)Write a function which takes a fractional decimal number as input and returns the octal number for decimalToOctalFraction()
until precision two
E.g.: decimalToOctal(6.06) returns 6.03

INPUTS: Single decimal number num;

OUTPUT: Octal value of the Decimal Number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>
#include<string.h>
int decimalToOctal(int num)
{
	char *str = (char*)malloc(0);
	int i = 0, k;
	if (num <= 0)
		return 0;
	else
	{
		while (num>0)
		{
			k = num % 8;
			num = num / 8;
			str[i] = k + '0';
			i++;
		}
		str[i] = '\0';
		_strrev(str);
		k = atoi(str);
		return k;
	}
}

float decimalToOctalFraction(float num)
{
	int n, k,i,n1;
	char *str = (char *)malloc(0);
	float p;
	if (num<=0)
	return 0.0;
	else
	{
		n = (int)num;
		k = decimalToOctal(n);
		p = num - n;
		i = 0;
		while (i < 2)
		{
			p = p * 8;
			n1 = (int)p;
			str[i] = n1;
			i++;
		}
		str[i] = '\0';
		n1 = atoi(str);
		p = (float)n1 / 100;
		p = k + p;
		return p;

	}
}

