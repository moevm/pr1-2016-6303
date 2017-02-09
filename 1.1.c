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
    printf("%d\n",c);

    return 0;
}

