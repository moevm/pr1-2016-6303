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

MusicalComposition* head;

MusicalComposition* createMusicalComposition(char* name, char* author, int year) 
{
  MusicalComposition* cmp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
  strcpy(cmp->name, name);
  strcpy(cmp->author, author);
  cmp->year = year;
  cmp->next = NULL;
  cmp->prev = NULL;
  return cmp;
}


MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n);

void push(MusicalComposition* head, MusicalComposition* element);

void removeEl(char* name_for_remove);

int count(MusicalComposition* head);

void print_names(MusicalComposition* head);

int main() 
{
  int k = 0;
  int i = 0;
  int length;
  scanf("%d\n", &length);

  char** names = (char**)malloc(sizeof(char*) * length);
  char** authors = (char**)malloc(sizeof(char*) * length);
  int* years = (int*)malloc(sizeof(int) * length);

  for(i = 0; i < length; i++) {
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
  head = createMusicalCompositionList(names, authors, years, length);
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
  k = count(head);

  printf("%d\n", k);
  push(head, element_for_push);

  k = count(head);
  printf("%d\n", k);

  removeEl(name_for_remove);
  print_names(head);

  k = count(head);
  printf("%d\n", k);

  return 0;
}



MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n) 
{
    int i = 0;
  MusicalComposition* head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
  MusicalComposition* cmp = head;
  for(i = 1; i < n; i++) 
  {
    MusicalComposition* new = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
    cmp->next = new;
    new->prev = cmp;
    cmp = cmp->next;
  }
  return head;
}

void push(MusicalComposition* head, MusicalComposition* element) 
{
  MusicalComposition* cmp = head;
  MusicalComposition* pushed = createMusicalComposition(element->name, element->author, element->year);
  while(cmp->next != NULL)
    cmp = cmp->next;
  cmp->next = pushed;
  pushed->prev = cmp;
}

void removeEl(char* name_for_remove) 
{ 
    MusicalComposition* ptr = head; 
    while (ptr != NULL) 
    { 
        if (strcmp(ptr->name, name_for_remove) == 0) 
        { 
            if (ptr->next != NULL && ptr->prev != NULL) 
            { 
                ptr->prev->next = ptr->next; 
                ptr->next->prev = ptr->prev; 
                ptr = ptr->next;
            } 
            else if (ptr->next == NULL && ptr->prev == NULL)
            {
                ptr = NULL;
                head = ptr;
            }
            else if (ptr->next == NULL && ptr-> prev != NULL) 
            { 
                
                ptr = ptr->prev;
                ptr->next = NULL;
                ptr = ptr->next;
            } 
            else if (ptr->prev == NULL && ptr->next != NULL) 
            { 
                ptr = ptr->next;
                ptr->prev = NULL;
                head = ptr;
            } 
            
    }     
        //ptr = ptr->next; 
} 
}

int count(MusicalComposition* head) 
{
  MusicalComposition* cmp = head;
  int count = 0;
  while(cmp != NULL) 
  {
    count++;
    cmp = cmp->next;
  }
  return count;
}

void print_names(MusicalComposition* head) 
{
  MusicalComposition* cmp = head;
  while(cmp != NULL) 
  {
    printf("%s\n", cmp->name);
    cmp = cmp->next;
  }
}
