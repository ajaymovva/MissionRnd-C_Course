/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void number_to_str(float number, char *str,int afterdecimal){
	int a,l,i,j,k;
	float f;
	a = (int)number;
	itoa(a, str, 10);
	l = strlen(str);

	if (afterdecimal > 0)
	{
		if (number < 0)
		{
			number = -number;
		}
		str[l] = '.';
		i = 0;
		f = number - a;
		while (i < afterdecimal)
		{
			f = f * 10;
			i++;
		}
		i = (int)f;
		j = l + afterdecimal;
		k = 0;
		while (k < afterdecimal)
		{
			a = i % 10;
			str[j] = a + '0';
			i = i / 10;
			j--;
			k++;
		}
		
	}
	
}
