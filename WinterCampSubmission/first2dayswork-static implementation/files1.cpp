//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//struct node
//{
//	int rollno;
//	char *str;
//	int m1;
//	int m2;
//	int m3;
//	int m4;
//	float avg;
//	float cgpa;
//};
//
//
//void printFile(FILE *fp)
//{
//	char c;
//	c = fgetc(fp);
//	while (c != EOF)
//	{
//		printf("%c", c);
//		c = fgetc(fp);
//	}
//
//}
//
//
//
//int funcint(FILE *fp,char *c1)
//{
//	char c; int k;
//	k = 0;
//	while (1)
//	{
//		c = fgetc(fp);
//		if (c != ','&&c!='\n'&&c!=EOF)
//		{
//			k = k * 10 + (c - 48);
//		}
//		else
//		{
//			break;
//		}
//	}
//	*c1 = c;
//	return k;
//}
//
//
//
//float cgpacal(int i)
//{
//	if (i >= 90 && i <= 100){ return 4.0; }
//	else if (i >= 85 && i <= 89){ return 3.76; }
//	else if (i >= 80 && i <= 84){ return 3.5; }
//	else if(i >= 75 && i <= 79){
//		return 3.33;
//	}
//	else if(i >= 70 && i <= 74){
//		return 3.0;
//	}
//	else if (i >= 65 && i <= 69){
//		return 2.76;
//	}
//	else if (i >= 60 && i <= 64){
//		return 2.5;
//	}
//	else 
//	{
//		return 2.0;
//	}
//}
//
//
//
//void pushinstructure(FILE *fp,struct node *temp)
//{
//	FILE *fp3;
//	fp3 = fopen("studentmarkslist1.csv", "w");
//	int i = 0, k; char c; char c1;
//	int p = 0;
//	while (1)
//	{
//			temp->rollno=funcint(fp,&c1);
//			i = 0;
//			while (1)
//			{
//				c = fgetc(fp);
//				if (c != ',')
//				{
//					temp->str[i++] = c;
//				}
//				else{ temp->str[i] = '\0'; break; }
//			}
//			temp->m1 = funcint(fp,&c1);
//			temp->m2 = funcint(fp,&c1);
//			temp->m3 = funcint(fp,&c1);
//			temp->m4 = funcint(fp,&c1);
//			temp->avg = ((float)temp->m1 + temp->m2 + temp->m3 + temp->m4) / 4;
//			temp->cgpa=cgpacal(temp->avg);
//			//if (p > 100)
//			//{
//				fprintf(fp3, "%d,%s,%d,%d,%d,%d,%f,%f\n", temp->rollno, temp->str, temp->m1, temp->m2, temp->m3, temp->m4, temp->avg, temp->cgpa);
//			//}
//			if (c1 == EOF){
//				break; 
//			}	
//			//p++;
//	}
//	fclose(fp3);
//}
//
//
//
//void calculate_average(FILE *fp,int *p,char *str,struct node *temp)
//{
//	int i = 0; char c;
//	while (1)
//	{
//		if (*p != 0)
//		{
//			pushinstructure(fp, temp);
//			break;
//		}
//		else
//		{
//			c = fgetc(fp);
//		}
//		(*p)++;
//	}
//	
//}
//
//
//
//void func(FILE *fp)
//{
//	int i = 0; char c;
//	char *str = (char *)malloc(sizeof(char) * 100);
//	struct node *temp = (struct node *)malloc(sizeof(struct node));
//	temp->str = (char *)malloc(sizeof(char) * 50);
//	while (1)
//	{
//		calculate_average(fp, &i,str,temp);
//		c = fgetc(fp);
//		if (c == EOF){ break; }
//	}
//}
//
//
//
//int main1()
//{
//	FILE *fp, *fp1,*fp2; int i = 0;
//	fp = fopen("studentmarkslist.csv", "a+");
//	fp2 = fopen("studentmarkslist.csv", "a+");
//	printFile(fp);
//	printf("\n");
//	fp1 = fopen("studentinfolist.csv", "a+");
//	printFile(fp1);
//	func(fp2);
//	printFile(fp);
//	fclose(fp); fclose(fp1); fclose(fp1);
//	system("pause");
//	return 0;
//}