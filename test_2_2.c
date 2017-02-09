#include "stdio.h"
#include "stdlib.h"

int main()
{
    int n, i, j;

    scanf("%d", &n);

    int** array = (int**)malloc(sizeof(int*)*n);
    for (i = 0; i < n; ++i)
        array[i] = (int*)malloc(sizeof(int)*n);

    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            array[i][j] = (i + j + 1);

    return 0;
}
