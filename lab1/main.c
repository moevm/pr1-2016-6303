#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cmp_str(const void * p1, const void * p2) //определение функции сравнения слов
    {
    return *(char*)p1 - *(char*)p2;
}


 int main(){


  char str[1000];
  fgets(str, 1001, stdin);
 

  char str_array [1000] [30];


  int len=0;


    char *pch = strtok (str," .\n"); //во втором параметре указаны разделители (пробел, точка, элемент переноса строки)
    
  while (pch != NULL) //пока есть лексемы
  {   
      strcpy(str_array[len], pch);
      pch = strtok (NULL, " .\n");
      len++;

  }



 //сортировка//

   qsort(str_array[0], len, 30, cmp_str);




//двоичный поиск слова в массиве//

char key[4]="str";

int * ptrItem = (int*) bsearch(key, str_array[0], len, 30, cmp_str);
if (ptrItem != NULL){
  printf("exists");
}
else{
  printf("doesn't exist");
}


  return 0;
 }
