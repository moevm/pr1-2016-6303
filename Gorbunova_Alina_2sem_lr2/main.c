/*
Лабораторная №2
Горбунова Алина
6303
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define N 500

 //определение структуры узел
typedef struct Stack_Node 
{
    char* value;
    struct Stack_Node *next;
} Stack_N;
 
 //функция добавления тега в стек
 //(создает новый узел -> указатель next на старый узел, 
 //указатель на вершину - на новый узел -> вершина - новый узел )
void push(Stack_N **head, char* value) 
{
Stack_N *tmp = malloc(sizeof(Stack_N));
    tmp->next = *head;
    tmp->value = value;
    *head = tmp;
}
 
 //функция удаления последнего добавленного тега из стека
void pop (Stack_N **head) 
{
    *head = (*head)->next;
    return;
}
 
 //функция возвращает последний добавленный в стек тег
char* peek( Stack_N* head) 
{
    return head->value;
}
 
 //функция вывoда элементов стека
void printStack(Stack_N* head) 
{
    printf("\n stack's elements:\n ");
    while (head) 
    {
        printf("%s ", head->value);
        head = head->next;
    }
}
 
 //функция подсчета элементов стека
size_t getSize(Stack_N *head) {
    size_t size = 0;
    while (head) {
        size++;
        head = head->next;
    }
    return size;
}

int main()
{
    char str[N+2];
    int control=1;
    Stack_N* head = (Stack_N*)malloc(sizeof(head));
    fgets(str, (N + 2), stdin);
	char* tag;
    char* op = strchr(str, '<');
    char* cl = strchr(str, '>');
    //функция strchr находит первое вхождение символа в строку и возвращает указатель на него или NULL
    while (cl)
    {
    	//открывающий тег
        if (*(op + 1) != '/')
           {
            tag = strtok((op + 1), ">");
            //функция strtok делит строку на лексемы, разделенные символом-разделителем
            if (strcmp(tag, "br")!=0 && strcmp(tag, "hr")!=0)
            //функция strcmp сравнивает поcимвольно две строки, если они равны возвращает 0
                push(&head, tag);
        	}
        //закрывающий тег
        else 
        {
        	if (getSize==1)
        	{
                control=0;
                break;
            }
        //функция сравнивает n символов двух строк, если они совпали возвращает 0 
        	if (!strncmp((op + 2), peek(head), (cl - op - 2)))
                pop(&head);
            else
            {
                control=0;
                break;
            }
        }
        op = strchr((cl + 1), '<');
        cl = strchr((cl + 1), '>');
    }
    if (getSize(head)!=1)
    control=0;

    if (control==1)
        printf("correct");
    else
        printf("wrong");
        
        free(head);
    return 0;
}