#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    scanf("%d", &n);
    int * arr = (int*)malloc(n*sizeof(int));
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int max, min;
    max = arr[0];
    min = arr[0];
    for(i = 1; i < n; i++)
    {
        if(max < arr[i])
            max = arr[i];
        if(min > arr[i])
            min = arr[i];
    }
    printf("%d", max - min);
    return 0;
}
