// Лабораторная работа №2 Иванов Д.В. гр 6303
// main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackL			//Структура - односвязный список, на базе которого реализован стек
{
	int number;
	struct StackL *next;
} StackL;

int getSize(StackL *head);			//Функция для определения кол-ва элементов в стеке
void push(StackL **head, int number);		//Функция ждя добавления элемента в стек
void pop(StackL **head);			//Функция для удаления элемента из стека
void operation(char buff, StackL **head);	//Функция выбора арифметической операции
void plus(StackL **head);			//Функция сложения двух элементов
void minus(StackL **head);			//Функция вычитания двух элементов
void times(StackL **head);			//Функция умножения двух элементов
void divid(StackL **head);			//Функция деления двух эдементов

int main()
{
	StackL *head = NULL;			//Указатель на первый элемент стека
	char str[100];				//Массив для записи поданной строки
	fgets(str, 100, stdin);
	char *lexem = strtok(str, " ");
	while (lexem != NULL)
	{
		int numb=atoi(lexem);		//Конвертация строки в числовой вид
		if ((numb == 0) && (*lexem != '0'))	//Если конвертированная строка == 0, но сама строка не '0', значит строка содержит символ/слово (не цифру/число)
		{
			if (getSize(head) == 1)		//Проверка на достаточное кол-во элементов в стеке
			{
				printf("error");	//Завершение программы, если элеменов недостаточно
				return 0;
			}
			else
				operation(*lexem, &head);	//Вызов необходимой арифметической операции, если в стеке достаточное кол-во элементов
		}
		else
			push(&head, numb);		//Если  строка содержала число - запись числа в стек
		lexem = strtok(NULL, " ");
	}
	if (getSize(head) > 1)		//Проверка на кол-во элементов, оставшихся в стеке
		printf("error");
	else 
		printf("%d", head->number);
	return 0;
}


int getSize(StackL *head) 
{
	int size = 0;
	while (head) {			///Подсчёт кол-во элементов в стеке
		size++;
		head = head->next;
	}
	return size;
}

void push(StackL **head, int number)
{
	StackL *tmp = (StackL*)malloc(sizeof(StackL));
	tmp->next = *head;		//Добавление элемента в стек
	tmp->number = number;
	*head = tmp;
}

void pop(StackL **head)
{
	*head = (*head)->next;		//Удаление элемента из стека
}

void operation(char buff, StackL **head)
{
	switch (buff)			//Выбор необходимой арифметической операции
	{
		case '+':
			plus(head);
			break;
		case '-':
			minus(head);
			break;
		case '*':
			times(head);
			break;
		case '/':
			divid(head);
			break;
		default:
			break;
	}
}

void plus(StackL **head)
{
	int a, b;
	a = (*(head))->number;
	b = (*(head))->next->number;		//Сложение двух элементов, их удаление и запись результата в стек
	pop(head);
	pop(head);
	push(head, b + a);
}

void minus(StackL **head)
{
	int a, b;
	a = (*(head))->number;
	b = (*(head))->next->number;		//Вычитание двух элементов, их удаление и запись результата в стек
	pop(head);
	pop(head);
	push(head, b - a);
}

void times(StackL **head)
{
	int a, b;
	a = (*(head))->number;
	b = (*(head))->next->number;		//Перемножение двух элементов, их удаление и запись результата в стек
	pop(head);
	pop(head);
	push(head, b*a);
}

void divid(StackL **head)
{
	int a, b;
	a = (*(head))->number;
	b = (*(head))->next->number;		//Деление двух элементов, их удаление и запись результата в стек
	pop(head);
	pop(head);
	push(head, b / a);
}
