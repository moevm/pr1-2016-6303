#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void scan(char *sent);
int main()
{
	int i = 0;
	int before = 0;
	int after = 0;
	char* check = "Dragon flew away!";
	char* sent = (char *)malloc(10 * sizeof(char));
	while (strcmp(sent, check) != 0)
	{
		scan(sent);
		before++;
		if (*sent != '\0' && strcmp(sent, check) != 0)
		{
			printf("%s\n", sent);
			after++;
		}
	}
	printf("Количество предложений до %d и количество предложений после %d\n", before - 1, after);
	return 0;
}

void scan(char *sent)
{
	int c = 0;
	int i = 0;
	while (c != '!' && c != ';' && c != '.' && c != '?')
	{
		c = getchar();
		if (i == 0 && (c == ' ' || c == '\t' || c == '\n')) continue;
		else
		{
			sent[i] = c;
			++i;
			if (i > 10)
			{
				sent = (char *)realloc(sent, 100 * sizeof(char));
			}
		}
	}
	if (sent[i - 1] == '?')
	{
		*sent = '\0';
	}
	else
	{
		sent[i] = '\0';
	}

	//return sent;
}