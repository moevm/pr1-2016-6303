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
void FM(char** tag){
    int q;
     for (q = 0; q<100; q++){
                           free(tag[q]);}
                                            free(tag);
}
int main()
{
    int flag = -1;

    /*ввод из файл*/
    //freopen("input.txt","r",stdin);

    char c,cup[80];
    int i,k;
    /*Выделение памяти под стэк*/
    char **tag;
    tag = (char**)malloc(100 * sizeof(char*));
        for (i = 0; i<100; i++){
                tag[i] = (char*)malloc(80 * sizeof(char));
        }
     /**/
    char *string = (char*)malloc(3000 * sizeof(char));
    gets(string);
   for( i= 0;i<strlen(string);i++){
    c = string[i];
        if (c == '<') {
                        k=0;

                        while((cup[k] = string[i+k+1]) != '>')k++;
                        cup[k] = '\0';

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
                                                    free(string);
                                                    FM(tag);
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
    FM(tag);
    free(string);
}
