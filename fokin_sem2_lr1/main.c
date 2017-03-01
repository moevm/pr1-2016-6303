#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int comparator_qsort (const void* x1, const void* x2)
{
    return strcmp(*((char**)x1), *((char**)x2));
}

int comparator_bsearch (const void* x1, const void* x2)
{
    return strcmp((char*)x1, *((char**)x2));
}

int main()
{
    int i = 0;
    char arr[1002];
    char str[32];
    char* arr_ptr[1000];
    char* ptr = NULL;
    char* ptr_str = NULL;

    fgets(arr, sizeof(arr), stdin);
    if (strstr(arr, "\n"))
        *(strstr(arr, "\n")) = '\0';
    fgets(str, sizeof(str), stdin);
    if (strstr(str, "\n"))
        *(strstr(str, "\n")) = '\0';

    ptr = strtok(arr, " .");
    while (ptr)
    {
        arr_ptr[i++] = ptr;
        ptr = strtok(NULL, " .");
    }

    qsort(arr_ptr, i, sizeof(char*), comparator_qsort);
    ptr_str = (char*)bsearch(str, arr_ptr, i, sizeof(char*), comparator_bsearch);
    if (ptr_str)
        printf("exists\n");
    else
       printf("doesn't exist\n");

    return 0;
}
