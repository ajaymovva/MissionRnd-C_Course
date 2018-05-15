/*
Author : Abhijith Ravuri
*/

#include "stdafx.h"
#include <stdlib.h>

#include "FunctionHeaders.h"

int main(){
	
	//Check NSnipers

	//Check CountPairs Sample Code 

	//Check Steps Sample Code

	//Check Spiral Sample Code

	//Check Maze Sample Code

	/*
	int maze[4][3] = {
		{ 0, 0, 1 },
		{ 1, 1, 1 },
		{ 1, 0, 1 },
		{ 1, 0, 1 }
	};

	int m = 4, n = 3;
	int x1 = 3, y1 = 0, x2 = 0, y2 = 2;

	int check=path_exists(&maze[0][0], m, n, x1, y1, x2, y2);
	printf("%d\n", check);
	*/
	//char *str = (char *)malloc(sizeof(char) * 5);
	//str = "zzzzz";
	//int i = count_pairs_wrapper(str, 5);
	//printf("pairs are%d", i);
	int maze[4][4] = {
		{ 0, 0, 0,0 },
		{ 0, 0, 0,0 },
		{ 0, 0, 0,0 },
		{ 0, 0, 0,0}
	};
	int i = solve_nsnipers((int *)maze, 4);
	printf(" value is %d", i);
	system("pause");
	return 0;
}