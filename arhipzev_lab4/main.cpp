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

void Sort(MusicalComposition* head)
 {
 	for (MusicalComposition *i = head; i; i = i->next) {
 		for (MusicalComposition *j = head; j; j = j->next) {
 			if (strcmp(i->name,j->name)>0)
 			{
 				MusicalComposition r = *i;
 				i->name = j->name;
 				j->name = r.name;
 				i->author = j->author;
 				j->author = r.author;
 				i->year = j->year;
 				j->year = r.year;
 			}
 		}
 	}
 }

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
int count(MusicalComposition* head)
{
    MusicalComposition* current = head;
    int count = 0;
    while (current)
    {
        ++count;
        current = current->next;
    }
    return count;
}
void removeEl(MusicalComposition* head, char* name_for_remove) {
    MusicalComposition *tmp = (MusicalComposition*)malloc(sizeof(MusicalComposition));
    tmp = head;
    while (strcmp(tmp -> name, name_for_remove)) {
        tmp = tmp -> next;
    }
    if (count(head) == 1){
         tmp -> next = NULL;
         tmp -> prev = NULL;
          *head = *tmp;
          head->name =NULL;
          head->author=NULL;
          head->year=NULL;

    }else{
    if (tmp -> prev == NULL) {
        tmp = tmp -> next;
        tmp -> prev = NULL;
        *head = *tmp;
          removeEl(head, name_for_remove);
    }
    else if (tmp -> next == NULL) {
        tmp = tmp -> prev;
        tmp -> next = NULL;
          removeEl(head, name_for_remove);
    } else {
        tmp -> prev -> next = tmp -> next;
        tmp -> next -> prev = tmp -> prev;
          removeEl(head, name_for_remove);
    }
}}




void print_names(MusicalComposition* head)
{
    MusicalComposition* current = head;
    while (current)
    {
        printf("%s\n", current->name);
        current = current->next;
    }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
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

        Sort(head);
		print_names(head);


    return 0;

}
