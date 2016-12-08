#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MusicalComposition
{
    char *name;
    char *author;
    int year;
    struct MusicalComposition *next, *prev;
};

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
    if ((head->prev) && (head->next))
        head = element;
    else
    {
        while (head->next)
            head = head->next;
        head->next = element;
        element->prev = head;
    }
}

int count(MusicalComposition *head)
{
    int count = 0;

    if (((head->prev) == 0) && ((head->next == 0)))
        return 0;
    else
        while (head)
        {
            ++count;
            head = head->next;
        }

    return count;
}

void removeEl(MusicalComposition *head, char *name_for_remove)
{
    int amount = count(head);
    MusicalComposition *temp = head;
    MusicalComposition *curr;

    while (temp->next)
    {
        if (strcmp(temp->name, name_for_remove) == 0)
        {
            if ((temp->prev) == 0)
            {
                temp = head->next;
                memcpy(head, temp, (sizeof(MusicalComposition) - 4));
                free(temp);
                temp = head;
            }
            else
            {
                curr = temp->next; curr->prev->prev->next = curr;
                curr = temp->prev; curr->next->next->prev = curr;
                free(temp);
                temp = curr->next;
            }
            --amount;
        }
        else
            temp = temp->next;
    }
    if (strcmp(temp->name, name_for_remove) == 0)
    {
        if (amount != 1)
        {
            temp->prev->next = NULL;
            free(temp);
        }
    }
}

void print_names(MusicalComposition *head)
{
    if (((head->prev) != 0) || ((head->next != 0)))
        while (head)
        {
            printf("%s\n", head->name);
            head = head->next;
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

    return 0;
}
