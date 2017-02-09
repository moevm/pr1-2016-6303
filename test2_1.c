#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[100],i=-1;
    do
    {
        i++;
        scanf("%d ",&arr[i]);
    }
    while (arr[i] != '\n');
    return 0;
}
