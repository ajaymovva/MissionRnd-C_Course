/*

Problem Code: IdentifyKid

There are three types of Guys,
'A' - Ambitious Boy 
'B' - Brilliant Boy
'C' - Creative Boy

The first generation guy is 'A'
each guy will have 3 kids 'A','B','C' , but the order will be different

'A' children will be  A ,B, C
'B' children will be  B ,C, A
'C' children will be  C ,A, B    ( rotations of “ABC”)


So basically , if it was represented in the form of a tree


1st  Generation -	                                   A
Index -                                                1
                                 /                     |                   \
2nd Generation -	            A                      B                    C
Index -			                1                      2                    3
                           /    |    \            /    |    \           /   |   \
3rd Generation -          A     B     C          B     C     A         C    A    B
Index-                    1     2     3          4     5     6         7    8     9

Given the N,K which represents the Nth generation and Kth index
You need to identify the type of the kid present there.

Note : If there is No Guy present there, return '\0'

*/

#include<stdio.h>
#include<string.h>
void fun(char c, int n, int k, int i, int *j, char *c1);
char identifyKid(int N, int K) {
	if (N<=0&&K<=0)
	return '\0';
	else
	{
		char c='\0';
		int i = 0;
		fun('A', N, K,1,&i,&c);
		return c;
	}
}
void fun(char c, int n, int k, int i, int *j,char *c1)
{
	if (i <= n&&*c1=='\0')
	{
		if (i == n)
		{
			(*j)++;
		}
		if (i == n&&*j == k)
		{
			*c1 = c;
		}
		else
		{
			if (i < n)
			{
				if (c == 'A')
				{
					fun('A', n, k, i + 1, j, c1);
					fun('B', n, k, i + 1, j, c1);
					fun('C', n, k, i + 1, j, c1);
				}
				else if (c == 'B')
				{
					fun('B', n, k, i + 1, j, c1);
					fun('C', n, k, i + 1, j, c1);
					fun('A', n, k, i + 1, j, c1);
				}
				else
				{
					fun('C', n, k, i + 1, j, c1);
					fun('A', n, k, i + 1, j, c1);
					fun('B', n, k, i + 1, j, c1);
				}
			}
		}
	}
}