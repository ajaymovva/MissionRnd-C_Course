#define _CRT_SECURE_NO_WARNINGS
#include "structures.h"
/*
	store all columns and data types given to all tables by creating two dimensional structure	to  all consecutive tables datatype ad column.
	fields is a double pointer to strucute.
*/
int createschema(int nameslength)
{
	char * data = (char *)malloc(sizeof(char) * 100);
	gets(data); int i=0,j=0;
	fields[nameslength][i].column = (char *)malloc(sizeof(char) * 20);
	fields[nameslength][i].datatype = (char *)malloc(sizeof(char) * 20);
	while (data[j] != '\0')
	{
		int k = 0;
		while (data[j] != ':')
		{
			fields[nameslength][i].column[k] = data[j];
			k++; j++;
		}
		fields[nameslength][i].column[k] = '\0';
		j++; k = 0;
		while (data[j] != ';'&&data[j] != '\0')
		{
			fields[nameslength][i].datatype[k] = data[j];
			k++; j++;
		}
		fields[nameslength][i].datatype[k] = '\0';
		i++;
		if (data[j] == '\0'){ break; }
		j++;
		fields[nameslength][i].column = (char *)malloc(sizeof(char) * 20);
		fields[nameslength][i].datatype = (char *)malloc(sizeof(char) * 20);
	}
	return i;
}


/*
storing name and columns in another structure.
*/

void createname(char *data,int *length,int noofcols)
{
	int i = 0, j = 0;
	names[*length].name = (char *)malloc(sizeof(char) * 30);
	while (data[i] != ' '){ i++; }
	while (data[i] == ' '){ i++; }
	while (data[i] != ' '){ i++; }
	while (data[i] == ' '){ i++; }
	while (data[i] != '\0'){ names[*length].name[j]= data[i]; i++; j++; }
	names[*length].name[j] = '\0';
	names[*length].coloumns = noofcols;
}



void joincreatename(char *data, int *length, int noofimport)
{
	names[*length].name = (char *)malloc(sizeof(char) * 30);
	int l = strlen(data);
	int iter = l - 1; int i = 0;
	while (data[iter] != ' '){ iter--; }
	iter++;
	while (data[iter] != '\0')
	{
		names[*length].name[i] = data[iter]; iter++; i++;
	}
	names[*length].name[i] = '\0';
	names[*length].noofimport = noofimport;
}


/*
	respected record in column  and data type structure is selected.
*/


int  calculaterecord(char *query,int nameslength,int noofimport)
{
	int i = 0;
	char *name = (char *)malloc(sizeof(char) * 20);
	while (query[i] != ' '){ i++; }
	while (query[i] == ' '){ i++; }
	int iter = 0;
	while (query[i] != ' ')
	{
		name[iter++] = query[i]; i++;
	}
	name[iter] = '\0'; iter = 0;
	while (iter < nameslength)
	{
		if (!strcmp(name, names[iter].name))
		{
			names[iter].noofimport = noofimport;
			return iter;
		}
		iter++;
	}
	return -1;
}

int strtoint(char *str, int *len)
{
	int k = 0;
	while (str[*len] != ','&&str[*len]!='\n')
	{
		k = k * 10 + (str[*len] - 48);
		(*len)++;
	}
	return k;
}


void copystr(char *tobecopy, char *copy, int *len)
{
	int k = 0;
	while (copy[*len] != ','&&copy[*len]!='\n')
	{
		tobecopy[k] = copy[*len];
		k++; (*len)++;
	}
	tobecopy[k] = '\0';
}

/*
The complete import operation is done here.
*/

int twiceimport(char *query, int nameslength,int *row1)
{
	int i = 0;
	char *name = (char *)malloc(sizeof(char) * 20);
	while (query[i] != ' '){ i++; }
	while (query[i] == ' '){ i++; }
	int iter = 0;
	while (query[i] != ' ')
	{
		name[iter++] = query[i]; i++;
	}
	name[iter] = '\0'; iter = 0;
	while (iter < nameslength)
	{
		if (!strcmp(name, names[iter].name))
		{
			break;
		}
		iter++;
	}
	if (iter < nameslength)
	{
		*row1 = iter;
		if (names[iter].noofimport >= 0)
		{
			return names[iter].noofimport;
		}
	}
	else
	{
		*row1 = -1;
	}
	return -1;
}

void import_operation(int record,int noofimport,char *filename)
{
	schema1[noofimport].record1 = (struct record *)malloc(sizeof(struct record) * 1000);
	int iter = 0;
	FILE *fp2;
	fp2 = fopen(filename, "r");
	char *str = (char *)malloc(sizeof(char) * 250);
	fgets(str, 250, fp2);
	while (fgets(str, 250, fp2))
	{
		schema1[noofimport].record1[iter].data1 = (struct data *)malloc(sizeof(struct data)*50);
		int iterdata = 0; int stringiter = 0;
		while (str[stringiter] != '\0')
		{
			if (!strcmp(fields[record][iterdata].datatype, "int"))
			{
				schema1[noofimport].record1[iter].data1[iterdata].integer = strtoint(str, &stringiter);
				stringiter++;
				schema1[noofimport].record1[iter].data1[iterdata].string = (char *)malloc(sizeof(char) * 50);
				strcpy(schema1[noofimport].record1[iter].data1[iterdata].string, "NA");
				schema1[noofimport].record1[iter].data1[iterdata].floatval = -1.5;
			}
			else if (!strcmp(fields[record][iterdata].datatype, "str"))
			{
				schema1[noofimport].record1[iter].data1[iterdata].string = (char *)malloc(sizeof(char) * 50);
				copystr(schema1[noofimport].record1[iter].data1[iterdata].string, str, &stringiter);
				stringiter++; schema1[noofimport].record1[iter].data1[iterdata].integer = -1;
				schema1[noofimport].record1[iter].data1[iterdata].floatval = -1.5;
			}
			else if (!strcmp(fields[record][iterdata].datatype, "float"))
			{
				schema1[noofimport].record1[iter].data1[iterdata].floatval = strtofloat(str, &stringiter);
				stringiter++;
				schema1[noofimport].record1[iter].data1[iterdata].string = (char *)malloc(sizeof(char) * 50);
				strcpy(schema1[noofimport].record1[iter].data1[iterdata].string, "NA");
				 schema1[noofimport].record1[iter].data1[iterdata].integer = -1;
			}
			iterdata++;
		}
		iter++;
	}
	schema1[noofimport].record1[iter].data1 = NULL;
	fclose(fp2);
}


void import_forsamerowtwice(int record, int noofimport, char *filename)
{
	int iter = 0;
	while (1)
	{
		if (schema1[noofimport].record1[iter].data1 == NULL)
		{
			break;
		}
		iter++;
	}
	FILE *fp2;
	fp2 = fopen(filename, "r");
	char *str = (char *)malloc(sizeof(char) * 250);
	fgets(str, 250, fp2);
	while (fgets(str, 250, fp2))
	{
		schema1[noofimport].record1[iter].data1 = (struct data *)malloc(sizeof(struct data) * 50);
		int iterdata = 0; int stringiter = 0;
		while (str[stringiter] != '\0')
		{
			if (!strcmp(fields[record][iterdata].datatype, "int"))
			{
				schema1[noofimport].record1[iter].data1[iterdata].integer = strtoint(str, &stringiter);
				stringiter++;
				schema1[noofimport].record1[iter].data1[iterdata].string = (char *)malloc(sizeof(char) * 50);
				strcpy(schema1[noofimport].record1[iter].data1[iterdata].string, "NA");
			}
			else if (!strcmp(fields[record][iterdata].datatype, "str"))
			{
				schema1[noofimport].record1[iter].data1[iterdata].string = (char *)malloc(sizeof(char) * 50);
				copystr(schema1[noofimport].record1[iter].data1[iterdata].string, str, &stringiter);
				stringiter++; schema1[noofimport].record1[iter].data1[iterdata].integer = -1;
			}
			else if (!strcmp(fields[record][iterdata].datatype, "float"))
			{
				schema1[noofimport].record1[iter].data1[iterdata].floatval = strtofloat(str, &stringiter);
				stringiter++;
				schema1[noofimport].record1[iter].data1[iterdata].string = (char *)malloc(sizeof(char) * 50);
				strcpy(schema1[noofimport].record1[iter].data1[iterdata].string, "NA");
				stringiter++; schema1[noofimport].record1[iter].data1[iterdata].integer = -1;
			}
			iterdata++;
		}
		iter++;
	}
	schema1[noofimport].record1[iter].data1 = NULL;
	fclose(fp2);
}

void calculatefilename(char *str, char *filename)
{
	int iter = 0,iter1=0;
	while (str[iter] != ' '){ iter++; }
	while (str[iter] == ' '){ iter++; }
	while (str[iter] != ' '){ iter++; }
	while (str[iter] == ' '){ iter++; }
	while (str[iter] != '\0'){ filename[iter1++] = str[iter++]; }
	filename[iter1] = '\0';
}




void calculaterecordvalues(char *query, int nameslength, int *join1row, int *join2row,int *join1value,int *join2value,int *count1,int *count2)
{
	char *name = (char *)malloc(sizeof(char) * 10);
	int i = 0;
	while (query[i] != ' '){ i++; }
	while (query[i] == ' '){ i++; }
	int iter = 0;
	while (query[i] != ' ')
	{
		name[iter++] = query[i]; i++;
	}
	name[iter] = '\0'; iter = 0;
	while (iter < nameslength)
	{
		if (!strcmp(name, names[iter].name))
		{
			*join1row = iter;
			*join1value = names[iter].noofimport;
			*count1 = names[iter].coloumns;
			break;
		}
		iter++;
	}
	while (query[i] == ' '){ i++; }
	iter = 0;
	while (query[i] != ' ')
	{
		name[iter++] = query[i]; i++;
	}
	name[iter] = '\0'; iter = 0;
	while (iter < nameslength)
	{
		if (!strcmp(name, names[iter].name))
		{
			*join2row = iter;
			*join2value = names[iter].noofimport;
			*count2 = names[iter].coloumns;
			break;
		}
		iter++;
	}
}



void evalcolumn(int *colsarr, int join1row, int join2row,int cols1,int cols2)
{
	int i = 0,j=0;
	while (i < cols2)
	{
		j = 0;
		while (j < cols1)
		{
			if (!strcmp(fields[join2row][i].column, fields[join1row][j].column))
			{
				colsarr[i] = 1; break;
			}
			j++;
		}
		i++;
	}
}




int  creationofschemajoin(int join1row, int join2row, int *colsarr, int cols1, int cols2,int nameslength)
{
	int i = 0, j=0;
	while (i < cols1)
	{
		fields[nameslength][i].column = (char *)malloc(sizeof(char) * 30);
		fields[nameslength][i].datatype = (char *)malloc(sizeof(char) * 30);
		strcpy(fields[nameslength][i].column, fields[join1row][i].column);
		strcpy(fields[nameslength][i].datatype, fields[join1row][i].datatype);
		i++;
	}
	while (j < cols2)
	{
		if (colsarr[j] == 0)
		{
			fields[nameslength][i].column = (char *)malloc(sizeof(char) * 30);
			fields[nameslength][i].datatype = (char *)malloc(sizeof(char) * 30);
			strcpy(fields[nameslength][i].column, fields[join2row][j].column);
			strcpy(fields[nameslength][i].datatype, fields[join2row][j].datatype);
			i++;
		}
		j++;
	}
	return i;
}


/*
	The join is done by taking first field as primary .
	ex:the only with same rollno is join in the same row.if not present then it is empty.
*/



void joincalculation(int join1row, int join2row, int join1value, int join2value,int noofimport,int cols1,int cols2,int nameslength)
{
	schema1[noofimport].record1 = (struct record *)calloc(sizeof(struct record) , 500);
	int *colsarr = (int *)calloc(sizeof(int),cols2);
	evalcolumn(colsarr, join1row, join2row,cols1,cols2);
	names[nameslength].coloumns=creationofschemajoin(join1row, join2row, colsarr,cols1,cols2,nameslength);
	int iter = 0;
	while (1)
	{
		schema1[noofimport].record1[iter].data1 = (struct data *)malloc(sizeof(struct data) * 20);
		int iterdata = 0;
		while (1)
		{
			schema1[noofimport].record1[iter].data1[iterdata].integer = schema1[join1value].record1[iter].data1[iterdata].integer;
			schema1[noofimport].record1[iter].data1[iterdata].floatval = schema1[join1value].record1[iter].data1[iterdata].floatval;
			schema1[noofimport].record1[iter].data1[iterdata].string = (char *)malloc(sizeof(char) * 30);
			strcpy(schema1[noofimport].record1[iter].data1[iterdata].string, schema1[join1value].record1[iter].data1[iterdata].string);
			iterdata++;
			if (iterdata == cols1){ break; }
		}
		int i = 0, iter1 = 0; 
		while (schema1[join2value].record1[iter1].data1 != NULL)
		{
			i = 0;
			if (schema1[join1value].record1[iter].data1[0].integer == schema1[join2value].record1[iter1].data1[0].integer)
			{
				while (i < cols2)
				{
					if (colsarr[i] == 0)
					{
						schema1[noofimport].record1[iter].data1[iterdata].integer = schema1[join2value].record1[iter1].data1[i].integer;
						schema1[noofimport].record1[iter].data1[iterdata].floatval = schema1[join2value].record1[iter1].data1[i].floatval;
						schema1[noofimport].record1[iter].data1[iterdata].string = (char *)malloc(sizeof(char) * 30);
						strcpy(schema1[noofimport].record1[iter].data1[iterdata].string, schema1[join2value].record1[iter1].data1[i].string);
						iterdata++;
					}
					i++;
				}
				break;
			}
			iter1++;
		}
		iter++;
		if (schema1[join1value].record1[iter].data1 == NULL ){ break; }//|| schema1[join2value].record1[iter].data1 == NULL
	}
	
}




void calculateselectrequires(int *fieldid, int *noofimport, int *columnscount,char *options,int nameslength)
{
	int iter = 0,iter2=0; char *table = (char *)malloc(sizeof(char) * 20);
	while (options[iter] != '\0')
	{
		if (options[iter-3]=='f' && options[iter-2]=='r' && options[iter-1]=='o' && options[iter]=='m')
		{
			break;
		}
		iter++;
	}
	iter++;
	while (options[iter] == ' '){ iter++; }
	while (options[iter] != ';'&&options[iter] != ' ')
	{
		table[iter2] = options[iter]; iter++; iter2++;
	}
	table[iter2] = '\0'; iter = 0;
	while (iter<nameslength)
	{
		if (!strcmp(names[iter].name, table))
		{
			*fieldid = iter; *noofimport = names[iter].noofimport;
			*columnscount = names[iter].coloumns;
			break;
		}
		iter++;
	}
}




void makeallcolumnsselect(int *requiredcolumns,int columnscount)
{
	int iter = 0;
	while (iter < columnscount){ requiredcolumns[iter] = 1; iter++; }
}


void makesomecolumnsselect(int *requiredcolumns, int columnscount, char *col, int fieldid)
{
	int i = 0;
	while (i < columnscount)
	{
		if (!strcmp(fields[fieldid][i].column, col))
		{
			requiredcolumns[i] = 1; break;
		}
		i++;
	}
}



int requestcolumnid(char *col, int columnscount, int fieldid,char *datatype)
{
	int iter = 0;
	while (iter < columnscount)
	{
		if (!strcmp(fields[fieldid][iter].column, col))
		{
			strcpy(datatype, fields[fieldid][iter].datatype);
			return iter;
		}
		iter++;
	}
	return -1;
}



/*
	select command is done with both * and other operations.
*/



int calculationquery(int *requiredcolumns, int columnscount, char *operation, char *value, int fieldid,char *options,char *datatype)
{
	int stringiter = 0; int operablecolumn=-1;
	char *col = (char *)malloc(sizeof(char) * 20); int iter = 0;
	while (options[stringiter] != ' '){ stringiter++; }
	while (options[stringiter] == ' '){ stringiter++; }
	if (options[stringiter] == '*')
	{
		makeallcolumnsselect(requiredcolumns,columnscount);

	}
	else
	{
		while (options[stringiter] != '\0')
		{
			iter = 0;
			while (options[stringiter] != ' ')
			{
				col[iter] = options[stringiter]; iter++; stringiter++;
			}
			col[iter] = '\0';
			makesomecolumnsselect(requiredcolumns, columnscount, col,fieldid);
			while (options[stringiter] == ' '){ stringiter++; }
			if (options[stringiter] == 'f'&&options[stringiter + 1] == 'r'&&options[stringiter + 2] == 'o'&&options[stringiter + 3] == 'm')
			{
				break;
			}
		}
	}
	while (options[stringiter] != ';'&&options[stringiter]!='\0')
	{
		if (options[stringiter] == 'w'&&options[stringiter + 1] == 'h'&&options[stringiter + 2] == 'e'&&options[stringiter + 3] == 'r'&&options[stringiter + 4] == 'e')
		{
			stringiter = stringiter + 5; int iter = 0;
			while (options[stringiter] == ' '){ stringiter++; }
			while (options[stringiter] != ' ')
			{
				col[iter] = options[stringiter]; iter++; stringiter++;
			}
			col[iter] = '\0'; operablecolumn = -2;
			operablecolumn=requestcolumnid(col,columnscount,fieldid,datatype);
			while (options[stringiter] == ' '){ stringiter++; }
			 iter = 0;
			 while (options[stringiter] != ' ')
			 {
				 operation[iter] = options[stringiter]; iter++; stringiter++;
			 }
			 operation[iter] = '\0';
			 while (options[stringiter] == ' '){ stringiter++; }
			 iter = 0;
			 while (options[stringiter] != ' '&&options[stringiter] != ';')
			 {
				 value[iter] = options[stringiter]; iter++; stringiter++;
			 }
			 value[iter] = '\0';
				
		}
		stringiter++;
	}
	return operablecolumn;
}



/*
	the print process for the select query is done here.
*/



void printquery(int noofimport, int *requiredcolumns, int columncount, char *operation, char *value,int operablecolumn,char *datatype)
{
	int recorditer = 0,k = 1;
	while (1)
	{
		if (operablecolumn != -1)
		{
			if (schema1[noofimport].record1[recorditer].data1[operablecolumn].integer > 0 || schema1[noofimport].record1[recorditer].data1[operablecolumn].integer == -1)
			{
				k = calculateprintrecords(noofimport, operation, value, operablecolumn, recorditer,datatype);
			}
			else{ k = 0; }
		}
		if (k == 1)
		{
			int iter = 0;
			while (iter < columncount)
			{
				if (requiredcolumns[iter] == 1)
				{
					if (schema1[noofimport].record1[recorditer].data1[iter].integer > 0 || schema1[noofimport].record1[recorditer].data1[iter].integer == -1)
					{
						if (schema1[noofimport].record1[recorditer].data1[iter].integer > 0)
						{
							printf("%d\t", schema1[noofimport].record1[recorditer].data1[iter].integer);
						}
						else if (schema1[noofimport].record1[recorditer].data1[iter].floatval > 0)
						{
							printf("%f\t", schema1[noofimport].record1[recorditer].data1[iter].floatval);
						}
						else
						{
							printf("%s\t", schema1[noofimport].record1[recorditer].data1[iter].string);
						}
					}
				}
				iter++;
			}
			printf("\n");
		}
		recorditer++;
		if (schema1[noofimport].record1[recorditer].data1 == NULL){ break; }
	}
}




int calculatetable_filename(char *options, char *filename,int nameslength,int *noofimport,int *columns)
{
	int iter = 0;
	char *table = (char *)malloc(sizeof(char) * 20);
	while (options[iter] != ' '){ iter++; }
	while (options[iter] == ' '){ iter++; }
	int iter1 = 0;
	while (options[iter] != ' ')
	{
		table[iter1] = options[iter]; iter1++; iter++;
	}table[iter1] = '\0';
	while (options[iter] == ' '){ iter++; }
	iter1 = 0;
	while (options[iter] != '\0')
	{
		filename[iter1] = options[iter]; iter1++; iter++;
	}filename[iter1] = '\0';
	iter = 0;
	while (iter < nameslength)
	{
		if (!strcmp(names[iter].name, table))
		{
			*columns = names[iter].coloumns;
			*noofimport = names[iter].noofimport;
			break;
		}
		iter++;
	}

	return iter;
}


/*
	flush operation is done here by giving filename the all the data in the table is pushed into the given file.
*/



void flush_to_file(char *filename, int noofimport, int columns)
{
	FILE *fp;
	fp = fopen(filename, "w");
	int recorditer = 0;
	while (1)
	{
		int iter = 0;
		while (iter < columns)
		{
			if (schema1[noofimport].record1[recorditer].data1[iter].integer > 0 || schema1[noofimport].record1[recorditer].data1[iter].integer == -1)
			{
				if (schema1[noofimport].record1[recorditer].data1[iter].integer > 0)
				{
					fprintf(fp, "%d\t", schema1[noofimport].record1[recorditer].data1[iter].integer);
				}
				else
				{
					fprintf(fp, "%s\t", schema1[noofimport].record1[recorditer].data1[iter].string);
				}
			}
			iter++;
		}
		fprintf(fp,"\n");
		recorditer++;
		if (schema1[noofimport].record1[recorditer].data1 == NULL){ break; }
	}
	fclose(fp);
}


