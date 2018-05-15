/*
OVERVIEW:  Given a single linked list (two digits as a node).Convert that to number


INPUTS:  SLL head pointer

OUTPUT: Create a number from the linked list given ,In each node there are two numbers ,digit1 and digit1 ,
So if the nodes are 12->34->56->78 , Final number would be 12345678 ( Integer)

ERROR CASES:

NOTES: Only Postive Numbers
*/

#include <stdio.h>
#include <malloc.h>

struct twoDigitNode {
	int digit1;
	int digit2;
	struct twoDigitNode *next;
}*temp;

int convert_sll_2digit_to_int(struct twoDigitNode *head){
	int count = 0;
	if (head == NULL)
	{
		return NULL;
	}
	else
	{
		temp = head->next;
		count = head->digit1;
		count = count * 10;
		count = count+head->digit2;
		while (temp != NULL)
		{
			count = count * 10;
			count = count + (temp->digit1);
			count = count * 10;
			count = count + (temp->digit2);
			temp = temp->next;
		}
		return count;
	}
}
