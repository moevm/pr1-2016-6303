#include "stdafx.h"
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

void push(stack* headUnit, char *tag);
void pop(stack* headUnit);
char* peek(stack* headUnit);
void freeStack(stack* headUnit);
char * getTag(char* tagPtr);


int main()
{
	char array[INPUTSIZE];
	char tagBr[] = "br";
	char tagHr[] = "hr";
	char * tag;
	char * pretag;
	fgets(array, INPUTSIZE, stdin);
	stack* headUnit = (stack*)malloc(sizeof(stack));
	headUnit->prevUnit = NULL;
	pretag = strtok(array, "<");
	if (array[0] != '<')
		pretag = strtok(NULL, "<");
	while(pretag)
	{
		tag = getTag(pretag);

		if (tag[0] != '/')
		{
			if (strcmp(tag, tagBr) && strcmp(tag, tagHr))
			{
				push(headUnit, tag);
				pretag = strtok(NULL, "<");
				continue;
			}
			else
			{
				free(tag);
			}
		}
		if (tag[0] == '/')
		{
			if (headUnit->prevUnit && !strcmp(&tag[1], peek(headUnit)))
			{
				pop(headUnit);
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
	if (!headUnit->prevUnit)
		printf("correct");
	else
		printf("wrong");
	freeStack(headUnit);
	return 0;
}

void push(stack* headUnit, char *tag)
{
	stack* temp = (stack*)malloc(sizeof(stack));
	temp->tag = tag;
	temp->prevUnit = headUnit->prevUnit;
	headUnit->prevUnit = temp;
}

void pop(stack* headUnit)
{
	stack* temp = (stack*)malloc(sizeof(stack));
	temp = headUnit->prevUnit;
	headUnit->prevUnit = headUnit->prevUnit->prevUnit;
	free(temp);
}

char* peek(stack* headUnit)
{
	return headUnit->prevUnit->tag;
}

void freeStack(stack* headUnit)
{
	stack* temp;
	while (headUnit)
	{
		temp = headUnit;
		headUnit = headUnit->prevUnit;
		free(temp);
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



