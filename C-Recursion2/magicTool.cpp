/*

	Given a matrix nxn and a starting point (p,q), 
	Output all the points in the matrix which are identical to the starting point in the fashion similar to magic tool in Adobe photoshop.
	Eg:
	(p,q) : (0,3)
	1 2 3 3
	3 2 3 3
	5 3 3 3
	4 5 1 4
	o/p : [ (0,2) (0,3) (1,2) (1,3) (2,2) (2,3) (2,1) ]

	Use 2 structures provided to solve the problem.
	
	struct point -> contains x, y corresponding to point on matrix.
	struct result -> contains 3 fields
						1. selected -> contains all the final points after the selecting process.
						2. size -> number of the selected points.
						3. visited -> utility variable to note the visited points on matrix during recursion.
	
	In error cases return a emply structures
		size = 0;
		selected = {};
		visited = {};

NOTE : Donot use any Global Variables
*/
#include <malloc.h>
//#include<stdlib.h>
#include<stdio.h>
struct Point {
	int x;
	int y;
};


struct result {
	Point* selected;
	bool *visited;
	int size;
};

//void select(char *pixels, int m, int n, struct Point pivot, result* res, struct Point current) {
	// feel free to change this function parameters
//}

void select(char **str, int m, int n, char c, result *res, int x, int y, int *k)
{
	//current.x = x; current.y = y;
	if (x <= m&&y <= n&&x >= 0 && y >= 0)
	{
		if (str[x][y] == c)
		{
			(res)->selected[*k] = { x, y };
			(res)->visited[x*n + y] = true;
			(*k)++;
			str[x][y] = '-';
			select(str, m, n, c, res, x - 1, y, k);
			select(str, m, n, c, res, x + 1, y, k);
			select(str, m, n, c, res, x, y + 1, k);
			select(str, m, n, c, res, x, y - 1, k);
		}
	}
}

struct result select_wrapper(char* pixels, int m, int n, struct Point pivot) {
	if (pixels == '\0'||pivot.x<0||pivot.y<0||pivot.x>m||pivot.y>n)
	{
		result res;
		res.size = 0;
		return res;
	}
	else
	{
		char c;
		result *res=(result*)malloc(sizeof(result));
		res->selected = (Point *)malloc(sizeof(Point)*((n+1)*(m+1)));
		res->visited = (bool*)malloc(sizeof(bool)*((n + 1)*(m + 1)));
		int i, j,k;
		char **str;
		str = (char **)malloc(sizeof(char *)*(m+1));
		for (i = 0; i <= m; i++)
		{
			str[i] = (char *)malloc(sizeof(char)*(n+1));
		}
		k = 0;
		for (i = 0; i <= m; i++)
		{
			for (j = 0; j <=n; j++)
			{
				str[i][j] = pixels[k]; k++;
			}
		}
		c = str[pivot.x][pivot.y];
		 k = 0;
		select(str, m, n, c, res, pivot.x, pivot.y,&k);
		res[0].size= k;
		return *res;
		free(res);
	}
}
