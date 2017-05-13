#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
	char tag[50];
	struct Stack * next;
}stack_t;

//Функции для управления стеком:

//*is_empty
//Определяет, пустой ли стек. Если да, то указатель на вершину - Null
int is_empty(stack_t ** top) {
	return *top == NULL;
}
//*Endis_empty



//*Push
//Добавление элемента в стек
void push(stack_t **top, char *tag)
{
	stack_t *tmp = (stack_t*)malloc(sizeof(stack_t));
	tmp->next = *top;
	strcpy(tmp->tag, tag);
	*top = tmp;
}
//*EndPush

//*Top
//Возвращает значение последнего элемента
char* top(stack_t **top) {
	if (!is_empty(top))
		return (*top)->tag;
	else
		return NULL;
}
//*EndTop

//*Pop
//Удаление элемента с вершины стека
void pop(stack_t **top) {
	stack_t *node;
	node = *top;
	*top = (*top)->next;
	free(node);
}
//*EndPop

int main() {
	stack_t *tags = NULL;
	char *buffer, checker, addslash[100], br[] = "br", hr[] = "hr";
	int i;
	buffer = (char *)malloc(sizeof(char) * 100);
	checker = getchar();
	while (checker != '\n')
	{

		while (checker != '<')
		{
		    if (checker == '\n')
            {
                if (top(&tags) == NULL)
                {
                    printf("correct\n");
                    return 0;
                }
                else
                {
                printf("wrong\n");
                return 0;
                }
            }
			checker = getchar();
		}
		i = 0;
		checker = getchar();
		while (checker != '>')
		{
			buffer[i] = checker;
			i++;
			checker = getchar();
		}
		buffer[i] = '\0'; //
		if ((strcmp(buffer, br) != 0) && (strcmp(buffer, hr) != 0) && (buffer[0] != '/'))
		{
			strcpy(addslash, "/");
			char *str;
			str = strcat(addslash, buffer);
			push(&tags, str);   //
		}
		else if (buffer[0] == '/' && (top(&tags) != NULL) &&(strcmp(top(&tags), buffer)==0))
			pop(&tags);			//
        else if (buffer[0] == '/' && (top(&tags) == NULL))
        {
            printf("wrong\n");
            return 0;
        }
		checker = getchar();
	}
	if (!is_empty(&tags)) printf("wrong\n");
		else printf("correct\n");
	return 0;

}

