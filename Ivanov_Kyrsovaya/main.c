#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct MusicalComposition
{
    char* name;
    char* author;
    int year;
    struct MusicalComposition *next;
    struct MusicalComposition *prev;
}MusicalComposition;

MusicalComposition* createMusicalComposition(char* name, char* author, int year);

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n);

void push(MusicalComposition* head, MusicalComposition* element);

void removeEl(MusicalComposition* head, char* name_for_remove);

int count(MusicalComposition* head);

void print_names(MusicalComposition* head);

void Sort(MusicalComposition* head);

int main(){
    int length, i;
    scanf("%d\n", &length);

    char** names = (char**)malloc(sizeof(char*)*length);
    char** authors = (char**)malloc(sizeof(char*)*length);
    int* years = (int*)malloc(sizeof(int)*length);

    for (i=0; i<length; i++)
    {
        char name[80];
        char author[80];

        fgets(name, 80, stdin);
        fgets(author, 80, stdin);
        fscanf(stdin, "%d\n", &years[i]);

        (*strstr(name,"\n"))=0;
        (*strstr(author,"\n"))=0;

        names[i] = (char*)malloc(sizeof(char*) * (strlen(name)+1));
        authors[i] = (char*)malloc(sizeof(char*) * (strlen(author)+1));

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
    (*strstr(name_for_push,"\n"))=0;
    (*strstr(author_for_push,"\n"))=0;

    MusicalComposition* element_for_push = createMusicalComposition(name_for_push, author_for_push, year_for_push);

    fgets(name_for_remove, 80, stdin);
    
	(*strstr(name_for_remove,"\n"))=0;

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

	Sort(head);
	printf("\n");
	print_names(head);

	system("pause");

	return 0;
}


MusicalComposition* createMusicalComposition(char* name, char* author, int year)
{
	MusicalComposition* ptr = (MusicalComposition*)malloc(sizeof(MusicalComposition));
	ptr->name = name;
	ptr->author = author;
	ptr->year = year;
	ptr->next = NULL;
	ptr->prev = NULL;
	return ptr;
}

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
	MusicalComposition *head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
	MusicalComposition *prev = head;
	MusicalComposition *ptr;
	int i;
	for (i = 1; i < n; i++)
	{
		ptr = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
		ptr->prev = prev;
		prev->next = ptr;
		prev = ptr;
	}
	return head;
}

void push(MusicalComposition* head, MusicalComposition* element)
{
	MusicalComposition *ptr = head;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = element;
	element->prev = ptr;
}

void removeEl(MusicalComposition* head, char* name_for_remove)
{
	MusicalComposition* ptr = head;
	while (ptr->next != NULL)
	{
		if (strcmp(ptr->name, name_for_remove) == 0)
		{
			if (ptr->next != NULL && ptr->prev != NULL)
			{
				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
			}
			else if (ptr->next == NULL)
			{
				ptr->prev->next = NULL;
			}
			else if (ptr->prev == NULL)
			{
				*head = *ptr->next;
				head->prev = NULL;
			}
		}
		ptr = ptr->next;
	}
}

int count(MusicalComposition* head)
{
	MusicalComposition* ptr = head;
	int count = 0;
	while (ptr->next)
	{
		++count;
		ptr = ptr->next;
	}
	++count;
	return count;
}

void print_names(MusicalComposition* head)
{
	MusicalComposition* ptr = head;
	while (ptr)
	{
		printf("%s\n", ptr->name);
		ptr = ptr->next;
	}
}

void Sort(MusicalComposition* head)
{
	for (MusicalComposition *i = head; i; i = i->next) {
		for (MusicalComposition *j = head; j; j = j->next) {
			if (i->year > j->year)
			{
				MusicalComposition *r = i->name;
				i->name = j->name;
				j->name = r;
				r = i->author;
				i->author = j->author;
				j->author = r;
				r = i->year;
				i->year = j->year;
				j->year = r;
			}
		}
	}
}