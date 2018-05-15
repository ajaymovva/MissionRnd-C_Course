
/*
OVERVIEW: Given an array of integers find the maximum possible sum formed by a positive and the negative
integer in the array.
Ex: input: [1, 9, 8, 2, 3, -1,-10,-5] output: 8 (formed by 9 and -1) 

INPUTS: An Integer array and the length of the array

OUTPUT: Maximum possible sum formed by a positive and the negative integer in the array

ERROR CASES: Return 0 for the invalid inputs

NOTES:
*/

#include <stdio.h>

int maxPosNegSum(int* input,int length)
{
	int i, p1, p2;
	p1 = 0, p2 = 0;
	for (i = 0; i<length; i++)
	{
		if (input[i] >= 0)
		{
			p1 = 1;
		}
		else if (input[i]<0)
		{
			p2 = 1;
		}
	}
	if (p1 == 0 || p2 == 0 || length <= 0)
	{
		return 0;
	}
	else
	{
		p1 = 0, p2 = -100;
		for (i = 0; i<length; i++)
		{
			if (input[i] >= p1)
			{
				p1 = input[i];
			}
			if (input[i]<0 && input[i]>p2)
			{
				p2 = input[i];
			}
		}
		//printf("\np1 %d p2 %d",p1,p2);
		p1 = p1 + p2;
		// printf("\nsum %d",p1);
		return p1;
	}
}