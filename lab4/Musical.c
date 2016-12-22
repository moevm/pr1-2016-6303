#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct MusicalComposition
{
char *name;
char *author;
int year;
struct MusicalComposition* next;
struct MusicalComposition* prev;
} MusicalComposition;

MusicalComposition* head;

MusicalComposition* createMusicalComposition(char* name, char* author, int year);

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n);

void push(MusicalComposition* element);

void removeEl(char* name_for_remove);

int count();

void print_names();

int elementInList(char* element);
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
char *name_for_push =(char*)malloc(sizeof(char)*80);
char *author_for_push = (char*)malloc(sizeof(char)*80);
int year_for_push;

char *name_for_remove = (char*)malloc(sizeof(char)*80);

fgets(name_for_push, 80, stdin);
fgets(author_for_push, 80, stdin);
fscanf(stdin, "%d\n", &year_for_push);
(*strstr(name_for_push,"\n"))=0;
(*strstr(author_for_push,"\n"))=0;

MusicalComposition* element_for_push = createMusicalComposition(name_for_push, author_for_push, year_for_push);

fgets(name_for_remove, 80, stdin);
(*strstr(name_for_remove,"\n"))=0;

int k = count(head);
printf("%s %s %d\n", head->name, head->author, head->year);

printf("%d\n", k);
push(head, element_for_push);

k = count(head);
printf("%d\n", k);

removeEl(head, name_for_remove);
print_names(head);

k = count(head);
printf("%d\n", k);

free(names);
free(authors);
free(years);
return 0;

}
MusicalComposition* createMusicalComposition(char* name, char* author, int year)
{
  MusicalComposition *head = (MusicalComposition*)malloc(sizeof(MusicalComposition));
  head->name=name;
  head->author=author;
  head->year=year;
  head->next=NULL;
  head->prev=NULL;
  return head; 
}
                                                         
MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
  head = createMusicalComposition(array_names[0],array_authors[0],array_years[0]);
  MusicalComposition *ThisList = head;
  for (int i=1;i<n;++i)
  {
MusicalComposition *newList = createMusicalComposition(array_names[i],array_authors[i],array_years[i]);
        ThisList->next=newList;
        newList->prev=ThisList;
        ThisList=ThisList->next;
  }
  return head;
}

void push(MusicalComposition* element)
{
  MusicalComposition* test = head;
  MusicalComposition* teck = createMusicalComposition(element->name, element->author, element->year);
  if (head == NULL)
  {
    head=element;
  }
  else
  {
  while(test->next!=NULL)
    test=test->next;
  test->next=teck;
  teck->prev=test;
  }
}

void removeEl( char* name_for_remove)
{
<<<<<<< HEAD:Grechkov_lr4/Musical.c
MusicalComposition *ptr;
ptr=head;
MusicalComposition* next;
MusicalComposition* prev;
while (elementInList(name_for_remove)==1) {
ptr=head;
while (*ptr->name!=*name_for_remove) {
ptr=ptr->next;
}
if (ptr==head) {
head=head->next;
}
else if(ptr->next==NULL) {
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

int count()
=======
	MusicalComposition* test=head;
    while(tast->name!=name_for_remove && test->next!=NULL)
    	test=test->next;
    if(test->next != NULL && test->prev != NULL) 
     {
     test->prev->next = test->next;
     test->next->prev = test->prev;
     }
    else if(test->next == NULL) 
 	 {
     test->prev->next = NULL;
 	 } 
  	else if(test->prev == NULL) 
 	 {
         test->year=test->next->year;         // при удалении 
         test->name=test->next->name;         // первого элемента
	 test->author=test->next->author;     // делаем второй первым
	 test->next=test->next->next;        // и удаляем
	 test->next->prev=test;              // второй элемент
	 }
}	 

int count(MusicalComposition* head)
>>>>>>> 0fae85c741cbb61c7558253c79795e9d28f702e5:Musical.c
{
  MusicalComposition* test =head;
  int count=0;
  while(test!=NULL)
    {
      ++count;
      test=test->next;
    }
  return count;
}

void print_names()
{   
<<<<<<< HEAD:Grechkov_lr4/Musical.c
  MusicalComposition* test =head;
  while(test)
  {
    printf("%s\n",test->name);
    test=test->next;
  }
}
    int elementInList(char* element)
   {
    MusicalComposition *ptr;
    ptr=head;
    int flag=0;
    while (ptr!=NULL && flag==0) 
    {
    if (strcmp(ptr->name, element)==0)    
     {
    flag=1;
     }
    else
     {
    ptr=ptr->next;
     }
    }
    if (flag==1) 
     {
    return 1;
     }
    else
     {
    return 0;
     }
    }
=======
	MusicalComposition* test =head;
	while(test!=NULL)
	{
		printf("%s\n",test->name);
		test=test->next;
	}
}
>>>>>>> 0fae85c741cbb61c7558253c79795e9d28f702e5:Musical.c
