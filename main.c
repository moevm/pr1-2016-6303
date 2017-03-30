#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpstr(const void* a, const void* b);

int main() {
    int c, i = 1;
    char input[1001];
    fgets(input, 1001, stdin);
    /* ! */ input[strlen(input) - 1] = '\0';
    for(c=0;input[c];c++)
        if((input[c]==' ') && (input[c+1] != ' '))
        i++;
    char* word, ** wordList;
    //double pointer array with the length of the number of words
    wordList = (char**) malloc(sizeof(char*) * i);
    //starts assigning each array to each word
    word = strtok(input, " .");
    c = 0;
    while(word != NULL) {
        wordList[c] = word;
        word = strtok(NULL, " .");
        c++;
    }
    /* sort array using qsort functions */
    qsort(wordList, i, sizeof(char*), cmpstr);
    char* key = (char*) malloc(31 * sizeof(char));
    char* exist;
    exist=NULL;
    scanf("%s", key);
    //searches for the needed word using bsearch
    exist = (char*) bsearch(&key, wordList, i, sizeof(char*), cmpstr);//и ищем нужное слово в массиве
    if(exist != NULL)
        printf("exists");
    else
        printf("doesn't exist");

    return 0;
}

int cmpstr(const void* a, const void* b) {//функция преобразования void* в char*
    return (strcmp(*(char**) a, *(char**) b));
}
