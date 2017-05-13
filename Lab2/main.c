// Лабораторная работа №2 Куликов М.Л. гр 6303

#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX_SIZE 100

typedef struct Stack_tag {
  int data[STACK_MAX_SIZE];
  size_t size;
} Stack_t;

void push(Stack_t *stack, const int value) {
  if (stack->size >= STACK_MAX_SIZE) {
    exit(0);
  }
  stack->data[stack->size] = value;
  stack->size++;
}

int pop(Stack_t *stack) {
  if (stack->size == 0) {
    printf("error\n");
    exit(0);
  }
  stack->size--;
  return stack->data[stack->size];
}


int main(){
  Stack_t stack;
  stack.size = 0;
  char ch;
  while ((ch = getchar()) != EOF) {
    int number, temp1, temp2 = 0;
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
          scanf("%d", &number);
          push(&stack, number*sign);
          break;
    }
  }
    
if(stack.size == 1){
    printf("%d\n", pop(&stack));
 } else {
    printf("error\n");
 }

return 0;
}
