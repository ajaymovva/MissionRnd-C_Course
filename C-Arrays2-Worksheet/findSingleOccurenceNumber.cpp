/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/

#include<stdio.h>
#include <stdlib.h>
void mergesort(int *nums, int low, int high, int len);
void sort(int *nums, int low, int high, int mid, int len);
int *arr1;
int findSingleOccurenceNumber(int *A, int len) {
	int i;
	if (A==NULL)
		return -1;
	else
	{	
		arr1 = (int *)malloc(sizeof(int) * len);
		mergesort(A, 0, len - 1, len);
		for (i = 0; i < len; i++)
		{
			if (A[i] == A[i + 1])
			{
				i = i + 2;
			}
			else
			{
				break;
			}
		}
		return A[i];

	}
}
void mergesort(int *nums, int low, int high, int len)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		mergesort(nums, low, mid, len);
		mergesort(nums, mid + 1, high, len);
		sort(nums, low, high, mid, len);
	}
}
void sort(int *nums, int low, int high, int mid, int len)
{
	int i, j, k = low;
	i = low; j = mid + 1;
	while (i <= mid&&j <= high)
	{
		if (nums[i] < nums[j])
		{
			arr1[k] = nums[i];
			k++;
			i++;
		}
		else
		{
			arr1[k] = nums[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		arr1[k] = nums[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		arr1[k] = nums[j];
		j++;
		k++;
	}
	for (k = low; k <= high; k++)
	{
		nums[k] = arr1[k];
	}
}
