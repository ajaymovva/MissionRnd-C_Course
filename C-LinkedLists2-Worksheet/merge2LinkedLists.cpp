/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>
struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node *temp1, *temp2,*temp3,*n,*head;
	if (head1 == NULL&&head2 == NULL)
	{
		return NULL;
	}
	else if (head1 == NULL&&head2 != NULL)
	{
		return head2;
	}
	else if (head1 != NULL&&head2 == NULL)
	{
		return head1;
	}
	else
	{
		head = (struct node*)malloc(sizeof(struct node));
		head->next = NULL;
		head->num = 1;
		temp1 = head1; temp2 = head2; temp3=head;
		
		while (temp1 != NULL&&temp2 != NULL)
		{
			if (temp1->num > temp2->num)
			{
				temp3->next = temp2; temp3 = temp3->next; temp2 = temp2->next;
			}
			else
			{
				temp3->next = temp1; temp3 = temp3->next;
				temp1 = temp1->next;
			}
		}
		while (temp1 != NULL)
		{
			temp3->next = temp1; temp3 = temp3->next;
			temp1 = temp1->next;
		}
		while (temp2 != NULL)
		{
			temp3->next = temp2; temp3 = temp3->next; temp2 = temp2->next;
		}
		head = head->next;
		return head;
	}
}
