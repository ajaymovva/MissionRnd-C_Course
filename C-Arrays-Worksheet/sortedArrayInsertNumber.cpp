/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use memory allocation techniques to allocate memory.

ProblemCode :SAIN
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
		
	int i, j, x, k;
	int *Arr1;
	if (Arr == NULL || len<0)
	{
		return NULL;
	}
	else
	{
		Arr1 = (int*)malloc(sizeof(int)*(len + 1));
		x = 0, k = 0;
		for (i = 0; i<len; i++)
		{
			if (Arr[i] >= num&&k == 0)
			{
				Arr1[x] = num;
				k = 1;
				x++;
			}
			Arr1[x] = Arr[i];
			x++;
		}
		if (Arr[len - 1]<num)
		{
			Arr1[len] = num;
		}
		for (i = 0; i <= len; i++)
		{
			printf("%d", Arr1[i]);
		}
		return Arr1;
	}
	}
