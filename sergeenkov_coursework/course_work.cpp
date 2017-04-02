#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct MusicalComposition MusicalComposition;
struct MusicalComposition {
        char *name;
        char *author;
        int year;
        MusicalComposition* next;
        MusicalComposition* prev;
};
MusicalComposition* head;
MusicalComposition* createMusicalComposition(char* name, char* author, int year);

// Функции для работы со списком MusicalComposition

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n);
MusicalComposition * deleteHead(MusicalComposition* head);
int elementInList(char* element);
void push(MusicalComposition* element);
void removeEl( char* name_for_remove);
int count();
void print_names();
void sortByAuthor();
void swap(MusicalComposition* a, MusicalComposition* b);
void print_authors();

int main(){
        int length;
        scanf("%d\n", &length);

        char** names = (char**)malloc(sizeof(char*)*length);
        char** authors = (char**)malloc(sizeof(char*)*length);
        int* years = (int*)malloc(sizeof(int)*length);

        for (int i=0; i<length; i++)
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
        head = createMusicalCompositionList(names, authors, years, length);
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
        int k = count();

        /printf("%d\n", k);
        push(element_for_push);

        k = count();
        printf("%d\n", k);

        removeEl(name_for_remove);
        print_names();

        k = count();
        printf("%d\n", k);
        sortByAuthor();
        print_authors();

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
        MusicalComposition  *ptr;
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

void push(MusicalComposition* element){
        MusicalComposition *ptr,*temp;
        if (head==NULL){
          head=element;
        }
        else{
        ptr=head;
        //ищем хвостовой элемент списка
        while(ptr->next!=NULL){
          ptr=ptr->next;
        }
        if (ptr==head){
          head=element;
        }
        else{
        element->next=NULL;
        element->prev=ptr;
        ptr->next=element;
      }
    }
}

void removeEl( char* name_for_remove){
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

int count(){
        MusicalComposition *ptr;
        ptr=head;
        int count=0;
        while (ptr!=NULL){
                ++count;
                ptr=ptr->next;
        }
        return count;
}

void print_names(){
        MusicalComposition *ptr;
        ptr=head;
        while (ptr!=NULL) {
                for (int i = 0; i < strlen(ptr->name); ++i)
                {
                        putchar(ptr->name[i]);
                }
                putchar('\n');
                ptr = ptr->next;
        }
}

int elementInList(char* element){
        MusicalComposition *ptr;
        ptr=head;
        int flag=0;
        while (ptr!=NULL) {
                if (strcmp(ptr->name, element)==0) {
                        flag=1;
                        break;
                }
                else{
                        ptr=ptr->next;
                }
        }
        if (flag==1) {
                return 1;
        }
        else{
                return 0;
        }
}

void sortByAuthor(){
        MusicalComposition* current;
        MusicalComposition* next;
        if (head!=NULL){
        current=head;
        next=current->next;
        int len=count();
        for(int i=0; i<len; ++i) {
                current=head;
                next=current->next;
                for(int j=0; j<len-i-1; ++j) {
                        if (strcmp(current->author, next->author)<0)
                                swap(current, next);
                        current=current->next;
                        next=next->next;
                }
        }
      }
}

void swap(MusicalComposition* a, MusicalComposition* b) {
        if (a->prev==NULL) {
                MusicalComposition* temp=(MusicalComposition*)malloc(sizeof(MusicalComposition));
                temp->name=b->name;
                temp->author=b->author;
                temp->year=b->year;
                b->name=a->name;
                b->author=a->author;
                b->year=a->year;
                a->name=temp->name;
                a->author=temp->author;
                a->year=temp->year;

       }
        else{
                a->next = b->next;
                b->prev = a->prev;

                if(a->next != NULL) {
                        a->next->prev = a;
                }
                if(b->prev != NULL) {
                        b->prev->next = b;
                }
                b->next = a;
                a->prev = b;
        }
        return;
}

void print_authors(){
        MusicalComposition *ptr;
        ptr=head;
        while (ptr!=NULL) {
                for (int i = 0; i < strlen(ptr->author); ++i)
                {
                        putchar(ptr->author[i]);
                }
                putchar('\n');
                ptr = ptr->next;
        }
}
