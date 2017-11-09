#include <stdio.h>
#include <stdlib.h>
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

// Функции для работы со списком MusicalComposition

MusicalComposition *createMusicalComposition(char *name, char *author, int year)
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

MusicalComposition *createMusicalCompositionList()
{
    int length;
    scanf("%d", &length);
    getchar();

    char **name = (char**)malloc(sizeof(char*)*length);
    char **author = (char**)malloc(sizeof(char*)*length);
    int *year = (int*)malloc(sizeof(int)*length);

    for (int i = 0; i < length; ++i)
    {
        name[i] = (char*)malloc(sizeof(char*)*81);
        author[i] = (char*)malloc(sizeof(char*)*81);

        gets(name[i]);
        gets(author[i]);
        scanf("%d", &year[i]);
        getchar();
    }

    MusicalComposition *head = createMusicalComposition(name[0], author[0], year[0]);
    MusicalComposition *prev = head;
    MusicalComposition *curr;

    for (int i = 1; i < length; ++i)
    {
        curr = createMusicalComposition(name[i], author[i], year[i]);
        curr->prev = prev;
        prev->next = curr;
        prev = curr;
    }

    return head;
}

void push(MusicalComposition *head)
{
    char *name_for_push = (char*)malloc(sizeof(char)*81);
    char *author_for_push = (char*)malloc(sizeof(char)*81);
    int year_for_push;

    gets(name_for_push);
    gets(author_for_push);
    scanf("%d", &year_for_push);
    getchar();

    MusicalComposition *element_for_push = createMusicalComposition(name_for_push, author_for_push, year_for_push);

    if ((head->status) == 0)
        memcpy(head, element_for_push, sizeof(MusicalComposition));
    else
    {
        while (head->next)
            head = head->next;
        element_for_push->prev = head;
        head->next = element_for_push;
    }
}

int count(MusicalComposition *head)
{
    int count = 0;

    if ((head->status) == 0)
        return 0;
    else
        while (head)
        {
            ++count;
            head = head->next;
        }

    return count;
}

void removeEl(MusicalComposition *head)
{
    char name_for_remove[81];
    int amount = count(head);
    MusicalComposition *temp = head;
    MusicalComposition *curr;

    gets(name_for_remove);

    while (temp->next)
    {
        if (strcmp(temp->name, name_for_remove) == 0)
        {
            if ((temp->prev) == NULL)
            {
                temp = head->next;
                memcpy(head, temp, sizeof(MusicalComposition));
                head->prev = NULL;
                free(temp);
                temp = head;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                curr = temp->next;
                free(temp);
                temp = curr;
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
        else
            head->status = 0;
    }
}

void print_names(MusicalComposition *head)
{
    if (head->status)
        while (head)
        {
            printf("%s\n", head->name);
            head = head->next;
        }
}

int main()
{
    //Функция createMusicalCompositionList всегда вызывается первой и всего один раз
    MusicalComposition *head = createMusicalCompositionList();

    printf("%s %s %d\n", head->name, head->author, head->year);
    printf("%d\n", count(head));
    push(head);
    printf("%d\n", count(head));
    removeEl(head);
    print_names(head);
    printf("%d\n", count(head));

    return 0;
}
