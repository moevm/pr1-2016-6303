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
// Описание структуры MusicalComposition


// Создание структуры MusicalComposition
// функция создания элемента списка
MusicalComposition* createMusicalComposition(char* name, char* author, int year)
{
    MusicalComposition *MusComp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    MusComp->name = name;
    MusComp->author = author;
    MusComp->year = year;
    MusComp->prev = NULL;
    MusComp->next = NULL;

    return MusComp;
}

// Функции для работы со списком MusicalComposition

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
//создает список музыкальных коспозиций
{
    MusicalComposition *head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
    MusicalComposition *prev = head;
    MusicalComposition *curr;

    for (int i = 1; i < n; ++i)
    {
        curr = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
        curr->prev = prev;
        prev->next = curr;
        prev = curr;
    }

    return head;
}
void push(MusicalComposition*  head, MusicalComposition* element)
// добавляет element  в конец списка musical_composition_list
{
  MusicalComposition* temp = head;
  while(temp->next != NULL)
    temp = temp->next;
  MusicalComposition* new = createMusicalComposition(element->name, element->author, element->year);
  temp->next = new;
  new->prev = temp;
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

int count(MusicalComposition* head) //возвращает количество элементов списка
{
  MusicalComposition* temp = head;
  int count = 0;
  while(temp != NULL) {
    count++;
    temp = temp->next;
  }
  return count;
}

void print_names(MusicalComposition*  head)
//вывести названия композиций 
{
  MusicalComposition* temp = head;
  while(temp != NULL) {
    printf("%s\n", temp->name);
    temp = temp->next;
  }
}

int main(){
    int length; //длина
    scanf("%d\n", &length);  

    char** names = (char**)malloc(sizeof(char*)*length);
    char** authors = (char**)malloc(sizeof(char*)*length);
    int* years = (int*)malloc(sizeof(int)*length);     //выделение памяти под массивы

    for (int i=0;i<length;i++)
    {
        char name[80];
        char author[80];

        fgets(name, 80, stdin);    //считывание имени автора и года
        fgets(author, 80, stdin);
        fscanf(stdin, "%d\n", &years[i]);

        (*strstr(name,"\n"))=0;     //функция стрстр-поиск первого вхождения подстроки в строку
        (*strstr(author,"\n"))=0;       //находит символ подстроки в строки заменяет на ноль

        names[i] = (char*)malloc(sizeof(char*) * (strlen(name)+1));
        authors[i] = (char*)malloc(sizeof(char*) * (strlen(author)+1));

        strcpy(names[i], name);  //копируем name в names[i]
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



