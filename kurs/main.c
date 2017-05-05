#include <stdio.h>
#include <stdlib.h>
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

MusicalComposition* createMusicalComposition(char* name, char* author, int year) {
    MusicalComposition* song = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    song -> name = name;
    song -> author = author;
    song -> year = year;
    song -> next = NULL;
    song -> prev = NULL;
    return song;
}

// Функции для работы со списком MusicalComposition

MusicalComposition *createMusicalCompositionList(char **array_names, char **array_authors, int *array_years, int n) {
    MusicalComposition *head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
    MusicalComposition *prev = head;
    MusicalComposition *current;

    for (int i = 1; i < n; i++) {
        current = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
        current -> prev = prev;
        prev -> next = current;
        prev = current;
    }
    return head;
}


void push(MusicalComposition* head, MusicalComposition* element) {
    MusicalComposition *tmp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    tmp = head;
    while (tmp -> next != NULL) {
        tmp = tmp -> next;
    }
    tmp -> next = element;
    element -> prev = tmp;
}


void removeEl(MusicalComposition* head, char* name_for_remove) {
   MusicalComposition *tmp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    tmp = head;
    while (strcmp(tmp -> name, name_for_remove)) {
        tmp = tmp -> next;
    }
    if (tmp -> prev == NULL) {
        tmp = tmp -> next;
        tmp -> prev = NULL;
        *head = *tmp;
        }
        else if (tmp -> next == NULL) {
                tmp = tmp -> prev;
                tmp -> next = NULL;
            } else {
            tmp -> prev -> next = tmp -> next;
            tmp -> next -> prev = tmp -> prev;
        }
}


int count(MusicalComposition* head) {
    MusicalComposition *tmp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    tmp = head;
    int count = 1;
    while (tmp -> next != NULL) {
        tmp = tmp -> next;
        count++;
    }
    return count;
}


void print_names(MusicalComposition * head) {
    MusicalComposition *tmp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    tmp = head;
    while (tmp -> next != NULL) {
        printf("%s %d\n", tmp -> name, tmp->year);
        tmp = tmp -> next;
    }
    printf("%s %d\n", tmp -> name, tmp->year);
}


void sort(MusicalComposition* head)
{
    int cnt = count(head);
    int cen = cnt/2;


    MusicalComposition *tmp;
    MusicalComposition *a;

    int t=0;
    char  *n;
    char *s;

    tmp=head;
    a=tmp->next;



    for (int i=0; i<cen-1; i++){
        for (int j = 0; j<cen-1; j++){
          if((tmp->year)<(a->year)){

            n = tmp->name;
            tmp->name = a->name;
            a->name = n;


           s = tmp->author;
           tmp->author = a->author;
           a->author = s;


         t=tmp->year;
         tmp->year=a->year;
         a->year=t;
          }

          if ((tmp->next)&&(a->next)){
               tmp=tmp->next;
             a=a->next;}
        }

        tmp=head;
        a=tmp->next;

    }

    MusicalComposition *newhead = head;
    a=newhead->next;
    for (int i=0; i<cen; i++)  newhead=newhead->next;

    tmp=newhead;
    a=tmp->next;


    for (int i=0; i<cen-1; i++){
        for (int j = 0; j<cen-1; j++){
          if((tmp->year)>(a->year)){

            n = tmp->name;
            tmp->name = a->name;
            a->name = n;


           s = tmp->author;
           tmp->author = a->author;
           a->author = s;


         t=tmp->year;
         tmp->year=a->year;
         a->year=t;
          }

          if ((tmp->next)&&(a->next)){
               tmp=tmp->next;
             a=a->next;}
        }

        tmp=newhead;
        a=tmp->next;

    }
}


int main() {
    int length;
    scanf("%d\n", &length);

    char** names = (char**)malloc(sizeof(char*)*length);
    char** authors = (char**)malloc(sizeof(char*)*length);
    int* years = (int*)malloc(sizeof(int)*length);

    for (int i = 0; i < length; i++) {
        char name[80];
        char author[80];

        fgets(name, 80, stdin);
        fgets(author, 80, stdin);
        fscanf(stdin, "%d\n", &years[i]);

        (*strstr(name,"\n")) = 0;
        (*strstr(author,"\n")) = 0;

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
    (*strstr(name_for_remove,"\n")) = 0;

    printf("%s %s %d\n", head -> name, head -> author, head -> year);
    int k = count(head);

    printf("%d\n", k);
    push(head, element_for_push);

    k = count(head);
    printf("%d\n", k);

    removeEl(head, name_for_remove);
    print_names(head);

    

    k = count(head);
    printf("%d\n", k);

    printf("After sorting:\n" );

    sort(head);
    print_names(head);

   free(names);
   free(authors);
   free(years);
    return 0;
}
