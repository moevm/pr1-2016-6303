#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void push(char ** stack, char * element,int* flag){   // Помещаем в СТЭК
    (*flag)++;
    strcpy(stack[*flag],element);
}
char *top(char ** stack,int* flag){
    return stack[*flag];
}
void pop(char ** stack,int* flag){ // Удаляем последний элемент СТЭКа
    (*flag)--;
}
int size_s(char ** stack,int* flag){ // Возвращает размер СТЭКа
    return *flag;
}
int empty_s(char ** stack,int* flag){ //     Возвращает 0 ,если стэк пуст
    if ((*flag) == -1){//Возвращает 1 ,если стэк не пуст
        return 0;
    }
    else{
        return 1;
    }
}
int main()
{

    char c,cup[80];
    int i;
    /*Выделение памяти под стэк*/
    char **tag;
    tag = (char**)malloc(100 * sizeof(char*));
        for (i = 0; i<100; i++){
                tag[i] = (char*)malloc(80 * sizeof(char));
        }
     /**/

    while ((c = getchar()) != EOF ){

        if (c == '<') {
                        scanf("%79[^>]>",cup); //Считываем ИМЯ тэга

                        if (strcmp(cup,"hr")  && strcmp(cup,"br") ){

                                if (cup[0] != '/'){ // Если тэг - открывающийся : заносим в стэк
                                                    push(tag,cup,&flag);
                                                    }
            else{
                    if (empty_s(tag,&flag) == 0){    // Если стэк пуст, то есть ЗАКРВАЮЩИЙСЯ  тэг не был открыт, то выход
                                printf("wrong");
                                return 0;
                                    }
                                else{
                                        if (strcmp(top(tag,&flag),cup+1) != 0){  // Если закрывающийся, не равен перед ним стоящему открывающемуся
                                                    printf("wrong");
                                                    return 0;
                                                                        }
                                                                        else{   // Если тэги совпадают
                                                                            pop(tag,&flag);
                                                                            }
                                        }
                }
                                                                    }
                    }
                                        }
    if (empty_s(tag,&flag) == 0){ // Если стэк пуст, то страницы ВАЛИДНА
        printf("correct");
    }
    else{
       printf("wrong");
    }
    free(tag);
}
