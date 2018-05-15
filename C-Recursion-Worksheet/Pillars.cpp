/*
Some where in MissionRnD world ,there is a large plot of empty Rectangular land ,divided into Blocks of
equal size . A Land of N Blocks at length and M Blocks at Breadth will have total of N x M Blocks .

Each Block has a pillar of Height H .[0 <= H <=100000] .A Pillar is said to be a Leader if there are no more
neighbouring pillars (East ,West ,Noth and South) whose height is greater than current one .
And excatly opposite ,A pillar is said to be a Looser if there are no more neighbouring pillars
whose height is less than the current pillar height

If a block has 0 specified ,It has No pillar and No person can be on that block.In the below example
1,2,4... are heights of pillars at that block.Do not consider 0 while calculating Leaders or Loosers .
Example :

1 2 0 1 0
0 0 0 9 0
0 0 0 8 0
0 1 4 6 5
0 0 2 3 4

Here a[0][1] ie 2 ,and a[1][3] ie 9 are leaders ,as all their neighbouring elements are less or equal than it .
Here a[0][0] ie 1 ,and a[0][3] ie 1 and a[3][1] ie 1 and a[4][2] ie 2 are Loose Pillars ,as all their
neighbouring pillars height are greater or equal than it .

Now there is a child who likes to jump from one pillar to another ,He starts at a looser Pillar and jumps to
a nearby pillar (4 Directions) ,if the nearby pillar height is "strictly greater" than curernt pillar height .
So he can jump from 1 to 3 ,or 3 to 7 but not 4 to 1 and 5 to 5 .[all these are heights]
He continues jumping until he reaches a LeaderPillar .

As he likes jumping ,He would like to know the Path which starts at a Looser Pillar and ends at a Leader Pillar
that involves maximum jumps ,Can you help the child solve his Task ?

In the above example :
1-2 Path , requires only 1 jump
1-4-6-8-9 requires 4 jumps
2-3-4-5-6-8-9 requires 6 jumps
1-9 requires only 1 jump.
So in the above example you need to return [2,3,4,5,6,8,9] and copy 6 in jumps_count

Input :
A 2D Array (passed as Single pointer,First element Address) ,N (number of Cols), M(number of rows),
jumps_count (Pointer to an Integer)
Output :
Return the Max Jumps path  ,and copy number of max jumps into jumps_count .

Constraints :
0<=N<=10000
0<=M<=10000
Note : If there is no such path ,Copy 0 in jumps_count and return NULL,(Same for Invalid Inputs too)
Examples :
-----
2 1 7
3 0 4   ->Max Path : [1,2,3,5,6] ,jumps_count =4 [Here both 4's are looser elements]
5 6 4
--------
5 8 9 10
4 3 1 0
3 0 0 3   ->Max Path is [1,2,3,4,5,8,9,10] , jumps_count =8
2 1 1 1
---------
0 0 0
0 4 0  ->Max Path is [4] ,jumps_count=0;
0 0 0
Note : There will be only One Maximum Jumps path .[If there are multiple ,Return any 1 path]
*/
#include <stdlib.h>
#include <stdio.h>
int * lower(int **arr, int r, int c,int *jumpscount);
void fun(int **arr, int i, int j, int r, int c, int *res, int *res1, int k, int *k1);
int * pillars_max_jumps(int *blocks, int n, int m, int *jumps_count){
	if (blocks==NULL||n<=0||m<=0)
	return NULL;
	else
	{
		int i,k=0,j, p=0,p1;
		int **arr = (int **)malloc(sizeof(int*)*m);
		for (i = 0; i < m; i++){ arr[i] = (int *)malloc(sizeof(int)*n); }
		int *res1;
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				p1 = blocks[k]; k++;
				arr[i][j] = p1;
				if (arr[i][j] != 0)
				{
					p++;
				}
			}
		}
		if (p == 0){ return NULL; }
		j = 0;
		res1 = lower(arr, m, n, &j);
		if (j >1)
		{
			*jumps_count = j - 1;
		}
		else{ *jumps_count = j; }
		if (j == 0){ res1[0] = 1; }
		return res1;
	}
}
int *lower(int **arr, int r, int c,int *jumpscount)
{
	int i, j, k, p, p1; p1 = 0;
	int *result = (int *)calloc(sizeof(int),(r*c));
	int *result1 = (int *)calloc(sizeof(int),(r*c));
	int *result2 = (int *)calloc(sizeof(int), (r*c));
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			if (arr[i][j] != 0)
			{
				k = 0;
				if (i > 0)
				{
					if (arr[i - 1][j] != 0)
					{
						if (arr[i - 1][j] > arr[i][j])
						{
							k++;
						}
					}
					else k++;
				}
				else k++;
				if (i < r - 1)
				{
					if (arr[i + 1][j] != 0)
					{
						if (arr[i + 1][j] > arr[i][j]){ k++; }
					}
					else k++;
				}
				else k++;
				if (j > 0)
				{
					if (arr[i][j - 1] != 0)
					{
						if (arr[i][j - 1] > arr[i][j]){ k++; }
					}
					else k++;
				}
				else k++;

				if (j < c - 1)
				{
					if (arr[i][j + 1] != 0)
					{
						if (arr[i][j + 1] > arr[i][j]){ k++; }
					}
					else k++;
				}
				else k++;

				if (i < r - 1 && j>0 && j < c - 1)
				{
					if (arr[i + 1][j] == arr[i][j] && arr[i][j - 1] > arr[i][j] && arr[i][j + 1] == arr[i][j])
					{
						k = 4;
					}
				}

				if (k == 4)
				{
					result[0] = arr[i][j]; p = 1;
					fun(arr, i, j,r,c, result,result1,1,&p);
					if (p > p1)
					{
						p1 = p;
						for (int k1 = 0; k1 < p1; k1++)
						{
							result2[k1] = result1[k1];
						}
					}
				}
			}
		}
	}
	*jumpscount = p1;
	return result2;
}
void fun(int **arr, int i, int j, int r, int c, int *res, int *res1, int k,int *k1)
{
	if (arr[i][j] != 0 && i < r&&j < c)
	{
		if (i > 0)
		{
			if (arr[i - 1][j]>arr[i][j])
			{
				res[k] = arr[i - 1][j];
				fun(arr, i - 1, j, r, c, res, res1, k+1,k1);
			}
		}
		if (i < r - 1)
		{
			if (arr[i + 1][j] > arr[i][j])
			{
				res[k] = arr[i + 1][j];
				fun(arr, i + 1, j, r, c, res, res1, k + 1,k1);
			}
		}
		if (j > 0)
		{
			if (arr[i][j - 1] > arr[i][j])
			{
				res[k] = arr[i][j - 1];
				fun(arr, i, j - 1, r, c, res, res1, k + 1,k1);
			}
		}
		if (j < c - 1)
		{
			if (arr[i][j + 1] > arr[i][j])
			{
				res[k] = arr[i][j + 1];
				fun(arr, i, j + 1, r, c, res, res1, k + 1,k1);
			}
			else
			{
				if (*k1 < k)
				{
					*k1 = k;
					for (int p = 0; p < *k1; p++)
					{
						res1[p] = res[p];
					}
				}
			}
		}
		else
		{
			if (*k1 < k)
			{
				*k1 = k;
				for (int p = 0; p < *k1; p++)
				{
					res1[p] = res[p];
				}
			}
		}
	}
}
