/*********************************************************************
***Code for Lab2: HTML Validator
***Created by Mikhail Sergeenkov on 23rd of April, 2017
***GitHub: Mishelles
***E-mail: sergeenkov.michael@gmail.com
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define INPUT_STR_LEN 3000

//Функция для проверки валидности html страницы
bool checkTagsSequence(char *check_str);

//Функции для работы со стеком
int findTop(char **stack); //получение индекса вершины стека
void push(char **stack, char *data); // добавление элемента в стек
void pop(char **stack); //удаление вершины стека
char *top(char **stack); //получение вершины стека
bool stackIsEmpty(char **stack); //проверка стека на пустоту
char **initStack(); //инициализация стека

int main(int argc, char const *argv[])
{
  char *input_str = (char*)malloc(INPUT_STR_LEN * sizeof(char));

  fgets(input_str, INPUT_STR_LEN, stdin);

  fprintf(stdout, checkTagsSequence(input_str) ? "correct\n" : "wrong\n");

  free(input_str);

  return 0;
}

bool checkTagsSequence(char *check_str)
{
  char **tags_stack = initStack();
  bool inside_tag_flag = false;
  bool tag_is_closer = false;
  char tag[INPUT_STR_LEN];
  int tag_sym_counter = 0;

  for (int i = 0; i < INPUT_STR_LEN; ++i)
  {
    if (inside_tag_flag)
    {
      if(check_str[i] == '/')
      {
        tag_is_closer = true;
        continue;
      }
      else
      {
        tag[tag_sym_counter] = check_str[i];
        ++tag_sym_counter;
      }
    }
    if (check_str[i] == '<')
    {
      inside_tag_flag = true;
      tag_sym_counter = 0;
      memset(tag, 0, INPUT_STR_LEN);
    }
    else if(check_str[i] == '>')
    {
      inside_tag_flag = false;
       if ((strncmp(tag, "br", 2) != 0) &&
           (strncmp(tag, "hr", 2) !=0))
       {
        if (tag_is_closer)
        {
          if (strncmp(tag, top(tags_stack), INPUT_STR_LEN) == 0)
          {
            pop(tags_stack);
          }
          tag_is_closer = false;
        }
        else
        {
          push(tags_stack, tag);
        }
      }
    }
  }
  return stackIsEmpty(tags_stack) ? true : false;
  free(tags_stack);
}

//функция инициализации стека
char **initStack()
{
  char **stack = (char**)malloc(INPUT_STR_LEN * sizeof(char*));
  for (size_t i = 0; i < INPUT_STR_LEN; i++)
  {
    stack[i] = (char*)malloc(INPUT_STR_LEN * sizeof(char));
    memset(stack[i], 0, sizeof(char));
  }
  return stack;
}

//функция возвращает индекс вершины стека
int findTop(char **stack)
{
  int i;
  for (i = 0; i < INPUT_STR_LEN; ++i)
  {
    if (strlen(stack[i]) == 0) break;
  }
  return i - 1;
}

//функция для добавления элемента в стек
void push(char **stack, char *data)
{
  int top_index = findTop(stack);
  if (top_index == (INPUT_STR_LEN - 1))
  {
    exit(1); //stack overflow
  }
  else
  {
    ++top_index;
    strncpy(stack[top_index], data, INPUT_STR_LEN);
  }
}

//функция снятия элемента с вершины стека
void pop(char **stack)
{
  int top_index = findTop(stack);
  memset(stack[top_index], 0, INPUT_STR_LEN);
}

//функция возвращает вершину стека без снятия
char *top(char **stack)
{
  return stack[findTop(stack)];
}

//функция для проверки стека на пустоту
bool stackIsEmpty(char **stack)
{
  return strlen(stack[0]) == 0 ? true : false;
}
