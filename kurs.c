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
  MusicalComposition * head;

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

void createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n) {
  head = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
  MusicalComposition *tmp = head;
  int i;
  for (i=1; i<n; i++) {
        MusicalComposition * pp = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
        tmp->next = pp;
        pp->prev = tmp;
        tmp = tmp->next;
  }
  return;
}

MusicalComposition * push( MusicalComposition* element) {
  MusicalComposition * tmp = head;
  if (tmp->next!=NULL){ 
        while ( tmp->next != NULL) {
                tmp = tmp->next;
        }
  }
  tmp->next = element;
  element->prev= tmp;
  element->next=NULL;
  return head;
}

void removeEl( char* name_for_remove){
  MusicalComposition *pp;
  pp=head;
  MusicalComposition *tmp;
  tmp=head;
  MusicalComposition* next;
  MusicalComposition* prev;
  while ( pp!=NULL){
        if (strcmp(pp->name, name_for_remove)==0) {
                tmp=head;
                while (*tmp->name!=*name_for_remove) {
                        tmp=tmp->next;
                }
                if (tmp==head) {
                        head=head->next;
                }
                else if(tmp->next==NULL) {
                        prev=tmp->prev;
                        prev->next=NULL;
                }
                else{
                        next=tmp->next;
                        prev=tmp->prev;
                        next->prev=prev;
                        prev->next=next;
                }
        }
        pp=pp->next;
   }
}

int count() {
  MusicalComposition * tmp = head;
  int count = 0;
  while (tmp != NULL) {
        ++count;
        tmp = tmp->next;
  }
  return count;
}

void print_names() {
  MusicalComposition * tmp = head;
  while (tmp != NULL) {
        printf("%s\n", tmp->name);
        tmp = tmp->next;
  }
  if(tmp==NULL) { printf("" );}

}

MusicalComposition * PUSH(MusicalComposition* element1, MusicalComposition* element2, MusicalComposition* element3) {
  MusicalComposition * tmp = head;
  int k=count();
  int schet=0;
  while(schet!=(k/2-1)) {
       tmp=tmp->next;
       ++schet;
  } 
  MusicalComposition* second = tmp->next ;
  tmp->next = element1;
  element1->prev=tmp;
  element1-> next = element2;
  element2->prev= element1;

  element2->next = element3;
  element3->prev= element2;
  element3->next=second;
  second->prev=element3;

  return head;
}



int main(){
  int length;
  scanf("%d\n", &length);

  char** names = (char**)malloc(sizeof(char*)*length);
  char** authors = (char**)malloc(sizeof(char*)*length);
  int* years = (int*)malloc(sizeof(int)*length);

  for (int i=0;i<length;i++) {
        char name[80];
        char author[80];

        fgets(name, 80, stdin);
        fgets(author, 80, stdin);
        fscanf(stdin, "%d\n", &years[i]);

        (*strstr(name,"\n"))=0;
        (*strstr(author,"\n"))=0;

        names[i] = (char*)malloc(sizeof(char*) * (strlen(name)+4));
        authors[i] = (char*)malloc(sizeof(char*) * (strlen(author)+4));

        strcpy(names[i], name);
        strcpy(authors[i], author);

   }
  createMusicalCompositionList(names, authors, years, length);

  char name_for_push1[80];
  char author_for_push1[80];
  int year_for_push1;

  char name_for_push2[80];
  char author_for_push2[80];
  int year_for_push2;char name_for_push3[80];
  char author_for_push3[80];
  int year_for_push3;

  char name_for_push[80];
  char author_for_push[80];
  int year_for_push;

  char name_for_remove[80];

  fgets(name_for_push, 80, stdin);
  fgets(author_for_push, 80, stdin);
  fscanf(stdin,"%d\n", &year_for_push);
  (*strstr(name_for_push,"\n"))=0;
  (*strstr(author_for_push,"\n"))=0;

  fgets(name_for_remove, 80, stdin);
  (*strstr(name_for_remove,"\n"))=0;

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

  MusicalComposition* element_for_push = createMusicalComposition(name_for_push, author_for_push, year_for_push);printf("%s %s %d\n", head->name, head->author, head->year);

  int k = count();
  printf("%d\n", k);

  PUSH(element_for_push1, element_for_push2, element_for_push3);

  int el;
  MusicalComposition* t = head;
  for(el=0; el<(length+3); ++el) {
        printf("%s %s %d\n", t->name, t->author, t->year);
        t=t->next;
  }

  k = count();
  printf("%d\n", k);

  push(element_for_push);

  k = count();
  printf("%d\n", k);

  removeEl( name_for_remove);
  print_names();

  k = count();
  printf("%d\n", k);

  return 0;

}
