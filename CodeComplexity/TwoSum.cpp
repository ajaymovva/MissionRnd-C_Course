/*
Given an array of integers, return the two numbers such that they add up to a specific target.

You may assume that each input will have exactly one solution. Return NULL for invalid inputs

Given nums = [1, 20, 2, 4], target = 24,

Because nums[1] + nums[3] = 20 + 4 = 24,
return [4, 20]. (Always the first number should be less in final answer)

If target is 5 ,Return [1,4]
If target is 22 ,return [2,20]

Note :
Return_Array[0] should always be less than/equal to Return_Array[1]

Constraints :
len <100000
-100000< nums[i] <100000

Question Source Link : https://leetcode.com/problems/two-sum/
We Picked this standard problem from Online , as its a very famous one and you will get habituated on solving on
Leetcode .

You need to solve this question in 3 ways.And measure time for each way.

Observations: (Write down what you observed here):

Way 1 :Time of execution is 3ms for a given length of 5 

Way 2 :Time of execution is 878ms  for a given length of 1000

Way 3:Time of execution is 323ms for a given length of 1000

Conclusion :
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
Take each element, Sum with all other elements.
Repeat it with all elements.

What is the complexity of this method ? _____O(n*n)_____
*/
void mergesort(int *arr, int low, int high,int len);
void sort(int *arr, int low, int high, int mid,int len);
//void qsort(int *, int, int, int);
int *arr1;
int* sumoftwoBF(int *nums, int target, int len){
	int i, j,k=0;
	int *arr = (int *)malloc(sizeof(int) * 2);
	if (nums==NULL||len<=0)
	return NULL;
	else
	{
		for (i = 0; i < len; i++)
		{
			for (j = 0; j < len; j++)
			{
				if (nums[i] + nums[j] == target)
				{
					k = 1;
					break;
				}
			}
			if (k == 1)
			{
				break;
			}
		}
		if (nums[i] < nums[j])
		{
			arr[0] = nums[i];
			arr[1] = nums[j];
		}
		else
		{
			arr[0] = nums[j];
			arr[1] = nums[i];
		}
		return arr;
	}
}

/*
Sort the array first. Preferably using quicksort/mergesort. (nlogn)

Now the array is sorted, Can you do improve the above method.

Hint: 
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11. 

Lets say we added 3+12 first, whats the sum, Its 15 right ? Its greater than 11.So should we next add 
so that total sum will become less. 

What is the complexity of this method ? __O(n*logn)________
*/
int* sumoftwoSortAndSearch(int *nums, int target, int len){
	//Sort the array
	int i,j;
	int *arr = (int *)malloc(sizeof(int) * 2);
	if (nums == NULL || len <= 0)
		return NULL;
	else
	{
		arr1 = (int *)malloc(sizeof(int *) * len);
		mergesort(nums,0, len-1,len);
		//Do the task
		//qsort(nums, 0, len - 1, len);
		i = 0, j = len - 1;
		while (i<j)
		{
			if (nums[i] + nums[j] == target)
			{
				break;
			}
			else if (nums[i] + nums[j] > target)
			{
				j--;
			}
			else
			{
				i++;
			}

		}
		arr[0] = nums[i];
		arr[1] = nums[j];
		return arr;
	}
}


/*

Array contains only integers from 1-100; Can you use this range restriction and an extra array to 
find 2Sum even more faster

Hint:
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11.

If we are at 3, What number we need to tell that 3 is in final answer? 8 right (11-3 = 8). So some how we need to find a way
to know whether 8 is already in the array or not.As of now we dont know that, we will store 3 somewhere
(Which can be accesible in O(1)) and move to next element. 4 is there, we need to know whether array has 7 or not.(11-4 =7)
We dont know that yet, we move on ...we will store 4 somewhere now.

We go on till 7(4th element). We reach here we require 4 (11-7 = 4) .We already know 4 is present in array. (With O(1)).
We immediately return the answer. Think and discuss with your friends.

You are expected to solve this method in O(n)
*/
int* sumoftwoExtraArray(int *nums, int target, int len) {
	//Initialise the array
	//Do the task
	int i=0, j=0, k = 0;
	int *arr = (int *)malloc(sizeof(int) * 2);
	int *arr1 = (int *)malloc(sizeof(int) * 101);
	if (nums == NULL || len <= 0)
		return NULL;
	else
	{
		for (i = 0; i <=100; i++)
		{
			arr1[i] = 0;
		}
		for (i = 0; i < len; i++)
		{
			k = nums[i];
			if (k != 0)
			{
				arr1[k] = k;
			}
		}
		for (i = 0; i < 101; i++)
		{
			if (arr1[i] + arr1[target - i] == target)
			{
				break;
			}
		}
		if (arr1[i]>arr1[target - i])
		{
			arr[0] = arr1[target - i];
			arr[1] = arr1[i];
		}
		else
		{
			arr[0] = arr1[i];
			arr[1] = arr1[target - i];
		}
		return arr;

	}
}

void mergesort(int *nums, int low,int high,int len)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		mergesort(nums, low, mid,len);
		mergesort(nums, mid + 1, high,len);
		sort(nums, low, high, mid,len);
	}
}
void sort(int *nums, int low, int high, int mid,int len)
{
	int i, j, k=low;
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



