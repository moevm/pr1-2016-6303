#include <stdio.h>
#include <stdlib.h>


void read(int *a, int *posle, int *vopros)
{
char ch;
int i = 0;
char* massiv = (char*)malloc(100 * sizeof(char));
  while (((ch = getchar()) != '.') && (ch != '?') && (ch != ';'))
  {
      if (ch == '!')
      {
        *a = 1;
        break;
      }

      if (((ch != '\t') && (ch != '\n') && (ch != ' ')) || (i != 0))
      massiv[i++] = ch;
  }

// засунуть знаки пр в конец предл
  if (*a == 0)

  if ((ch == '.') || (ch == ';'))
  {
    massiv[i++] = ch;
    massiv[i] = '\0';
    printf("%s\n", massiv);
    ++*posle;
  }
  else
  ++*vopros;
  }
 
int main()
{
int a = 0;
int posle = 0;//Эта переменная после компиляции без предложений с вопросами("?")
int vopros = 0;//количество "?"
while (a == 0)
read(&a, &posle, &vopros);
printf("Количество предложений до %d и количество предложений после %d", (posle + vopros), posle);
return 0;
}
