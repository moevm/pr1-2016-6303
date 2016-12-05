#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct MusicalComposition MusicalComposition;
struct MusicalComposition{
    char *name;
    char *author;
    int year;
    MusicalComposition* next;
    MusicalComposition* prev;
};

MusicalComposition* createMusicalComposition(char* name, char* author, int year);

// Функции для работы со списком MusicalComposition

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n);
MusicalComposition * deleteHead(MusicalComposition* head);
int elementInList(MusicalComposition *head, char* element);
void push(MusicalComposition* head, MusicalComposition* element);
void removeEl(MusicalComposition* head, char* name_for_remove);
int count(MusicalComposition* head);
void print_names(MusicalComposition* head);

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

MusicalComposition* createMusicalComposition(char* name, char* author, int year){
    MusicalComposition *tmp;
    tmp=(MusicalComposition*)malloc(sizeof(MusicalComposition));
    tmp->name=name;
    tmp->author=author;
    tmp->year=year;
    return tmp;
}

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n){
    MusicalComposition *head, *ptr;
    head=(MusicalComposition*)malloc(sizeof(MusicalComposition));
    ptr=head;
    head->name=array_names[0];
    head->author=array_authors[0];
    head->year=array_years[0];
    for (int i = 1; i < n; ++i)
    {
        MusicalComposition* temp;
        temp=(MusicalComposition*)malloc(sizeof(MusicalComposition));
        temp->prev=ptr;
        temp->next=NULL;
        temp->name=array_names[i];
        temp->author=array_authors[i];
        temp->year=array_years[i];
        ptr->next=temp;
        ptr=ptr->next;
    }
    return head;
}

void push(MusicalComposition* head, MusicalComposition* element){
    MusicalComposition *ptr ,*temp;
    ptr=head;
    //ищем хвостовой элемент списка
    for (int i = 0; i < (count(head)-1); ++i)
    {
        ptr=ptr->next;
    }
    element->next=NULL;
    element->prev=ptr;
    ptr->next=element;
}

void removeEl(MusicalComposition* head, char* name_for_remove){
  MusicalComposition *ptr;
  ptr=head;
  MusicalComposition* next;
  MusicalComposition* prev;
  while (elementInList(head, name_for_remove)==1){
    ptr=head;
    while (*ptr->name!=*name_for_remove){
        ptr=ptr->next;
    }
    if (ptr->prev==NULL){
        *head=*deleteHead(head);
    }
    else if(ptr->next==NULL){
        prev=ptr->prev;
        prev->next=NULL;
        free(ptr);
    }
    else{
        next=ptr->next;
        prev=ptr->prev;
        next->prev=prev;
        prev->next=next;
        free(ptr);
    }
  }

}

int count(MusicalComposition* head){
    MusicalComposition *ptr;
    ptr=head;
    int count=0;
    do{
        ++count;
        ptr=ptr->next;
    }while (ptr!=NULL);
    return count;
}

void print_names(MusicalComposition* head){
    MusicalComposition *ptr;
    ptr=head;
    while (ptr!=NULL){    
    for (int i = 0; i < strlen(ptr->name); ++i)
      {
          putchar(ptr->name[i]);
      }  
      putchar('\n');
    ptr = ptr->next; 
  } 
}

int elementInList(MusicalComposition *head, char* element){
    MusicalComposition *ptr;
    ptr=head;
    int flag=0;
    while (ptr!=NULL){
        if (strcmp(ptr->name, element)==0){
            flag=1;
            break;
        }
        else{
            ptr=ptr->next;
        }
    }
    if (flag==1){
        return 1;
    }
    else{
        return 0;
    }
}

MusicalComposition * deleteHead(MusicalComposition* head) {
  MusicalComposition *temp;
  temp = head->next;
  temp->prev = NULL;
  free(head);   // освобождение памяти текущего корня
  return(temp); // новый корень списка
}

