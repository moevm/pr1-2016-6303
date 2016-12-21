#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct MusicalComposition
{
char *name;
char *author;
int year;
struct MusicalComposition *next, *prev;
};

typedef struct MusicalComposition MusicalComposition;

MusicalComposition* createMusicalComposition(char* name, char* author, int year)
{
MusicalComposition *MusComp =(MusicalComposition*)malloc(sizeof(MusicalComposition));
MusComp->name = name;
MusComp->author = author;
MusComp->year = year;
MusComp->prev = NULL;
MusComp->next = NULL;
return MusComp;
}

MusicalComposition* createMusicalCompositionList(char** array_names, char**array_authors, int* array_years, int n)
{
MusicalComposition *head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
MusicalComposition *prev = head;
MusicalComposition *curr;
int i;
for (i = 1; i < n; ++i)
{
curr = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
curr->prev = prev;
prev->next = curr;
prev = curr;
}
return head;
}

void pushend(MusicalComposition*  head, MusicalComposition* element)

{
  		MusicalComposition* temp = head;	
  		while(temp->next != NULL)
  		temp = temp->next;
MusicalComposition* new = createMusicalComposition(element->name, element->author, element->year);
  		temp->next = new;
 		new->prev = temp;
        }	

void push (MusicalComposition** head, MusicalComposition* element1, MusicalComposition* element2, MusicalComposition* element3)
{
MusicalComposition* temp =* head;
MusicalComposition* new1 = createMusicalComposition(element1->name, element1->author, element1->year);
temp->prev = new1;
new1->next = temp;
*head = new1;

MusicalComposition* new2 = createMusicalComposition(element2->name, element2->author, element2->year);
new1->next=new2;
new2->prev=new1;
new2->next=temp;
temp->prev=new2;

MusicalComposition* new3 = createMusicalComposition(element3->name, element3->author, element3->year);
new2->next=new3;
new3->prev=new2;
new3->next=temp;
temp->prev=new3;
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
MusicalComposition* temp = head;
int count = 0;
while(temp != NULL) 
{
count++;
temp = temp->next;
}
return count;
}

void print_names(MusicalComposition* head)
{
MusicalComposition* temp = head;
while(temp != NULL) 
{
printf("%s\n", temp->name);
temp = temp->next;
}
}

int main()
{
int length; 
scanf("%d\n", &length);
char** names = (char**)malloc(sizeof(char*)*length);
char** authors = (char**)malloc(sizeof(char*)*length);
int* years = (int*)malloc(sizeof(int)*length); 
int i;
for (i=0;i<length;i++)
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
char name_for_push1[80]; 
char author_for_push1[80]; 
int year_for_push1;
fgets(name_for_push1, 80, stdin);
fgets(author_for_push1, 80, stdin);
fscanf(stdin, "%d\n", &year_for_push1);
(*strstr(name_for_push1,"\n"))=0;
(*strstr(author_for_push1,"\n"))=0;
MusicalComposition* element_for_push1 = createMusicalComposition(name_for_push1, author_for_push1, year_for_push1);

char name_for_push2[80];
char author_for_push2[80];
int year_for_push2;
fgets(name_for_push2, 80, stdin);
fgets(author_for_push2, 80, stdin);
fscanf(stdin, "%d\n", &year_for_push2);
(*strstr(name_for_push2,"\n"))=0;
(*strstr(author_for_push2,"\n"))=0;
MusicalComposition* element_for_push2 = createMusicalComposition(name_for_push2, author_for_push2, year_for_push2);

char name_for_push3[80];
char author_for_push3[80];
int year_for_push3;
fgets(name_for_push3, 80, stdin);
fgets(author_for_push3, 80, stdin);
fscanf(stdin, "%d\n", &year_for_push3);
(*strstr(name_for_push3,"\n"))=0;
(*strstr(author_for_push3,"\n"))=0;
MusicalComposition* element_for_push3 = createMusicalComposition(name_for_push3, author_for_push3, year_for_push3);

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

int k = count(head);
printf("Before: \n %d\n", k);

removeEl(head, name_for_remove); 

pushend(head, element_for_push);
push(&head, element_for_push1, element_for_push2, element_for_push3);

k = count(head);
printf("After: \n %d\n", k);

printf("Head: %s %s %d\n", head->name, head->author, head->year);

print_names(head);

free(names);
free(authors);
free(years);
return 0;

}


