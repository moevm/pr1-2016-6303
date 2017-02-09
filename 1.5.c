#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,b,min,max;
    printf("size of array\n");
    scanf("%d",b);
    int a[100];
    for(i=0;i<b;i++)
    {
        scanf("%d",&a[i]);
    }
    a[b]=\0;
    min=a[0];
    max=a[0];
    
    for(i=1;i<d;i++)
    {
        if(min>a[i]) 
         min=a[i];
        if(max<a[i]) 
        max=a[i];
    }
    printf("%d\n",(max-min));
    return 0;
}
