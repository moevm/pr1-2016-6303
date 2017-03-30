//Ченцов Данил 6303//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define text_len 1001 //максимальная длина строки
#define word_size 31 //максимальная длина слова


int cmp_str(const void* p1, const void* p2) {//определение функции сравнения слов
    return (strcmp(*(char**) p1, *(char**) p2));
}


 int main() {
    char* str = (char*) malloc(word_size * sizeof(char));
    char* string = (char*) malloc(text_len * sizeof(char));

    fgets(string, text_len, stdin);
    scanf("%s", str);

    string[strlen(string)-1] = '\0';
    char** str_array = (char**) malloc(sizeof(char*) * 300);
    char* pch = strtok(string, " .");

    int len;
    for(len = 0; pch != NULL; len++) {//пока есть лексемы
        str_array[len] = pch;
        pch = strtok(NULL, " .");
}



 //сортировка//

qsort(str_array, len, sizeof(char*), cmp_str);




//двоичный поиск слова в массиве//


char * ptrItem = (char*) bsearch(&str, str_array, len, sizeof(char*), cmp_str);
if (ptrItem != NULL){
  printf("exists");
}
else{
  printf("doesn't exist");
}


  return 0;
}
