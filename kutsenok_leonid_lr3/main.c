#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define PRIMARY_STRING_LEN 50

int scan(char* input, int* current_size_max);

int counter_before = 0;//счетчик предложений до вывода
int counter_after = 0;//счетчик предложений после вывода

int main(int argc, char const *argv[]) {
  int current_size_max = PRIMARY_STRING_LEN;
  int result;//возвращаемое значение функции scan
  char* input = (char*)malloc(PRIMARY_STRING_LEN*sizeof(char));
  while(1) {
    result = scan(input ,&current_size_max);
    if(result == 2 || result == 3) {
      break;
    } else if (result == 0) {
      printf("%s\n", input);
    }
  }
  free(input);
  printf("Количество предложений до %d и количество предложений после %d", counter_before, counter_after);
  return 0;
}

int scan(char* input, int *current_size_max) {
  int current_size = 0;
  char c;
  while (1) {
    if(current_size == (*current_size_max - 1)) {//если массив закончился
      *current_size_max += 50;
      input = (char*)realloc(input, *current_size_max);//выделяем еще памяти
    }
    c = getchar();
    switch(c) {
      case 46: //точка
      case 59: //точка с запятой
        input[current_size] = c;
        input[current_size + 1] = '\0';
        counter_before++;
        counter_after++;
        return 0;//все хорошо
      case 63:
        counter_before++;
        return 1; //ничего не произошло, был вопрос
      case -1: //EOF
        return 3;
      case 9: //TAB
        break;
      default:
        if(current_size == 0 && (c == 32 /* пробел */ || c == 10 /*  новая строка */)) {
          break;
        }
        input[current_size] = c;
        current_size++;
        break;
      }
    if(strcmp(input, "Dragon flew away!") == 0) {
      return 2;//конец
    }
  }
}
