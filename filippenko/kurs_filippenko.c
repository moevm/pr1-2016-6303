#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct MusicalComposition
{
char* name;
char* author;
int status;
int year;
struct MusicalComposition *prev, *next;
};

typedef struct MusicalComposition MusicalComposition;

MusicalComposition* createMusicalComposition(char* name, char* author, int year)
{
MusicalComposition* MusComp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
MusComp->name=name;
MusComp->author=author;
MusComp->status = 1;
MusComp->year=year;
MusComp->prev=NULL;
MusComp->next=NULL;

return MusComp;
}

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
MusicalComposition *head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
MusicalComposition *prev = head;
MusicalComposition *actual;
int i;
for(i=1; i<n; i++)
{
actual = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
actual->prev = prev;
prev->next = actual;
prev = actual;
}
return head;
}

void push(MusicalComposition* head, MusicalComposition* element)
// добавляет element в конец списка musical_composition_list
{
  MusicalComposition* actual = head;
  MusicalComposition* new = createMusicalComposition(element->name, element->author, element->year);
  if (head-> status == 0)
        *head = *new;
  else
  {
    while(actual->next != NULL)
    actual = actual->next;
    actual->next = new;
    new->prev = actual;
  }
}

void removeEl(MusicalComposition* head, char* name_for_remove)
// удаляет элемент element списка, у которого значение name равно значению name_for_remove
{
MusicalComposition* actual = head;
while(actual != NULL )
if (strcmp(actual->name, name_for_remove) == 0)//strcmp сравнивает name и name_for_remove
{
if(actual->next != NULL && actual->prev != NULL)
{
actual->prev->next = actual->next;
actual->next->prev = actual->prev;
actual = actual->next;
}
else if(actual->prev == NULL && actual->next != NULL)
{
*actual = *(actual->next);
actual->prev = NULL;
}
else if(actual->next == NULL)
{
if (actual->prev == NULL)
{
head->status = 0;
actual=NULL;
}
else
{
actual->prev->next = NULL;
actual=NULL;
}
}
}
else
actual = actual->next;
}

int count(MusicalComposition* head) //считает количество структур в списке

{
MusicalComposition* actual = head;
int count = 0;
while(actual)
    if (actual->status == 0)
        return 0;
    else
        {
        count++;
        actual = actual->next;
        }
return count;
}

void print_names(MusicalComposition* head)
//вывести названия композиций
{
MusicalComposition* actual = head;
if (actual->status == 1)
    while(actual)
    {
        printf("%s\n", actual->name);
        actual = actual->next;
    }
}

void push_double(MusicalComposition* head, char *name, char *author, int year)

{
MusicalComposition* actual = head;
MusicalComposition* head_temp = head;
MusicalComposition *next;
int i = 1;
while(actual->next)
{
    if((i%2) == 0)
    {
        MusicalComposition* element1 = createMusicalComposition(name, author, year);
        MusicalComposition* element2 = createMusicalComposition(name, author, year);
        next = actual->next;
        actual->next = element1;
        element1->prev = actual;

        element1->next = element2;
        element2->prev = element1;
        element2->next = next;
        next->prev = element2;

        actual = next;
    }
    else
        actual = actual->next;
    i++;
}
if ((i%2) == 0)
{
  MusicalComposition* element1 = createMusicalComposition(name, author, year);
  MusicalComposition* element2 = createMusicalComposition(name, author, year);

  actual->next = element1;
  element1->prev = actual;

  element1->next = element2;
  element2->prev = element1;
}
}

int main()
{
int length;
scanf("%d\n",&length);

char** names = (char**)malloc(sizeof(char*)*length);
char** authors = (char**)malloc(sizeof(char*)*length);
int* years = (int*)malloc(sizeof(int)*length);

int i;
for(i=0;i<length;i++)
{
char name[80];
char author[80];

fgets(name, 80, stdin);
fgets(author, 80, stdin);
fscanf(stdin, "%d\n", &years[i]);

(*strstr(name, "\n"))=0;
(*strstr(author, "\n"))=0;

names[i] = (char*)malloc(sizeof(char)*((strlen(name))+1));
authors[i] = (char*)malloc(sizeof(char)*((strlen(author))+1));
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
(*strstr(name_for_push, "\n"))=0;
(*strstr(author_for_push, "\n"))=0;

MusicalComposition* element_for_push = createMusicalComposition(name_for_push, author_for_push, year_for_push);
fgets(name_for_remove, 80, stdin);
(*strstr(name_for_remove, "\n"))=0;
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



push_double(head, name_for_push, author_for_push, year_for_push);
print_names(head);
k = count(head);
printf("%d\n",k);

return 0;
}
