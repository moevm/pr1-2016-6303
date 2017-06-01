#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char len[1002];
  char str[32];
  char arr[1000][31];
  int i=0;

  fgets(len, sizeof(len), stdin);
    *(strstr(len, "\n")) = '\0';
  fgets(str, sizeof(str), stdin);
  if (strstr(str, "\n"))
    *(strstr(str, "\n")) = '\0';

  char* ptr = strtok(len, " .");
  while (ptr)
  {
    strcpy(arr[i++], ptr);
    ptr = strtok(NULL, " .");
  }
    /*for (int g = 0; g < i; g++)
    printf("%s\n", arr[g]);*/

  qsort(arr, i, sizeof(char[31]), (int(*)(const void*, const void*)) strcmp);
  char* ptrstr = (char*)bsearch(str, arr, i, sizeof(char[31]), (int(*)(const void*, const void*)) strcmp);
  if (ptrstr)
    printf("exists\n");
  else
    printf("doesn't exist\n");
  return 0;
}
