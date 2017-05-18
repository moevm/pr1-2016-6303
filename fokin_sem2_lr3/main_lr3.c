#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

#define DIR_SIZE 100
#define STR_SIZE 100
#define PATH_SIZE 1000

typedef struct letter
{
    char symbol;
    char path[PATH_SIZE + 1];
    int flag;
} letter;

int fullName (letter *letterPath, int length)
{
    for (int i = 0; i < length; ++i)
        if (!((letterPath + i)->flag))
            return 0;
    return 1;

}

void checkLetter (letter *letterPath, char *currDir, char *fileName, int length)
{
    for (int i = 0; i < length; ++i)
    {
        if (((letterPath + i)->symbol == *fileName) && !((letterPath + i)->flag))
        {
              *(fileName + strlen(fileName)) = '.';
              int currDir_len = strlen(currDir);
              strcat(currDir, "/");
              strcpy((letterPath + i)->path, strcat(currDir, fileName));
              (letterPath + i)->flag = 1;
              *(currDir + currDir_len) = '\0';
              break;
        }
    }
}

int viewDir (char *dirName, letter *letterPath, int length)
{
    char currDir[DIR_SIZE];
    strcpy(currDir, dirName);

    DIR *dir = opendir(currDir);
    struct  dirent *content = readdir(dir);

    if(dir)
        while(content)
        {
            if (content->d_type == 8)
            {
                char *fileName = strtok(content->d_name, ".");
                checkLetter(letterPath, currDir, fileName, length);
                if (fullName(letterPath, length))
                    return 0;
            }
            if ((content->d_type == 4) && strcmp(".", content->d_name) && strcmp("..", content->d_name))
            {
                int currDir_len = strlen(currDir);
                strcat(currDir, "/");
                strcat(currDir, content->d_name);
                viewDir(currDir, letterPath, length);
                *(currDir + currDir_len) = '\0';
            }
            content = readdir(dir);
        }
    closedir(dir);
    return 0;
}

int main ()
{
    char dirName[DIR_SIZE] = {'.', '\0'};
    char str[STR_SIZE];

    fgets(str, (STR_SIZE + 2), stdin);
    int length = (strlen(str) - 1);

    letter *letterPath = (letter*)malloc(length * sizeof(letter));
    for (int i = 0; i < length; ++i)
    {
        (letterPath + i)->symbol = *(str + i);
        (letterPath + i)->flag = 0;
    }

    viewDir(dirName, letterPath, length);

    for (int i = 0; i < length; ++i)
        printf("%s\n", (letterPath + i)->path);


    return 0;
}
