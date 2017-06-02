#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <string.h> 
#include <dirent.h> 
#define PATHSIZE 500 
#define STRINGSIZE 200
#define STRINGCOUNT 100 


struct file
{
    int number;
    char string[STRINGSIZE];
};

void readFiles(char *currPath, struct file * files, int *index);
int compare(const void * number1, const void * number2);

int main() 
{ 
    char path[PATHSIZE] = "."; 
    int index = 0; 
    int i, j;
    struct file* files = (struct file*)malloc(STRINGCOUNT*sizeof(struct file));
    readFiles(path, files, &index); 
    qsort(files, index, sizeof(struct file), compare);
    for( i = 0; i < index; i++) 
        printf("%s\n", files[i].string);
    free(files);
    return 0; 
} 

void readFiles(char *currPath, struct file * files, int *index) 
{ 
    strcat(currPath, "/"); 
    DIR * dir = opendir(currPath); 
    struct dirent *obj = readdir(dir); 
    int pathLen;
    if(dir) 
    { 
        while(obj) 
        { 
            if(obj->d_type == DT_DIR && strcmp(obj->d_name, ".") && strcmp(obj->d_name, "..")) 
            { 
                pathLen = strlen(currPath); 
                strcat(currPath, obj->d_name); 
                readFiles(currPath, files, index); 
                currPath[pathLen] = '\0'; 
            } 
            if(obj->d_type == DT_REG && strstr(obj->d_name, ".txt")) 
            {  
                pathLen = strlen(currPath); 
                strcat(currPath, obj->d_name); 
                FILE *txt = fopen(currPath, "r"); 
                if(txt) 
                { 
                    
                    fscanf(txt,"%d" ,&files[*index].number);
                    rewind(txt);
                    fgets(files[*index].string, STRINGSIZE, txt);
                    (*index)++;
                } 
               currPath[pathLen] = '\0'; 
            } 
            obj = readdir(dir); 
        } 
    } 
    closedir(dir); 
}

int compare(const void * number1, const void * number2)
{
    return (*(int*)number1 - *(int*)number2);
}