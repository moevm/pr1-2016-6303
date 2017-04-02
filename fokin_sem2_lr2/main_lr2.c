/*
    Программа main_lr2.c (Л/р №2) определяет валидность кода html-страницы.
    Необходима проверка на наличие закрывающей скобки (">") в теге
    (в условии не сказано, но иначе "Failed test #22. Runtime error:").

    By foksen98 02.04.2017.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  максимальная длина входной строки
#define LENGTH 500

//  структура элемента списка
typedef struct bracket
{
    char* tag;
    struct bracket* prev;
} bracket;

//  функция освобождает динамическую память (весь список)
void delete (bracket* current)
{
    bracket* temp;
    while (current->prev)
    {
        temp = current->prev;
        free(current);
        current = temp;
    }
    free(current);
}

//  функция добавляет в список структуру с именем последнего открывающего
//  (но требующего закрытия) тега
bracket* add (char* tag, bracket* current)
{
    //  если тег не требует закрытия, возвращаем указатель на текущий
    //  (последний) элемент списка
    if (!strcmp(tag, "br") || !strcmp(tag, "hr"))
        return current;
    //  иначе создаем новый элемент списка с именем последнего открывающего
    //  тега и возвращаем указатель на него
    else
    {
        bracket* next = (bracket*)malloc(sizeof(bracket));
        next->tag = tag;
        next->prev = current;
        return next;
    }
}

//  функция проверяет, закрывает ли этот тег последний отрывающий тег из списка
bracket* check (char* tag, bracket* current)
{
    //  если имя закрывающего тега соответствует имени последнего
    //  открывающего тега, то удаляем последний элеменент списка и
    //  возвращаем указатель на предпоследний
    if (!strcmp(tag, current->tag))
    {
        bracket* temp = current->prev;
        free(current);
        return temp;
    }
    //  иначе освобождаем память всего списка и возвращаем NULL
    else
    {
        delete(current);
        return NULL;
    }
}

int main()
{
    char str[LENGTH + 2];
    char* ptr;
    char* temp;
    bracket* current = (bracket*)malloc(sizeof(bracket));
    current->tag = "null";
    current->prev = NULL;

    fgets(str, (LENGTH + 2), stdin);

    ptr = strstr(str, "<");
    //  проверка на наличие закрывающей скобки для открывающей
    //  (в данном случае строка "<tag1" считается валидной)
    if (!strstr(str, ">"))
        ptr = NULL;

    while (ptr)
    {
        //  если тег закрывающий, то вызываем функцию check() для проверки
        if (*(ptr + 1) == '/')
        {
            temp = (strstr(ptr, ">") + 1);
            current = check((strtok(ptr, ">") + 2), current);
            //  если функция check() вернула NULL, выводим "wrong"
            //  и завершаем программу
            if (!current)
            {
                printf("wrong\n");
                return 0;
            }
        }
        //  иначе вызываем функцию add() для добавления нового открывающего
        //  тега в список
        else
        {
            temp = (strstr(ptr, ">") + 1);
            current = add((strtok(ptr, ">") + 1), current);
        }
        ptr = strstr(temp, "<");
        //  проверка на наличие закрывающей скобки для открывающей
        //  (строка "<tag1><tag2></tag2></tag1" считается невалидной)
        if (!strstr(temp, ">"))
            ptr = NULL;
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
