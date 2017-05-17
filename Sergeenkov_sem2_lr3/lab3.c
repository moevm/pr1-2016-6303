#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define ADD_DIR "add/"
#define MUL_DIR "mul/"
#define ADD_NAME "add"
#define MUL_NAME "mul"
#define ROOT_PATH "./Dataset/"
#define FILE_EXTENSION ".txt"

#define ADD_FLAG 0
#define MUL_FLAG 1

#define MAX_PATH_LEN 3000
#define MAX_DIR_NAME 3

//Рекурсивная функция для выполнения арифметических операция в директориях
long long dirCalculator(char *path, const char *operation);

int main(int argc, char const *argv[])
{
  char path[MAX_PATH_LEN];
  strcat(path, ROOT_PATH);
  DIR *directory = opendir(path);

  //Проверка существования директории
  if (!directory)
  {
    fprintf(stdout, "Incorrect path\n");
    return 0;
  }

  struct dirent *current;
  while (current = readdir(directory))
  {
    if (!strncmp(current->d_name, MUL_NAME, MAX_DIR_NAME))
      fprintf(stdout, "%lld\n", dirCalculator(path, MUL_DIR));
    if (!strncmp(current->d_name, ADD_NAME, MAX_DIR_NAME))
        fprintf(stdout, "%lld\n", dirCalculator(path, ADD_DIR));
  }

  closedir(directory);

  return 0;
}

long long dirCalculator(char *path, const char *operation)
{
  int path_len = strlen(path);
  int operation_flag = ADD_FLAG;
  if(!strcmp(operation, MUL_DIR))
    operation_flag = MUL_FLAG;
  //Если умножение, то 1, если сложение, то 0
  long long result = operation_flag;
  //Проверка на превышение максимальной длины пути
  if ((path_len + MAX_DIR_NAME + 1) > MAX_PATH_LEN)
  {
    fprintf(stdout, "Path length limit exceeded\n");
    return 0;
  }

  strncat(path, operation, MAX_DIR_NAME + 1);
  DIR *dir = opendir(path);
  struct dirent *current;
  while (current = readdir(dir))
  {
    //Подсчет чисел из файла, если встречен файл
    if (strstr(current->d_name, FILE_EXTENSION))
    {
      strncat(path, current->d_name, path_len + MAX_DIR_NAME);
      FILE * file = fopen(path, "r");
      int number;
      while(fscanf(file, "%d", &number) > 0)
        operation_flag ? (result *= number) : (result += number);
      path[path_len + MAX_DIR_NAME + 1] = '\0';
      fclose(file);
    }
    if(!strcmp(current->d_name, MUL_NAME))
        operation_flag ? (result *= dirCalculator(path, MUL_DIR)) : (result += dirCalculator(path, MUL_DIR));
    if(!strcmp(current->d_name, ADD_NAME))
        operation_flag ? (result *= dirCalculator(path, ADD_DIR)) : (result += dirCalculator(path, ADD_DIR));
    }
  closedir(dir);
  path[path_len] = '\0';
  return result;
}
