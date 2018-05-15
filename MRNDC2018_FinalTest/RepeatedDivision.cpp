/*

problemCode : RepeatedDivision
score : 10

Repeated 2 Division.

Given a Number N, your task is to find a number in the range [1,N]
such that the number is most divisible reptedly by 2

Example :
N = 6

x   -    DivisibleCount
1   -    0
2   -    1
3   -    0
4   -    2
5   -    0
6   -    1

Hence the answer is 4 since it can be repetedly divisible 2 times.

CONSTRAINTS : 
	1 <= N < 2^32

*/


int RepeatedDivision(int N){
	if (N <= 0)
	{
		return -1;
	}
	else
	{
		int i = 1,k,j;
		int n1 = 0, n2 = 0;
		while (i <= N)
		{
			k = 0;
			j = i;
			while (j % 2 == 0&&j!=1)
			{
				k++;
				j = j / 2;
			}
			if (n1 < k)
			{
				n1 = k;
				n2 = i;
			}
			i++;
		}
		return n2;
	}
}

