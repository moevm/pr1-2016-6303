#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_STACK_SIZE 100
#define LINE_SIZE 20

#define FUNC_PUSH "push"
#define FUNC_POP "pop"
#define FUNC_TOP "top"
#define FUNC_SIZE "size"
#define FUNC_EXIT "exit"

typedef struct Stack {
    int* data;
    int size;
} Stack;

void init(Stack* stack);

int top(Stack* stack, int* val);

int pop(Stack* stack, int* val);

void push(Stack* stack, int data);

int main() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    init(stack);

    char* line = (char*) malloc(LINE_SIZE * sizeof(char));
    char* token;
    int val = 0;

    while(fgets(line, LINE_SIZE, stdin) != NULL) {
        token = strtok(line, " \n");
        if(strcmp(token, FUNC_PUSH) == 0) {
            if(sscanf(strtok(NULL, " \n"), "%d", &val)) {
                push(stack, val);
                printf("ok\n");
            } else {
                printf("error\n");
                return 0;
            }
        } else if(strcmp(token, FUNC_POP) == 0) {
            if(pop(stack, &val)) {
                printf("%d\n", val);
            } else {
                printf("error\n");
                return 0;
            }
        } else if(strcmp(token, FUNC_TOP) == 0) {
            if(top(stack, &val)) {
                printf("%d\n", val);
            } else {
                printf("error\n");
                return 0;
            }
        } else if(strcmp(token, FUNC_SIZE) == 0) {
            printf("%d\n", stack->size);
        } else if(strcmp(token, FUNC_EXIT) == 0) {
            printf("bye\n");
        }
    }
}

int top(Stack* stack, int* val) {
    if(stack->size == 0) {
        return 0;
    } else {
        *val = stack->data[stack->size - 1];
        return 1;
    }
}

void init(Stack* stack) {
    stack->data = (int*) malloc(INITIAL_STACK_SIZE * sizeof(int));
    stack->size = 0;
}

int pop(Stack* stack, int* val) {
    if(stack->size == 0) {
        return 0;
    } else {
        *val = stack->data[--stack->size];
        return 1;
    }
}

void push(Stack* stack, int data) {
    stack->data[stack->size++] = data;
}