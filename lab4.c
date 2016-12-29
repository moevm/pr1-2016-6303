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
} MusicalComposition;

MusicalComposition* createMusicalComposition(char* name, char* author, int year);

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n);

void push(MusicalComposition* head, MusicalComposition* element);

void removeEl(MusicalComposition* head, char* name_for_remove);

int count(MusicalComposition* head);

void print_names(MusicalComposition* head);
int main(){
int length;
printf("Length of List:   ");
scanf("%d\n", &length);

char** names = (char**)malloc(sizeof(char*)*length);
char** authors = (char**)malloc(sizeof(char*)*length);
int* years = (int*)malloc(sizeof(int)*length);
int j;
for (int i = 0; i<length; i++)
{
    j=i+1;
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
printf("Name of Head-Group:   ");
printf("%s %s %d\n", head->name, head->author, head->year);
int k = count(head);

printf("Number of Groups at first:  %d\n", k);
push(head, element_for_push);

k = count(head);
printf("Number of Groups on addition:  %d\n", k);

removeEl(head, name_for_remove);
printf("Names of groups Left:\n");
print_names(head);

k = count(head);
printf("Number of Groups Left:  %d\n", k);

return 0;

}

MusicalComposition* createMusicalComposition(char* name, char* author, int year) {
	MusicalComposition* current = (MusicalComposition*)malloc(sizeof(MusicalComposition));
	current->name = name;
	current->author = author;
	current->year = year;
	current->next = NULL;
	current->prev = NULL;
	return current;
}

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n) {
	MusicalComposition *head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
	MusicalComposition *prev = head;
	MusicalComposition *composition;
	for (int i = 1; i < n; i++) {
		composition = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
		composition->prev = prev;
		prev->next = composition;
		prev = composition;
	}
	return head;
}

void push(MusicalComposition* head, MusicalComposition* element) {
	MusicalComposition *current = head;
	while (current->next) {
		current = current->next;
	}
	current->next = element;
	element->prev = current;
}

void removeEl(MusicalComposition* head, char* name_for_remove)
{
	MusicalComposition* current = head;
	while (current)
	{
		if (strcmp(current->name, name_for_remove) == 0)
		{
			if (current->next != NULL && current->prev != NULL)
			{
				current->prev->next = current->next;
				current->next->prev = current->prev;
				current = current->next;
			}
			else if (current->next == NULL && current->prev!=NULL)
			{
				current->prev->next = NULL;
				current = NULL;
			}
			else if (current->next!=NULL && current->prev==NULL)
			{
				*head = *head->next;
				head->prev = NULL;
				current = head;
			}
			else if (current->next == NULL && current->prev == NULL)
			{
				current->year=-1;
				current = NULL;
			}
		}else{
			current = current->next;
		}
	}

}

int count(MusicalComposition* head)
{
	MusicalComposition* current = head;
	int count = 0;
	while (current && current->year != -1)
	{
		count++;
		current = current->next;
	}
	return count;
}

void print_names(MusicalComposition* head)
{
	MusicalComposition* current = head;
	while (current && current->year!=-1)
	{
		printf("%s\n", current->name);
		current = current->next;
	}
}
