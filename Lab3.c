#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

//Определение констант
#define PATH_LEN 500
#define WRD_LEN 200
#define WordNum 100

//Функция обхода дерева директорий и файлов
void ArrPrint(char *curr_path, char** str_word, int *str_word_len)
{
    strcat(curr_path, "/");
    DIR * dir = opendir(curr_path);
    struct dirent *obj = readdir(dir);
    char file_path[PATH_LEN];
    if(dir)
    {
        while(obj)
            {
                if(obj->d_type == DT_DIR && strcmp(obj->d_name, ".") && strcmp(obj->d_name, ".."))
                /*d_name содержит начало символьного массива, дающего имя этой структуры каталога.
                Это имя завершается нулем и может содержать самое большее MAXNAMLEN символов.*/
                {
                    int pathLen;
                    pathLen=strlen(curr_path);
                    strcat(curr_path, obj->d_name);
                    ArrPrint(curr_path, str_word, str_word_len);
                    curr_path[pathLen] = '\0'; //"обрубание" части названия пути
                }
                if(obj->d_type == DT_REG && strstr(obj->d_name, ".txt")) //найден файл формата .txt
            {
                strcpy(file_path, curr_path);
                strcat(file_path, obj->d_name);
                FILE *f = fopen(file_path, "r"); //Открываем текстовый файл на чтение
                if(f)
                    {
                        fgets(str_word[*str_word_len], WRD_LEN, f);
                        (*str_word_len)++;
                        fclose(f);
                    }
            }
            obj = readdir(dir);
        }
    }
    closedir(dir);
}

int main()
{
    char path[PATH_LEN] = ".";
    int str_word_len = 0;
    char ** str_word = (char**)malloc(WordNum * sizeof(char*));
    for(int i = 0; i < WordNum; i++)
        str_word[i] = (char*)malloc(sizeof(char)*WRD_LEN);
    ArrPrint(path, str_word, &str_word_len);
    for(int i = 0; i < str_word_len; i++)
        for(int j = 0; j < str_word_len -i - 1; j++)
            if(atoi(str_word[j]) > atoi(str_word[j+1]))
            {
                char* str = str_word[j];
                str_word[j] = str_word[j + 1];
                str_word[j + 1] = str;
            }

        //Вывод на экран
    for(int i = 0; i < str_word_len; i++)
        printf("%s", str_word[i]);

        //Освобождение памяти
    for(int i = 0; i < WordNum; i++)
        free(str_word[i]);
    free(str_word);
return 0;
}
