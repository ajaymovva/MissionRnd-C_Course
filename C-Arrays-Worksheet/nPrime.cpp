
/*
OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7] 

INPUTS: An Integer N

OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)

ERROR CASES: Return NULL for invalid inputs

Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}
NOTES:

Try to think of a optimized way , and avoid unnecessary comparisons.
*/

#include <stdio.h>
#include<stdlib.h>
int* nPrime(int N)
{
		if (N == 0)
			return NULL;
		else
		{
			int i, j, k, x;
			k = 0;
			int *arr1 = (int*)malloc(sizeof(int) * 100);
			int *arr;
			if (N == 0)
				return NULL;
			else
			{
				for (i = 1; i<N; i++)
				{
					x = 0;
					for (j = 1; j<i; j++)
					{
						if (i%j == 0)
						{
							x++;
						}
					}
					if (x == 1)
					{
						arr1[k] = i;
						k++;
					}
				}
				arr = (int*)malloc(sizeof(int)*k);
				for (i = 0; i<k; i++)
				{
					arr[i] = arr1[i];
				}
				return arr;
			}
	}
}