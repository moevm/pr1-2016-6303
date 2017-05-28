#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

#define SIZE_OF_LIST 10
#define SIZE_OF_ONE_WAY 1000
#define SIZE_OF_STR 100

typedef struct ListOfWays
{
  char **ways;
  int size;
} ListOfWays;

int compare (char* way, ListOfWays *listofways)
{
    int foreach = 0;
    for (int j = 0; j < (listofways->size - 1); j++)
    {
        if (strcmp (listofways->ways[j], way) == 0)
            foreach++;
    }
    return foreach;
}

//функция поиска пути, принимает начальную директорию, букву для поиска,структуру списка использованных путей
//возвращает 0 - если файл не найден, 1 - если найден
int FoundWay(char* startDir, char letter, ListOfWays *listofways)
{
    char way[SIZE_OF_ONE_WAY];
    strcpy (way, startDir);
    DIR *dir = opendir (way);
    if (dir)
    {
         struct dirent *de = readdir (dir);
         while (de)
         {
           if (de->d_type == DT_REG && strstr (de->d_name, ".txt") && letter == de->d_name[0])
           {
                int waylen = strlen (way);
                strcat (way, "/");
                strcat (way, de->d_name);
                strcpy (listofways->ways[listofways->size], way);
                listofways->size++;
                if (!compare (way, listofways))
                {
                    printf ("%s\n", way);
                    closedir (dir);
                    return 1;
                }
                way[waylen] = '\0';
                closedir(dir);
                return 0;

          }
          else if (de->d_type == DT_DIR && strcmp(".", de->d_name)!=0 && strcmp("..", de->d_name)!=0 )
          {
                int waylen = strlen (way);
                strcat (way, "/");
                strcat (way, de->d_name);
                if (FoundWay (way, letter, listofways)==1)
                {
                    closedir(dir);
                    return 1;
                }
                way[waylen] = '\0';
          }
          de = readdir(dir);
        }
    }
    closedir(dir);
    return 0;
}

int main ()
{
  ListOfWays listofways;
  //создание структуры для хранения использованных путей к файлам ()в структуре: динамический массив указателей, его размер)
  //выделение памяти
  listofways.ways = (char **)malloc(SIZE_OF_LIST*sizeof(char *));
  for (int i=0; i<SIZE_OF_LIST; i++)
    (listofways.ways)[i] = (char *)malloc(SIZE_OF_ONE_WAY);
  listofways.size = 0;
  char str[SIZE_OF_STR];
  fgets (str, SIZE_OF_STR, stdin);
  //считывание строки и вызов функции поиска путей для каждой буквы
  for (int i = 0; i < (strlen(str)-1); i++)
  {
    FoundWay(".", str[i], &listofways);
  }
  //очищение памяти
  for (int i=0; i<SIZE_OF_LIST; i++)
   free((listofways.ways)[i]);
   free(listofways.ways);
  return 0;
}
