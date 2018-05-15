/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes
will be followed by ones and then twos.

You should only change the links and shouldnt swap the data. Basically no write operation should be done on data field.

INPUTS:  SLL head pointer
OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2
ERROR CASES:
NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

/*
Optional : For this function swapping data is allowed.Although this wont be tested on our end.
It is only for learning purpose.
*/
void sll_012_sort_swapData(struct node **head){

}

/*
This is the actual function. You are supposed to change only the links.
*/
void sll_012_sort(struct node **head){
	int i = 0;
	struct node *outer, *inner, *outp,*inp;
	outer = *head; outp = outer;
	inner = outer->next;
	while (outer != NULL)
	{
		inp = outer; inner = inp->next;
		while (inner != NULL)
		{
			if (outer->data > inner->data)
			{
				
				if(i!=0)outp->next = inner;
				inp->next = inner->next;
				inner->next = outer;
				outer = inner;
			}
			inp = inner;
			inner = inner->next;
		}
		outp = outer;
		if (i == 0)
		{
			*head = outp;
		}
		i++;
		outer = outer->next;
	}

}

