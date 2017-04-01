#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
	int store_in_cell;
	struct stack * prev_cell;
} stack;

void push_cell_in_stack(stack * root_of_stack, int number);

int pop_cell_from_stack(stack * root_of_stack);

int top_cell_of_stack(stack * root_of_stack);

void free_stack(stack * root_of_stack);

int main()
{
	stack * root_of_stack = (stack*)malloc(sizeof(stack));
	root_of_stack->prev_cell = NULL;
	int count_stack_cell = 0;
	char command[5];
	do
	{
		fgets(command, 5, stdin);
		if (!strcmp(command, "push"))
		{
			int number;
			scanf("%d", &number);
			printf("ok\n");
			getchar();
			push_cell_in_stack(root_of_stack, number);
			++count_stack_cell;
		}
		else if (!strcmp(command, "pop\n"))
		{
			if (!count_stack_cell)
			{
				printf("error\n");
				free_stack(root_of_stack);
				return 0;
			}
			printf("%d\n", pop_cell_from_stack(root_of_stack));
			--count_stack_cell;
		}
		else if (!strcmp(command, "top\n") && (count_stack_cell!=0))
		{
			printf("%d\n", top_cell_of_stack(root_of_stack));
		}
		else if (!strcmp(command, "size"))
		{
			printf("%d\n", count_stack_cell);
			getchar();
		}
		else if (!strcmp(command, "exit"))
		{
			printf("bye\n");
			free_stack(root_of_stack);
			return 0;
		}
		else
		{
			printf("error");
			free_stack(root_of_stack);
			return 0;
		};
	} while (1);
	return 1;
}

void push_cell_in_stack(stack * root_of_stack, int number)
{
	stack * created_cell = (stack*)malloc(sizeof(stack));
	created_cell->store_in_cell = number;
	created_cell->prev_cell = root_of_stack->prev_cell;
	root_of_stack->prev_cell = created_cell;
	return;
}

int pop_cell_from_stack(stack * root_of_stack)
{
	stack * poping_elem = (stack*)malloc(sizeof(stack));
	poping_elem = root_of_stack->prev_cell;
	int poping_number = poping_elem->store_in_cell;
	root_of_stack->prev_cell = root_of_stack->prev_cell->prev_cell;
	free(poping_elem);
	return poping_number;
}

int top_cell_of_stack(stack * root_of_stack)
{
	return root_of_stack->prev_cell->store_in_cell;
}

void free_stack(stack * root_of_stack)
{
	stack * buffer = (stack*)malloc(sizeof(stack));
	while (root_of_stack->prev_cell != NULL)
	{
		buffer = root_of_stack;
		while (buffer->prev_cell->prev_cell != NULL)
		{
			buffer = buffer->prev_cell;
		}
		free(buffer);
		buffer->prev_cell = NULL;
	}
}