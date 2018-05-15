#include<stdlib.h>
#include "Boarddata.h"
#include<windows.h>
#pragma once
typedef struct User{
	char *name;
	int movesCount;
	char *Date;
	int size;
};
//void addUsertoList(Board *board, User *user, int size);


User *createUser(char *str)
{
	User *user = (User *)malloc(sizeof(User));
	user->name = str;
	user->movesCount = 0;
	return user;
}





char *getDate()
{
	SYSTEMTIME t;
	GetSystemTime(&t);
	char *date = (char *)malloc(sizeof(char) * 11);
	date[0] = (t.wDay / 10) + '0';
	date[1] = (t.wDay % 10) + '0';
	date[2] = '-';
	date[3] = (t.wMonth / 10) + '0';
	date[4] = (t.wMonth % 10) + '0';
	date[5] = '-';
	date[6] = (t.wYear / 1000) + '0';
	date[7] = ((t.wYear / 100) % 10) + '0';
	date[8] = ((t.wYear / 10) % 100) + '0';
	date[9] = (t.wYear % 10) + '0';
	date[10] = '\0';
	return date;
}



void placeuserList(User *user, int size)
{
	user->Date = getDate();
	FILE *fp;
	fp = fopen("userinfo1.txt", "a+");
	fprintf(fp, "%s:",user->Date);
	fprintf(fp, "%s:", user->name);
	fprintf(fp, "%d:", user->size);
	fprintf(fp, "%d\n", user->movesCount);
	fclose(fp);
}





void EndGame(User *user)
{
	printf("===============================================================\n");
	printf("	%s won the game in	%d	Moves\n", user->name,user->movesCount);
}





void LostGame(User *user)
{
	printf("===============================================================\n\n");
	printf("	%s lost the	game in	%d	Moves\n", user->name, user->movesCount);
}




void storeGame(User *user)
{
	printf("	content written succesfully\n");
	printf("==================================================================\n");
	printf("	Game stored with moves of %d\n", user->movesCount);
}

