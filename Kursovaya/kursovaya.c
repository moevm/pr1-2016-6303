#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct MusicalComposition
{
    char *name;
    char *author;
    int year;
    struct MusicalComposition *prev, *next;
} ;

typedef struct MusicalComposition MusicalComposition;

// Функции для работы со списком MusicalComposition

MusicalComposition *createMusicalComposition(char *name, char *author, int year)
{
    MusicalComposition *MusComp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    MusComp->name = name;
    MusComp->author = author;
    MusComp->year = year;
    MusComp->prev = NULL;
    MusComp->next = NULL;

    return MusComp;
}

MusicalComposition *createMusicalCompositionList(char **array_names, char **array_authors, int *array_years, int n)
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

void push(MusicalComposition *head, MusicalComposition *element)
{
    MusicalComposition *curr = head;
    while (curr->next)
        curr = curr->next;
    curr->next = element;
    element->prev = curr;
}

void removeEl(MusicalComposition *head, char *name_for_remove)
{
    MusicalComposition *curr = head;
    while (curr->next)
    {
        if (strcmp(curr->name, name_for_remove) == 0)
            if ((curr->prev) == 0)
            {
                MusicalComposition *curr_2 = curr->next;
                curr->name = curr_2->name;
                curr->author = curr_2->author;
                curr->year = curr_2->year;
                curr_2->next->prev = curr;
                curr->next = curr_2->next;
                free(curr_2);
            }
            else
            {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                free(curr);
            }
        curr = curr->next;
    }
    if ((strcmp(curr->name, name_for_remove) == 0) && (curr->next == 0))
    {
        curr->prev->next = NULL;
        free(curr);
    }
}

int count(MusicalComposition *head)
{
    int count = 0;;
    MusicalComposition *curr = head;

    while (curr->next)
    {
        ++count;
        curr = curr->next;
    }

    return ++count;
}

void print_names(MusicalComposition *head)
{
    MusicalComposition *curr = head;

    while (curr->next)
    {
        printf("%s\n", curr->name);
        curr = curr->next;
    }
    printf("%s\n", curr->name);
}

// Функция сортировки для курсовой

void sort(MusicalComposition *head)
{
    MusicalComposition *curr_i = head;
    MusicalComposition *curr_j;

    while (curr_i->next)
    {
        curr_j = head;
        while (curr_j->next)
        {
            if ((strcmp(curr_j->name, curr_j->next->name)) > 0)
            {
                MusicalComposition *temp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
                temp->name = curr_j->next->name; temp->author = curr_j->next->author; temp->year = curr_j->next->year;
                curr_j->next->name = curr_j->name; curr_j->next->author = curr_j->author; curr_j->next->year = curr_j->year;
                curr_j->name = temp->name; curr_j->author = temp->author; curr_j->year = temp->year;
                free(temp);
            }
            curr_j = curr_j->next;
        }
        curr_i = curr_i->next;
    }
}

int main()
{
    int length;
    scanf("%d\n", &length);

    char **names = (char**)malloc(sizeof(char*)*length);
    char **authors = (char**)malloc(sizeof(char*)*length);
    int *years = (int*)malloc(sizeof(int)*length);

    for (int i = 0; i < length; ++i)
    {
        char name[80];
        char author[80];

        fgets(name, 80, stdin);
        fgets(author, 80, stdin);
        fscanf(stdin, "%d\n", &years[i]);

        (*strstr(name,"\n")) = 0;
        (*strstr(author,"\n")) = 0;

        names[i] = (char*)malloc(sizeof(char*)*(strlen(name) + 1));
        authors[i] = (char*)malloc(sizeof(char*)*(strlen(author) + 1));

        strcpy(names[i], name);
        strcpy(authors[i], author);
    }

    MusicalComposition *head = createMusicalCompositionList(names, authors, years, length);

    char name_for_push[80];
    char author_for_push[80];
    int year_for_push;

    char name_for_remove[80];

    fgets(name_for_push, 80, stdin);
    fgets(author_for_push, 80, stdin);
    fscanf(stdin, "%d\n", &year_for_push);
    (*strstr(name_for_push,"\n")) = 0;
    (*strstr(author_for_push,"\n")) = 0;

    MusicalComposition *element_for_push = createMusicalComposition(name_for_push, author_for_push, year_for_push);

    fgets(name_for_remove, 80, stdin);
    (*strstr(name_for_remove,"\n")) = 0;

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

    //Вывзов фунции сортировки

    sort(head);
    print_names(head);

    return 0;
}
