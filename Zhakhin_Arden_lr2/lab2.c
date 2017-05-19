#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pushN(int *arr, int *sizeSt, int n)
{
  arr[*sizeSt] = n;
  *sizeSt = *sizeSt+1;
  printf("ok\n");
}

int pop(int *arr, int *sizeSt)
{
  if(*sizeSt != 0)
    {
      printf("%d\n", arr[*sizeSt-1]);
      arr[*sizeSt-1] = 0;
      *sizeSt = *sizeSt - 1;
      return 0;
    }
  else
  {
    printf("error");
    return 1;
  }
}

int top(int *arr, int *sizeSt)
{
  if(*sizeSt != 0)
  {
  printf("%d\n", arr[*sizeSt-1]);
  return 0;
  }
  else
  {
    printf("error");
    return 1;
  }
}

void size(int *sizeSt)
{
  printf("%d\n", *sizeSt);
}

void runAway()
{
  printf("bye");
}

int cmp(char *a)
{
  if (strcmp (a, "push")==0)
    return 1;
  if (strcmp (a, "pop\n")==0)
    return 2;
  if (strcmp (a, "top\n")==0)
    return 3;
  if (strcmp (a, "size\n")==0)
    return 4;
  if (strcmp (a, "exit\n")==0)
    return 5;
  else
    return 0;
  return 0;
}

int main()
{
  int array[100];
  int n;
  char command[100];
  char *arrayPtr[2];  //массив указателей на строки, в которых будут храниться слова из текста
  int j;
  int sizeSt = 0;
  for(j=0; j<100; j++)
  {
    fgets(command, 100, stdin);

    arrayPtr[0] = strtok(command, " "); // нулевому указателю присваеваеncz первое слово
    arrayPtr[1] = strtok(NULL, " "); //второе слово

    if(arrayPtr[1] != NULL)
    {
      n = atoi(arrayPtr[1]);
    }

    int var = cmp(arrayPtr[0]);

    switch (var)
    {
      case 1:
      {
        pushN(array, &sizeSt, n);
        break;
      }
      case 2:
      {
        if(pop(array, &sizeSt))
          return 0;
        break;
      }
      case 3:
      {
        if(top(array, &sizeSt))
          return 0;
        break;
      }
      case 4:
      {
        size(&sizeSt);
        break;
      }
      case 5:
      {
        runAway();
        return 0;
        break;
      }
      case 0:
      {
        printf("error");
        return 0;
        break;
      }
    }
    arrayPtr[0] = NULL;
    arrayPtr[1] = NULL;
  }
  return 0;
}
