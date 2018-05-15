/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
#include<string.h>
int isOlder(char *dob1, char *dob2) {
	int l1, l2, i, j, k = 0, z = 0,x,y,x1,y1;
	l1 = strlen(dob1);
	l2 = strlen(dob2);
	x = dob1[l1 - 1], y = dob1[l1 - 2];
	x = x - 48; y = y - 48;
	x = (10 * y )+ x;
	if (l1 != 10 || l2 != 10)
	{
		z = 1;
		return -1;
	}
	else if (dob1[3] == 49 && dob1[4] > 50)
	{
		return -1;
	}
	else if ((x % 4 != 0) && (dob1[0] == '2'&&dob1[1] == '9'&&dob1[3] == '0'&&dob1[4] == '2'))
	{
		return -1;
	}
	else
	{
		for (i = 0; i <= 9; i++)
		{
			if (i != 2 && i != 5)
			{
				x = dob1[i];
				y = dob2[i];
				//printf("%d,%d", x, y);
				if (x > 57 || x < 48 || y>57 || y < 48)
				{
					z = 1;
				}
			}

		}
	/*	if ((dob1[3] == 49 && dob1[4] > 50) || (dob2[3] == 49 && dob2[4]>50))
		{
			z = 1;
		}*/
		if (z == 1)
			return -1;
		else
		{
			i = 6;
			j = 9;
			while (i <= j)
			{
				if (dob1[i] > dob2[i])
				{
					k = 2;
					break;
				}
				else if (dob1[i] < dob2[i])
				{
					k = 1;
					break;
				}
				i++;
			}
			if (k != 0)
			{
				return k;
			}
			else
			{
				i = 3;
				j = 4;
				while (i <= j)
				{
					if (dob1[i] > dob2[i])
					{
						k = 2;
						break;
					}
					else if (dob1[i] < dob2[i])
					{
						k = 1;
						break;
					}
					i++;
				}
				if (k != 0)
				{
					return k;
				}
				else
				{
					i = 0;
					j = 1;
					while (i <= j)
					{
						if (dob1[i] > dob2[i])
						{
							k = 2;
							break;
						}
						else if (dob1[i] < dob2[i])
						{
							k = 1;
							break;
						}
						i++;
					}
					return k;

				}
			}
		}
		
	}

}