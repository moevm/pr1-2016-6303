// Ilyashuk Danil 6303
//lab2



#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#define INPUTSIZE 3000 
#define TAGSIZE 20


typedef struct stack
{
	char * tag;
	struct stack* prevUnit;
}stack;

void push(stack** headUnit, char *tag);
void pop(stack** headUnit);
char* peek(stack* headUnit);
void freeStack(stack* headUnit);
char * getTag(char* tagPtr);
int sizeOfStack(stack* headUnit);


int main()
{
	char array[INPUTSIZE];
	char * tag;
	char * pretag;
	fgets(array, INPUTSIZE, stdin);
	stack* headUnit = NULL;
	pretag = strtok(array, "<");
	if (array[0] != '<')
		pretag = strtok(NULL, "<");
	while (pretag)
	{
		tag = getTag(pretag);

		if (tag[0] != '/')
		{
			if (strcmp(tag, "br") && strcmp(tag, "hr"))
			{
				push(&headUnit, tag);
			}
			else
			{
				free(tag);
			}
		}
		if (tag[0] == '/')
		{
			if (sizeOfStack(headUnit) && !strcmp(&tag[1], peek(headUnit)))
			{
				pop(&headUnit);
			}
			else
			{
				printf("wrong");
				freeStack(headUnit);
				return 0;
			}
		}
		pretag = strtok(NULL, "<");
	}

	if (!sizeOfStack(headUnit))
		printf("correct");
	else
		printf("wrong");
	freeStack(headUnit);
	return 0;
}

void push(stack** headUnit, char* tag)
{
	stack* temp = (stack*)malloc(sizeof(stack));
	temp->tag = tag;
	temp->prevUnit = *headUnit;
	*headUnit = temp;
}

void pop(stack** headUnit)
{
	stack* temp = *headUnit;
	char * ctemp = (*headUnit)->tag;
	*headUnit = (*headUnit)->prevUnit;
	free(temp);
	free(ctemp);
}

char* peek(stack* headUnit)
{
	return headUnit->tag;
}

void freeStack(stack* headUnit)
{
	stack* temp;
	char * ctemp;
	while (headUnit)
	{
		temp = headUnit;
		ctemp = headUnit->tag;
		headUnit = headUnit->prevUnit;
		free(temp);
		free(ctemp);
	}
}

char * getTag(char* tagPtr)
{
	char * tag = (char*)malloc(TAGSIZE * sizeof(char));
	int i = 0;
	while (tagPtr[i] != '>')
	{
		tag[i] = tagPtr[i];
		i++;
	}
	tag[i] = '\0';
	return tag;
}

int sizeOfStack(stack* headUnit)
{
	int size = 0;
	while (headUnit)
	{
		size++;
		headUnit = headUnit->prevUnit;
	}
	return size;
}
