/***********************************************************
******Code for laboratory work #1
------------------------------------------------------------
******The program sorts array using qsort and finds zero using
******bsearch feom standart library. It calculates how much
******time program does its work using system call clock().
------------------------------------------------------------
******Created by Mikhail Sergeenkov on the 28th of February, 2017
******sergeenkov.michael@gmail.com
******github.com/Mishelles
************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define LEN 1000 /*array lenght*/

int funccmp(const void * x1, const void * x2);
bool findZero(int* array);

int main(int argc, char const *argv[]) {
  int search=0;
  int array[LEN];
  int i=0;
  clock_t time;
  clock_t start_time;
  clock_t end_time;
  for (i=0; i<LEN; ++i){
    scanf("%d", &array[i]);
  }
  qsort(array,LEN, sizeof(int), funccmp );
  start_time=clock();
  int * ptrItem = (int*)bsearch(&search, array, LEN, sizeof (int), funccmp);
  end_time=clock();
  if (ptrItem!=NULL){
    printf("exists\n");
  }else{
    printf("doesn't exist\n");
  }
  printf("%i\n", (int)(end_time-start_time));
  start_time=clock();
  if (findZero(array)==true){
    printf("exists\n");
  }else{
    printf("doesn't exist\n");
  }
  end_time=clock();
  printf("%i\n", (int)(end_time-start_time));
  return 0;
}

/*This function is used as an argument for
**qsort and bsearch
*/
int funccmp(const void * x1, const void * x2)
{
  return ( *(int*)x1 - *(int*)x2 );
}

/*This function searches for zero in array
**step by step
*/
bool findZero(int* array){
  bool flag=false;
  int i=0;
  for (i = 0; i < LEN; i++) {
    if (array[i]==0){
      flag=true;
      break;
    }
  }
  return flag;
}
