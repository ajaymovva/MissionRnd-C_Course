/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

Problem Code :SAP
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{

	int i, k = 0, p = 0, n;

	if (Arr == NULL || len < 0)
		return NULL;
	else
	{
		for (i = 0; i<len - 1; i++)
		{
			if (Arr[i]>Arr[i + 1])
			{
				k = i;
				break;
			}

		}
		for (i = 0; i<len - 1; i++)
		{
			if (Arr[i]>Arr[i + 1] && k != i)
			{
				p = i + 1;
				break;
			}
		}
		n = Arr[k];
		Arr[k] = Arr[p];
		Arr[p] = n;
		
	}
}