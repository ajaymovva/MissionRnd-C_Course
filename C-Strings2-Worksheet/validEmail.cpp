/*

In a college, there is a data centre where all the communications go on.
Like mails about Holidays, Schedules, Notices etc information.
The clerk at data centre used to ask students of every new batch to create new emails and submit through forms.
The clerk must know the name of the student by seeing the email.

But the students are mischevious. Their emails are unidentifiable.
For example: A student Manoj gave his email as iamironman123@gmail.com, Sunil as rockrocky143@gmail.co.in

The clerk is unable to find the name of the student just by seeing the email address.
So, he added a rule that email must contain the student name as prefix or suffix to email address

Example: Manoj has to create his email as "manojsomething@something.com" or "somethingmanoj@something.com"

Note: "abcmanojabc@live.com is invalid email address Since "manoj" is neither a prefix nor a suffix.

Help the clerk to check the following:

(1). Given email is Valid or not
ex: "manoj@gmail" is not a valid email address

(2). Given email satisfies the suffix/prefix condition
ex: student name: abc, email: "ab@c.com" is not valid
because even though it is valid email email address, it is not satisfying the clerk's new rule.


Given input is in the form of "name email" space seperated Name and email.
Return 1 if email condition (1) is only satisfied. Return 2 if both (1) and (2) are satisfied. Return 0 for all other cases
ex: INPUT: "Manoj iammanoj@gmail.com"
OUTPUT: 2

INPUT: "abc abc.com"
OUTPUT: 0


NOTE: (1) Do not use any string.h functions.
(2) Rules of a valid email address
a. should use only alphanumeric characters. That is, use only “a” through “z” and “0 (zero)” through “9”.
b. Use of the following characters: < > ( ) [ ] ; : , @ \ <space> is not allowed
c. As long as they are not the first character in the e-mail address, hyphens ( – ), underscores ( _ ), periods ( . ),
and numeric characters (“0” through “9”) are acceptable characters to use within the address.
d. Do not use null characters (spaces) between characters. However, as mentioned above, underscores are acceptable.
e. Email length must be less than or equal to 254 characters.
(3) MANoJ ,MaNoj all are same and to be treated as manoj in the name field
(4) Delimiter b/w name and email can be single or multiple spaces
(5) Input is in read only mode. you cannot edit it.
*/

#include <stdio.h>
#include <stdlib.h>


int isValidEmail(char *email)
{
	// variable email is in form of "name something@domain.server"
	int i = 0,j=0,k1,k2,k,k3,k4,j1,p1,p,k5;
	char *str;
	while (email[i] != '\0')
	{
		i++;
	}
	str = (char *)malloc(sizeof(char)*i);
	if (i > 254 || email == NULL||i==0)
	{
		return 0;
	}
	else
	{
		k1 = 0, k2 = 0, k = 0,k4=0;
		while (j < i)
		{
			if (email[j] == '<' || email[j] == '>' || email[j] == '[' || email[j] == ']' || email[j] == '(' || email[j] == ')' || email[j] == ':' || email[j] == ';' || email[j] == ',')
			{
				k = 1;
			}
			else if (email[j] == '@')
			{
				k3 = j;
				k1++;
			}
			else if (email[j] == ' ')
			{
				k2++;
			}
			else if (email[j] == '.')
			{
				k4 = 1;
			}
			j++;
		}
		if (k == 1 || k1 > 1||k1==0||k4==0)
		{
			return 0;
		}
		else
		{
			
			k = 0;
			while (email[k] != ' ')
			{
				str[k] = email[k];
				k++;
			}
			str[k] = '\0';
			k1 = k;
			while (email[k] == ' ')
			{
				k++;
			}
			p = k;
			p1 = k3;
			while (p < p1)
			{
				if (email[p] == ' ')
				{
					break;
				}
				p++;
			}
			if (email[k] == '_'||email[k]=='-'||email[k]=='.'||p<p1)
			{
				return 0;
			}
			else
			{
				k2 = k;
				while (k2 < i)
				{
					if (email[k2] == '.')
					{
						k4 = k2;
						break;
					}
					k2++;
				}
				if (k4 - k3 < 1 || k4 >=i - 1)
				{
					return 0;
				}
				else
				{
					j = k; j1 = 0; p1 = 0,k2=0;
					if (k + k1 > k3)
					{
						return 1;
					}
					else{
						while (j < k + k1)
						{
							p = email[j];
							p1 = str[j1];
							if (p >= 65 && p <= 90)
							{
								if (p1 != p + 32 && p1 != p)
								{
									k2 = 1;
									break;
								}
							}
							else if (p >= 97 && p <= 122)
							{
								if (p1 != p&&p1 != p - 32)
								{
									k2 = 1;
									break;
								}
							}
							j++;
							j1++;
						}
						j1 = 0; j = k3 - k1; p = 0; p1 = 0; k5 = 0;
						while (j < k3)
						{
							p = email[j];
							p1 = str[j1];
							if (p >= 65 && p <= 90)
							{
								if (p1 != p + 32 && p1 != p)
								{
									k5 = 1;
									break;
								}
							}
							else if (p >= 97 && p <= 122)
							{
								if (p1 != p&&p1 != p - 32)
								{
									k5 = 1;
									break;
								}
							}
							j++;
							j1++;
						}
						if (k2 == 0 || k5 == 0)
						{
							return 2;
						}
						else
						{
							return 1;
						}
					}
				}
			}
		}
	}
}