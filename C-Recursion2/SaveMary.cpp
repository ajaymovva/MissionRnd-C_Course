/*

	Raju bhai is a new don in town. He enjoys hanging people every weekend.
	This weekend he assembled N people in a circular manner (1,2,..N,1) and choosen a random integer K. 
	He framed certain rules to hang people.
	
	Rule 1: He skips K-1 persons (inclusive) and hang Kth person.
	Rule 2: He always starts counting from 1st person.
	Rule 3: The last person will be allowed to live for rest of his life.
	
	Sample Case:
		Given N=5, K=2
			Initial state: 1,2,3,4,5
		Step 1: skips 1 and hangs 2
			1,3,4,5
		Step 2: Now skips 3 and hangs 4
			1,3,5
		Step 3: Now skips 5 and hangs 1
			3,5
		Step 4: Now skips 3 and hangs 5
			3
		As 3 is only person, he lets him live.

	Save our friend Mary by choosing correct position in the initial circle.
	You have to return the integer x, such that if mary is positioned at x in [1..N] she
	will not be killed, if no such position exists, return -1
	Fill the below function with code and return the postion.
	Return -1 for error cases
*/
#include<stdio.h>
#include<stdlib.h>
void fun(int *arr, int n, int k, int *p,int j);
void fun2(int *arr, int k1, int *p, int *j, int n, int k);
int saveMary(int n, int k){
	if (n<=0&&k<=0)
	return -1;
	else
	{
		int *arr = (int *)malloc(sizeof(int)*n);
		int i;
		for (i = 0; i < n; i++)
		{
			arr[i] = i + 1;
		}
		int k1=0;
		fun(arr, n, k-1,&k1,0);
		for (i = 0; i < n; i++)
		{
			if (arr[i] != 0)
			{
				break;
			}
		}
		return i + 1;
	}
}
void fun(int *arr, int n, int k,int *p,int j)
{
	if (*p != n && *p != n-1)
	{
		int k1=0;
		fun2(arr, k1, p, &j, n, k);
		fun(arr, n, k, p, j);
	}
}
void fun2(int *arr, int k1, int *p, int *j,int n,int k)
{
	if (k1 < n)
	{
		if (arr[k1] != 0)
		{
			if (*j == k)
			{
				arr[k1] = 0; (*p)++; *j = 0;
			}
			else
			{
				(*j)++;
			}
		}
		k1++;
		fun2(arr, k1, p, j, n, k);
	}
}