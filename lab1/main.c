#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#define N 1000


int cmpval (const void * a, const void * b) {  //функция сравнения двух элементов массива
    return (*(int*)a-*(int*)b);
}


int main() {
    int arr[N];
    clock_t start, stop, timeB, timeQ;
    for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
    }

    start = clock();  
        for (int i = 0 ; i < N - 1; i++) { // сравнение двух соседних элементов 
            for (int j = 0 ; j < N - i - 1 ; j++) {  
                if(arr[j] > arr[j+1]) { // если они идут в неправильном порядке,
                    int tmp = arr[j];   // то меняем их местами
                    arr[j] = arr[j+1] ;
                    arr[j+1] = tmp;
          }
        }
    }   
  stop = clock();
  timeB = stop - start;

  start = clock();
  qsort(arr, N, sizeof(int), cmpval);
  stop = clock();
  timeQ = stop - start;
 
  for (int i = 0; i < N; i++) {
    printf("%d ", arr[i]);
  }
 printf("\n");
 
 printf("BubbleSort time = %d\n", timeB);
 printf("QuickSort time = %d\n", timeQ);
 return 0;
}
