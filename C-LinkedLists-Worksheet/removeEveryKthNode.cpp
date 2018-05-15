/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	int i;
	if (head == NULL||K < 2)
	{
		return NULL;
	}
	else
	{
		struct node *temp1,*temp;
		temp = head; temp1 = head;
		i = 0;
		while (temp != NULL)
		{
			i++;
			if (i == K)
			{
				temp1->next = temp->next;
				temp1 = temp->next;
				temp = temp->next;
				i = 0;
			}
			else
			{
				temp1 = temp;
				temp = temp->next;
			}
		}
		return head;
	}
}