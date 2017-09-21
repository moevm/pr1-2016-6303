#include <stdio.h>
#include "get_min.h"

int get_min(int arr[], int n)
{
int j, min = arr[0];
    for (j = 1; j < n; ++j)
        if (arr[j] < min)
            min = arr[j];
    printf("%d\n", min);
}
