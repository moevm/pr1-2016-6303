#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int flag = -1;

void push(char ** stack, char * element){   // Помещаем в СТЭК
    flag++;
    strcpy(stack[flag],element);
}
void pop(char ** stack){ // Удаляем последний элемент СТЭКа
    flag--;
}
int size_s(){ // Возвращает размер СТЭКа
    return flag;
}
int empty_s(){ //     Возвращает 0 ,если стэк пуст
    if (flag == -1){//Возвращает 1 ,если стэк не пуст
        return 0;
    }
    else{
        return 1;
    }
}
int main()
{
    char c,tag[80];
    int i;
    /*Выделение памяти под стэк*/
    char **stack;
    stack = (char**)malloc(100 * sizeof(char*));
        for (i = 0; i<100; i++){
                stack[i] = (char*)malloc(80 * sizeof(char));
        }
     /**/
    while ((c = getchar()) != EOF ){

        if (c == '<') {
                        scanf("%79[^>]>",tag); //Считываем ИМЯ тэга

                        if (strcmp(tag,"hr") && strcmp(tag,"br")){

                                if (tag[0] != '/'){ // Если тэг - открывающийся : заносим в стэк
                                                    push(stack,tag);
                                                    }
            else{
                    if (empty_s() == 0){    // Если стэк пуст, то есть ЗАКРВАЮЩИЙСЯ  тэг не был открыт, то выход
                                printf("wrong");
                                return 0;
                                    }
                                else{
                                        if (strcmp(stack[flag],tag+1) != 0){  // Если закрывающийся, не равен перед ним стоящему открывающемуся
                                                    printf("wrong");
                                                    return 0;
                                                                        }
                                                                        else{   // Если тэги совпадают
                                                                            pop(stack);
                                                                            }
                                        }
                }
                                                                    }
                    }
                                        }
    if (empty_s() == 0){ // Если стэк пуст, то страницы ВАЛИДНА
        printf("correct");
    }
    else{
       printf("wrong");
    }
}
