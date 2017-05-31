#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List //односвязный список, на базе которого реализуется стек
{
	int a;
	struct List*  next;
} List;

void push(List** head, int a) //функция добавления элемента в стек
{
	List* temp = (List*)malloc(sizeof(List));

	temp->a = a;
	temp->next = *head;
	*head = temp;
}

void pop(List** head) //функция удаления элемента из стека
{
	List* last;

	last = *head;
	*head = (*head)->next;

	free(last);
}

int top(List* head) //функция возвращает верхний элемент стека
{
	return head->a;
}

void print(List* head) 
{
	while (head->next != NULL)
	{
		printf("%d ", head->a);
		head = head->next;
	}
	printf("%d ", head->a);
}

int size(List* head) //функция, определяющая размер стека
{
	int size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	return size;
}

void func(List** head, char c) //функция, выполняющая заданную пользователем команду
{
	int a, b;
	a = top(*head);
	pop(head);

	b = top(*head);
	pop(head);

	switch (c)
	{
	case '+': 
		push(head, (b + a)); 
		break;

	case '-': 
		push(head, (b - a));
		break;

	case '*':
		push(head, (b*a));
		break;

	case '/': 
		push(head, (b / a));
		break;

	default:
		printf("error");
	}
}

int main()
{
	List* head = NULL;
	char str[100];
	char* stroka;
	fgets(str, 100, stdin);
	stroka = strtok(str, " \n");
    int log=0; //логическая переменная, если log==0, то все хорошо, если log==1, то ошибка
    
	while(stroka)
	{
		if (atoi(stroka) != 0) //проверка является ли элемент числом
		{
			push(&head, atoi(stroka));
		}
		else
		{
			if (size(head) >= 2) //в стеке должно быть больше 2х элементов
			{
				func(&head, stroka[0]);
			}
			else
			{
				printf("error");
                log=1;
				break;
			}
		}
		stroka = strtok(NULL, " \n");
	}

    if(log==0)
    {
        if (size(head)>1) //в конце работы должно остаться одно число
	    {
		    printf("error");
	    }

	    else
	    {
	        printf("%d", top(head)); //печатаем результат
	    }
    }

return 0;
}