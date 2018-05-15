/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
#include<stdlib.h>
int removeArrayDuplicates(int *Arr, int len)
{
	
	int k = 0, i = 0, j = 0, n, x;
	k = 0;
	n = len;
	int *arr1;
	if (len <= 0||Arr==NULL)
		return -1;
	
	else
	{
		arr1 = (int*)malloc(sizeof(int) * n);
		for (i = 0; i<len; i++)
		{
			arr1[i] = Arr[i];
		}
		for (i = 0; i<len; i++)
		{
			j = 0, x = 0;
			n = arr1[i];
			for (j = 0; j<i; j++)
			{
				if (n == arr1[j])
				{
					x++;
				}
			}
			if (x == 0)
			{
				k++;
				Arr[k - 1] = n;
			}
		}

		for (i = 0; i<k; i++)
		{
			printf("%d", Arr[i]);
		}
		return k;

	}

}