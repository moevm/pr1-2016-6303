#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <string.h> 
#include <dirent.h> 
#define PATHSIZE 500 
#define STRINGSIZE 200
#define STRINGCOUNT 100 

void readFiles(char *currPath, char** strings, int *index); 

int main() 
{ 
    char path[PATHSIZE] = "."; 
    int index = 0; 
    int i, j;
    char ** strings = (char**)malloc(STRINGCOUNT * sizeof(char*)); 
    for(i = 0; i < STRINGCOUNT; i++) 
        strings[i] = (char*)malloc(sizeof(char)*STRINGSIZE); 
    readFiles(path, strings, &index); 
    for(i = 0; i < index; i++) 
        for(j = 0; j < index -i - 1; j++) 
            if(atoi(strings[j]) > atoi(strings[j+1])) 
            { 
                char* temp = strings[j]; 
                strings[j] = strings[j + 1]; 
                strings[j + 1] = temp; 
            } 
    for( i = 0; i < index; i++) 
        printf("%s\n", strings[i]);
    for(i = 0; i < STRINGCOUNT; i++)
        free(strings[i]);
    free(strings);
    return 0; 
} 

void readFiles(char *currPath, char** strings, int *index) 
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
                readFiles(currPath, strings, index); 
                currPath[pathLen] = '\0'; 
            } 
            if(obj->d_type == DT_REG && strstr(obj->d_name, ".txt")) 
            {  
                pathLen = strlen(currPath); 
                strcat(currPath, obj->d_name); 
                FILE *txt = fopen(currPath, "r"); 
                if(txt) 
                { 
                    fgets(strings[*index], STRINGSIZE, txt); 
                    (*index)++; 
                    fclose(txt); 
                } 
               currPath[pathLen] = '\0'; 
            } 
            obj = readdir(dir); 
        } 
    } 
    closedir(dir); 
}