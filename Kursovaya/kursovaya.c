#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MusicalComposition
{
    char *name;
    char *author;
    int year;
    int status;
    struct MusicalComposition *next, *prev;
} MusicalComposition;

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

    printf("Enter the number of compositions: ");
    scanf("%d", &length);
    getchar();
    printf("Enter the information about %d compositions:\n", length);

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

    printf("Enter the information about composition to push:\n");

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

    printf("Enter the name of composition to remove:\n");
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
    printf("The list of compositions:\n");

    if (head->status)
        while (head)
        {
            printf("%s %s %d\n", head->name, head->author, head->year);
            head = head->next;
        }
}

// Функция сортировки для курсовой
void sort(MusicalComposition *head)
{
    int amount = count(head);
    MusicalComposition *curr;
    MusicalComposition *temp = (MusicalComposition*)malloc(sizeof(MusicalComposition));

    printf("The list of compositions after sort:\n");

    for (int i = 0; i < (amount - 1); ++i)
    {
        curr = head;
        while (curr->next)
        {
            if ((strcmp(curr->name, curr->next->name)) > 0)
            {
                memcpy(temp, curr->next, (sizeof(MusicalComposition) - 8));
                memcpy(curr->next, curr, (sizeof(MusicalComposition) - 8));
                memcpy(curr, temp, (sizeof(MusicalComposition) - 8));
            }
            curr = curr->next;
        }
    }
    free(temp);
}

int main()
{
    //Функция createMusicalCompositionList всегда вызывается первой и всего один раз
    MusicalComposition *head = createMusicalCompositionList();

    push(head);
    removeEl(head);
    printf("The nuber of compositions: %d\n", count(head));
    print_names(head);

    //Вывзов фунции сортировки
    sort(head);
    printf("The nuber of compositions: %d\n", count(head));
    print_names(head);

    return 0;
}
