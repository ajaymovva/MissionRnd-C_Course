/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
Problem Code :TK
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int K) {
	struct student swap;
	struct student **stud1;
	struct student *stud;
	int i, j;
	if (K <= 0)
	{
		return NULL;
	}
	else
	{
		stud = (struct student *)malloc(K*sizeof(struct student));
		stud1 = (struct student **)malloc(K*sizeof(struct student));
		for (i = 0; i<len; i++)
		{
			for (j = i; j<len; j++)
			{
				if (students[i].score>students[j].score)
				{
					swap = students[i];
					students[i] = students[j];
					students[j] = swap;
				}
			}
		}
		/*for (i = 0; i<len; i++)
		{
			printf("%d", students[i].score);
			printf("%s", students[i].name);
		}*/
		if (K>len)
		{
			i = 0; j = 0;
			while (i<len)
			{
				stud[j].name = students[i].name;
				stud[j].score = students[i].score;
				i++;
				j++;
			}
		}
		else{
			i = len - K; j = 0;
			while (i<len)
			{
				stud[j] = students[i];
				i++;
				j++;
			}
		}
		printf("\n");
		for (i = 0; i<j; i++)
		{
			stud1[i] = &stud[i];
		}
		return stud1;
	}
}