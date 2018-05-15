#include "temp.h"
#pragma once
void sort();
void sorts1();
void sorts2();
void sorts3();


void allfieldss1()
{
	query->rollno = 1; query->name = 1; query->m1 = 1;
	query->m2 = 1; query->m3 = 1; query->m4 = 1;
	query->avg = 1; query->cgpa = 1;
}



void allfieldss2()
{
	query->rollno = 1; query->address = 1; query->city = 1;
	query->phoneno = 1; query->pincode = 1;
}



void allfieldss3()
{
	query->rollno = 1; query->name = 1; query->m1 = 1;
	query->m2 = 1; query->m3 = 1; query->m4 = 1;
	query->avg = 1; query->cgpa = 1;
	query->address = 1; query->city = 1;
	query->phoneno = 1; query->pincode = 1;
}



void printquerys1(int p,char *str)
{
	struct student2 *temp;
	temp = head2; int k = 1;
	while (temp != NULL)
	{
		if (p > 0)
		{
			k = finalprint1(&p, str, temp);
		}
		if (k == 1)
		{
			if (query->rollno == 1)
			{
				printf("%d\t", temp->rollno);
			}
			if (query->name == 1){ printf("%s\t", temp->name); }
			if (query->m1 == 1){ printf("%d\t", temp->m1); }
			if (query->m2 == 1){ printf("%d\t", temp->m2); }
			if (query->m3 == 1){ printf("%d\t", temp->m3); }
			if (query->m4 == 1){ printf("%d\t", temp->m4); }
			if (query->avg == 1){ printf("%s\t", temp->avg); }
			if (query->cgpa == 1){ printf("%s\t", temp->cgpa); }
			printf("\n");
		}
		temp = temp->link;
	}
}



void printquerys2(int p,char *str)
{
	struct info *temp; int k = 1;
	temp = info1;
	while (temp != NULL)
	{
		if (p > 0)
		{
			k = finalprint2(&p, str, temp);
		} 
		if (k == 1)
		{
			if (query->rollno == 1)
			{
				printf("%d\t", temp->rollno);
			}
			if (query->city == 1){ printf("%s\t", temp->city); }
			if (query->address == 1){ printf("%s\t", temp->address); }
			if (query->phoneno == 1){ printf("%s\t", temp->phoneno); }
			if (query->pincode == 1){ printf("%s\t", temp->pincode); }
			printf("\n");
		}
		temp = temp->link;
	}
}





int finalprint3(int *p, char *str, struct all *temp)
{
	int k = 0;
	if (*p == 1||*p==2||*p==3||*p==4||*p==5)
	{
		int val = strtoint(str);
		if (*p == 1)
		{
			k=greaterthaneq(val, temp);
		}
		else if (*p == 2)
		{
			k=greaterthan(val, temp);
		}
		else if (*p == 3){ k=lessthaneq(val, temp); }
		else if (*p == 4){ k=lessthan(val, temp); }
		else if (*p == 5){k= equal(val, temp); }
	}
	else
	{
		if (*p == 6)
		{
			if (query1->address == 1)
			{
				k=strequal(temp->address, str);
			}
			else if (query1->avg == 1){k= strequal(temp->avg, str); }
			else if (query1->cgpa == 1){k= strequal(temp->cgpa, str); }
			else if (query1->city == 1){ k=strequal(temp->city, str); }
			else if (query1->phoneno == 1){ k=strequal(temp->phoneno, str); }
			else if (query1->pincode == 1){k= strequal(temp->pincode, str); }
			else if (query1->name== 1){k= strequal(temp->name, str); }
		}
		else if (*p == 7)
		{
			if (query1->address == 1)
			{
				k = strcontain(temp->address, str);
			}
			else if (query1->avg == 1){ k = strcontain(temp->avg, str); }
			else if (query1->cgpa == 1){ k = strcontain(temp->cgpa, str); }
			else if (query1->city == 1){ k = strcontain(temp->city, str); }
			else if (query1->phoneno == 1){ k = strcontain(temp->phoneno, str); }
			else if (query1->pincode == 1){ k = strcontain(temp->pincode, str); }
			else if (query1->name == 1){ k = strcontain(temp->name, str); }
		}
	}
	return k;
}



void printquerys3(int p,char *str)
{
	struct all *temp; int k = 1;
	temp = all1;
	while (temp != NULL)
	{
		if (p > 0)
		{
			k = finalprint3(&p, str, temp);
		}
		if (k == 1)
		{
			if (query->rollno == 1){ printf("%d ", temp->rollno); }
			if (query->name == 1){ printf("%s ", temp->name); }
			if (query->m1 == 1){ printf("%d ", temp->m1); }
			if (query->m2 == 1){ printf("%d ", temp->m2); }
			if (query->m3 == 1){ printf("%d  ", temp->m3); }
			if (query->m4 == 1){ printf("%d  ", temp->m4); }
			if (query->avg == 1){ printf("%s  ", temp->avg); }
			if (query->cgpa == 1){ printf("%s  ", temp->cgpa); }
			if (query->city == 1){ printf("%s  ", temp->city); }
			if (query->address == 1){ printf("%s  ", temp->address); }
			if (query->phoneno == 1){ printf("%s  ", temp->phoneno); }
			if (query->pincode == 1){ printf("%s  ", temp->pincode); }
			printf("\n");
		}
		temp = temp->link;
	}
}




void querysplit(char *querystr, int *i)
{
	while (querystr[*i] != ' '){ (*i)++; }
	while (querystr[*i] == ' '){ (*i)++; }
}



void queryend(char *str, int *i)
{
	while (str[*i] != ';'&&str[*i]==' '){ (*i)++; }
}



int schemafind(char *str)
{
	int i = 0;
	while (str[i] != 'f'){ i++; }
	while (str[i] != ' '){ i++; }
	while (str[i] == ' '){ i++; }
	if (str[i + 1] == '1')return 1;
	else if (str[i + 1] == '2')return 2;
	else if (str[i + 1] == '3')return 3;
	else return 4;
}


int caloperator(char *str, int *i)
{
	if (str[*i] == '>'&&str[(*i) + 1] == '='){ return 1; }
	else if (str[*i] == '>'&&str[(*i)+1] != '='){ return 2; }
	else if (str[*i] == '<'&&str[(*i) + 1] == '='){ return 3; }
	else if (str[*i] == '<'&&str[(*i) + 1] != '='){ return 4; }
	else if (str[*i] == '='){ return 5; }
	else if (str[*i] == 'm'){ return 6; }
	else if (str[*i] == 'c'){ return 7; }
	return 0;

}


int  makecolumn(char *str,int *p)
{
	int s;
	if (str[*p] == 'r'){ query1->rollno = 1; }
	else if (str[*p] == 'n'){ query1->name = 1; }
	else if (str[*p] == 'm'&&str[(*p)+1] == '1'){ query1->m1 = 1; }
	else if (str[*p] == 'm'&&str[(*p)] == '2'){ query1->m2 = 1; }
	else if (str[*p] == 'm'&&str[(*p)+1] == '3'){ query1->m3 = 1; }
	else if (str[*p] == 'm'&&str[(*p) + 1] == '4'){ query1->m4 = 1; }
	else if (str[*p] == 'a'&&str[(*p) + 1] == 'v'){ query1->avg = 1; }
	else if (str[*p] == 'a'&&str[(*p) + 1] == 'd'){ query1->address = 1; }
	else if (str[*p] == 'c'&&str[(*p) + 1] == 'g'){ query1->cgpa = 1; }
	else if (str[*p] == 'c'&&str[(*p) + 1] == 'i'){ query1->city = 1; }
	else if (str[*p] == 'p'&&str[(*p) + 1] == 'i'){ query1->pincode = 1; }
	else if (str[*p] == 'p'&&str[(*p) + 1] == 'h'){ query1->phoneno = 1; }
	while (str[*p] != ' '){ (*p)++; }(*p)++;

	s = *p;
	int k=caloperator(str, &s);
	*p = s;
	return k;
}


int operationdone(char *querystr, int *i,char *value)
{
	int k; int j = 0,p=0;
	query1 = (struct querycal *)calloc(sizeof(struct querycal), 1);
	//oper = (struct querycal *)calloc(sizeof(struct querycal), 1);
	while (querystr[*i] != ' '){ (*i)++; }
	while (querystr[*i] == ' '){ (*i)++; }
	p = *i;
	k=makecolumn(querystr, &p);
	*i = p;
	while (querystr[*i] != ' '){ (*i)++; }
	while (querystr[*i] == ' '){ (*i)++; }
	while (querystr[*i] != ';'){ value[j++] = querystr[*i]; (*i)++; }
	value[j] = '\0';
	return k;
}


void parsequery(char *querystr)
{
	char *value = (char *)malloc(sizeof(char) * 10);
	int k = 0; 
	query = (struct querycal *)calloc(sizeof(struct querycal),1);
	int i = 6; int p = -1;
	if (querystr[0] == 's'&&querystr[1] == 'o'&&querystr[2] == 'r'&&querystr[3] == 't')
	{
		sort();
	}
	else
	{
		k = schemafind(querystr);
		while (querystr[i] == ' '){ i++; }
		if (querystr[i] == '*')
		{
			int end = 0;
			if (k == 1){ allfieldss1(); }
			else if (k == 2){ allfieldss2(); }
			else if (k == 3){ allfieldss3(); }
			while (querystr[i] != ';')
			{
				if (querystr[i] == 'w'&&querystr[i + 1] == 'h'){ p = operationdone(querystr, &i, value); i--; }
				i++;
				end++; if (end > 100){ p = 0; break; }
			}
		}
		else
		{
			int end = 0;
			while (1)
			{
				if (querystr[i] == 'r'&&querystr[i + 1] == 'o'&&querystr[i + 2] == 'l'&&querystr[i + 3] == 'l'){ query->rollno = 1; querysplit(querystr, &i); }
				if (querystr[i] == 'n'&&querystr[i + 1] == 'a'&&querystr[i + 2] == 'm'&&querystr[i + 3] == 'e'){ query->name = 1; querysplit(querystr, &i); }
				if (querystr[i] == 'm'&&querystr[i + 1] == '1'){ query->m1 = 1; i = i + 3; }
				if (querystr[i] == 'm'&&querystr[i + 1] == '2'){ query->m2 = 1; i = i + 3; }
				if (querystr[i] == 'm'&&querystr[i + 1] == '3'){ query->m3 = 1; i = i + 3; }
				if (querystr[i] == 'm'&&querystr[i + 1] == '4'){ query->m4 = 1; i = i + 3; }
				if (querystr[i] == 'a'&&querystr[i + 1] == 'v'&&querystr[i + 2] == 'g'){ query->avg = 1; querysplit(querystr, &i); }
				if (querystr[i] == 'c'&&querystr[i + 1] == 'g'){ query->cgpa = 1; querysplit(querystr, &i); }
				if (querystr[i] == 'c'&&querystr[i + 1] == 'i'){ query->city = 1; querysplit(querystr, &i); }
				if (querystr[i] == 'a'&&querystr[i + 1] == 'd'){ query->address = 1; querysplit(querystr, &i); }
				if (querystr[i] == 'p'&&querystr[i + 1] == 'i'){ query->pincode = 1; querysplit(querystr, &i); }
				if (querystr[i] == 'p'&&querystr[i + 1] == 'h'){ query->phoneno = 1; querysplit(querystr, &i); }
				if (querystr[i] == 'f'){ querysplit(querystr, &i); }
				if (querystr[i] == 's')
				{
					i = i + 2;
					if (querystr[i] != ';'){ i++; }
				}
				if (querystr[i] == 'w'&&querystr[i + 1] == 'h'){ p = operationdone(querystr, &i, value); }
				if (querystr[i] == ';'){ break; }
				end++;
				if (end > 12){ break; p = 0; }
			}
		}
		if (p != 0)
		{
			if (k == 1)
			{
				printquerys1(p, value);
			}
			else if (k == 2)
			{
				printquerys2(p, value);
			}
			else if (k == 3)
			{
				printquerys3(p, value);
			}
		}
		else
		{
			printf("enter valid string");
		}
	}
}




void querycalfunc(char *querystr)
{
	parsequery(querystr);
}
void sorts1()
{
	int value;
	printf("enter column by sort [1:rollno] [2:m1] [3:m2] [4:m3] [5:m4]\n");
	scanf("%d", &value);
	int i = 0;
	struct student2 *outer, *inner, *outp, *inp;
	outer = head2; outp = outer;
	inner = outer->link;
	while (outer != NULL)
	{
		inp = outer; inner = inp->link;
		while (inner != NULL)
		{
			if (trueorfalses1(outer,inner,value))
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
			head2 = outp;
		}
		i++;
		outer = outer->link;
	}
}
void sorts2()
{
	int i = 0;
	struct info *outer, *inner, *outp, *inp;
	outer = info1; outp = outer;
	inner = outer->link;
	while (outer != NULL)
	{
		inp = outer; inner = inp->link;
		while (inner != NULL)
		{
			if (outer->rollno>inner->rollno)
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
			info1 = outp;
		}
		i++;
		outer = outer->link;
	}
}
void sorts3()
{
	int value;
	printf("enter column by sort [1:rollno] [2:m1] [3:m2] [4:m3] [5:m4]\n");
	scanf("%d", &value);
	int i = 0;
	struct all *outer, *inner, *outp, *inp;
	outer = all1; outp = outer;
	inner = outer->link;
	while (outer != NULL)
	{
		inp = outer; inner = inp->link;
		while (inner != NULL)
		{
			if (trueorfalses3(outer, inner, value))
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
			all1 = outp;
		}
		i++;
		outer = outer->link;
	}
}
void sort()
{
	int k = 0;
	printf("enter schema 1 2 3\n");
	scanf("%d", &k);
	if (k == 1){ sorts1(); }
	else if (k == 2){ sorts2(); }
	else if (k == 3){ sorts3(); }
}