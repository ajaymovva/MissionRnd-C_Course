#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "query.h"
#pragma once
/*
This is static creation of tables of two differnt schemas and join the schemas and applying
operations of all done same as dynamic structure.
operations:
	import join select flush 
	However this must be iplemented in dynamic way in dynamic structure project.
	The respected files is present in the project it self.
*/


int stringtoint(int *i, char *str)
{
	int k = 0;
	while (str[*i] != ','&&str[*i] != '\0')
	{
		k = k * 10 + (str[*i] - 48);
		(*i)++;
	}
	return k;
}


void stringconcat(int *i, char *toappend, char *input)
{
	int j = 0;
	while (input[*i] != ','&&input[*i] != '\0')
	{
		toappend[j++] = input[(*i)++];
	}
	toappend[j] = '\0';
}



void createthirdFile(struct info *std1, struct info *temp1,char *filename)
{
	char *str = (char *)malloc(sizeof(char) * 250);
	FILE *fp2; int i, j, k;
	//fp2 = fopen("studentinfolist.csv", "r");
	fp2 = fopen(filename, "r");
	while (fgets(str, 250, fp2))
	{
		std1 = (struct info *)malloc(sizeof(struct info));
		std1->phoneno = (char *)malloc(sizeof(char) * 30);
		std1->address = (char *)malloc(sizeof(char) * 30);
		std1->city = (char *)malloc(sizeof(char) * 30);
		std1->pincode = (char *)malloc(sizeof(char *) * 10);
		for (i = 0; str[i] != '\0'; i++)
		{
			std1->rollno = stringtoint(&i, str); i++;
			stringconcat(&i, std1->phoneno, str); i++;
			stringconcat(&i, std1->address, str); i++;
			stringconcat(&i, std1->city, str); i++;
			stringconcat(&i, std1->pincode, str);
			std1->link = NULL;
			std1->flag = 0;
			break;
		}
		if (info1 == NULL){ info1 = std1; temp1 = info1; }
		else if (temp1 == NULL){ temp1 = std1; infolast->link = temp1; }
		else{ temp1->link = std1; temp1 = std1; }
	}
	infolast = temp1;
	fclose(fp2);
}




void createsecondFile(struct student2 *std1, struct student2 *temp1,char *filename)
{
	char *str = (char *)malloc(sizeof(char) * 100);
	FILE *fp2; int i, j, k,p=0;
	//fp2 = fopen("studentmarkslist1.csv", "r");
	fp2 = fopen(filename, "r");
	while (1)
	{
		k = fscanf(fp2, "%s", str);
		if (k == -1){ break; }
		std1 = (struct student2 *)malloc(sizeof(struct student2));
		std1->name = (char *)malloc(sizeof(char) * 30);
		std1->avg = (char *)malloc(sizeof(char) * 30);
		std1->cgpa = (char *)malloc(sizeof(char) * 30);
		for (i = 0; str[i] != '\0'; i++)
		{
			std1->rollno = stringtoint(&i, str); i++;
			stringconcat(&i, std1->name, str); i++;
			std1->m1 = stringtoint(&i, str); i++;
			std1->m2 = stringtoint(&i, str); i++;
			std1->m3 = stringtoint(&i, str); i++;
			std1->m4 = stringtoint(&i, str); i++;
			stringconcat(&i, std1->avg, str); i++;
			stringconcat(&i, std1->cgpa, str);
			std1->flag = 0;
			std1->link = NULL;
			p++;
			break;
		}
		if (head2 == NULL)
		{ 
			head2 = std1; 
			last2 = std1; 
		}
		else if (temp1 == NULL)
		{
			temp1 = std1;
			last2->link = temp1;
		}
		else{ temp1->link = std1; temp1 = std1; }
	}
	last2 = temp1;
	fclose(fp2);
}




void createfirstFile(struct student1 *std1, struct student1 *temp)
{
	char *str = (char *)malloc(sizeof(char) * 100);
	FILE *fp1; int i, j, k, p = 0;
	fp1 = fopen("studentmarkslist.csv", "r");
	while (1)
	{
		k = fscanf(fp1, "%s", str);
		if (k == -1){ break; }
		std1 = (struct student1*)malloc(sizeof(struct student1));
		std1->name = (char *)malloc(sizeof(char) * 30);
		for (i = 0; str[i] != '\0'; i++)
		{
			std1->rollno = stringtoint(&i, str);
			i++;
			stringconcat(&i, std1->name, str); i++;
			std1->m1 = stringtoint(&i, str); i++;
			std1->m2 = stringtoint(&i, str); i++;
			std1->m3 = stringtoint(&i, str); i++;
			std1->m4 = stringtoint(&i, str); i++;
			std1->link = NULL;
			break;
		}
		if (head1 == NULL){ head1 = std1; temp = head1; }
		else{ temp->link = std1; temp = std1; }
	}
	fclose(fp1);
}




void joinfirst()
{
	FILE *fp5;
	fp5 = fopen("joinfirst.csv", "w");
	struct student1 *temp1;
	struct info *temp2;
	temp1 = head1; temp2 = info1;
	while (temp1 != NULL)
	{
		temp2 = info1;
		while (temp2 != NULL)
		{
			if (temp1->rollno == temp2->rollno)
			{
				fprintf(fp5, "%d,%s,%d,%d,%d,%d,noaverage,nocgpa,", temp1->rollno, temp1->name, temp1->m1, temp1->m2, temp1->m3, temp1->m4);
				fprintf(fp5, "%s,%s,%s,%s", temp2->phoneno, temp2->address, temp2->city, temp2->pincode);
				break;
			}
			temp2 = temp2->link;
		}
		temp1 = temp1->link;
	}
	fclose(fp5);
}




void joinsecond()
{
	FILE *fp4;
	char str[15] = "joinsecond.csv";
	//fp4 = fopen("joinsecond.csv", "w");
	fp4 = fopen(str, "w");
	struct student2 *temp1;
	struct info *temp2;
	temp1 = head2; temp2 = info1;
	while (temp1 != NULL)
	{
		temp2 = info1;
		while (temp2 != NULL)
		{
			if (temp1->rollno == temp2->rollno)
			{
				fprintf(fp4, "%d,%s,%d,%d,%d,%d,%s,%s,", temp1->rollno, temp1->name, temp1->m1, temp1->m2, temp1->m3, temp1->m4, temp1->avg, temp1->cgpa);
				fprintf(fp4, "%s,%s,%s,%s", temp2->phoneno, temp2->address, temp2->city, temp2->pincode);
				break;
			}
			temp2 = temp2->link;
		}
		temp1 = temp1->link;
	}
	fclose(fp4);
}



void stringconcat1(int *i, char *toappend, char *input)
{
	int j = 0;
	while (input[*i] != ' '&&input[*i] != '\0')
	{
		toappend[j++] = input[(*i)++];
	}
	toappend[j] = '\0';
}



void import_cal(char *option)
{
	int i = 6;
	struct student1 *std1 = NULL, *temp = NULL;
	struct student2 *std2 = NULL, *temp1 = NULL;
	struct info *info = NULL, *temp3 = NULL;
	char *filename = (char *)malloc(sizeof(char) * 30);
	char *schema = (char *)malloc(sizeof(char) * 10);
	while (option[i++] != ' '){}
	stringconcat1(&i, filename, option);
	while (option[i++] != ' '){}
	stringconcat1(&i, schema, option);
	//createfirstFile(std1, temp);
	if (schema[0] == 's'&&schema[1] == '1')
	{
		createsecondFile(std2, temp1,filename);
	}
	else if (schema[0] == 's'&&schema[1] == '2')
	{
		createthirdFile(info, temp3,filename);
	}
}


void pushstructuretofile(char *filename)
{
	FILE *fp4;
	fp4 = fopen(filename, "w");
	struct all *temp;
	temp = all1;
	while (temp != NULL)
	{
		fprintf(fp4, "%d,",temp->rollno);
		fprintf(fp4, "%s,",temp->name);
		fprintf(fp4, "%d,",temp->m1);
		fprintf(fp4, "%d,",temp->m2);
		fprintf(fp4, "%d,",temp->m3);
		fprintf(fp4, "%d,",temp->m4);
		fprintf(fp4, "%s,",temp->avg);
		fprintf(fp4, "%s,",temp->cgpa);
		fprintf(fp4, "%s,",temp->phoneno);
		fprintf(fp4, "%s,",temp->address);
		fprintf(fp4, "%s,",temp->city);
		fprintf(fp4, "%s", temp->pincode);
		temp = temp->link;
	}
	fclose(fp4);
}



void createjoinfile()
{
	struct all *temp=NULL,*temp3=NULL;// = (struct all *)malloc(sizeof(struct all));
	struct student2 *temp1; struct info *temp2;
	temp1 = head2; temp2 = info1;
	while (temp1 != NULL)
	{
		temp2 = info1;
		while (temp2 != NULL)
		{
			if (temp1->rollno == temp2->rollno&&temp1->flag==0&&temp2->flag==0)
			{
				temp = (struct all *)malloc(sizeof(struct all));
				temp->rollno = temp1->rollno;
				temp->address = temp2->address;
				temp->avg = temp1->avg;
				temp->cgpa = temp1->cgpa;
				temp->city = temp2->city;
				temp->m1 = temp1->m1;
				temp->m2 = temp1->m1;
				temp->m3 = temp1->m3;
				temp->m4 = temp1->m4;
				temp->name = temp1->name;
				temp->phoneno = temp2->phoneno;
				temp->pincode = temp2->pincode;
				temp->link = NULL;
				if (all1 == NULL){ all1 = temp; temp3 = temp; }
				else{ temp3->link = temp; temp3 = temp; }
				temp1->flag = 1; temp2->flag = 1;
			}
			temp2 = temp2->link;
		}
		temp1 = temp1->link;
	}

}



void join_cal(char *option)
{
	//printf("please wait");
	int i = 4;
	char *filename = (char *)malloc(sizeof(char) * 30);
	char *schema1 = (char *)malloc(sizeof(char) * 10);
	char *schema2 = (char *)malloc(sizeof(char) * 10);
	while (option[i++] != ' '){}
	stringconcat1(&i, schema1, option);
	while (option[i++] != ' '){}
	stringconcat1(&i, schema2, option);
	if (schema1[0] == 's'&&schema1[1] == '1'&&schema2[0] == 's'&&schema2[1] == '2')
	{
		createjoinfile();
	}
	else{}
}




void flush_cal(char *option)
{
	//printf("please wait");
	int i = 5;
	char *filename = (char *)malloc(sizeof(char) * 30);
	while (option[i++] != ' '){}
	stringconcat1(&i, filename, option);
	pushstructuretofile(filename);
}


void exit_cal()
{
	printf("please wait");
}


void process_input(char *option)
{
	int k = 0;
	while (1)
	{
		printf("\n	ENTER OPTIONS [IMPORT] [JOIN] [FLUSH] [EXIT] [SELECT] [sort]\n");
		gets(option);
		if (option[0] == 'i'&&option[1] == 'm'&&option[2] == 'p'&&option[3] == 'o')
		{
			import_cal(option);
		}
		else if (option[0] == 'j'&&option[1] == 'o'&&option[2] == 'i'&&option[3] == 'n')
		{
			join_cal(option);
		}
		else if (option[0] == 'f'&&option[1] == 'l'&&option[2] == 'u'&&option[3] == 's')
		{
			flush_cal(option);
		}
		else if (option[0] == 's'&&option[1] == 'e'&&option[2] == 'l'&&option[3] == 'e')
		{
			querycalfunc(option);
		}
		else if (option[0] == 's'&&option[1] == 'o'&&option[2] == 'r'&&option[3] == 't')
		{
			querycalfunc(option);
		}
		else if(option[0] == 'e')
		{
			break;
		}
	}
	
}




int main()
{
	char *option = (char *)malloc(sizeof(char) * 100);
	process_input(option);
	joinfirst();
	joinsecond();
	system("pause");
	return 0;
}