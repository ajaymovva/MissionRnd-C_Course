/*
Problem Statement :

Check if a DOM (string format) is valid or not.
Take string as a input and validate if every opening tag end with closing tag.
valid tags are html, head, body, p.

consider the following priority for tags  [ html > head == body > p ]

Return false if you encounter a invalid tags.
For all invalid cases return -1; other wise 1

Eg: <html><head><body></body></head></html>  o/p : 1
<body><p></p></body> o/p : 1
<html><head></body></head></html> o/p: -1
<head><html></html></head> o/p: -1

In case of
- empty string return -1
- no tag return 1

NOTE : Donot use any Global Variables

Marks : 15
*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int isStringValidDom(char* input) {
	if (input == NULL)
		return -1;
	else
	{
		int i, j, l, k = 0;
		l = strlen(input);
		for (i = 0, j = l - 1; i < j; )
		{
			if (i + 5 < l - 1 && j - 6 > 0)
			{
				if (input[i] == '<'&&input[i + 1] == 'h'&&input[i + 2] == 't'&&input[i + 3] == 'm'&&input[i + 4] == 'l'&&input[i + 5] == '>')
				{
					if (input[j] != '>' || input[j - 1] != 'l' || input[j - 2] != 'm' || input[j - 3] != 't' || input[j - 4] != 'h' || input[j - 5] != '/' || input[j - 6] != '<')
					{
						k = 1; break;
					}
					i = i + 6; j = j - 7;
				}
				else if (input[i] == '<'&&input[i + 1] == 'h'&&input[i + 2] == 'e'&&input[i + 3] == 'a'&&input[i + 4] == 'd'&&input[i + 5] == '>')
				{
					if (input[j] != '>' || input[j - 1] != 'd' || input[j - 2] != 'a' || input[j - 3] != 'e' || input[j - 4] != 'h' || input[j - 5] != '/' || input[j - 6] != '<')
					{
						k = 1; break;
					}
					i = i + 6; j = j - 7;
				}
				else if (input[i] == '<'&&input[i + 1] == 'b'&&input[i + 2] == 'o'&&input[i + 3] == 'd'&&input[i + 4] == 'y'&&input[i + 5] == '>')
				{
					if (input[j] != '>' || input[j - 1] != 'y' || input[j - 2] != 'd' || input[j - 3] != 'o' || input[j - 4] != 'b' || input[j - 5] != '/' || input[j - 6] != '<')
					{
						k = 1; break;
					}
					i = i + 6; j = j - 7;
				}
			}
			if (i+2<l-1&&j-3>0)
			{
				if (input[i] == '<'&&input[i + 1] == 'p'&&input[i + 2] == '>')
				{
					if (input[j] != '>' || input[j - 1] != 'p' || input[j - 2] != '/'&&input[j - 3] != '<')
					{
						k = 1; break;
					}
					i = i + 3; j = j - 4;
				}
			}
		}
		if (k == 1){ return -1; }
		else
		{
			for (i = 0; i < l / 2;)
			{
				if (l / 2>(i + 5))
				{
					if (input[i] == '<'&&input[i + 1] == 'h'&&input[i + 2] == 'e'&&input[i + 3] == 'a'&&input[i + 4] == 'd'&&input[i + 5] == '>')
					{
						if (l / 2 > (i + 11))
						{
							if (input[i + 6] == '<'&&input[i + 7] == 'h'&&input[i + 8] == 't'&&input[i + 9] == 'm'&&input[i + 10] == 'l'&&input[i + 11] == '>')
							{
								k = 1;
								break;
							}
						}
						i = i + 6;
					}
					else if (input[i] == '<'&&input[i + 1] == 'b'&&input[i + 2] == 'o'&&input[i + 3] == 'd'&&input[i + 4] == 'y'&&input[i + 5] == '>')
					{
						if (l / 2 > (i + 11))
						{
							if (input[i + 6] == '<'&&input[i + 7] == 'h'&&input[i + 8] == 't'&&input[i + 9] == 'm'&&input[i + 10] == 'l'&&input[i + 11] == '>')
							{
								k = 1;
								break;
							}
							else if (input[i + 6] == '<'&&input[i + 7] == 'h'&&input[i + 8] == 'e'&&input[i + 9] == 'a'&&input[i + 10] == 'd'&&input[i + 11] == '>')
							{
								k = 1; break;
							}
						}
						i = i + 6;
					}
				}
				if (l / 2 > (i + 2))
				{
					if (input[i] == '<'&&input[i + 1] == 'p'&&input[i + 2] == '>')
					{
						if (l / 2 > (i + 6))
						{
							if (input[i + 3] != '<' || input[i + 4] != '/' || input[i + 5] == 'p' || input[i + 6] == '>')
							{
								k = 1; break;
							}
						}
						i = i + 3;
					}
				}
				if (k == 1){ return -1; }
				else return 1;
			}
		}
	}
}