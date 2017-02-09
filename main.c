#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,buf,i=2;
    scanf("%d %d",&a, &b);
    buf=a;
    for (i;i<=b;i++)
    {
        a=a*buf;
    }
    printf("Result: %d",a);
    return 0;
}
