#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000

int funccmp( const void *x1, const void *x2){ //функция сравнения двух эл-тов
return (*(int*)x1 - *(int*)x2);
}

int comp (const int *a, const int *b)//компаратор для qsort
{
return *a - *b;
}



int main() {
  int i;
  int timeBeg1, timeBeg2, timeEnd1, timeEnd2;
  int key=0;//ключ для двоичного поиска
  int* arr=(int*)malloc(sizeof(int)*N);
  for (i=0;i<N;i++)//заполнение массива числами
    {
     scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int),(int(*)(const void *,const void *))comp); //сортировка массива через алгоритм быстрой сортировки
    timeBeg1 = clock(); //время начала поиска
    int *ptrItem=(int*) bsearch( &key, arr, 100, sizeof(int), funccmp);
    timeEnd1 = clock(); //время конца поиска

    if (ptrItem==NULL) {  //вывод результата двоичного поиска
    printf("doesn't exist\n");}
    else {
      printf("exists\n");}

    printf("%d\n",timeEnd1-timeBeg1);//вывод времени двоичного поиска

    int l = 0; //поиск 0 перебором
    timeBeg2 = clock();
    for (i=0;i<N;i++)
    {
        if (arr[i]==key)
        {
            l=1;
        }
    }
    timeEnd2 = clock();

    if (l==1)//вывод результата поиска перебором
    {
        printf("exists\n");
    }
    else
    {
        printf("doesn't exists\n");
    }
    printf("%d\n",timeEnd2-timeBeg2);//вывод времени поиска перебором
free(arr);
  return 0;
}
