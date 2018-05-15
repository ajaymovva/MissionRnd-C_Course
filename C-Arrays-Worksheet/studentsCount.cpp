
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:

Problem Code :SC
*/

#include <stdio.h>

void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount) {
	int i, p1 = 0, p2 = 0, k = 0;
	if (Arr == NULL || len < 0)
		return NULL;
	else
	{
		for (i = 0; i<len; i++)
		{
			if (Arr[i] == score)
			{
				k++;
			}
			if (Arr[i]>score)
			{

				p1 = i - k;
				p2 = len - i;
				break;

			}
		}
		if (Arr[len - 1]<score)
		{
			p1 = len;
			p2 = 0;
		}
		if (Arr[0]>score)
		{
			p2 = len;
			p1 = 0;
		}

		printf("p1 is %d p2 is %d", p1, p2);
		*lessCount = p1;
		*moreCount = p2;
	}

}
