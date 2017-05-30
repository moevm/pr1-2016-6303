#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdbool.h>

int dirTraveler(const char *startDir, char symbol, char *check)
{
  char path[1000];
  strcpy(path, startDir);
  DIR *dir=opendir(path);
  if(dir)
  {
  	struct dirent *de = readdir(dir);
    while(de)
    {
      if(de->d_type == DT_REG && strstr(de->d_name,".txt") && de->d_name[0] == symbol)
  		{
  			int path_len = strlen(path);
        strcat(path, "/");
        strcat(path, de->d_name);
        if(strstr(check, path))
        {
          return 0;
        }
        else
        {
          strcat(check, path);
          printf("%s\n", path);
          path[path_len] = '\0';
          closedir(dir);
          return 1;
        }
  		}
      if(de->d_type == DT_DIR && 0!=strcmp(".", de->d_name) && 0!=strcmp("..", de->d_name))
      {
        int path_len = strlen(path);
        strcat(path, "/");
        strcat(path, de->d_name);
        if(dirTraveler(path, symbol, check)==1)
          return 1;
        path[path_len] = '\0';
      }
      de = readdir(dir);
    }
  }
  else
  {
    printf("error");
    return 0;
  }
  closedir(dir);
  return 0;
}

int main()
{
  char arr[11];
  char check[1000]="";
  fgets(arr, 10, stdin);
  for (int i = 0; i < (strlen(arr)-1); i++)
  {
    if(dirTraveler(".", arr[i], check)==0)
    {
      printf("error\n");
      return 0;
    }
  }
	return 0;
}
