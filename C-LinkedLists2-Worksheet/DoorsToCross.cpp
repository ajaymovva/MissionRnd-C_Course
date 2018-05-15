/*

Bharath is genius reverse engineer, invented a world demanding machine and Kept in a secret building with many doors with each door having a passkey.
A Pass key is made up of some digits. Like a passkey can be 1234, 452 etc.
All doors will have passkeys of same digits, (formed from each other). like if number of doors are 3, 1223,2132,2321 can be passkeys for those doors. 
(Where as 3321 cannot as 3 is repeated 2 times where as in above sequence its repeated only 1 time)

Sam is very excited to see his wonderful creation. So, she went to the building. She knows the final passkey of last door but dont know
what is the exact passkey for each before door. As said before there are many doors with lock in a linear fashion such that
she can cross second door only after crossing first door. she can cross third door only after crossing 2nd door.

Lets say the final pass key she has is 758.
First door pass key is the largest number that can be formed by given final passkey -> 875
Second door pass key is the next largest number that can be formed -> 857
Third door opens for next largest number ->785
Finally fourth door has 758 as passkey and she can enter the room.

Find which Nth door's room contains the machine or How many doors should Sam cross to see the machine?

The final passkey Sam has will be given in the form of Doubly Linked List
eg: 7 <-> 5 <-> 8  o/p: 4

For the above Passkey ,output will be 4, as Sam needs to cross 4 doors which each door having below passkeys.
explanation: (1) 875 (2) 857 (3) 785 (4) 758

Ex 2 : 
If DLL has 9 <-> 1 <-> 4 <-> 6.
For the above Passkey ,output will be 4, as Sam needs to cross 6 doors which each door having below passkeys.
explanation: (1) 9641 (2) 9614 (3) 9461 (4) 9416 (5) 9164 (6) 9146

NOTE:	(1)	DLL can contain maximum of 12 nodes
(2)	All doors will have a Passkey which is formed by the numbers of the original pass key only
(3) From the first door to last, passkey will be in decreasing order.
(4) Duplicates are allowed
(5) "075" is not treated as "75". 0 is also given same importance as others.

You can solve this question in multiple ways. 
Can you solve it without converting to any intermediate forms or using extra space etc? These will be the common followup questions
that can be asked in an interview.

Return -1 for invalid cases.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct passKeyNode
{
	int num;
	struct passKeyNode *prev;
	struct passKeyNode *next;
};

int doorstoCross(struct passKeyNode *passKeyHead)
{
	struct passKeyNode *temp,*temp1,*temp3,*last,*lastp;
	int i,j,k=0;
	if (passKeyHead == NULL)
	{
		return -1;
	}
	else
	{
		i = 1; temp = passKeyHead;
		while (temp->next!= NULL)
		{
			i++; temp1 = temp; temp = temp->next;
		}
		last = temp; lastp = temp1;
		while (1)
		{
			k++;
			while (temp1 != NULL)
			{
				if (temp1->num < temp->num)
					break;
				temp = temp1;
				temp1 = temp1->prev;
			}
			if (temp1 == NULL)break;
			else
			{
				j = temp->num; temp3 = temp;
				while (temp != NULL)
				{
					if (temp->num > temp1->num&&temp->num < j)
					{
						temp3 = temp; j = temp->num;
					}
					temp = temp->next;
				}
				temp3->num = temp1->num;
				temp1->num = j;
				temp = temp1->next;
				while (temp != NULL)
				{
					temp3 = temp->next;
					while (temp3 != NULL)
					{
						if (temp->num > temp3->num)
						{
							j = temp3->num; temp3->num = temp->num; temp->num = j;
						}
						temp3 = temp3->next;
					}
					temp = temp->next;
				}

			}
			temp = last;
			temp1 = lastp;

		}
		return k;
	}
}