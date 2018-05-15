#include<stdlib.h>
struct operatevalue
{
	int rollno;
	char *name;
	int m1;
	int m2;
	int m3;
	int m4;
	char *avg;
	char *cgpa;
	char *phoneno;
	char *address;
	char *city;
	char *pincode;
	struct all *link;
}*values=NULL;


struct querycal
{
	int rollno;
	int name;
	int m1; int m2; int m3; int m4;
	int avg; int cgpa;
	int phoneno;
	int address; int city; int pincode;
	struct querycal *link;
}*query = NULL,*query1=NULL,*oper=NULL;


struct student1
{
	int rollno;
	char *name;
	int m1;
	int m2;
	int m3;
	int m4;
	int flag = 0;
	struct student1 *link;
}*head1 = NULL, *last1 = NULL;


struct student2
{
	int rollno;
	char *name;
	int m1;
	int m2;
	int m3;
	int m4;
	char *avg;
	char *cgpa;
	int flag = 0;
	struct student2 *link;
}*head2 = NULL, *last2 = NULL;



struct info
{
	int rollno;
	char *phoneno;
	char *address;
	char *city;
	char *pincode;
	int flag = 0;
	struct info *link;
}*info1 = NULL, *infolast = NULL;


struct all
{
	int rollno;
	char *name;
	int m1;
	int m2;
	int m3;
	int m4;
	char *avg;
	char *cgpa;
	char *phoneno;
	char *address;
	char *city;
	char *pincode;
	struct all *link;
}*all1 = NULL, *alllast = NULL;



int greaterthaneq(int val, struct all *temp)
{
	if (query1->rollno == 1){ if (temp->rollno >= val) return 1; }
	if (query1->m1 == 1){ if (temp->m1 >= val) return 1; }
	if (query1->m2 == 1){ if (temp->m2 >= val) return 1; }
	if (query1->m3 == 1){ if (temp->m3 >= val) return 1; }
	if (query1->m4 == 1){ if (temp->m4 >= val) return 1; }
	return 0;
}



int greaterthan(int val, struct all *temp)
{
	if (query1->rollno == 1){ if (temp->rollno > val) return 1; }
	if (query1->m1 == 1){ if (temp->m1 > val) return 1; }
	if (query1->m2 == 1){ if (temp->m2 > val) return 1; }
	if (query1->m3 == 1){ if (temp->m3 > val) return 1; }
	if (query1->m4 == 1){ if (temp->m4 > val) return 1; }
	return 0;
}


int lessthaneq(int val, struct all *temp)
{
	if (query1->rollno == 1){ if (temp->rollno <= val) return 1; }
	if (query1->m1 == 1){ if (temp->m1 <= val) return 1; }
	if (query1->m2 == 1){ if (temp->m2 <= val) return 1; }
	if (query1->m3 == 1){ if (temp->m3 <= val) return 1; }
	if (query1->m4 == 1){ if (temp->m4 <= val) return 1; }
	return 0;
}


int lessthan(int val, struct all *temp)
{
	if (query1->rollno == 1){ if (temp->rollno < val) return 1; }
	if (query1->m1 == 1){ if (temp->m1 < val) return 1; }
	if (query1->m2 == 1){ if (temp->m2 < val) return 1; }
	if (query1->m3 == 1){ if (temp->m3 < val) return 1; }
	if (query1->m4 == 1){ if (temp->m4 < val) return 1; }
	return 0;
}


int  equal(int val, struct all *temp)
{
	if (query1->rollno == 1){ if (temp->rollno == val) return 1; }
	if (query1->m1 == 1){ if (temp->m1 == val) return 1; }
	if (query1->m2 == 1){ if (temp->m2 == val) return 1; }
	if (query1->m3 == 1){ if (temp->m3 == val) return 1; }
	if (query1->m4 == 1){ if (temp->m4 == val) return 1; }
	return 0;
}


int greaterthaneq(int val, struct info *temp)
{
	if (query1->rollno == 1){ if (temp->rollno >= val) return 1; }
	return 0;
}



int greaterthan(int val, struct info *temp)
{
	if (query1->rollno == 1){ if (temp->rollno > val) return 1; }
	return 0;
}


int lessthaneq(int val, struct info *temp)
{
	if (query1->rollno == 1){ if (temp->rollno <= val) return 1; }
	return 0;
}



int lessthan(int val, struct info *temp)
{
	if (query1->rollno == 1){ if (temp->rollno < val) return 1; }
	return 0;
}


int  equal(int val, struct info *temp)
{
	if (query1->rollno == 1){ if (temp->rollno == val) return 1; }
	return 0;
}



int greaterthaneq(int val, struct student2 *temp)
{
	if (query1->rollno == 1){ if (temp->rollno >= val) return 1; }
	if (query1->m1 == 1){ if (temp->m1 >= val) return 1; }
	if (query1->m2 == 1){ if (temp->m2 >= val) return 1; }
	if (query1->m3 == 1){ if (temp->m3 >= val) return 1; }
	if (query1->m4 == 1){ if (temp->m4 >= val) return 1; }
	return 0;
}


int greaterthan(int val, struct student2 *temp)
{
	if (query1->rollno == 1){ if (temp->rollno > val) return 1; }
	if (query1->m1 == 1){ if (temp->m1 > val) return 1; }
	if (query1->m2 == 1){ if (temp->m2 > val) return 1; }
	if (query1->m3 == 1){ if (temp->m3 > val) return 1; }
	if (query1->m4 == 1){ if (temp->m4 > val) return 1; }
	return 0;
}




int lessthaneq(int val, struct student2 *temp)
{
	if (query1->rollno == 1){ if (temp->rollno <= val) return 1; }
	if (query1->m1 == 1){ if (temp->m1 <= val) return 1; }
	if (query1->m2 == 1){ if (temp->m2 <= val) return 1; }
	if (query1->m3 == 1){ if (temp->m3 <= val) return 1; }
	if (query1->m4 == 1){ if (temp->m4 <= val) return 1; }
	return 0;
}




int lessthan(int val, struct student2 *temp)
{
	if (query1->rollno == 1){ if (temp->rollno < val) return 1; }
	if (query1->m1 == 1){ if (temp->m1 < val) return 1; }
	if (query1->m2 == 1){ if (temp->m2 < val) return 1; }
	if (query1->m3 == 1){ if (temp->m3 < val) return 1; }
	if (query1->m4 == 1){ if (temp->m4 < val) return 1; }
	return 0;
}


int  equal(int val, struct student2 *temp)
{
	if (query1->rollno == 1){ if (temp->rollno == val) return 1; }
	if (query1->m1 == 1){ if (temp->m1 == val) return 1; }
	if (query1->m2 == 1){ if (temp->m2 == val) return 1; }
	if (query1->m3 == 1){ if (temp->m3 == val) return 1; }
	if (query1->m4 == 1){ if (temp->m4 == val) return 1; }
	return 0;
}


int strcontain(char *main, char *sub)
{
	int k = 0,j=0;
	while (main[k] != '\0')
	{
		if (sub[j] == main[k])
		{
			while (main[k] == sub[j]&&(main[k]!='\0'&&sub[j]!='\0'))
			{
				k++; j++;
			}
			if (sub[j] == '\0'){ return 1; }
			else return 0;
		}
		k++;
	}
	return 0;
}



int strequal(char *node, char *value)
{
	int i = 0;
	while (node[i] != '\0'&&value[i] != '\0')
	{
		if (node[i] != value[i]){ return 0; }
		i++;
	}
	return 1;
}



int strtoint(char *str)
{
	int k, k1;
	k = 0; k1 = 0;
	while (str[k] != '\0')
	{
		k1 = k1 * 10 + (str[k] - 48);
		k++;
	}
	return k1;
}



int finalprint2(int *p, char *str, struct info *temp)
{
	int k = 0;
	if (*p == 1 || *p == 2 || *p == 3 || *p == 4 || *p == 5)
	{
		int val = strtoint(str);
		if (*p == 1)
		{
			k = greaterthaneq(val, temp);
		}
		else if (*p == 2)
		{
			k = greaterthan(val, temp);
		}
		else if (*p == 3){ k = lessthaneq(val, temp); }
		else if (*p == 4){ k = lessthan(val, temp); }
		else if (*p == 5){ k = equal(val, temp); }
	}
	else
	{
		if (*p == 6)
		{
			if (query1->address == 1)
			{
				k = strequal(temp->address, str);
			}
			else if (query1->city == 1){ k = strequal(temp->city, str); }
			else if (query1->phoneno == 1){ k = strequal(temp->phoneno, str); }
			else if (query1->pincode == 1){ k = strequal(temp->pincode, str); }
		}
		else if (*p == 7)
		{
			if (query1->address == 1)
			{
				k = strcontain(temp->address, str);
			}
			else if (query1->city == 1){ k = strcontain(temp->city, str); }
			else if (query1->phoneno == 1){ k = strcontain(temp->phoneno, str); }
			else if (query1->pincode == 1){ k = strcontain(temp->pincode, str); }
		}
	}
	return k;
}




int finalprint1(int *p, char *str, struct student2 *temp)
{
	int k = 0;
	if (*p == 1 || *p == 2 || *p == 3 || *p == 4 || *p == 5)
	{
		int val = strtoint(str);
		if (*p == 1)
		{
			k = greaterthaneq(val, temp);
		}
		else if (*p == 2)
		{
			k = greaterthan(val, temp);
		}
		else if (*p == 3){ k = lessthaneq(val, temp); }
		else if (*p == 4){ k = lessthan(val, temp); }
		else if (*p == 5){ k = equal(val, temp); }
	}
	else
	{
		if (*p == 6)
		{
			if (query1->avg == 1){ k = strequal(temp->avg, str); }
			else if (query1->cgpa == 1){ k = strequal(temp->cgpa, str); }
			else if (query1->name == 1){ k = strequal(temp->name, str); }
		}
		else if (*p == 7)
		{
			if (query1->avg == 1){ k = strcontain(temp->avg, str); }
			else if (query1->cgpa == 1){ k = strcontain(temp->cgpa, str); }
			else if (query1->name == 1){ k = strcontain(temp->name, str); }
		}
	}
	return k;
}



int trueorfalses1(struct student2 *outer, struct student2 *inner,int value)
{
	if (value == 1)
	{
		if (outer->rollno > inner->rollno){ return 1; }
	}
	else if (value == 2){ if (outer->m1 > inner->m1){ return 1; } }
	else if (value == 3){ if (outer->m2 > inner->m2){ return 1; } }
	else if (value == 4){ if (outer->m3 > inner->m3){ return 1; } }
	else if (value == 5){ if (outer->m4 > inner->m4){ return 1; } }
	return 0;
}



int trueorfalses3(struct all *outer, struct all *inner, int value)
{
	if (value == 1)
	{
		if (outer->rollno > inner->rollno){ return 1; }
	}
	else if (value == 2){ if (outer->m1 > inner->m1){ return 1; } }
	else if (value == 3){ if (outer->m2 > inner->m2){ return 1; } }
	else if (value == 4){ if (outer->m3 > inner->m3){ return 1; } }
	else if (value == 5){ if (outer->m4 > inner->m4){ return 1; } }
	return 0;
}