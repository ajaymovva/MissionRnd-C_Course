/*

Here you will be doing the same ArraysQuestion you did before, but now in multiple ways.

OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7]
INPUTS: An Integer N
OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)
ERROR CASES: Return NULL for invalid inputs
Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}

Observations: (Write down what you observed here):

Way 1 :complexity is O(n*n)

Way 2 :comparisions are reduced a lot than way1.

Way 3:Nice hint but taking some time to analyse it was best way to analysing a problem.
It takes O(n) complexity.

Conclusion :
*/

#include <stdio.h>
#include <math.h>
#include<stdlib.h>

/*

Manually loop over every element, Find if its prime or not. Store it in an array.
Write the worst complexity code you can write :D.
*/
int* nPrimeBruteForce(int N)
{
	int *arr1 = (int *)malloc(sizeof(int *)*N);
	int i,j,p=0,k;
	if (N <= 0)
	{
		return NULL;
	}
	else
	{
		for (i = 2; i <= N; i++)
		{
			k = 0;
			for (j = 1; j < i; j++)
			{
				if (i%j == 0)
				{
					k++;
				}
			}
			if (k == 1)
			{
				arr1[p] = i;
				p++;
			}
		}
		return arr1;

	}
}


/*
Remove even numbers, Run it again.
Just remove even numbers. So it should essentially take half of time for function 1, Did it really happened?

*/
int* nPrimeEvenRemoved(int N)
{
	int *arr1 = (int *)malloc(sizeof(int *)*N / 2);
	int i, j, p = 0, k;
	if (N <= 0)
	{
		return NULL;
	}
	else
	{
		arr1[p] = 2;
		for (i = 3; i <= N; i+=2)
		{
			k = 0;
			for (j = 1; j <i; j+=2)
			{
				if (i%j == 0)
				{
					k++;
				}
			}
			if (k == 1)
			{
				p++;
				arr1[p] = i;
			}
		}
		return arr1;

	}
}

/*
Do all optimizations you can think of.

Hint : 
A number can be considered a prime, if its not divisible by any of the primes which are less than it.
ie 100 can be considered as a prime, if no prime number which is less than 100 divides 100 (With remainder as 0).
7 is prime as no prime less than it (2,3,5) can divide it. Think proof for this too.

This heavily reduces the number of divisions you do. If you did correctly you should see some heavy difference in timings.

*/
int* nPrimeOptimized(int N)
{
	int *arr1 = (int *)malloc(sizeof(int *)*N);
	int *arr2 = (int *)malloc(sizeof(int)*200);
	int i, j, p = 0, k=0;
	double d=0;
	if (N <= 0)
	{
		return NULL;
	}
	else
	{
		j = 2, p = 0;
		for (i = 2; i < N - 1; i++)
		{
			arr1[i] = 0;
		}
		arr1[N - 1] = 0;
		i = 2;
		d = N;
		d = sqrt(d);
		while (i < d)
		{
			if (arr1[i] == 0)
			{
				j = i*i;
				while (j < N)
				{
					arr1[j] = -1;
					j = j + i;
				}
			}
			i++;
		}
		k = 0;
		for (i = 2; i<N; i++)
		{
			if (arr1[i] == 0)
			{
				arr2[k] = i;
				k++;
			}
		}
		return arr2;

	}
	
}