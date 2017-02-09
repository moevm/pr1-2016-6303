#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i,j,k=0,arr[10],buf,res;
    for (k;k<10;k++)
    {
        scanf("%d\n",&arr[k]);
    }
    for (i=0;i<10;i++)
    {
        if (arr[i] > arr[i+1])
        {
            buf=arr[i+1];
            arr[i+1]=arr[i];
            arr[i]=buf;
            printf("%d %d",arr[i],arr[i+1]);
        }
        else continue;

    }
    res=arr[10]-arr[0];
    printf("%d",res);
    return 0;
}
