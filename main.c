#include <stdio.h>
#include <string.h>

// Описание структуры MusicalComposition
typedef struct MusicalComposition
{
    char* name;
    char* author;
    int year;
    struct MusicalComposition *next;
    struct MusicalComposition *prev;
}MusicalComposition;

// Создание структуры MusicalComposition

MusicalComposition* createMusicalComposition(char* name, char* author, int year)
{
    MusicalComposition *next = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    next->name = name;
    next->author = author;
    next->year = year;
    next->next=NULL;
    next->prev=NULL;
    return next;
}

// Функции для работы со списком MusicalComposition

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
    MusicalComposition* head;
    int i=1;
    head=createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
    MusicalComposition* ptr=head;
    for (i;i<n;i++)
    {
        ptr->next=createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
        ptr->next->prev = ptr;
        ptr->next->next=NULL;
        ptr=ptr->next;
    }
    return head;
}

void push(MusicalComposition* head, MusicalComposition* element)
{
while (head->next != NULL)
    {
        head=head->next;
    }
    head->next=element;
    element->next=NULL;
}

void removeEl(MusicalComposition* head, char* name_for_remove)
{
    MusicalComposition* buf=head;
    while (head != NULL)
    {
        if (strcmp(head->name,name_for_remove) == 0 )
        {
            if (head->prev == NULL)
            {
                *head = *head->next;
                head->prev=NULL;
                buf=head;
            }
            else if (head->next == NULL)
            {
                head->prev->next = NULL;
                buf=head;
            }
            else 
            {
                head->prev->next = head->next;
                head->next->prev = head->prev;
                buf=head;
            }   
            free(buf);
        }
        head=head->next;
    }
}

int count(MusicalComposition* head)
{
  int counter = 0;
  while(head)
  {
    counter++;
    head=head->next;
  }
  return counter;
}

void print_names(MusicalComposition* head)
{
  while(head)
  {
    printf("%s\n",head->name);
    head=head->next;
  }
}

int cut(MusicalComposition* head, int i, int j) 
{ 
int count = 1; 
if (i < j && i != 0 && j != 0 && head != NULL)
    {
        for (count;count <= j;count++) 
            { 
                if (count < i) 
                { 
                    *head=*head->next; 
                    head->prev=NULL; 
                } 
                if (count > i && count <  j) 
                { 
                    head=head->next;
                } 
                    else if (count == j)
        {
           head=head->next;
           head->next=NULL;
        }
            }
        return 0;       
    }
    else return 1;
}


int main(){
    int length,c,d;
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
    printf("Введите начало и конец среза (числа через пробел)\n");
    scanf("%d %d",&c,&d);
    cut(head, c, d);
    print_names(head);
   while (head->next)
    {
     MusicalComposition* buf=head;
     head=head->next;
     free(buf);
    }
    return 0;
}
