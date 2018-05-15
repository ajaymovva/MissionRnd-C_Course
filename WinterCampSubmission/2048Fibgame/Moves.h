#include<stdlib.h>
#include "Userdata.h"
#include "Boarddata.h"
#pragma once


void moveUp(Board *board, int size,int *k);

void moveLeft(Board *board, int size,int *k);

void moveRight(Board *board,int size,int *k);

void moveDown(Board *board,int size,int *k);

void placeOne(Board *board, int size);



void fibnocci(int actual, int *prev, int *next)
{
	int f1 = 1, f2 = 1, f3 = 2;
	if (actual == 1){ *prev = 1; *next = 2; }
	else
	{
		while (f2 != actual)
		{
			f1 = f2;
			f2 = f3;
			f3 = f2 + f1;
		}
		*prev = f1; *next = f3;
	}

}



void loaddatatotemp(Board *board)
{
	int size, i,j;
	i = 0; size = board->size;
	for (int i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			board->temp[i][j] = board->table[i][j];
		}
	}
}


void loadbacktable(Board *board)
{
	int size, i, j;
	i = 0; size = board->size;
	for (int i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			board->table[i][j] = board->temp[i][j];
		}
	}
}



void placeOne(Board *board, int size)
{
	int i, j;
	i = rand() % size; j = rand() % size;
	while (board->table[i][j] != 0)
	{
		i = rand() % size; j = rand() % size;
	}
	board->table[i][j] = 1;
}

void startplay(Board *board, int size,User *user)
{
	char dir;
	int p = 0,k=0,left=0,right=0,up=0,down=0,count=user->movesCount;
	while (1)
	{
		printf("		enter [w-up] \t [a-left] \t [s-down] \t [d-right]\t [rest-save]\n");
		scanf("%c", &dir);
		scanf("%c", &dir);
		switch (dir)
		{
			case 'w':
					moveUp(board, size,&k);
					if (k == 1){ up = 1; }
					else{ left = 0; up = 0; right = 0; down = 0; count++; }
					break;
			case 'a':
					moveLeft(board, size,&k);
					if (k == 2){ left = 1; }
					else{ left = 0; up = 0; right = 0; down = 0; count++; }
					break;
			case 's':
					moveDown(board, size,&k);
					if (k == 3){ down = 1; }
					else{ left = 0; up = 0; right = 0; down = 0; count++; }
					break;
			case 'd':
					moveRight(board, size,&k);
					if (k == 4){ right = 1; }
					else{ left = 0; up = 0; right = 0; down = 0; count++; }
					break;
			default:
					p = 1;
					board->count = count;
					user->movesCount = count;
					putinfile(board, size);
					break;
		}
		if (p == 1)
		{
			storeGame(user);
			break;
		}
		p = -1;
		gameEnd(board, size,&p);
		if (p == 0)
		{
			board->count = count;
			placeOne(board, size);
			printBoard(board, size);
		}
		else if (p == 1)
		{
			board->count = count;
			printBoard(board, size);
			user->movesCount = count;
			placeuserList(user,size);
			EndGame(user);
			break;
		}
		else if (up == 1 && down == 1 && left == 1 && right == 1)
		{
			board->count = count;
			printBoard(board, size);
			user->movesCount = count;
			LostGame(user);
			break;
		}
		else if (p == -1)
		{
			board->count = count;
			printBoard(board, size);
		}
		loaddatatotemp(board);
		moveUp(board, size, &k);
		if (k == 1){ up = 1; }
		moveLeft(board, size, &k);
		if (k == 2){ left = 1; }
		moveRight(board, size, &k);
		if (k == 4){ right = 1; }
		moveDown(board, size, &k);
		if (k == 3){ down = 1; }
		loadbacktable(board);
		if (up == 1 && left == 1 && right == 1 && down == 1)
		{
			board->count = count;
			printBoard(board, size);
			user->movesCount = count;
			LostGame(user);
			break;
		}
	}
}





void moveUp(Board *board, int size,int *val)
{
	int i, j,prev,next,actual,temp,k,p,x=0;
	for (i = 0; i <size; i++)
	{
		k = 0;
		for (j = 0; j < size; j++)
		{
			if (board->table[j][i] != 0)
			{
				if (k != j)
				{
					x++;
					p = board->table[j][i];
					board->table[j][i] = 0;
					board->table[k][i] = p;
				}
				k++;
			}
		}
	}
	for (i = 1; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			prev = 0; next = 0;
			actual = board->table[i][j];
			if (actual != 0)
			{
				fibnocci(actual, &prev, &next);
				temp = board->table[i-1][j];
				if ((temp == prev || temp == next)&&(temp!=0))
				{
					x++;
					board->table[i-1][j] = actual + temp;
					board->table[i][j] = 0;
				}
			}
		}
	}
	for (i = 0; i <size; i++)
	{
		k = 0;
		for (j = 0; j < size; j++)
		{
			if (board->table[j][i] != 0)
			{
				//x++;
				p = board->table[j][i];
				board->table[j][i] = 0;
				board->table[k++][i] = p;
			}
		}
	}
	if (x == 0){ *val = 1; }
	else{ *val = 0; }
}





void moveDown(Board *board, int size,int *val)
{
	int i, j, prev, next, actual, temp,k,p,x=0;
	for (i = size-1; i >=0; i--)
	{
		k = size-1;
		for (j = size-1; j >=0; j--)
		{
			if (board->table[j][i] != 0)
			{
				if (k != j)
				{
					x++;
					p = board->table[j][i];
					board->table[j][i] = 0;
					board->table[k][i] = p;
				}
				k--;
			}
		}
	}
	for (i = size-2; i >=0; i--)
	{
		for (j = 0; j < size; j++)
		{
			prev = 0; next = 0;
			actual = board->table[i][j];
			if (actual != 0)
			{
				fibnocci(actual, &prev, &next);
				temp = board->table[i+1][j];
				if ((temp == prev || temp == next) && (temp != 0))
				{
					x++;
					board->table[i+1][j] = actual + temp;
					board->table[i][j] = 0;
				}
			}
		}
	}
	for (i = size - 1; i >= 0; i--)
	{
		k = size - 1;
		for (j = size - 1; j >= 0; j--)
		{
			if (board->table[j][i] != 0)
			{
				//x++;
				p = board->table[j][i];
				board->table[j][i] = 0;
				board->table[k--][i] = p;
			}
		}
	}
	if (x == 0){ *val = 3; }
	else{ *val = 0; }
}




void moveLeft(Board *board, int size,int *val)
{
	int i, j, prev, next, actual, temp,k,p,x=0;
	for (j = 0; j<size; j++)
	{
		k = 0;
		for (i = 0; i <size; i++)
		{
			if (board->table[j][i] != 0)
			{
				if (k != i)
				{
					x++;
					p = board->table[j][i];
					board->table[j][i] = 0;
					board->table[j][k] = p;
				}
				k++;
			}
		}
	}
	for (i = 1; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			prev = 0; next = 0;
			actual = board->table[j][i];
			if (actual != 0)
			{
				fibnocci(actual, &prev, &next);
				temp = board->table[j][i-1];
				if ((temp == prev || temp == next) && (temp != 0))
				{
					x++;
					board->table[j][i-1] = actual + temp;
					board->table[j][i] = 0;
				}
			}
		}
	}
	//printBoard(board, size);
	for (j = 0; j<size; j++)
	{
		k = 0;
		for (i = 0; i <size; i++)
		{
			if (board->table[j][i] != 0)
			{
				//x++;
				p = board->table[j][i];
				board->table[j][i] = 0;
				board->table[j][k++] = p;
			}
		}
	}
	if (x == 0){ *val = 2; }
	else{ *val = 0; }
}





void moveRight(Board *board, int size,int *val)
{
	int i, j, prev, next, actual, temp,k,p,x=0;
	for (j = 0; j<size; j++)
	{
		k = size-1;
		for (i = size-1; i>=0; i--)
		{
			if (board->table[j][i] != 0)
			{
				if (k!=i)
				{
					x++;
					p = board->table[j][i];
					board->table[j][i] = 0;
					board->table[j][k] = p;
				}
				k--;
			}
		}
	}
	//printBoard(board, size);
	for (i = size-2; i >=0; i--)
	{
		for (j = 0; j < size; j++)
		{
			prev = 0; next = 0;
			actual = board->table[j][i];
			if (actual != 0)
			{
				fibnocci(actual, &prev, &next);
				temp = board->table[j][i + 1];
				if ((temp == prev || temp == next) && (temp != 0))
				{
					x++;
					board->table[j][i + 1] = actual + temp;
					board->table[j][i] = 0;
				}
			}
		}
	}
	for (j = 0; j<size; j++)
	{
		k = size - 1;
		for (i = size - 1; i >= 0; i--)
		{
			if (board->table[j][i] != 0)
			{
				//x++;
				p = board->table[j][i];
				board->table[j][i] = 0;
				board->table[j][k--] = p;
			}
		}
	}
	if (x == 0){ *val = 4; }
	else{ *val = 0; }
}
