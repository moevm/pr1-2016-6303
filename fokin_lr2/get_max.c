#include <stdio.h>
#include "get_max.h"

int get_max(int arr[], int n)
{
int j, max = arr[0];
    for (j = 1; j < n; ++j)
        if (arr[j] > max)
            max = arr[j];
    printf("%d\n", max);
}
