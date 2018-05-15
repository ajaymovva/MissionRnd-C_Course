/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
int *spiralarray(int **arr, int *arr1, int rows, int cols,int r1,int c1, int k,int p,int p1,int k1)
{
	if (k1==1)
	{
		if (k < rows||p < cols)
		{
			if (p < cols)
			{
				while (p < cols)
				{
					arr1[p1] = arr[k][p]; p++; p1++;
				}
				p--; k++;
			}
			if (k <rows)
			{
				while (k < rows)
				{
					arr1[p1] = arr[k][p]; k++; p1++;
				}
				k--; p--;
			}
			return spiralarray(arr, arr1, rows - 1, cols - 1, r1, c1, k, p, p1, 2);
		}
		else{ return arr1; }
	}
	else
	{
		if ((k > r1 || p >= c1)&&(r1!=rows&&c1!=cols))
		{
			if (p >= c1)
			{
				while (p >= c1)
				{
					arr1[p1] = arr[k][p]; p--; p1++;
				}
				p++; k--;
			}
			if (k > r1)
			{
				while (k > r1)
				{
					arr1[p1] = arr[k][p]; k--; p1++;
				}
				k++; p++;
			}
			return spiralarray(arr, arr1, rows, cols, r1 + 1, c1 + 1, k, p, p1, 1);
		}
		else
			return arr1;
	}
}
int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL||rows<=0||columns<=0){ return NULL; }
	else
	{
		int *arr1 = (int *)malloc(sizeof(int)*(rows*columns));
		arr1 = spiralarray(input_array, arr1, rows, columns,0,0,0, 0,0,1);
		return arr1;
	}
}
