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

MusicalComposition* createMusicalComposition(char* name, char* author, int year)
{
    MusicalComposition* MusCom = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    MusCom->name = name;
    MusCom->author = author;
    MusCom->year = year;
    MusCom->next = NULL;
    MusCom->prev = NULL;
    return MusCom;
}

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
    MusicalComposition *head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
    MusicalComposition *prev = head;
    MusicalComposition* current;
    int i;
    for(i = 1; i < n; i++)
    {
        current = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
        current->prev = prev;
        prev->next = current;
        prev = current;
    }
    return head;
}

void push(MusicalComposition* head, MusicalComposition* element)
{
    MusicalComposition* current = head;
    while(current->next)
        current = current->next;
    current->next = element;
    element->prev = current;
}

void removeEl(MusicalComposition* head, char* name_for_remove)
{
    MusicalComposition* current = head;
    while(current)
    {
        if(strcmp(current->name, name_for_remove) == 0)
        {
            if(current->next != NULL && current->prev != NULL)
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            else if(current->next == NULL)
            {
                current->prev->next = NULL;
            }
            else if(current == head)
            {
                *head = *head->next;
                head->prev = NULL;
                if(head->next != NULL)
                    head->next->prev = head;
                current = head;
            }
        }
        current = current->next;
    }

}

int count(MusicalComposition* head)
{
    MusicalComposition* current = head;
    int count = 0;
    while (current->next)
    {
        ++count;
        current = current->next;
    }
    ++count;
    return count;
}

void print_names(MusicalComposition* head)
{
    MusicalComposition* current = head;
    while (current->next)
    {
        printf("%s\n", current->name);
        current = current->next;
    }
    printf("%s\n", current->name);
}

MusicalComposition* swap(MusicalComposition* head)
{
    MusicalComposition* current = head;
    MusicalComposition* buffer = current;
    while (current)
    {
        buffer = current->next;
        current->next = current->prev;
        current->prev = buffer;
        buffer = current;
        current = current->prev;
    }
    return buffer;
}

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
    printf("\n");
    head = swap(head);
    print_names(head);

    return 0;

}

