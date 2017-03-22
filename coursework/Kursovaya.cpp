#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct MusicalComposition {
	char name[80];
	char author[80];
	int year;
	struct MusicalComposition *next;
	struct MusicalComposition *prev;
} MusicalComposition;

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n);

MusicalComposition* createMusicalComposition(char* name, char* author, int year);

void push(MusicalComposition* head, MusicalComposition* element);

void removeEl(MusicalComposition* head, char* name_for_remove);

int count(MusicalComposition* head);

void print_names(MusicalComposition* head);

void removeElnechetniy(MusicalComposition* head);

int main() {
	int length;
	scanf("%d\n", &length);

	char** names = (char**)malloc(sizeof(char*)*length);
	char** authors = (char**)malloc(sizeof(char*)*length);
	int* years = (int*)malloc(sizeof(int)*length);

	for (int i = 0;i<length;i++)
	{
		char name[80];
		char author[80];

		fgets(name, 80, stdin);
		fgets(author, 80, stdin);
		fscanf(stdin, "%d\n", &years[i]);

		(*strstr(name, "\n")) = 0;
		(*strstr(author, "\n")) = 0;

		names[i] = (char*)malloc(sizeof(char*) * (strlen(name) + 1));
		authors[i] = (char*)malloc(sizeof(char*) * (strlen(author) + 1));

		strcpy(names[i], name);
		strcpy(authors[i], author);


	}
	MusicalComposition* head = createMusicalCompositionList(names, authors, years, length);
	char name_for_push[80];
	char author_for_push[80];
	int year_for_push;

	char name_for_remove[80];

	fgets(name_for_push, 80, stdin);
	fgets(author_for_push, 80, stdin);
	fscanf(stdin, "%d\n", &year_for_push);
	(*strstr(name_for_push, "\n")) = 0;
	(*strstr(author_for_push, "\n")) = 0;

	MusicalComposition* element_for_push = createMusicalComposition(name_for_push, author_for_push, year_for_push);

	fgets(name_for_remove, 80, stdin);
	(*strstr(name_for_remove, "\n")) = 0;

	printf("%s %s %d\n", head->name, head->author, head->year);
	int k = count(head);

	printf("%d\n", k);
	push(head, element_for_push);

	k = count(head);
	printf("%d\n", k);

	removeEl(head, name_for_remove);
	print_names(head);

	k = count(head);
	printf("%d\n", k);
	removeElnechetniy(head);
	print_names(head);
	k = count(head);
	printf("%d\n", k);
	printf("Press any key to exit...");
	while (head->next)
	{
		MusicalComposition* buf = head;
		head = head->next;
		free(buf);
	}
	return 0;
}

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
	MusicalComposition *head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
	MusicalComposition *prev = head;
	MusicalComposition *tmp;
	int i;
	for (i = 1; i < n; i++)
	{
		tmp = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
		tmp->prev = prev;
		prev->next = tmp;
		prev = tmp;
	}
	return head;
}
MusicalComposition* createMusicalComposition(char* name, char* author, int year)
{
	MusicalComposition* track = (MusicalComposition*)malloc(sizeof(MusicalComposition));
	strcpy(track->name, name);
	strcpy(track->author, author);
	track->year = year;
	track->next = NULL;
	track->prev = NULL;
	return track;
}

void push(MusicalComposition* head, MusicalComposition* element)
{
	MusicalComposition *tmp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
	tmp = head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = element;
	element->prev = tmp;
}

void removeEl(MusicalComposition* head, char* name_for_remove)
{
	MusicalComposition* buf = head;
	while (head != NULL)
	{
		if (strcmp(head->name, name_for_remove) == 0)
		{
			if (head->prev == NULL)
			{
				*head = *head->next;
				head->prev = NULL;
				buf = head;
			}
			else if (head->next == NULL)
			{
				head->prev->next = NULL;
				buf = head;
			}
			else
			{
				head->prev->next = head->next;
				head->next->prev = head->prev;
				buf = head;
			}
			free(buf);
		}
		head = head->next;
	}
}

int count(MusicalComposition* head)
{
	MusicalComposition *tmp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
	tmp = head;
	int counter = 1;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		counter++;
	}
	return counter;
}

void print_names(MusicalComposition * head)
{
	MusicalComposition *tmp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
	tmp = head;
	while (tmp->next != NULL)
	{
		printf("%s\n", tmp->name);
		tmp = tmp->next;
	}
	printf("%s\n", tmp->name);
}

void removeElnechetniy(MusicalComposition* head)
{
	MusicalComposition *tmp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
	tmp = head;
	int counter = 0;
	tmp = tmp->next;
	tmp->prev = NULL;
	*head = *tmp;
	while (tmp != NULL)
	{
		if (counter % 2 != 0)
		{
			if (tmp->next == NULL)
			{
				tmp = tmp->prev;
				tmp->next = NULL;
			}
			else
			{
				tmp->next->prev = tmp->prev;
				tmp->prev->next = tmp->next;
			}
		}
		tmp = tmp->next;
		counter++;
	}
	*head->next = *head->next->next;
}
