#include<stdlib.h>
#pragma once



typedef struct Board
{
	int table[4][4];
	int size;
	int count;
	char name[50];
	int temp[4][4];
};



Board *createBoard(int row, int col)
{
	Board *board = (Board *)malloc(sizeof(Board));
	board->size = 0;
	board->count = 0;
	return board;
}




void initializeBoard(Board *board,int row, int col)
{
	int i, j;
	if (board != NULL&&row > 0&&col > 0)
	{
		int k = 0;
		for (i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				board->table[i][j] = 0;
			}
		}
		i = rand() % row; j = rand() % row;
		board->table[i][j] = 1; 
		i = rand() % row; j = rand() % row;
		board->table[i][j] = 1;
		board->size = row;
	}
}




void printBoard(Board *board, int size)
{
	system("cls");
	printf("\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%d\t", board->table[i][j]);
		}
		printf("\n");
	}
	printf("===================================================================================\n");
	printf("	NO OF MOVES: %d \n", board->count);
	printf("===================================================================================\n");
}




void gameEnd(Board *board, int size, int *p)
{
	int k = (2 * size*size);
	int f1 = 0, f2 = 1, f3 = 1, i = 4;
	while (i <= k)
	{
		f1 = f2; f2 = f3; f3 = f1 + f2;
		i++;
	}
	if (k == 2){ f3 = f2; }
	int  j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (board->table[i][j] == 0)
			{
				*p = 0;
			}
			else if (board->table[i][j] == f3)
			{
				*p = 1; break;
			}
		}
		if (j < size){ break; }
	}

}




void putinfile(Board *board, int size)
{
	FILE *outfile2,*outfile4;
	/*if (outfile2 == NULL)
	{
		fprintf(stderr, "\nError opend file\n");
		exit(1);
	}
	if (outfile4 == NULL)
	{
		fprintf(stderr, "\nError opend file\n");
		exit(1);
	}*/
	Board board1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			board1.table[i][j] = board->table[i][j];
		}
	}
	board1.size = size; 
	board1.count = board->count;int i = 0;
	while (board->name[i]!='\0')
	{
		board1.name[i] = board->name[i]; i++;
	}
	board1.name[i] = '\0';
	if (size == 2)
	{
		outfile2 = fopen("person.txt", "w");
		fwrite(&board1, sizeof(Board), 1, outfile2);
		fclose(outfile2);
	}
	else
	{
		outfile4 = fopen("person1.txt", "w");
		fwrite(&board1, sizeof(Board), 1, outfile4);
		fclose(outfile4);
	}
	if (fwrite != 0)
		printf("");
	else
		printf("\nerror writing file !\n");
}