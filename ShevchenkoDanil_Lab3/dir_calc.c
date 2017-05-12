//#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

int sizeOfWay = 100;

const char mul[5] = {"mul/"};
const char add[5] = {"add/"};

enum operations
{
  ADD,
  MULTIPLIED
};

long long int DirMulAdd(char * way, const char * operation);

int main()
{
  char * way = (char*)malloc(sizeof(char)*sizeOfWay);
  strcat(way, "./");
  DIR *dir;
  dir = opendir(way);
  if(!dir)
  {
    printf("Dir on this way %s doesn't root\n", way);
    return 0;
  }
  struct dirent *entry;
  while( entry = readdir(dir) )
  {
    if(!strcmp(entry->d_name, "mul"))
      printf("> Result is: %lli\n", DirMulAdd(way, mul));
    if(!strcmp(entry->d_name, "add"))
      printf("> Result is: %lli\n", DirMulAdd(way, add));
  }
  closedir(dir);
  free(way);
  return 0;
}

long long int DirMulAdd(char * way, const char * operation)
{
  char opFlag = ADD;
  if(!strcmp(operation, mul))
    opFlag = MULTIPLIED;
  int wayLen = strlen(way);
  long long int fileNum = opFlag;
  DIR *dir;
  if(wayLen > (sizeOfWay-40))
  {
    sizeOfWay+=100;
    way = (char*)realloc(way, sizeof(char)*sizeOfWay);
  }
  strcat(way, operation);
  struct dirent *entry;
  dir = opendir(way);

  while (entry = readdir(dir))
  {
    if(strstr(entry->d_name, ".txt"))
    {
      char * buf = &entry->d_name[strlen(entry->d_name)-4];
      if(!strcmp(buf, ".txt"))
      {
        strcat(way,entry->d_name);
        FILE * file = fopen(way, "r");
        int bufNum;
        while(fscanf(file, "%d", &bufNum) > 0)
        {
          if(opFlag)
            fileNum *= bufNum;
          else
            fileNum += bufNum;
        }
        way[wayLen+4] = '\0';
        fclose(file);
      }
    }

    if(!strcmp(entry->d_name, "mul"))
    {
      if(opFlag)
        fileNum *= DirMulAdd(way, mul);
      else
        fileNum += DirMulAdd(way, mul);
    }
    if(!strcmp(entry->d_name, "add"))
    {
      if(opFlag)
        fileNum *= DirMulAdd(way, add);
      else
        fileNum += DirMulAdd(way, add);
    }
  }
  closedir(dir);
  way[wayLen] = '\0';
  return fileNum;
}
