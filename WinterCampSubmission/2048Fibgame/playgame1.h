#define _CRT_SECURE_NO_WARNINGS
#include "Userdata.h"
#include "Boarddata.h"
#include "Moves.h"
#pragma once
#include<stdio.h>
#include<stdlib.h>



struct node
{
	char date[11];
	char Name[50];
	int size;
	int game_count;
	struct node *link;
}*head=NULL,*n;


void display(struct node *temp);
void sort(struct node **head);
int playGame()
{
	int size,k;
	User *user; Board *board;
	char *name = (char *)malloc(sizeof(char) * 50);
	printf("\n	[Register Name]:");
	scanf("%s", name);
	printf("\n	select [2 X 2] or [4 X 4]:");
	scanf("%d", &size);
	user = createUser(name);
	user->size = size;
	board = createBoard(size, size);
	initializeBoard(board, size, size); int i = 0;
	while (name[i] != '\0')
	{
		board->name[i] = name[i];
		i++;
	}
	board->name[i] = '\0';
	printBoard(board, size);
	startplay(board, size,user);
	printf("\n	enter [1] to go to menu [rest-exit]\n");
	scanf("%d", &k);
	if (k == 1){ return 0; }
	return 1;
}





void initializeBoardreplay(Board *board,Board board1,int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			board->table[i][j] = board1.table[i][j];
		}
	}
	board->size = size;
	board->count = board1.count;
}




int rePlay()
{
	FILE *infile2,*infile4; int k;
	printf("\n	2 X 2 OR 4 X 4\n");
	scanf("%d", &k);
	char *name = (char *)malloc(sizeof(char) * 50);
	Board board1;
	User *user; Board *board;
	if (k == 2)
	{
		infile2 = fopen("person.txt", "r");
		if (infile2 == NULL)
		{
			fprintf(stderr, "\nError opend file\n");
			exit(1);
		}
		fread(&board1, sizeof(Board), 1, infile2);
		fclose(infile2);
	}
	else if (k == 4)
	{
		infile4 = fopen("person1.txt", "r");
		if (infile4 == NULL)
		{
			fprintf(stderr, "\nError opend file\n");
			exit(1);
		}
		fread(&board1, sizeof(Board), 1, infile4);
		fclose(infile4);
	}
	int size = board1.size;
	user = createUser(board1.name);
	user->size = size;
	user->movesCount = board1.count;
	board = createBoard(size, size);
	initializeBoardreplay(board, board1, size);
	int i = 0;
	while (board1.name[i] != '\0')
	{
		board->name[i] = board1.name[i]; i++;
	}
	board->name[i] = '\0';
	printBoard(board, size);
	startplay(board, size,user);
	printf("\n	enter [1] to go to menu [rest-exit]");
	scanf("%d", &k);
	if (k == 1){ return 0; }
	return 1;
}



void eachRecord(struct node *temp, char c,FILE *fp)
{
	char ctemp;
	int i = 0;
	while (i<10)
	{
		temp->date[i++] = c;
		c = fgetc(fp);	
	}
	temp->date[i] = '\0';
	//c = fgetc(fp);
	i = 0;
	while (1)
	{
		c = fgetc(fp);
		if (c != ':')
		{
			temp->Name[i++] = c;
		}
		else{ break; }
	}
	temp->Name[i] = '\0';
	c = fgetc(fp);
	i = c - 48;
	temp->size = i;
	c = fgetc(fp);
	i = (fgetc(fp) - 48);
	while (1)
	{
		c = fgetc(fp);
		if (c != '\n')
		{
			i = i * 10 + (c - 48);
		}
		else{ break; }
	}
	temp->game_count = i; temp->link = NULL;
}




int view_Leader_Board()
{
	FILE *fp;
	char c;
	int k;
	fp = fopen("userinfo1.txt", "a+");
	struct node *temp=NULL,*temp1=NULL;
	while (1)
	{
		c = fgetc(fp);
		if (c == EOF){ break; }
		else
		{
			n = (struct node *)malloc(sizeof(struct node));
			eachRecord(n, c,fp);
			if (head == NULL){ head = n; temp = head; }
			else
			{
				temp->link = n;
				temp = n;
			}
		}
	}
	
	sort(&head);
	display(head);
	fclose(fp);
	printf("\n	enter [1] to go to menu [rest-exit]");
	scanf("%d", &k);
	if (k == 1){ return 0; }
	return 1;
}


void sort(struct node **head)
{
	int i = 0;
	struct node *outer, *inner, *outp, *inp;
	outer = *head; outp = outer;
	inner = outer->link;
	while (outer != NULL)
	{
		inp = outer; inner = inp->link;
		while (inner != NULL)
		{
			if (outer->game_count > inner->game_count)
			{

				if (i != 0)outp->link = inner;
				inp->link = inner->link;
				inner->link = outer;
				outer = inner;
			}
			inp = inner;
			inner = inner->link;
		}
		outp = outer;
		if (i == 0)
		{
			*head = outp;
		}
		i++;
		outer = outer->link;
	}
}



void display(struct node *temp)
{
	int i=1;
	printf("\n");
	while (temp != NULL&&i<=20)
	{
		printf("\t");
		printf("%d\t", i);
		printf("%s\t", temp->date);
		printf("%s\t", temp->Name);
		printf("%d X %d\t", temp->size, temp->size);
		printf("%d", temp->game_count);
		i++; temp = temp->link;
		printf("\n");
	}
}