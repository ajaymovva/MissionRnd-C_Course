/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES:

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
}*head=NULL,*last,*temp,*n,*prev,*temp1;

struct node * numberToLinkedList(int N) {
	int rem, n1;
	if (N < 0)
	{
		N = -N;
	}
	if (N == 0)
	{
		n = (struct node*)malloc(sizeof(struct node));
		n->num = N;
		n->next = NULL;
		return n;
	}
	else
	{
		n1 = N; head = NULL;
		while (n1 > 0)
		{
			rem = n1 % 10;
			n = (struct node*)malloc(sizeof(struct node));
			n->num = rem;
			n->next = NULL;
			if (head == NULL)
			{
				head = n;
				last = n;
			}
			else
			{
				last->next = n;
				last = n;
			}
			n1 = n1 / 10;
		}
		temp = head;
		prev = NULL;
		while (temp != NULL)
		{
			temp1 = temp->next;
			temp->next = prev;
			prev = temp;
			temp = temp1;
		}
		head = prev;
		return head;
	}
	
}