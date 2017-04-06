#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void * x1, const void * x2)   // функция сравнения элементов массива
{
  return ( *(int*)x1 - *(int*)x2 );              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}

int main() {
  int *a ,end,start; // e,s переменные для подсчета времени
   a = (int* )malloc(1000*sizeof(int));
    for(int i = 0;i<1000;i++){ //считываем массив
        scanf("%d",&a[i]);
    }
    /*quicksort*/
    qsort(a, 1000, sizeof(int), compare);
    /**/

    /*find 0 Binary search|| times*/
    start = clock();
    int number = 0;
    int * ptrItem = (int*) bsearch(&number, a, 1000, sizeof (int), compare);
    end = clock();
    /**/


    /**/
    if (ptrItem != NULL){
        printf("exists\n");}
    else{
        printf("doesn't exist\n");}
    printf("%d",end-start);
    /**/


    /*find 0 Full search*/
    //bool Fd_Nm = false;
    int Fd_Nm = 0; // переменная 1 - наличие, 0 - отсутствие
    start = clock();
    for (int i = 0;i<1000;i++){
        if (a[i] == 0){
            /*Fd_Nm = true;*/Fd_Nm = 1;break;
        }
    }
    end = clock();
    if (Fd_Nm == 1){
         printf("exists\n");
    }else{
        printf("doesn't exist\n");
    }
    printf("%d",end - start);
    /**/
    free(a);
  return 0;
}
