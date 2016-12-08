#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct MusicalComposition
{
char name[80];
char author[80];
int year;
struct MusicalComposition* next;
struct MusicalComposition* prev;
} MusicalComposition;

MusicalComposition* createMusicalComposition(char* name, char* author, int year);

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n);

void push(MusicalComposition* head, MusicalComposition* element);

void removeEl(MusicalComposition* head, char* name_for_remove);

int count(MusicalComposition* head);

void print_names(MusicalComposition* head);


int main(){
int length;
scanf("%d\n", &length);

char** names = (char**)malloc(sizeof(char*)*length);
char** authors = (char**)malloc(sizeof(char*)*length);
int* years = (int*)malloc(sizeof(int)*length);

for (int i=0;i<length;i++)
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

return 0;

}
MusicalComposition* createMusicalComposition(char* name, char* author, int year)
{
  MusicalComposition *head = (MusicalComposition*)malloc(sizeof(MusicalComposition));
  strcpy(head->name, name);
  strcpy(head->author, author);
  head->year=year;
  head->next=NULL;
  head->prev=NULL;
  return head; 
}
                                                         
MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
	MusicalComposition *head = createMusicalComposition(array_names[0],array_authors[0],array_years[0]);
	MusicalComposition *ThisList = head;
	for (int i=1;i<n;++i)
	{
MusicalComposition *newList = createMusicalComposition(array_names[i],array_authors[i],array_years[i]);
        ThisList->next=newList;
        newList->prev=ThisList;
        ThisList=ThisList->next;
	}
	return head;
}

void push(MusicalComposition* head, MusicalComposition* element)
{
	MusicalComposition* test = head;
	MusicalComposition* new = createMusicalComposition(element->name, element->author, element->year);
	while(test->next!=NULL)
		test=test->next;
	test->next=new;
	new->prev=test;
}

void removeEl(MusicalComposition* head, char* name_for_remove)
{
	MusicalComposition* test=head;
    while(strcmp(test->name, name_for_remove) != 0 && test->next!=NULL)
    	test=test->next;
    if(test->next != NULL && test->prev != NULL) 
     {
     test->prev->next = test->next;
     test->next->prev = test->prev;
     }
    else if(test->next == NULL) 
 	 {
     test->prev->next = NULL;
 	 } 
  	else if(test->prev == NULL) 
 	 {
     test->next->prev = NULL;
	 }
}	 

int count(MusicalComposition* head)
{
	MusicalComposition* test =head;
	int count=0;
	while(test!=NULL)
		{
			++count;
			test=test->next;
		}
	return count;
}

void print_names(MusicalComposition* head)
{   
	MusicalComposition* test =head;
	while(test!=NULL)
	{
		printf("%s\n",test->name);
		test=test->next;
	}
}