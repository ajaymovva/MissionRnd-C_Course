/*

Problem Code : New York

Count the number of ways of reaching top left cell (0,0) to right bottom cell (n-1,m-1) of a 2d matrix.

You have to change the direction "exactly 'k' times", you can change to any direction top,down,left,right.

You can start with any direction (initially at (0,0) only right and down are possible).

For Example :
N = 3, m = 4 , k = 1
These are the two sequences , change in direction is indicated by *

(1,1) -->  (2,1) -->  (3,1) -->  (3,2)* -->  (3,3) --> (3,4)
(1,1) -->  (1,2) -->  (1,3) -->  (1,4) --> (2,4)* -->  (3,4)

N = 3, m = 4, k = 2

(1,1) --> (2,1) --> (2,2)* --> (2,3) -->  (2,4) -->  (3,4)*
(1,1) --> (1,2) -->  (2,2)* --> (3,2) -->  (3,3)* --> (3,4)
(1,1) --> (1,2) -->  (1,3) -->  (2,3)* -->  (3,3) -->  (3,4)*

Return 0 for invalid cases
*/

#include <stdio.h>
#include <stdlib.h>
void newyork2(int n, int m, int x, int y, int k, int dir, int move, int *p)
{
	if (x == n - 1 && y == m - 1)
	{
		if (dir == k)
		{
			(*p)++;
		}
	}
	 else if (dir<=k)
	{
		if (move == 0 && x > 0)
		{
			newyork2(n, m, x - 1, y, k, dir, move, p);
		}
		else if (x > 0)//&&move!=2
		{
			newyork2(n, m, x - 1, y, k, dir+1, 0, p);
		}
		if (move == 1  && y < m - 1)// && y < m-1
		{
			newyork2(n, m, x, y + 1, k, dir, move, p);
		}
		else if (y < m-1)//&&move!=3
		{
			newyork2(n, m, x, y + 1, k, dir+1, 1, p);
		}
		if (move == 2 && x < n-1)
		{
			newyork2(n, m, x + 1, y, k, dir, move, p);
		}
		else if (x < n-1)//&&move!=0
		{
			newyork2(n, m, x + 1, y, k, dir+1, 2, p);
		}
		if (move == 3 && y > 0)
		{
			newyork2(n, m, x, y-1, k, dir, move, p);
		}
		else if (y > 0)//&&move!=1
		{
			newyork2(n, m, x, y-1, k, dir+1, 3, p);
		}
		
	}
}
int newyork_recur(int n, int m, int x, int y, int K, int dir) {
	int p = 0;
	newyork2(n, m, 0, 1, K, 0, 1, &p);
	newyork2(n, m, 1, 0, K, 0, 2, &p);
	return p;
}

int NewYork(int n, int m, int k){
	return newyork_recur(n, m, 0, 0, k, 0);
}