#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#define SIZE 20

typedef struct List
{
  char **strings;
  int size;
  int max;
}List; 

void add(char *current_path, List *list, struct dirent *de)
{	
  int len = strlen(current_path);
  int log = 0;
  strcat(strcat(current_path, "/"), de->d_name);
  for (int i = 0; i < list->size; i++)	
    if ( strcmp(list->strings[i], current_path) == 0)
      log = 1;
  if (log != 1 && list->size < list->max)
  {
    strcpy(list->strings[list->size], current_path);
    list->size++;
    log = 0;
  }
  current_path[len] = '\0';
}

void print(List *list)
{
  for(int i=0; i < list->size; i++)
    printf("%s\n", (list->strings)[i]);
}

void list_dir(const char *startdir, char c, List *list)
{
  char current_path[500];
  strcpy(current_path,startdir);
  DIR *dir = opendir(current_path);
  struct  dirent *de = readdir(dir);
  if(dir)
    while(de)
    {
     if ( de->d_type == DT_REG && c == de->d_name[0] )
     {
	add(current_path, list, de);
     }
     else
     if(de->d_type == DT_DIR && 
       	 strcmp(".",de->d_name) && strcmp("..",de->d_name))
     { 
       int path_len = strlen(current_path); 
       strcat(strcat(current_path,"/"),de->d_name);
       list_dir(current_path, c, list);
       current_path[path_len] = '\0';
     }
     de = readdir(dir);
    }
  closedir(dir);
}

int main(int c, char **v, char **env)
{
  char *string = (char *)malloc(SIZE);
  List list;
  list.strings = (char **)malloc(SIZE*sizeof(char *));
  for (int i=0; i<SIZE; i++) 
    (list.strings)[i] = (char *)malloc(500);  
  list.size = 0;
  list.max = 0;
  fscanf(stdin,"%s", string);
  if(c==2)
  {
    for (int i=0; i < strlen(string); i++) 
    {
      list.max = i+1;
 	list_dir(v[1], string[i], &list);
    }
  } 
  else
  {
     for (int i=0; i < strlen(string); i++)
     {
	list.max=i+1;
	list_dir(".", string[i], &list);
     }
  }
  print(&list);
  free(string); 
  for (int i=0; i<20; i++) 
    free((list.strings)[i]); 
  return 0;
}
