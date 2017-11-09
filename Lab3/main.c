#include <stdio.h>
#include <stdlib.h>

int check(char *sent);

void sentence(int *control, int *before, int *quest);

int main()
{

	int control = 0, before = 0, quest = 0;

	while (control == 0)
		sentence(&control, &before, &quest);

  printf("Количество предложений до %i и количество предложений после %i\n", before, (before - quest));

	return 0;
}

int check(char *sent_check)
{
	int j;
	char str[] = "Dragon flew away!";

	for (j = 0; j < 16; ++j)
		if (*(sent_check + j) != str[j])
			return 0;
	return 1;
}

void sentence(int *control, int *before, int *quest)
{
	char c;
	int i = 0, am = 0, size = 20;
	char *sent = (char*)malloc(size*sizeof(char));

	while (((c = getchar()) != '.') && (c != ';') && (c != '?'))
		if (((c != '\t') && (c != '\n') && (c != ' ')) || (i != 0))
		{
			sent[i] = c;
			if (i == 16)
				if (check(sent) == 1)
				{
					*control = 1;
					break;
				}
			++i;
			if (++am == (size))
				sent = realloc(sent, sizeof(char)*(++size));
		}
	if (*control == 0)
	{
		++*before;
		if ((c == ';') || (c == '.'))
			{
				sent[i++] = c;
				sent[i] = (char)0;
				printf("%s\n", sent);
			}
		else
			++*quest;
	}
}
