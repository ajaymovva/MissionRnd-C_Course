//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//struct student1
//{
//	int rollno;
//	char *name;
//	int m1;
//	int m2;
//	int m3;
//	int m4;
//	int flag = 0;
//	struct student1 *link;
//}*head1=NULL,*n1;
//
//
//struct student2
//{
//	int rollno;
//	char *name;
//	int m1;
//	int m2;
//	int m3;
//	int m4;
//	char *avg;
//	char *cgpa;
//	int flag = 0;
//	struct student2 *link;
//}*head2=NULL;
//
//
//
//struct info
//{
//	int rollno;
//	char *phoneno;
//	char *address;
//	char *city;
//	char *pincode;
//	int flag = 0;
//	struct info *link;
//}*info1=NULL;
//
//
//
//int stringtoint(int *i,char *str)
//{
//	int k = 0;
//	while (str[*i] != ','&&str[*i]!='\0')
//	{
//		k = k * 10 + (str[*i] - 48);
//		(*i)++;
//	}
//	return k;
//}
//
//
//void stringconcat(int *i, char *toappend,char *input)
//{
//	int j = 0;
//	while (input[*i] != ','&&input[*i]!='\0')
//	{
//		toappend[j++] = input[(*i)++];
//	}
//	toappend[j] = '\0';
//}
//
//
//
//void createthirdFile(struct info *std1, struct info *temp1)
//{
//	char *str = (char *)malloc(sizeof(char) * 250);
//	FILE *fp2; int i, j, k;
//	fp2 = fopen("studentinfolist.csv", "r");
//	while (fgets(str, 250, fp2))
//	{
//		std1 = (struct info *)malloc(sizeof(struct info));
//		std1->phoneno = (char *)malloc(sizeof(char) * 30);
//		std1-> address= (char *)malloc(sizeof(char) * 30);
//		std1->city = (char *)malloc(sizeof(char) * 30);
//		std1->pincode = (char *)malloc(sizeof(char *) * 10);
//		for (i = 0; str[i] != '\0'; i++)
//		{
//			std1->rollno = stringtoint(&i, str); i++;
//			stringconcat(&i, std1->phoneno, str); i++;
//			stringconcat(&i, std1->address, str); i++;
//			stringconcat(&i, std1->city, str); i++;
//			stringconcat(&i, std1->pincode, str);
//			std1->link = NULL;
//			break;
//		}
//		if (info1 == NULL){ info1 = std1; temp1 = info1; }
//		else{ temp1->link = std1; temp1 = std1; }
//	}
//	fclose(fp2);
//}
//
//
//
//
//void createsecondFile(struct student2 *std1, struct student2 *temp1)
//{
//	char *str = (char *)malloc(sizeof(char) * 100);
//	FILE *fp2; int i, j, k;
//	fp2 = fopen("studentmarkslist1.csv", "r");
//	while (1)
//	{
//		k = fscanf(fp2, "%s", str);
//		if (k == -1){ break; }
//		std1 = (struct student2 *)malloc(sizeof(struct student2));
//		std1->name = (char *)malloc(sizeof(char) * 30);
//		std1->avg = (char *)malloc(sizeof(char) * 30);
//		std1->cgpa = (char *)malloc(sizeof(char) * 30);
//		for (i = 0; str[i] != '\0'; i++)
//		{
//			std1->rollno = stringtoint(&i, str); i++;
//			stringconcat(&i, std1->name, str); i++;
//			std1->m1 = stringtoint(&i, str); i++;
//			std1->m2 = stringtoint(&i, str); i++;
//			std1->m3 = stringtoint(&i, str); i++;
//			std1->m4 = stringtoint(&i, str); i++;
//			stringconcat(&i, std1->avg, str); i++;
//			stringconcat(&i, std1->cgpa, str);
//			std1->link = NULL;
//			break;
//		}
//		if (head2 == NULL){ head2 = std1; temp1 = head2; }
//		else{ temp1->link = std1; temp1 = std1; }
//	}
//	fclose(fp2);
//}
//
//
//
//
//void createfirstFile(struct student1 *std1,struct student1 *temp)
//{
//	char *str = (char *)malloc(sizeof(char) * 100);
//	FILE *fp1; int i, j, k, p = 0;
//	fp1 = fopen("studentmarkslist.csv", "r");
//	while (1)
//	{
//		k = fscanf(fp1, "%s", str);
//		if (k == -1){ break; }
//		std1 = (struct student1*)malloc(sizeof(struct student1));
//		std1->name = (char *)malloc(sizeof(char) * 30);
//		for (i = 0; str[i] != '\0'; i++)
//		{
//			std1->rollno = stringtoint(&i, str);
//			i++;
//			stringconcat(&i,std1->name,str); i++;
//			std1->m1 = stringtoint(&i, str); i++;
//			std1->m2 = stringtoint(&i, str); i++;
//			std1->m3 = stringtoint(&i, str); i++;
//			std1->m4 = stringtoint(&i, str); i++;
//			std1->link = NULL;
//			break;
//		}
//		if (head1 == NULL){ head1 = std1; temp = head1; }
//		else{ temp->link = std1; temp = std1; }
//	}
//	fclose(fp1);
//}
//
//
//
//
//void joinfirst()
//{
//	FILE *fp5;
//	fp5 = fopen("joinfirst.csv", "w");
//	struct student1 *temp1;
//	struct info *temp2;
//	temp1 = head1; temp2 = info1;
//	while (temp1 != NULL)
//	{
//		temp2 = info1;
//		while (temp2 != NULL)
//		{
//			if (temp1->rollno == temp2->rollno)
//			{
//				fprintf(fp5, "%d,%s,%d,%d,%d,%d,noaverage,nocgpa,", temp1->rollno, temp1->name, temp1->m1, temp1->m2, temp1->m3, temp1->m4);
//				fprintf(fp5, "%s,%s,%s,%s", temp2->phoneno, temp2->address, temp2->city, temp2->pincode);
//				break;
//			}
//			temp2 = temp2->link;
//		}
//		temp1 = temp1->link;
//	}
//	fclose(fp5);
//}
//
//
//
//
//void joinsecond()
//{
//	FILE *fp4;
//	fp4 = fopen("joinsecond.csv", "w");
//	struct student2 *temp1;
//	struct info *temp2;
//	temp1 = head2; temp2 = info1;
//	while (temp1 != NULL)
//	{
//		temp2 = info1;
//		while (temp2 != NULL)
//		{
//			if (temp1->rollno == temp2->rollno)
//			{
//				fprintf(fp4, "%d,%s,%d,%d,%d,%d,%s,%s,", temp1->rollno, temp1->name, temp1->m1, temp1->m2, temp1->m3, temp1->m4, temp1->avg, temp1->cgpa);
//				fprintf(fp4, "%s,%s,%s,%s", temp2->phoneno, temp2->address, temp2->city, temp2->pincode);
//				break;
//			}
//			temp2 = temp2->link;
//		}
//		temp1 = temp1->link;
//	}
//}
//
//
//
//
//int main()
//{
//	struct student1 *std1=NULL,*temp=NULL;
//	struct student2 *std2 = NULL, *temp1 = NULL;
//	struct info *info=NULL,*temp3=NULL;
//	createfirstFile(std1,temp);
//	createsecondFile(std2, temp1);
//	createthirdFile(info, temp3);
//	joinfirst();
//	joinsecond();
//	system("pause");
//	return 0;
//}