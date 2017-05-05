#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEXT_SIZE 1001 //макс размер текста
#define STR_SIZE 31 //макс размер слова
#define WORDS_COUNT 10 //начальное количество слов в массиве

int cmpstr(const void* a, const void* b) {//функция преобразования void* в char*
    return (strcmp(*(char**) a, *(char**) b));
}

int main() {
    int k = 1;
    char* str = (char*) malloc(STR_SIZE * sizeof(char));
    char* text = (char*) malloc(TEXT_SIZE * sizeof(char));
    fgets(text, TEXT_SIZE, stdin);//читаем текст
    scanf("%s", str);//читаем слово
    text[strlen(text)-1] = '\0';
    char** words_arr = (char**) malloc(sizeof(char*) * WORDS_COUNT);
    char* token = strtok(text, " .");
    size_t i;
    for(i = 0; token != NULL; i++) {//каждое слово заносим в массив
        if(i == WORDS_COUNT * k - 1) {//если массив заканчивается, увеличиваем его размер
            k++;
            words_arr = (char**) realloc(words_arr, WORDS_COUNT * k * sizeof(char*));
        }
        words_arr[i] = token;
        token = strtok(NULL, " .");
    }
    qsort(words_arr, i, sizeof(char*), cmpstr);//сортируем слова
    char* ptr = (char*) bsearch(&str, words_arr, i, sizeof(char*), cmpstr);//и ищем нужное слово в массиве
    if(ptr != NULL)
        printf("exists");
    else
        printf("doesn't exist");
    return 0;
}