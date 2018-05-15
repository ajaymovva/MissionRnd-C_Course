/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

//Use this function , Dont create any new function with name createNode or createList
struct node * createNodeDummy(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
}

struct node * insertAtEveryKthNode(struct node *head, int K) {
	struct node *temp,*n,*temp1;
	int i = 0;
	if (head == NULL||K < 1)
	{
		return NULL;
	}
	temp = head;
	while (temp != NULL)
	{
		i++; temp = temp->next;
	}
	if (K > i+1)
	{
		return head;
	}
	else
	{
		i = 0; temp = head;
		while (temp != NULL)
		{
			if (i == K)
			{
				n = createNodeDummy(K);
				n->next = temp;
				temp1->next = n;
				// temp = n;
				i = 0;
			}
			i++;
			temp1 = temp;
			temp = temp->next;
		}
		if (i == K)
		{
			n = createNodeDummy(K);
			temp1->next = n;
		}
		return head;
	}

}
