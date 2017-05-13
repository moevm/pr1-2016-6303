#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackTag{
  char tag[100][80];
  size_t size;
}Stack_t;

void push(Stack_t *stack, char *tag_push) {
  stack->size++;
  strcpy(stack->tag[stack->size], tag_push);
}

const char * pop(Stack_t *stack){
  stack->size--;
  return stack->tag[stack->size+1];
}

int main() {
  Stack_t head;
  head.size=-1;
  char c;
  char cur_tag[80];
  char temp_tag[80];
  while ((c = getchar()) != EOF ){
    if (c == '<') {
      scanf("%79[^>]>",cur_tag);
      if (strcmp(cur_tag,"hr") && strcmp(cur_tag,"br")){
        if(cur_tag[0] != '/'){
          push(&head, cur_tag);
        }else{
          if (head.size ==-1){
            printf("wrong");
            return 0;
          }else{
          	strcpy(temp_tag, pop(&head));
            if(strcmp(temp_tag,cur_tag+1)!=0){
              printf("wrong");
              return 0;
            }
          }
        }
      }
    }
  }
  if (head.size == -1){
    printf("correct");
  }
  else{
    printf("wrong");
  }
}
