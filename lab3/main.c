#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

#define DIR_SIZE 100
#define STR_SIZE 100
#define PATH_SIZE 1000



typedef struct letter {
    char character;
    char path[PATH_SIZE+1];
    int flag;
} letter;



int dir_traveller (char *dir_name, letter *letter_path, int n) { //рекурсивная функция обхода директории

    char current_dir[DIR_SIZE];
    strcpy(current_dir, dir_name);

    DIR *dir = opendir(current_dir);
    struct  dirent *obj = readdir(dir);

    if(dir)  // проверка существования директории
        while (obj) {

            if (obj->d_type == DT_REG) {    //файл
                char *file_name = strtok(obj->d_name, ".");
                letter_locating_check(letter_path, current_dir, file_name, n);
                if (str_collect_check(letter_path, n))
                    return 0;
            }

            if ((obj->d_type == DT_DIR) && strcmp(".", obj->d_name) && strcmp(obj->d_name, "..")) { //вложенная директория           
                int current_dir_len = strlen(current_dir);
                strcat(current_dir, "/");
                strcat(current_dir, obj->d_name);
                dir_traveller(current_dir, letter_path, n);
                *(current_dir + current_dir_len) = '\0';
            }
            obj = readdir(dir);
        }
    closedir(dir);
    return 0;
}



void letter_locating_check(letter *letter_path, char *current_dir, char *file_name, int n) {
    for (int i = 0; i < n; i++) {

        if (((letter_path + i)->character == *file_name) && !((letter_path + i)->flag)) {
              *(file_name + strlen(file_name)) = '.';
              int current_dir_len = strlen(current_dir);
              strcat(current_dir, "/");
              strcpy((letter_path + i)->path, strcat(current_dir, file_name));
              (letter_path + i)->flag = 1;
              *(current_dir + current_dir_len) = '\0';
              break;
        }
    }
}



int str_collect_check(letter *letter_path, int length) {
    for (int i = 0; i < length; i++)
        if (!((letter_path + i)->flag)) {
            return 0;
        }
    return 1;
}




int main () {
    char dir_name[DIR_SIZE] = {'.', '\0'};
    char str[STR_SIZE];

    fgets(str, (STR_SIZE + 2), stdin);
    int length = (strlen(str) - 1);

    letter *letter_path = (letter*)malloc(length * sizeof(letter));

    for (int i = 0; i < length; i++) {
        (letter_path + i)->character = *(str + i);
        (letter_path + i)->flag = 0;
    }

    dir_traveller(dir_name, letter_path, length);

    for (int i = 0; i < length; i++) {
        printf("%s\n", (letter_path + i)->path);
    }

    free(letter_path);
      
    return 0;
}