/*
There are two friends Hack and Code . They have decided to go on a world tour which consists of only Islands.
There are a total of 26 Islands in the world ,where Each Island has a name from A ,B ,C ,D ... till Z .
[Each Island name is restricted to only 1 Letter]

Hack and Code seperately made their travel lists ,where they specify List of Islands they want to visit
in a particular order .
Ex : If Hack's List is "CADBZ" , He wants to go first to C island ,next A island and B and so on ,and finally
reach Z island .

Now Hack and Code had shared their lists , and they observed that their lists are not at all similar .
No one wants to compromise on their Travel List and Order,and each wants other person to accept their List .
After a through discussion,They finally decided that they will Find the Common route in the List which covers
Maxium Islands and make that their Tour .

Cost of Visting each Island will be equal to the position in the Alphabats Series that Island Name is( Letter ) .
Cost of Visiting A island is 1 ,H is 8 , Z is 26 and so on .
Can you help Hack and Code to find the Common Route ,so that their dispute is solved .

Inputs :
Two Strings of Capital Letters ,where each Letter denotes an Island .They can visit each Island any
number of times.
Output :
Return a Common Route String which covers maxiumum Islands

Example 1 :
Input : HackList="CADBZAYZY" CodeList="BZAYACAFRDBZ"
Output: Return "BZAY" and modify the Cost variable to  54 [2+26+1+25]
Explanation :
They both can start at B ,Go to Z ,and go to A,Finally reach Y .This Route covers 4 islands ,where
all other routes like CA ,DBZ , ZAY ,etc covers less than 4 islands .

Note : If there are Two Maximum routes which cover Equal number of Islands , Return the Route which Costs
less . IF the Costs are also equal ,Return the Route ,whose FirstIsland is Alphabetically Before
[Assume two routes with same cost ,will always have first island a different one].

Final Route Islands should be in Both Hack and Codes list and in same order ,If Final route is ACB
There must be a route in both Lists which is ACB . [AZZCB , ADCDB dont qualify ,Order should be continous]
Return NULL for Invalid Inputs or No Common Route[Cost will be 0].

Example 2 : Input : "CABTYUZZZ" , "ZZZTYUCAB" , Output : "CAB" and cost should be 6 (Least Cost )
Example 3 : Input : "HHHZAADTD" , "ZAAHHHDTDRR" , Output : "DTD" (DTD , HHH ,ZAA has same cost of 28 ,but the
First Island in DTD ie 'D' occurs alphabatically before 'H' and 'Z')

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include<string.h>
char * find_common_route(char * hacklist, char *codelist, int *cost){
	int i, j, k1 = 0, k, k2, sum = 0, l1, l2, p1, k4 = 0, p2 = 0;
	char *str; char *str1; char *str2="";
	if (hacklist == NULL || codelist == NULL)
	{
		return NULL;
		*cost = 0;
	}
	else
	{
		l1 = strlen(hacklist);
		l2 = strlen(codelist);
		i = 0, j = 0; p2 = 0; k = 0;
		while (i < l1-k1+2)
		{
			p2 = i; j = 0; k = 0;
			while (j < l2-k1+2)
			{
				if (hacklist[p2] == codelist[j]&&p2<l1)
				{
					k++;
					p2++;
				}
				else
				{
					if (k1 < k)
					{
						k1 = k;
					}
					k = 0;
					p2 = i;
				}
				j++;
			}
			if (k1 < k)
			{
				k1 = k;
			}
			i++;
		}
		str = (char *)malloc(sizeof(char *)*k1);
		
		str1 = (char *)malloc(sizeof(char *)*l1);
		if (k1 == 0)
		{
			*cost = 0;
			return NULL;
		}
		else if (k1==l1||k1==l2)
		{
			sum = 0; i = 0;
			if (k1 == l1)
			{
				while (hacklist[i] != '\0')
				{
					sum = sum + (hacklist[i] - 64);
					i++;
				}
				*cost = sum;
				return hacklist;
			}
			else
			{
				sum = 0; i = 0;
				while (codelist[i] != '\0')
				{
					sum = sum + (codelist[i] - 64);
					i++;
				}
				*cost = sum;
				return codelist;
			}
		}
		else
		{
			i = 0; p1 = 0;
			while (i < l1-k1+1)
			{
				k2 = i; k4 = 0;
				while (k2 < i + k1)
				{
					str[k4] = hacklist[k2];
					k4++;
					k2++;
				}
				str[k4] = '\0';
				j = 0;
				str2 = strstr(codelist, str);
				if (str2!=NULL)
				{
					while (j<k1)
					{
						str1[p1] = str[j];
						j++;
						p1++;
					}
				}
				i++;
			}
			str1[p1] = '\0';
			i = k1 - 1; k2 = 0; k2 = str1[0]; p2 = 0;
			while (i < p1-1&&k1>0)
			{
				if (k2 > str1[i])
				{
					k2 = str1[i];
					p2 = i;
				}
				i=i+k1;
			}
			i = p2; j = 0; sum = 0;
			while (j < k1&&k1>0)
			{
				str[j] = str1[i];
				sum = sum + (str[j] - 64);
				j++;
				i++;
			}
			*cost = sum;
			return str;
		}
	}
}