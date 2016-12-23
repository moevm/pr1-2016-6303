#include <stdio.h>
#include <stdlib.h>

void read(int *a, int *after, int *question)
{
  char ch;
  int i = 0;
  char* arr = (char*)malloc(100 * sizeof(char));
     while (((ch = getchar()) != '.') && (ch != '?') && (ch != ';'))
     {
        if (ch == '!')
        {
        *a = 1;
        break;
        }
     if (((ch != '\t') && (ch != '\n') && (ch != ' ')) || (i != 0))
     arr[i++] = ch;
     }
       
       if (*a == 0)
       if ((ch == '.') || (ch == ';'))
         {
           arr[i++] = ch;
           arr[i] = '\0';
           printf("%s\n", arr);
            (*after)++;
          }
       else
       (*question)++;
}
 
int main()
{
  int a = 0;
  int after = 0;
  int question = 0;
    while (a == 0)
    read(&a, &after, &question);
  printf("Количество предложений до %d и количество предложений после %d", (after + question), after);
return 0;
}
