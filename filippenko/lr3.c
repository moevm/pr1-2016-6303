#include <stdio.h>
#include <stdlib.h>

void read(int *temp, int *after, int *question)
{
  char symbol;
  int i = 0;
  char* arr = (char*)malloc(100 * sizeof(char));
     while (((symbol = getchar()) != '.') && (symbol != '?') && (symbol != ';'))
     {
        if (symbol == '!')
        {
        *temp = 1;
        break;
        }
     if (((symbol != '\t') && (symbol != '\n') && (symbol != ' ')) || (i != 0))
     arr[i++] = symbol;
     }
       
       if (*temp == 0)
       if ((symbol == '.') || (symbol == ';'))
         {
           arr[i++] = symbol;
           arr[i] = '\0';
           printf("%s\n", arr);
            (*after)++;
          }
       else
       (*question)++;
}
 
int main()
{
  int temp = 0;
  int after = 0;
  int question = 0;
    while (a == 0)
    read(&temp, &after, &question);
  printf("Количество предложений до %d и количество предложений после %d", (after + question), after);
return 0;
}
