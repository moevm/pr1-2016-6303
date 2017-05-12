#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACK_SIZE 1000
#define NAME_SIZE 30

int find(char** stack);
void push(char** stack, char* name,int* i);
void pop(char** stack,char* name, int* i);

int main()
{
	char** stack = (char**)malloc(sizeof(char*)*STACK_SIZE);
	char* br = "br";
	char* hr = "hr";
	int i = 0;	// номер тега в массиве 
	char c;
	scanf("%c",&c);
	while ((c != '\n')&&(!(i<0)))
	{
		if (c == '<')
		{
			char* arr = (char*)malloc(sizeof(char)*NAME_SIZE);
			int j =0;
			scanf("%c",&c);
			while((c !='>') && (c != '\n'))
			{
				arr[j] = c;
				++j;
				scanf("%c",&c);
			}
			if (c =='\n')
			{
				printf("wrong\n");		
				return 0;
			}
			arr[j] = '\0';
		
			if ((strcmp(br,arr) != 0)&&(strcmp(hr,arr) != 0))
			{
				if(arr[0]=='/')
				{
					pop(stack,arr,&i);
				}
				else 
				{
					push(stack,arr,&i);
				}
			}
			free(arr);
		}	

		scanf("%c",&c);
	}
	if(i == 0)
	{
		printf("correct\n");
	}
	else printf("wrong\n");
	free(stack);
	return 0;
}

int find(char** stack)
{	
	int i =0;
	while(stack[i] !=NULL ){ ++i;}
	return i;
}

void push(char** stack, char* name,int* i)
{
	int number = find(stack);
	stack[number] = (char*)malloc(sizeof(char)*NAME_SIZE);
	strcpy(stack[number],name);
	(*i)++;
}

void pop(char** stack,char* name,int* i)
{
	int number = find(stack)-1;
	if(number>=0)
	{
	char s[31] ="/";
	strcat(s,stack[number]);
	if (!strcmp(s,name))
	{
		free(stack[number]);
		(*i)--;
	}
	}
}
