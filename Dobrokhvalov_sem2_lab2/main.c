#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data         	//описание структуры для работы со стеком
{
	int *arr;
	int size_of_arr;
}Data;

void push(Data *my_stack, int number)	//добавление элемента в стек
{
	my_stack->arr[my_stack->size_of_arr] = number;
	my_stack->size_of_arr++;
}

void action(Data *my_stack, char c)     //действие с последними элементами стекаи запись нового элемента
{
    my_stack->size_of_arr--;
	switch (c)
	{
    case '+':
        my_stack->arr[my_stack->size_of_arr-1] =
            my_stack->arr[my_stack->size_of_arr-1] + my_stack->arr[my_stack->size_of_arr];
        break;
    case '-':
        my_stack->arr[my_stack->size_of_arr-1] =
            my_stack->arr[my_stack->size_of_arr-1] - my_stack->arr[my_stack->size_of_arr];
        break;
    case '*':
        my_stack->arr[my_stack->size_of_arr-1] =
            my_stack->arr[my_stack->size_of_arr-1] * my_stack->arr[my_stack->size_of_arr];
        break;
    case '/':
        my_stack->arr[my_stack->size_of_arr-1] =
            my_stack->arr[my_stack->size_of_arr-1] / my_stack->arr[my_stack->size_of_arr];
        break;
    default:
        printf("Error");
        break;
	}
	my_stack->arr[my_stack->size_of_arr] = '\0';
}

int main()
{
	Data *my_stack = (Data *)malloc(sizeof(Data));   
	my_stack->arr = (int *)malloc(100*sizeof(int));
	my_stack->size_of_arr = 0;
	char input[100]; 				//поток ввода
	fgets(input, 100, stdin);
	char *str = strtok(input," ");			//поиск лексем в строке, считанной из потока ввода
    while (str!=NULL)
	{
		if (atoi(str))			        //преобразование строки в число
		{
			push(my_stack, atoi(str));	//добавление элемента в стек
		}
        else
        {
            if ( (strstr(str,"+")||strstr(str,"-")||strstr(str,"*")||strstr(str,"/"))
                && (my_stack->size_of_arr > 1) )
            {
                char c = str[0];
                action(my_stack, c);			//действия с двумя последними элементами стека, если это возможно
            }
            else
            {
                my_stack->size_of_arr++;
                break;
            }
        }
		str=strtok(NULL," ");
	}
	if (my_stack->size_of_arr == 1)
            printf("%d", my_stack->arr[my_stack->size_of_arr-1]);
    else printf("error");
	return 0;
}
