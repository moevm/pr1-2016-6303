#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACK_SIZE 1000
#define NAME_SIZE 20

int find(char** stack, char* name, int n);
void push(char** stack, char* name, int number);
void removeEl(char** stack, int number);

int main()
{
	char** stack = (char**)malloc(sizeof(char*)*STACK_SIZE);
	char* br = "/br";
	char* hr = "/hr";
	int i = 0;	// номер тега в массиве 
	int k;
	char c;
	scanf("%c",&c);
	while(c != '\n')
	{
		if (c == '<')
		{
			stack[i] = (char*)malloc(sizeof(char)*NAME_SIZE);
			char* arr = (char*)malloc(sizeof(char)*NAME_SIZE);
			int j =0;
			scanf("%c",&c);
			if (c !='/')
			{
				arr[j] = '/';
				++j;
			}
			while((c !='>') && (c != '\n'))
			{
				arr[j] = c;
				++j;
				scanf("%c",&c);
			}
			if (c =='\n')
			{
				printf("wrong\n");		// если тег будет оборван на середине
				return 0;
			}
			arr[j] = '\0';
		
			if ((strcmp(br,arr) != 0)&&(strcmp(hr,arr) != 0))
			{
				k = find(stack, arr, i);
				if(k == i)
				{
					push(stack,arr,i);
					++i;
				}
				else if(i-1 == k)
				{
					removeEl(stack,i);
					free(stack[i]);
					--i;
				}
				else
				{
					printf("wrong\n");
					return 0;
				}
				free(arr);
			}
		}	

		scanf("%c",&c);
	}
	free(stack);
	if (i == 0)
	{
		printf("correct\n");
	}
	else printf("wrong\n");
	return 0;
}

int find(char** stack, char* name, int n)
{
	int i;
	for(i=0;i<n;++i)
	{
		if(strstr(name,stack[i]) != NULL)
		{
			break;
		}
	}
	return i;
}

void push(char** stack, char* name, int number)
{
	strcpy(stack[number],name);
}

void removeEl(char** stack, int number)
{
	stack[number]='\0';
}