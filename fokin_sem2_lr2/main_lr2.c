/*
    Программа main_lr2.c (Л/р №2) определяет валидность кода html-страницы.

    By foksen98 02.04.2017 (Last update 13.04.2017).
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  максимальная длина входной строки
#define LENGTH 3000

//  структура элемента списка
typedef struct stack
{
    char* tag;
    struct stack* prev;
} stack;

//  функция добавляет в список структуру с именем последнего открывающего
void push (char* tag, stack** current)
{
    stack* next = (stack*)malloc(sizeof(stack));
    next->tag = tag;
    next->prev = *current;
    *current = next;
}

//  функция удаляет последний элемент списка
char* pop (stack** current)
{
    char* temp = (*current)->tag;
    stack* prev = *current;
    *current = (*current)->prev;
    free(prev);
    return temp;
}


//  функция извлекает значение последнего элемента списка
char* top (stack* current)
{
    return current->tag;
}

//  функция проверяет список на пустоту
stack* isEmpty (stack* current)
{
    return current->prev;
}

//  функция освобождает динамическую память (весь список)
void delete (stack* current)
{
    stack* temp;
    while (current->prev)
    {
        temp = current->prev;
        free(current);
        current = temp;
    }
    free(current);
}

int main()
{
    char str[LENGTH + 2];
    char *ptrOpen, *ptrClose, *tag;
    stack* current = (stack*)malloc(sizeof(stack));
    current->tag = "null";
    current->prev = NULL;

    fgets(str, (LENGTH + 2), stdin);

    ptrOpen = strchr(str, '<');
    ptrClose = strchr(str, '>');

    while (ptrOpen)
    {
        if (*(ptrOpen + 1) == '/')
            if (!strncmp((ptrOpen + 2), top(current), (ptrClose - ptrOpen - 2)))
                pop(&current);
            else
            {
                delete(current);
                printf("wrong\n");
                return 0;
            }
        else
        {
            tag = strtok((ptrOpen + 1), ">");
            if (strcmp(tag, "br") && strcmp(tag, "hr"))
                push(tag, &current);
        }
        ptrOpen = strchr((ptrClose + 1), '<');
        ptrClose = strchr((ptrClose + 1), '>');
    }

    //  если были закрыты все открывающие теги (осталась только голова списка),
    //  то выводим "correct"
    if (!current->prev)
        printf("correct\n");
    //  иначе "wrong"
    else
        printf("wrong\n");

    //  очищаем оставшуюся динамическую память
    delete(current);

    return 0;
}
