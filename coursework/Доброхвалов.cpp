#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct MusicalComposition
{
	char *name;
	char *author;
	int year;
	struct MusicalComposition *next;
	struct MusicalComposition *previous;
}MusicalComposition;
MusicalComposition *head;

MusicalComposition *createMusicalComposition(char *name, char *author, int year)
{
	MusicalComposition *composition = (MusicalComposition*)malloc(sizeof(MusicalComposition));
	composition->name = name;
	composition->author = author;
	composition->year = year;
	composition->next = NULL;
	composition->previous = NULL;
	return composition;
}

MusicalComposition *createMusicalCompositionList(char **array_names, char **array_authors, int *array_years, int n)
{
	head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
	MusicalComposition *tmp = head;
	for (int i = 1; i < n; i++)
    {
		tmp->next = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
		tmp->next->previous = tmp;
		tmp = tmp->next;
	}
	return head;
}

int Count()
{
	MusicalComposition *tmp = head;
	int counter = 0;
	while (tmp != NULL)
	{
		counter++;
		tmp = tmp->next;
	}
	return counter;
}

void push_course(MusicalComposition *element_top, MusicalComposition *element_middle, MusicalComposition *element_end)
{
	MusicalComposition *tmp = head;
	element_top->next = tmp;
	tmp->previous = element_top;
	head = element_top;
	int i = 1, n = Count();
	while (i < n / 2)
	{
		tmp = tmp->next;
		i++;
	}
	element_middle->next = tmp->next;
	element_middle->previous = tmp;
	tmp->next->previous = element_middle;
	tmp->next = element_middle;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = element_end;
	element_end->next = NULL;
	element_end->previous = tmp;
}

void removeEl(char* name_for_remove)
{
	MusicalComposition *tmp = head;
	while(tmp != NULL)
	{
		if (strcmp(tmp->name, name_for_remove) == 0)
		{
		    if ( (tmp->previous == NULL) && (tmp->next != NULL) )
            {
                tmp = tmp->next;
                tmp->previous = NULL;
                head = tmp;
            }
            else
            {
                if ( (tmp->previous != NULL) && (tmp->next == NULL) )
                {
                    tmp = tmp->previous;
                    tmp->next = NULL;
                    tmp = tmp->next;
                }
                else
                {
                    if ( (tmp->previous != NULL) && (tmp->next != NULL) )
                    {
                        tmp->next->previous = tmp->previous;
                        tmp->previous->next = tmp->next;
                        tmp = tmp->next;
                    }
                    else
                    {
                        if ( (tmp->next == NULL) && (tmp->previous == NULL) )
                        {
                            tmp = NULL;
                            head = tmp;
                        }
                    }
                }
            }
		}
		else
        {
            tmp = tmp->next;
        }
    }
}


void print_names()
{
	MusicalComposition *tmp = head;
	if (tmp == NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        while (tmp != NULL)
        {
            printf("%s\n", tmp->name);
            tmp = tmp->next;
        }
    }
}

int main()
{
	int length;
	scanf("%d\n", &length);

	char **names = (char**)malloc(sizeof(char*)*length);
	char **authors = (char**)malloc(sizeof(char*)*length);
	int *years = (int*)malloc(sizeof(int)*length);

	for (int i = 0; i < length; i++)
	{
		char name[80];
		char author[80];
		fgets(name, 80, stdin);
		fgets(author, 80, stdin);
		fscanf(stdin, "%d\n", &years[i]);
		(*strstr(name, "\n")) = 0;
		(*strstr(author, "\n")) = 0;
		names[i] = (char*)malloc(sizeof(char*)*(strlen(name) + 1));
		authors[i] = (char*)malloc(sizeof(char*)*(strlen(author) + 1));
		strcpy(names[i], name);
		strcpy(authors[i], author);
	}

	head = createMusicalCompositionList(names, authors, years, length);

	char name_for_push_top[80];
	char author_for_push_top[80];
	int year_for_push_top;
	fgets(name_for_push_top, 80, stdin);
	fgets(author_for_push_top, 80, stdin);
	fscanf(stdin, "%d\n", &year_for_push_top);
	(*strstr(name_for_push_top, "\n")) = 0;
	(*strstr(author_for_push_top, "\n")) = 0;
	MusicalComposition *element_for_push_top = createMusicalComposition(name_for_push_top, author_for_push_top, year_for_push_top);

	char name_for_push_middle[80];
	char author_for_push_middle[80];
	int year_for_push_middle;
	fgets(name_for_push_middle, 80, stdin);
	fgets(author_for_push_middle, 80, stdin);
	fscanf(stdin, "%d\n", &year_for_push_middle);
	(*strstr(name_for_push_middle, "\n")) = 0;
	(*strstr(author_for_push_middle, "\n")) = 0;
	MusicalComposition * element_for_push_middle = createMusicalComposition(name_for_push_middle, author_for_push_middle, year_for_push_middle);

	char name_for_push_end[80];
	char author_for_push_end[80];
	int year_for_push_end;
	fgets(name_for_push_end, 80, stdin);
	fgets(author_for_push_end, 80, stdin);
	fscanf(stdin, "%d\n", &year_for_push_end);
	(*strstr(name_for_push_end, "\n")) = 0;
	(*strstr(author_for_push_end, "\n")) = 0;
	MusicalComposition *element_for_push_end = createMusicalComposition(name_for_push_end, author_for_push_end, year_for_push_end);

	char name_for_remove[80];
	fgets(name_for_remove, 80, stdin);
	(*strstr(name_for_remove, "\n")) = 0;

	printf("%s %s %d\n", head->name, head->author, head->year);
	int k = Count();
	printf("%d\n", k);

    push_course(element_for_push_top, element_for_push_middle, element_for_push_end);
	k = Count();
	printf("%d\n", k);

	removeEl(name_for_remove);
	print_names();
	k = Count();
	printf("%d\n", k);

	return 0;
}
