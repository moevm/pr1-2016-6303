#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int cmp(const void *a, const void *b) 
{
     return *(int*)a - *(int*)b;
 }

 int main() {
    int i, j;
    int N=1000;
    int arr1[N], arr2[N];
    //дл€ массива arr1  будем использовать метод  bubble sort, дл€ arr2 - функцию qsort
    double timebsort, timeqsort;
    //выбираем тип данных double  чтобы вывести врем€ в дол€х секунд 
    for(i = 0 ; i < N; i++) 
    { 
        scanf("%d", &arr1[i]);
    }
    //считываем элементы массива arr1
     for(i = 0 ; i < N; i++) 
    { 
        arr2[i]=arr1[i];
    }
    //копируем массив arr1 в масссив arr2
    
    timebsort = clock();
    //записываем в переменную timebsort врем€ до начала сортировки 
    for(i = 0 ; i < N - 1; i++) 
    { 
       // сравниваем два соседних элемента.
       for(j = 0 ; j <N - i - 1 ; j++) 
       {  
           if(arr1[j] > arr1[j+1]) 
           {           
              // если они идут в неправильном пор€дке, то мен€ем их местами. 
              int tmp = arr1[j];
              arr1[j] = arr1[j+1] ;
              arr1[j+1] = tmp; 
           }
        }
    }
     timebsort = (clock()-timebsort)/CLOCKS_PER_SEC;
     //отнимаем от текущего времени врем€ из time1, переводим его в секунды
     //—LOCKS_PER_SEC - константа котора€ представл€ет количество единиц процессорного времени в секунде
     
     timeqsort = clock();
     //записываем текущее врем€ в переменную timeqsort
      qsort(arr2, N, sizeof(int), cmp ); // вызываем функцию сортировки
       timeqsort = (clock()-timeqsort)/CLOCKS_PER_SEC;
       //отнимаем от текущего времени врем€ из timeqsort, переводим его в секунды
    for(i = 0 ; i < N; i++) 
    { 
    	//выводим отсортированный массив
        printf("%d ", arr2[i]);
    }
         printf("\n%.5f seconds\n", timebsort);
         printf("%.5f seconds\n", timeqsort);
     
 }