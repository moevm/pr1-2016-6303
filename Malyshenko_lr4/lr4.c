#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct MusicalComposition
{
  char *name;
  char *author;
  int year;
  int status;
  struct MusicalComposition *next, *prev;
};
  typedef struct MusicalComposition MusicalComposition;
  // Описание структуры MusicalComposition

MusicalComposition* createMusicalComposition(char* name, char* author, int year)
// функция создания элемента списка
{
  MusicalComposition *MusComp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
  MusComp->name = name;
  MusComp->author = author;
  MusComp->year = year;
  MusComp->status = 1;
  MusComp->prev = NULL;
  MusComp->next = NULL;

  return MusComp;
}

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
// Функции для работы со списком MusicalComposition
{
  MusicalComposition *head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
  MusicalComposition *prev = head;
  MusicalComposition *curr; //текущая
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

void push(MusicalComposition* head, MusicalComposition* element)
// добавляет element в конец списка musical_composition_list
{
  MusicalComposition* temp = head;
  MusicalComposition* new = createMusicalComposition(element->name, element->author, element->year);
  if (head-> status == 0)
        *head = *new;
  else
  {
    while(temp->next != NULL)
    temp = temp->next;
    temp->next = new;
    new->prev = temp;
  }
}

void removeEl(MusicalComposition* head, char* name_for_remove)
// удаляет элемент element списка, у которого значение name равно значению name_for_remove
{
  MusicalComposition* temp = head;
  while(temp->next)
  if (strcmp(temp->name, name_for_remove) == 0)//strcmp сравнивает name  и  name_for_remove
{
    if(temp->next != NULL && temp->prev != NULL)
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp = temp->next;
    }
    else if(temp->prev == NULL)
    {
        *temp = *(temp->next);
        temp->prev = NULL;
    }
}
else
    temp = temp->next;

if (strcmp(temp->name, name_for_remove) == 0)
{
    if(temp->prev == NULL)
        head->status = 0;
    else
        temp->prev->next = NULL;
}
}



int count(MusicalComposition* head) //считает количество структур в списке
{
MusicalComposition* temp = head;
int count = 0;
while(temp)
    if (temp->status == 0)
        return 0;
    else
        {
        count++;
        temp = temp->next;
        }
return count;
}

void print_names(MusicalComposition* head)
//вывести названия композиций
{
MusicalComposition* temp = head;
if (temp->status == 1)
    while(temp)
    {
        printf("%s\n", temp->name);
        temp = temp->next;
    }
}

int main(){
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

        fgets(name, 80, stdin);   // считывает входной поток длиной 80 в name. fgets записывает
        fgets(author, 80, stdin); //конец строки который нам надо будет заменить на ноль
        fscanf(stdin, "%d\n", &years[i]); // считывает входные данные в years
        (*strstr(name,"\n"))=0; //заменяет конец строки на 0
        (*strstr(author,"\n"))=0;//искать где, искать что, приравнять это к нулю
        names[i] = (char*)malloc(sizeof(char*) * (strlen(name)+1)); // выделили память размера  name
        authors[i] = (char*)malloc(sizeof(char*) * (strlen(author)+1));
        strcpy(names[i], name); //копирует name в name[i]
        strcpy(authors[i], author);

    }

MusicalComposition* head = createMusicalCompositionList(names, authors, years, length);

  char name_for_push[80];
  char author_for_push[80];
  int year_for_push;

  char name_for_remove[80];
  char name_for_removePOD[80];
  fgets(name_for_push, 80, stdin);
  fgets(author_for_push, 80, stdin);
  fscanf(stdin, "%d\n", &year_for_push); //откуда сколько куда
  (*strstr(name_for_push,"\n"))=0;
  (*strstr(author_for_push,"\n"))=0;

 MusicalComposition* element_for_push = createMusicalComposition(name_for_push, author_for_push, year_for_push);

  fgets(name_for_remove, 80, stdin); //куда сколько откуда
  (*strstr(name_for_remove,"\n"))=0;
  printf("%s %s %d\n", head->name, head->author, head->year);

  int k = count(head);//записывает количество структур в списке в переменную k
  printf("Изначально: %d\n", k);

  push(head, element_for_push);
  k = count(head);
  printf("После добавления: %d\n", k);

  removeEl(head, name_for_remove);
  print_names(head);

    fgets(name_for_removePOD, 80, stdin);
    (*strstr(name_for_removePOD,"\n"))=0;
    removeElPOD(head, name_for_removePOD);
    print_names(head);
    k = count(head);
    printf("Количество элементов: %d\n", k);
    char name_for_push2[80];
    char author_for_push2[80];
    int year_for_push2;

    fgets(name_for_push2, 80, stdin);
    fgets(author_for_push2, 80, stdin);
    fscanf(stdin, "%d\n", &year_for_push2); //откуда сколько куда
    (*strstr(name_for_push2,"\n"))=0;
    (*strstr(author_for_push2,"\n"))=0;

    MusicalComposition* element_for_push2 = createMusicalComposition(name_for_push2, author_for_push2, year_for_push2);
    push(head, element_for_push2);

      print_names(head);
      k = count(head);
      printf("Количество элементов: %d\n", k);
      char name_for_push3[80];
      char author_for_push3[80];
      int year_for_push3;

      fgets(name_for_push3, 80, stdin);
      fgets(author_for_push3, 80, stdin);
      fscanf(stdin, "%d\n", &year_for_push3); //откуда сколько куда
      (*strstr(name_for_push3,"\n"))=0;
      (*strstr(author_for_push3,"\n"))=0;

      MusicalComposition* element_for_push3 = createMusicalComposition(name_for_push3, author_for_push3, year_for_push3);
      push(head, element_for_push3);

  print_names(head);
  k = count(head);

printf("Количество элемнтов: %d\n", k);
free (names);
free(authors);
free(years);
return 0;
}
