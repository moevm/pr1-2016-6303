#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct MusicalComposition
{
    char *name;
    char *author;
    int year;
    int vivod;
    struct MusicalComposition* next;
    struct MusicalComposition* prev;
};

typedef struct MusicalComposition MusicalComposition;

MusicalComposition* createMusicalComposition(char* name, char* author, int year)
{
    MusicalComposition *MusComp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    MusComp->name = name;
    MusComp->author = author;
    MusComp->year = year;
    MusComp->vivod = 1;
    MusComp->prev = NULL;
    MusComp->next = NULL;

    return MusComp;
}

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
    MusicalComposition *head;
    head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
    MusicalComposition *tmp = head;
    MusicalComposition* next;
    int i;
    for (i = 1; i < n; i++)
    {
        next = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
        tmp->next = next;
        next->prev = tmp;
        tmp = tmp->next;
    }
    return head;
}

void push(MusicalComposition* head, MusicalComposition* element)
{
    MusicalComposition* tmp = head;
    MusicalComposition* push = createMusicalComposition(element->name, element->author, element->year);
    if (head->vivod == 0)
      *head = *push;
    else
    {
      while(tmp->next != NULL)
      tmp = tmp->next;
      tmp->next = push;
      push->prev = tmp;
    }
}


void removeEl(MusicalComposition* head, char* name_for_remove)
{
    MusicalComposition* tmp = head;
    while(tmp->next)
      if(strcmp(tmp->name, name_for_remove) == 0)
      {
        if(tmp->next != NULL && tmp->prev != NULL)
        {
          tmp->prev->next = tmp->next;
          tmp->next->prev = tmp->prev;
          tmp = tmp->next;
        }
        else if(tmp->prev == NULL)
        {
          *tmp = *(tmp->next);
          tmp->prev = NULL;
        }
      }
      else
        tmp = tmp->next;
    if(strcmp(tmp->name, name_for_remove) == 0)
    {
      if(tmp->prev == NULL)
        head->vivod = 0;
      else
        tmp->prev->next = NULL;
    }

}

void rmyear(MusicalComposition* head)
{
    MusicalComposition* tmp = head;
    while(tmp->next)
    if((tmp->year % 4) == 0)
    {
      if(tmp->next != NULL && tmp->prev != NULL)
      {
          tmp->prev->next = tmp->next;
          tmp->next->prev = tmp->prev;
          tmp = tmp->next;
      }
      else if(tmp->prev == NULL)
      {
        *tmp = *(tmp->next);
        tmp->prev = NULL;
      }
    }
    else
      tmp = tmp->next;

    if ((tmp->year % 4) == 0)
    {
      if(tmp->prev == NULL)
          head->vivod = 0;
      else
          tmp->prev->next = NULL;
    }
}

int count(MusicalComposition* head)
{
    MusicalComposition* tmp = head;
    int count = 0;
    while(tmp)
      if(tmp->vivod == 0)
        return 0;
      else
      {
        count++;
        tmp = tmp->next;
      }
    return count;
}

void print_names(MusicalComposition* head)
{
    MusicalComposition* tmp = head;
    if(tmp->vivod ==1)
      while(tmp)
      {
        printf("%s\n", tmp->name);
        tmp = tmp->next;
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
    printf("изначально:%d\n", k);

    push(head, element_for_push);

    k = count(head);
    printf("после добавления:%d\n", k);

    removeEl(head, name_for_remove);

    k = count(head);
    printf("после удаления структур с именем name for remove:%d\n", k);

    print_names(head);

    rmyear(head);
    k = count(head);
    printf("после удаления годов кратных 4:%d\n", k);

    print_names(head);

    free(names);
    free(authors);
    free(years);
    return 0;
}
