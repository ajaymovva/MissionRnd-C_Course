#include "working.h"
void All_working_process()
{

	char *options = (char *)malloc(sizeof(char) * 100);
	char *filename = (char *)malloc(sizeof(char) * 50);
	int nameslength = 0;
	int attrbuteslength = 0; int nooffields = 0; int noofimport = 0;
	while (1)
	{
		printf("   [enter] [create] [import] [join must use as in between table2 and final table] [select] [flush] [exit]\n");
		gets(options);
		if (options[0] == 'c'&&options[1] == 'r'&&options[2] == 'e'&&options[3] == 'a'&&options[4] == 't'&&options[5] == 'e')
		{
			nooffields = createschema(nameslength);
			createname(options, &nameslength, nooffields);
			nameslength++;
		}
		else if (options[0] == 'i'&&options[1] == 'm'&&options[2] == 'p'&&options[3] == 'o'&&options[4] == 'r'&&options[5] == 't')
		{
			int row1 = 0;
			int noofimport1 = twiceimport(options, nameslength, &row1);
			if (noofimport1 == -1)
			{
				int row = calculaterecord(options, nameslength, noofimport);
				if (row == -1)
				{
					printf("enter valid tablename");
				}
				else
				{
					calculatefilename(options, filename);
					import_operation(row, noofimport, filename);
					noofimport++;
				}
				printf("import done\n");
			}
			else
			{
				if (row1 == -1)
				{
					printf("enter valid tablename");
				}
				else
				{
					calculatefilename(options, filename);
					import_forsamerowtwice(row1, noofimport1, filename);
				}
				printf("import for sam table done");
			}
		}
		else if (options[0] == 'j'&&options[1] == 'o'&&options[2] == 'i'&&options[3] == 'n')
		{
			joincreatename(options, &nameslength, noofimport);
			nameslength++;
			int join1row = -1, join2row = -1, join1value = 0, join2value = 0, cols1 = 0, cols2 = 0;
			calculaterecordvalues(options, nameslength, &join1row, &join2row, &join1value, &join2value, &cols1, &cols2);
			if (join1row == -1 || join2row == -1)
			{
				printf("respected tables not found");
			}
			else
			{
				joincalculation(join1row, join2row, join1value, join2value, noofimport, cols1, cols2, nameslength - 1);
				noofimport++;
				printf("joindone");
			}
		}
		else if (options[0] == 's'&&options[1] == 'e'&&options[2] == 'l'&&options[3] == 'e'&&options[4] == 'c'&&options[5] == 't')
		{
			char *operation = (char *)malloc(sizeof(char *) * 10);
			char *value = (char *)malloc(sizeof(char) * 20);
			int fieldid = 0, noofimport = 0, columnscount = 0;
			calculateselectrequires(&fieldid, &noofimport, &columnscount, options, nameslength);
			int *requiredcolumns = (int *)calloc(sizeof(int), columnscount);
			char *datatype = (char *)malloc(sizeof(char) * 20);
			int operablecolumn = calculationquery(requiredcolumns, columnscount, operation, value, fieldid, options, datatype);
			if (operablecolumn == -1 || operablecolumn >= 0)
			{
				printquery(noofimport, requiredcolumns, columnscount, operation, value, operablecolumn, datatype);
			}
		}
		else if (options[0] == 'f'&&options[1] == 'l'&&options[2] == 'u'&&options[3] == 's'&&options[4] == 'h')
		{
			char *filename = (char *)malloc(sizeof(char) * 40); int fields = 0, noofimport = 0, columns = 0;
			fields = calculatetable_filename(options, filename, nameslength, &noofimport, &columns);
			flush_to_file(filename, noofimport, columns);
		}
		else if (options[0] == 'e'&&options[1] == 'x'&&options[2] == 'i'&&options[3] == 't'){ break; }
		else
		{
			printf("enter valid option");
		}
	}
}