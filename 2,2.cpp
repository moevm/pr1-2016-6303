#include <stdio.h>
#include <stdlib.h>


int main()
{
    int a;
    scanf("%d", &a);
    int ** arr = (int**)malloc(a*sizeof(int*));
    for(int i = 0; i < a; i++)
    {
        arr[i] = (int*)malloc(a*sizeof(int));
    }
    for (int i = 0; i < a; i++)
        for(int j = 0; j < a; j++)
            arr[i][j] = 1 + i + j;
    for (int i = 0; i < a; i++)
    {
        for(int j = 0; j < a; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    return 0;
}
