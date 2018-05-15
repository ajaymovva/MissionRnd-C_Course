#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*
EXPLANATION:
	In this project the implementation is done as follows:
	I think this problem as a tree implementation having many children to the parent.
	Initially we need a structure which store the many tables as so for this a structure array is created which can store many tables.
	next for each table we have many rows as possible so this strucuture array is also created for storing the record of single structure.
	for each rows we has many columns which is of three differnt data types
	as->"int"->Integer
	 ->"str"-->string
	 -->"float"-->float
	 so this every row is also treated as structure array which has store either integer or float or string depend on the requirement.
	 so by this as tree traversal the dynamic structure is created based on the structure of structures.

	 struct schema
	 {
	 struct record *record1;
	 }*schema1;
	 
	 the above is a structure stores the data of all strucutes by creating array of structures to it.

	 struct record
	 {
	 struct data *data1;
	 };

	 we need a array strcture to store all records of single structure so the above is created and we can see the schema structure
	 has attribute record.

	 struct data
	 {
	 int integer;
	 char *string;
	 float floatval;
	 };

		In the same way array of structure is created to data strucute to store all the columns of single record depend on
		the type of datatype given along the query.

*/


/*
structure to store column and datatype of all the tables so struct ** is taken.
*/
struct attribute
{
	char *column;
	char *datatype;
}**fields;


/*
To store the names of all the given tables and columns count of table.
*/

struct schemas
{
	char *name;
	int noofimport;
	int coloumns;
}*names;

/*
	It store the data for each column depend on type of data type.
*/
struct data
{
	int integer;
	char *string;
	float floatval;
};


/*
This structure to store a rows of a table in the format of structure of record.
By creating array of strucutes to this we can implement this dynamic strucute for the differnt tables as given.
Multiple tables are creating by this implementation of array of structures.
*/
struct schema
{
	struct record *record1;
}*schema1;


/*
This structure implements all the data of each record in table which means a row.
The data for each column for the single row is again placed in data strucute 
depend on the input of column wheather string or int.
*/


struct record
{
	struct data *data1;
};


/*
the below are basic operation functions.
that required for the many operations
*/

int strtoint1(char *value)
{
	int k = 0, i = 0;
	while (value[i]!='\0')
	{
		k = k * 10 + (value[i] - 48);
		i++;
	}
	return k;
}


float strtofloat(char *str, int *stringiter)
{
	int val = 0; int count = 0;
	while (str[*stringiter] != '.'&&str[*stringiter] != ','&&str[*stringiter] != '\n')
	{
		val = val * 10 + (str[*stringiter] - 48);
		(*stringiter)++;
	}
	float ans;
	if (str[*stringiter] == '.')
	{
		(*stringiter)++;
		while (str[*stringiter] != ','&&str[*stringiter] != '\n')
		{
			val = val * 10 + (str[*stringiter] - 48);
			(*stringiter)++;
			count++;
		}
	}
	if (count != 0)
	{
		ans = (float)val;
		return ans / (pow(10.0, count));
	}
	else
	{
		ans = (float)val;
		return ans;
	}
}

int strcontain(char *main, char *sub)
{
	int k = 0, j = 0;
	while (main[k] != '\0')
	{
		if (sub[j] == main[k])
		{
			while (main[k] == sub[j] && (main[k] != '\0'&&sub[j] != '\0'))
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

float strtofloat1(char *str)
{
	int val = 0; int count = 0; int iter = 0;
	while (str[iter] != '.'&&str[iter]!='\0')
	{
		val = val * 10 + (str[iter] - 48);
		(iter)++;
	}
	float ans;
	if (str[iter] == '.')
	{
		(iter)++;
		while (str[iter] != ','&&str[iter] != '\0')
		{
			val = val * 10 + (str[iter] - 48);
			(iter)++;
			count++;
		}
	}
	if (count != 0)
	{
		ans = (float)val;
		return ans / (pow(10.0, count));
	}
	else
	{
		ans = (float)val;
		return ans;
	}
}

int calculateprintrecords(int noofimport, char *operation, char *value, int operablecolumn, int recorditer,char *datatype)
{
	int yesorno = 0;
	
	if (operation[0] == '>' || operation[0] == '<' || operation[0] == '=')
	{
		if (!strcmp(datatype, "int"))
		{
			int comp;
			comp = strtoint1(value);
			if (operation[0] == '>'&&operation[1] == '=')
			{
				if (schema1[noofimport].record1[recorditer].data1[operablecolumn].integer >= comp)
				{
					yesorno = 1;
				}
			}
			else if (operation[0] == '>')
			{
				if (schema1[noofimport].record1[recorditer].data1[operablecolumn].integer > comp)
				{
					yesorno = 1;
				}
			}
			else if (operation[0] == '<'&&operation[1] == '=')
			{
				if (schema1[noofimport].record1[recorditer].data1[operablecolumn].integer <= comp){ yesorno = 1; }
			}
			else if (operation[0] == '<')
			{
				if (schema1[noofimport].record1[recorditer].data1[operablecolumn].integer < comp){ yesorno = 1; }
			}
			else if (operation[0] == '=')
			{
				if (schema1[noofimport].record1[recorditer].data1[operablecolumn].integer == comp){ yesorno = 1; }
			}
		}
		else if (!strcmp(datatype, "float"))
		{
			float comp; int i = 0;
			comp = strtofloat1(value);
			if (operation[0] == '>'&&operation[1] == '=')
			{
				if (schema1[noofimport].record1[recorditer].data1[operablecolumn].floatval >= comp)
				{
					yesorno = 1;
				}
			}
			else if (operation[0] == '>')
			{
				if (schema1[noofimport].record1[recorditer].data1[operablecolumn].floatval > comp)
				{
					yesorno = 1;
				}
			}
			else if (operation[0] == '<'&&operation[1] == '=')
			{
				if (schema1[noofimport].record1[recorditer].data1[operablecolumn].floatval <= comp){ yesorno = 1; }
			}
			else if (operation[0] == '<')
			{
				if (schema1[noofimport].record1[recorditer].data1[operablecolumn].floatval < comp){ yesorno = 1; }
			}
			else if (operation[0] == '=')
			{
				if (schema1[noofimport].record1[recorditer].data1[operablecolumn].floatval == comp){ yesorno = 1; }
			}
		}
	}
	else
	{
		if (operation[0] == 'c'&&operation[1] == 'o'&&operation[2] == 'n'&&operation[3] == 't'&&operation[4] == 'a')
		{
			yesorno = strcontain(schema1[noofimport].record1[recorditer].data1[operablecolumn].string, value);
		}
		else if (operation[0] == 'm'&&operation[1] == 'a'&&operation[2] == 't'&&operation[3] == 'c'&&operation[4] == 'h')
		{
			yesorno = strequal(schema1[noofimport].record1[recorditer].data1[operablecolumn].string, value);
		}
	}
	return yesorno;
}