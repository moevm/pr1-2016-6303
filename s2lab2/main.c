#include <stdio.h>
#include <stdlib.h>

#define STACK_LEN 100

typedef struct Stack {
  int data[STACK_LEN];
  size_t size;
} t_Stack;




void push(t_Stack *stack, int value) {
  if (stack->size >= STACK_LEN)
    exit(0);
  else{
    stack->data[stack->size] = value;
    stack->size++;
  }
}

int pop(t_Stack *stack) {
  if (stack->size == 0) {
    printf("error\n");
    exit(0);
  }
  else{
  stack->size--;
  return stack->data[stack->size];
}
}


int main(){

  t_Stack stack;
  stack.size = 0;
  char ch;

  while ((ch = getchar()) != EOF) {
    int arg, temp1, temp2 = 0;
    int sign = 1;
    switch(ch) {
      case ' ' :
      case '\n' :
          break;

      case '+' :

          push(&stack, pop(&stack) + pop(&stack));
          break;

      case '*' :

          push(&stack, pop(&stack) * pop(&stack));
          break;

      case '/' :

          temp1 = pop(&stack);
          temp2 = pop(&stack);
          if(temp1==0){
              printf("error\n");
              exit(0);
          }
          push(&stack, temp2 / temp1);
          break;

      case '-' :

          ch = getchar();
          if ((ch == ' ') || (ch == EOF)) {
              temp1 = pop(&stack);
              temp2 = pop(&stack);
              push(&stack, temp2 - temp1);
              break;
          } else {
              sign = -1;
          }

      default :
          ungetc(ch, stdin);
          scanf("%d", &arg);
          push(&stack, arg*sign);
          break;
    }
  }

if(stack.size == 1)
    printf("%d\n", pop(&stack));
  else
    printf("error\n");


return 0;
}
