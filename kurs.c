#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Описание структуры MusicalComposition
typedef struct MusicalComposition {
        char* name;
        char* author;
        int year;
        struct MusicalComposition *next;
        struct MusicalComposition *prev;
} MusicalComposition;

// Создание структуры MusicalComposition

MusicalComposition *createMusicalComposition(char* name, char* author, int year) {
        MusicalComposition * music = (MusicalComposition*)malloc(sizeof(MusicalComposition));
        music->name = name;
        music->author = author;
        music->year = year;
        music->next = NULL;
        music->prev = NULL;
        return music;
}

// Функции для работы со списком MusicalComposition

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n) {
        MusicalComposition *head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
        MusicalComposition *tmp = head;
        int i;
        for (i=1; i<n; i++) {
                MusicalComposition * pp = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
                tmp->next = pp;
                pp->prev = tmp;
                tmp = tmp->next;
        }
 return head;
}

//функция вставляет в середину 3 элемента
void push(MusicalComposition * head, MusicalComposition* element1, MusicalComposition* element2, MusicalComposition* element3) {
        MusicalComposition * tmp = head;
        int schet = 0;
        while ( tmp->next != NULL) {
                ++schet;
                tmp = tmp->next;
        }
        for (int j=0; j<((schet/2)+1); ++j) {
                tmp = tmp->prev;
        }
        MusicalComposition* second = tmp->next ;
        MusicalComposition* pp1= createMusicalComposition(element1->name, element1->author, element1->year);
        tmp->next = pp1;
        MusicalComposition* pp2= createMusicalComposition(element2->name, element2->author, element2->year);
        pp1-> next = pp2;
        pp2->prev= pp1;
        MusicalComposition* pp3= createMusicalComposition(element3->name, element3->author, element3->year);
        pp2->next = pp3;
        pp3->prev= pp2;
        pp3->next=second;

}

//создание дополнительных функций, не используются в программе

void removeEl(MusicalComposition * head, char* name_for_remove)
{
    MusicalComposition *tmp = head;
  	while(tmp != NULL) {
        if(strcmp(tmp->name, name_for_remove) == 0)
            {
                if(tmp == head)
                {
                    *head = *head->next;
                    head->prev = NULL;
                    if(head->next != NULL)
                    {
                        head->next->prev = head;
                    }
                    tmp = head;
                    continue;
                }
                else if(tmp->next == NULL)
                {
                    tmp = tmp->previous;
                    tmp->next = NULL;
                } else {
                    tmp->next->prev = tmp->prev;
                    tmp->prev->next = tmp->next;
                }
            }
        tmp = tmp->next;
    }


int count(MusicalComposition* head) {
        MusicalComposition * tmp = head;
        int count = 0;
        while (tmp != 0) {
                ++count;
                tmp = tmp->next;
        }
        return count;
}

void print_names(MusicalComposition* head) {
        MusicalComposition * tmp = head;
        while (tmp != NULL) {
                printf("%s\n", tmp->name);
                tmp = tmp->next;
        }

}
int main(){
        int length;
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
        char name_for_push1[80];
        char author_for_push1[80];
        int year_for_push1;

        char name_for_push2[80];
        char author_for_push2[80];
        int year_for_push2;

        char name_for_push3[80];
        char author_for_push3[80];
        int year_for_push3;
fgets(name_for_push1, 80, stdin);
        fgets(author_for_push1, 80, stdin);
        fscanf(stdin, "%d\n", &year_for_push1);
        (*strstr(name_for_push1,"\n"))=0;
        (*strstr(author_for_push1,"\n"))=0;

        fgets(name_for_push2, 80, stdin);
        fgets(author_for_push2, 80, stdin);
        fscanf(stdin, "%d\n", &year_for_push2);
        (*strstr(name_for_push2,"\n"))=0;
        (*strstr(author_for_push2,"\n"))=0;

        fgets(name_for_push3, 80, stdin);
        fgets(author_for_push3, 80, stdin);
        fscanf(stdin, "%d", &year_for_push3);
        (*strstr(name_for_push3,"\n"))=0;
        (*strstr(author_for_push3,"\n"))=0;

        MusicalComposition* element_for_push1 = createMusicalComposition(name_for_push1, author_for_push1, year_for_push1);
        MusicalComposition* element_for_push2 = createMusicalComposition(name_for_push2, author_for_push2, year_for_push2);
        MusicalComposition* element_for_push3 = createMusicalComposition(name_for_push3, author_for_push3, year_for_push3);

        push(head, element_for_push1, element_for_push2, element_for_push3);
        int k;
        MusicalComposition* t = head;
        for(k=0; k<(length+3); ++k) {
                printf("%s %s %d\n", t->name, t->author, t->year);
                t=t->next;
        }

        return 0;
}
