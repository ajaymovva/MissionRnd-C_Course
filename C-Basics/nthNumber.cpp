/*
Given a value n

1. return nth Fibonacci number for the function nthFibonacci(int)
	EX: 0 for n=1 and 1 for n=2


2. return nth prime number for the function nthPrime(int)
	EX: 2 for n=1 and 3 for n=2

INPUTS: single integer n

OUTPUTS: nth Fibonacci number for nthFibonacci() 
		 nth prime number for nthPrime()

ERROR CASES: return -1 for the error cases
*/
#include<math.h>

int nthFibonacci(int n)
{
	int f1 = 0, f2 = 1, f3=0, i = 3;
	if (n <= 0)
		return -1;
	else if (n == 1)
		return f1;
	else if (n == 2)
		return f2;
	else
	{
		while (i <= n)
		{
			f3 = f1 + f2;
			f1 = f2;
			f2 = f3;
			i++;
		}
		return f3;
	}
	
}

int nthPrime(int num)
{
	int i = 0, k = 1, j = 1, z = 1;
	if (num <= 0)
	{
		return -1;
	}
	else
	{
		while (i < num)
		{
			k = 0;
			for (j = 1; j < z; j++)
			{
				if (z%j == 0)
				{
					k++;
				}
			}
			if (k == 1)
			{
				i++;

			}
			z++;

		}

		return z - 1;
	}
}