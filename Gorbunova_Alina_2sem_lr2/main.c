/*
������������ �2
��������� �����
6303
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define N 500

 //����������� ��������� ����
typedef struct Stack_Node 
{
    char* value;
    struct Stack_Node *next;
} Stack_N;
 
 //������� ���������� ���� � ����
 //(������� ����� ���� -> ��������� next �� ������ ����, 
 //��������� �� ������� - �� ����� ���� -> ������� - ����� ���� )
void push(Stack_N **head, char* value) 
{
Stack_N *tmp = malloc(sizeof(Stack_N));
    tmp->next = *head;
    tmp->value = value;
    *head = tmp;
}
 
 //������� �������� ���������� ������������ ���� �� �����
void pop (Stack_N **head) 
{
    *head = (*head)->next;
    return;
}
 
 //������� ���������� ��������� ����������� � ���� ���
char* peek( Stack_N* head) 
{
    return head->value;
}
 
 //������� ���o�� ��������� �����
void printStack(Stack_N* head) 
{
    printf("\n stack's elements:\n ");
    while (head) 
    {
        printf("%s ", head->value);
        head = head->next;
    }
}
 
 //������� �������� ��������� �����
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
    //������� strchr ������� ������ ��������� ������� � ������ � ���������� ��������� �� ���� ��� NULL
    while (cl)
    {
    	//����������� ���
        if (*(op + 1) != '/')
           {
            tag = strtok((op + 1), ">");
            //������� strtok ����� ������ �� �������, ����������� ��������-������������
            if (strcmp(tag, "br")!=0 && strcmp(tag, "hr")!=0)
            //������� strcmp ���������� ��c�������� ��� ������, ���� ��� ����� ���������� 0
                push(&head, tag);
        	}
        //����������� ���
        else 
        {
        	if (getSize==1)
        	{
                control=0;
                break;
            }
        //������� ���������� n �������� ���� �����, ���� ��� ������� ���������� 0 
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