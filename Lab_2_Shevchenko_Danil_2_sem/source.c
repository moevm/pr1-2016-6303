// lab №2 "simulation of stack" by Shevchenko Danil, 6303 group
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack			// структура описывающая элемент стека
{
	int store_in_cell;		// хранимое значение
	struct stack * prev_cell; 	// указатель на следующий элемент стека (сверху->вниз)
} stack;

void push_cell_in_stack(stack * root_of_stack, int number); // добавление элемента в список

int pop_cell_from_stack(stack * root_of_stack);		    // удаление элемента из списка и возврат хранившегося значения

int top_cell_of_stack(stack * root_of_stack);	            // вывод значения верхнего значения списка

void free_stack(stack * root_of_stack);			    // очистка всей выделенной под стек памяти

int main()
{
	stack * root_of_stack = (stack*)malloc(sizeof(stack)); // создаем корень списка (не является элементом стека)
	root_of_stack->prev_cell = NULL;		       // задействуется только как основа, по сути -1 элемент списка
	int count_stack_cell = 0;			       // счетчик элементов в стеке
	char command[5];
	do
	{
		fgets(command, 5, stdin);			// считывание команды
		if (!strcmp(command, "push"))			
		{
			int number;				
			scanf("%d", &number);
			printf("ok\n");
			getchar();
			push_cell_in_stack(root_of_stack, number); // добавление ранее считанного числа в список (стек)
			++count_stack_cell;			   // увеличение счетчика элементов на 1
		}
		else if (!strcmp(command, "pop\n"))
		{
			if (!count_stack_cell)				   // если счетчик = 0, не существует элемента для удаления
			{
				printf("error\n");			   // ошибка и завершение работы
				free_stack(root_of_stack);		   // очистка памяти
				return 0;
			}
			printf("%d\n", pop_cell_from_stack(root_of_stack)); // удаление элемента и вывод удаленного числа
			--count_stack_cell;				    // уменьшение счетчика элементов на 1
		}
		else if (!strcmp(command, "top\n") && (count_stack_cell!=0))
		{
			printf("%d\n", top_cell_of_stack(root_of_stack)); // вывод значения верхнего элемента стека (if exist's)
		}
		else if (!strcmp(command, "size"))
		{
			printf("%d\n", count_stack_cell);		// вывод кол-ва элементов в стеке
			getchar();
		}
		else if (!strcmp(command, "exit"))			
		{
			printf("bye\n");				// выход из программы "легальным способом"
			free_stack(root_of_stack);			// очистка памяти
			return 0;
		}
		else
		{
			printf("error");				// если подана неверная команда, сообщение об ошибке
			free_stack(root_of_stack);			// очистка памяти и завершение из программы
			return 0;
		};
	} while (1);
	return 1;	// если каким-то образом бесконечный цикл был завершен, сообщение о серьезной ошибке и ненулевой код возврата
}

void push_cell_in_stack(stack * root_of_stack, int number)
{
	stack * created_cell = (stack*)malloc(sizeof(stack));			// создание нового элемента
	created_cell->store_in_cell = number;					// присвоение значения новому элементу
	created_cell->prev_cell = root_of_stack->prev_cell;			// внедрение элемента в начало списка
	root_of_stack->prev_cell = created_cell;
	return;
}

int pop_cell_from_stack(stack * root_of_stack)
{
	stack * poping_elem = root_of_stack->prev_cell;
	int poping_number = poping_elem->store_in_cell;				// сохранение значения удаляемого элемента
	root_of_stack->prev_cell = root_of_stack->prev_cell->prev_cell; 	// отвязывание удаляемого элемента
	free(poping_elem);							// очистка памяти удаляемого элемента
	return poping_number;							// возврат числа хранившегося в удаленном элементе
}

int top_cell_of_stack(stack * root_of_stack)
{
	return root_of_stack->prev_cell->store_in_cell;	// можно было реализовать просто указателем, без функции, но так понятнее
}

void free_stack(stack * root_of_stack)
{
	stack * buffer;						// буферный указатель структурного типа
	while (root_of_stack->prev_cell != NULL)
	{
		buffer = root_of_stack;			     // ввиду особенностей одностороннего списка, вынужденно
		while (buffer->prev_cell->prev_cell != NULL) // каждый раз доходим до конца списка и очищаем последний элемент
		{
			buffer = buffer->prev_cell;
		}
		free(buffer);
		buffer->prev_cell = NULL;
	}
}
