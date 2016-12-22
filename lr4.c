#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// Описание структуры MusicalComposition
typedef struct MusicalComposition
{
	char name[80];
	char author[80];
	int year;
	struct MusicalComposition* next;
	struct MusicalComposition* prev;		
} MusicalComposition;

// Создание структуры MusicalComposition

MusicalComposition* createMusicalComposition(char* name, char* author, int year)
{
	MusicalComposition* newMusicalComposition = (MusicalComposition*)malloc(sizeof(MusicalComposition));
	strcpy(newMusicalComposition->name, name);
	strcpy(newMusicalComposition->author, author);
	newMusicalComposition->year = year;
	newMusicalComposition->next = NULL;
	newMusicalComposition->prev = NULL;
	return 	newMusicalComposition;
}

// Функции для работы со списком MusicalComposition

MusicalComposition* createMusicalCompositionList(char** array_names, char** array_authors, int* array_years, int n)
{
	MusicalComposition* HeadComp = createMusicalComposition(array_names[0], array_authors[0], array_years[0]);
	MusicalComposition* PrevComp = HeadComp;
	int i;
	for (i=1; i<n; i++)
	{
		MusicalComposition* CurrentComp = createMusicalComposition(array_names[i], array_authors[i], array_years[i]);
		CurrentComp->prev = PrevComp;
		PrevComp->next = CurrentComp;
		CurrentComp->next = NULL;
		PrevComp = CurrentComp;
	}	
	return HeadComp;
}

void push(MusicalComposition* head, MusicalComposition* element)
{
	if (head == NULL)
	{
		head = element;
		return;
	}
	MusicalComposition* CurrentComp = head;
	while (CurrentComp->next != NULL)
	{
		CurrentComp = CurrentComp->next;	
	}
	CurrentComp->next = element;
	element->prev = CurrentComp;
}


void removeEl(MusicalComposition* head, char* name_for_remove)
{ 
//According to the requirements the function can't delete the head element
	if (head == NULL)
	{
		return;
	}

	MusicalComposition* CurrentComp = head;
	do
	{
		if (strcmp(CurrentComp->name, name_for_remove) == 0)
		{	
			MusicalComposition* prev = CurrentComp->prev;
			MusicalComposition* next = CurrentComp->next;
  			if (prev != NULL)
			{
    			prev->next = CurrentComp->next;
			}
  			if (next != NULL)
    		{
				next->prev = CurrentComp->prev;
			}
			MusicalComposition* DelComp = CurrentComp;
			CurrentComp = CurrentComp->next;
  			free(DelComp);
		}
		else 
		{
			CurrentComp = CurrentComp->next;
		}		
	} while (CurrentComp != NULL);
}
	
int count(MusicalComposition* head)
{
	int count = 0;
	MusicalComposition* CurrentComp = head;
	while (CurrentComp != NULL)
	{
		count++;
		CurrentComp = CurrentComp->next;
	}
	return count;
}

void print_names(MusicalComposition* head)
{
	MusicalComposition* CurrentComp = head;
	while (CurrentComp != NULL)
	{
		printf("%s\n", CurrentComp->name);
		CurrentComp = CurrentComp->next;
	}
}


int main(){
    int length;
    scanf("%d\n", &length);  

    char** names = (char**)malloc(sizeof(char*)*length);
    char** authors = (char**)malloc(sizeof(char*)*length);
    int* years = (int*)malloc(sizeof(int)*length);
	int i;
    for (i=0;i<length;i++)
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
