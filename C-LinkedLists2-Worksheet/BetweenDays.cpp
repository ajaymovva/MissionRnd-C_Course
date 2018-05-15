/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Year 999 will be represented as 0999.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};
int days(int *arr);
int between_days(struct node *date1head, struct node *date2head){
	struct node *temp;
	int *arr = (int *)malloc(sizeof(int) * 3);
	int *arr1 = (int *)malloc(sizeof(int) * 3);
	int i, j,n1,n2;
	if (date1head == NULL || date2head == NULL)
	{
		return -1;
	}
	else
	{
		temp = date1head; i = 0; j = 0;
		while (temp != NULL)
		{
			if (i < 2)
			{
				j = j * 10 + (temp->data);
				arr[0] = j;
				if (i == 1)j = 0;
			}
			else if (i < 4 && i>=2)
			{
				j = j * 10 + (temp->data);
				arr[1] = j;
				if (i == 3)j = 0;
			}
			else
			{
				j = j * 10 + (temp->data);
				arr[2] = j;
			}
			i++;
			temp=temp->next;
		}
		temp = date2head; i = 0; j = 0;
		while (temp != NULL)
		{
			if (i < 2)
			{
				j = j * 10 + (temp->data);
				arr1[0] = j;
				if (i == 1)j = 0;
			}
			else if (i < 4 && i >= 2)
			{
				j = j * 10 + (temp->data);
				arr1[1] = j;
				if (i == 3)j = 0;
			}
			else
			{
				j = j * 10 + (temp->data);
				arr1[2] = j;
			}
			i++;
			temp = temp->next;
		}
		n1 = days(arr);
		n2 = days(arr1);
		if (arr1[1] > 2)
		{
			if (arr1[2] % 4 == 0)
			{
				n2 = n2 + 1;
			}
		}
		if (arr[1] > 2)
		{
			if (arr[2] % 4 == 0&&arr[2]%100!=0)
			{
				n1 = n1 + 1;
			}
		}
		n1 = (n1 - n2);
		if (n1 == 0||n1==1)
			return 0;
		if (n1 < 0)
		{
			n1 = -n1;
		}
		return n1-1;
	}
}
int days(int *arr)
{
	int i,j,k1,k2,k3;
	int arr1[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	i = (arr[2] * 365); j = 0;
	while (j < arr[1]-1)
	{
		i = i + arr1[j];
		j++;
	}
	i = i + (arr[0]); j = 0; k1 = 0, k2 = 0, k3 = 0;
	while (j < arr[2])
	{
		if (j % 4 == 0)
		{
			k1++;
		}
		if (j % 100 == 0)
		{
			k2++;
		}
		if (j % 400 == 0)
		{
			k3++;
		}
		j++;
	}
	i = i +k1-k2+k3;
	return i;
}