#include <stdio.h>
#include <stdlib.h>
/*__*/
#include "get_name.h"

char* get_name() { // * - указатель на массив
  int c;
  int i = 0;
  //char * input = malloc(100); //работает так
  static char input[100]; /*и так тоже (static
    оставляет место в пямяти)*/
  while((c = getchar()) != EOF) {
          input[i] = c;
          i++;
  }
  input[i] = '\0'; //надо же как-то вывод завершить
  return input;
}
