/*
Mock Test 1
Make Sure you submit well before time .
And dont repeteadtly submit ,as it will cause sync issues , Try to submit alteast with
5-10mins gap between each submit .
Make sure your files are uploaded to GoogleDrive before Time Expires.

95% of times ,The last minute Code changes wont fetch you any more marks .It might even
decrease or become 0 , If it leads to a Project Build Failure .
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "FunctionHeaders.h"
#include<stdlib.h>
int main(){

	//Test here
	
	long long start1 = -10, end1 = 0;
	long long start2 = 0, end2 = -5;
	//int result = countCommonStars(start1,end1,start2,end2,-2);
	//printf("result = %d", result);
	int **snakeBoard;
	snakeBoard = (int **)malloc(sizeof(int*) * 3);
	int i, j;
	for (i = 0; i < 3; i++)
	{
		snakeBoard[i] = (int *)malloc(sizeof(int) * 100);
	}
	snakeBoard=initialSnakePosition(20);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 100; j++)
		{
			printf("%d", snakeBoard[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

