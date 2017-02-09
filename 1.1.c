#include <stdio.h>

int main()
{
    int a,b,c;
    c=1;
    scanf("%d %d",&a,&b);
    for(;b>=1;b--)
    {
        c=c*a;
    }
    printf("%d",c);

    return 0;
}

