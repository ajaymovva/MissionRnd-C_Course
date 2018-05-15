#define _CRT_SECURE_NO_WARNINGS
/*
	Thanks for dynamic structure to understand many concepts  of strctures and memory visualization in storage and use of 
	memory in as requirement as possible.
				{""""The implementation way and main idea is present in header file structures.h"""""}
*/


/*
	In this project the dynamic strucute is implemented for the following operations:
	->CREATE{"It create the structure or a table as per your wish by giving data types and columns"}
	->IMPORT{"by import the file name the data in the file is copy to table which is created by the create option"
	->SELECT{ we can select the requested options by select command as dbms with * and where options and also respected columns 
					and data is displayed on the console}
	->JOIN{ to join two tables then this commnad is used.This command is worked by placing first column as primary key.}
	->FLUSH{flush command is used to push certain table to file which is given by the command it self.}

	Syntax for the above commands as follows:
		CREATE:
				create table <tablename>
				<columnname1>:<datatype>;<columnname2>:<datatype>;------<columnnamex>:<datatype>
				here column names as you like and as per as file given in the import statement.
				datatypes are "int"  and "str"and "float" these are only handled here in program.so do not use these with other names.
		IMPORT:
				import <tablename> <filename>
				file data is loaded into table as form of creation.so be sure run create before import.
		SELECT:
				select <colunm names1><space><columnname2>--or * from<space> <table name><space>
				where<space><columnname><space><operation><space><value><;>
				<;>it compulsory to run select.
				if do not want where then place <;>after table name.
		JOIN:
				join<space>tablename1<space>tablename2<space>as<new table>
				Here new table is formed by by joining two  tables the join operation is done based on the 
				first columns if there is not availability of row  then it makes as empty the remaining part.only having values are joined.
			VVVV-IMP	{There are many joins are possible I consider the left join.}
		FLUSH:
				flush<space><tablename><space><filename>
		operations:
					(<)&&(<=)&&(>)&&(>=)&&(=)for int and float data types
					"contains" && "matches" for str data types.

*/
#include "operations.h"
int main()
{
	fields = (struct attribute **)malloc(sizeof(struct attribute *)*20);
	for (int iter = 0; iter < 10; iter++)
	{
		fields[iter] = (struct attribute *)malloc(sizeof(struct attribute) * 20);
	}
	names = (struct schemas *)malloc(sizeof(struct schemas) * 20);
	schema1 = (struct schema *)malloc(sizeof(struct schema) * 20);
	printf("Please go to comments to do operations efficienty\n");
	printf("	create table <tablename>\n\t<columnname1>:<datatype>; <columnname2>:<datatype>; ------<columnnamex>:<datatype>\n");
	printf("	import <tablename> <filename>\n");
	printf("	select <col1> <col2>--or * from <table name> where <colname> <operation> <value><; >\n");
	printf("	operations are <,>,<=,>=,=,matches,contains\n");
	printf("	join table1 table2 as newtablename\n");
	printf("	flush tablename filename\n\n\n\n");
	All_working_process();
	system("pause");
	return 0;
}