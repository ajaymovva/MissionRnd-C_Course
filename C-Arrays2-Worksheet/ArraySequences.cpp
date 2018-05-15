/*
Given an array which has two arithmetic sequences and
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array
will be start and end indexes of Second A.P

The final_arr[4], final_arr[5] values in final array
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index .

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int * find_sequences(int *arr, int len){
	int *arr1 = (int *)malloc(sizeof(int)*len - 1);
	float *arr2 = (float *)malloc(sizeof(int)*len - 1);
	int *finarr = (int *)malloc(sizeof(int) * 6);
	int i,k,p;
	float k1;
	if (arr == NULL&&len <= 0)
	{
		return NULL;
	}
	else
	{
		for (i = 1; i < len; i++)
		{
			arr1[i-1] = arr[i] - arr[i - 1];
			k = arr1[i - 1];
		}
		for (i = 1; i < len; i++)
		{
			arr2[i - 1] = (float)arr[i] / arr[i - 1];
			k1 = arr2[i - 1];
		}
		k = 0;
		for (i = 0; i < len - 2; i++)
		{
			if (arr2[i] == arr2[i + 1])
			{
				p = i+1;
				k++;
			}
			else if (arr2[i] != arr[i + 1] && k != 0)
			{
				break;
			}
		}
		finarr[4] = p - k;
		finarr[5] = p + 1;
		k = 0;
		for (i = 0; i < len - 2; i++)
		{
			if (arr1[i] == arr1[i + 1])
			{
				p = i + 1;
				k++;
			}
			else if (arr1[i] != arr1[i + 1] && k != 0)
			{
				break;
			}
		}
		finarr[0] = p - k;
		finarr[1] = p + 1;
		k = 0;
		for (i = p+1; i < len - 2; i++)
		{
			if (arr1[i] == arr1[i + 1])
			{
				p = i + 1;
				k++;
			}
			else if (arr1[i] != arr1[i + 1] && k != 0)
			{
				break;
			}
		}
		finarr[2] = p - k;
		finarr[3] = p + 1;
		return finarr;
	}
}