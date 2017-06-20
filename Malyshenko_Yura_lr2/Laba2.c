#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define STACK_MAX 100
typedef int I;

typedef struct Stack_tag
{
  I data[STACK_MAX];
  I size; // Размер типа выбирается таким образом, чтобы в него можно было записать максимальный размер теоретически возможного массива любого типа
   // количество элементов, и вместе с тем указатель на вершину стека
  // Вершина будет указывать на следующий элемент массива, в который будет занесено значение.
} Stack_t;

void push(Stack_t *stack, const I value)
{
  stack->data[stack->size] = value; //указатель на структуру
  stack->size++;
}


int pop(Stack_t *stack)
{
  stack->size--;
  return stack->data[stack->size];
}

int Size (Stack_t  *stack)
  {
  return  stack->size;
  }

int top(const Stack_t *stack)
{

    return stack->data[stack->size - 1];
}

int input(char n, Stack_t *stack)
{
  if (stack->size == 0 || stack->size == 1  )
  {
    return 1;
  }
 int x;
 int y;


if(Size(stack) != 0)
{
 x=top(stack);
 pop(stack);

 y=top(stack);
 pop(stack);
}
 int result;
 switch(n)
 {
 	case '+': { result = y+x; break; }
 	case '-': { result = y-x; break; }
 	case '*': { result = y*x;	break; }
 	case '/': { result = y/x; break; }
 }
 push(stack, result);
 return 0;
}


int main()
{
Stack_t stack;
stack.size=0;
char arr[100];
int tmp;
int i;
int control = 1;

fgets(arr, 100, stdin);
char* arrPtr = strtok(arr, " "); //разделение исходной строки arr на лексемы arrPtr, по пробелам

while(arrPtr != NULL)
{
  if(isdigit(*arrPtr))
      push(&stack, atoi(arrPtr));

      else

  if(strlen(arrPtr) > 1)
  {
      push(&stack, atoi(arrPtr));
  }

      else
  if(strlen(arrPtr) == 1)
  {
      if(input(*arrPtr, &stack) == 1)
      control = 1;
  }

  arrPtr = strtok(NULL, " \n");
}

if(Size(&stack) == 1)
  printf("%d\n", top(&stack));
else
{
  control = 1;
  printf("error");
  return 0;
}

return 0;
}
