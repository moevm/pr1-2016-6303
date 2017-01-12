#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void chitka(int *q, int *ttz, int *vop); 

int main()
{    
    int q = 0;
    int ttz = 0; //количество знаков : и ;
    int vop = 0; //количество знаков ?
    while (q == 0)
    chitka(&q, &ttz, &vop);  //вызов функции
    printf("Количество предложений до %d и количество предложений после %d", (ttz + vop), ttz);
    return 0; 
}

void chitka (int *q, int *ttz, int *vop)
{
    char c;
    char* result;
    result = (char*) malloc (200 * sizeof(char));   //выделили память
    int i = 0;
    while (((c = getchar()) != '.') && (c != ';') && (c != '?')) //считывать символы пока не дойдем до . ; ? 
    {
        if ((c != '\t') && (c != '\n') && (c != ' ') || (i != 0))  //если табуляция новая строка или пробел
        {
        result[i++] = c; //запишем символ в массив
        }
        if (c == '!')  
        {
            *q = 1;
            break;
        }
    }
    if (*q == 0)
        if((c == ';') || (c == '.'))
        {
            result[i++] = c; //дозаписать в массив . и ;
            result[i] = '\0'; //записать в конец символ конца предложения
            printf("%s\n", result);
            ++*ttz; 
        }
        else
            ++*vop; 
}
