/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	struct node *temp;
	int i, j,n1,n2,k;
	if (head == NULL)
	{
		return -1;
	}
	else
	{
		temp = head; i = 0;
		while (temp != NULL)
		{
			i++;
			temp = temp->next;
		}
		k = i;
		temp = head; j = 1; i = i / 2 + 1; n1 = 0, n2 = 0;
		while (temp != NULL)
		{
			if (j == i)
			{
				n1 = n2;
				n2 = temp->num;
				break;
			}
			else
			{
				j++;
				n1 = n2;
				n2 = temp->num;
			}
			temp = temp->next;
		}
		if (k % 2 == 0)
		{
			i = (n1 + n2) / 2;
			return i;
		}
		else
		{
			return n2;
		}

	}
}
