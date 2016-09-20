#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100;

char * get_name();
void print_str(char*);

int main() {
  char * input = get_name();
  char output[107] = "Hello, ";
  strcat(output, input);
  print_str(output);
}

char * get_name() { // * - указатель на массив
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

void print_str(char * output) {
  printf("%s\n", output);
}
