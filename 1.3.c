#include <stdio.h>

int main()
{
    int i,c=0;
    char a[100],b;
    scanf("%s %c",a,&b);
    for(i=0;a[i]!=NULL;i++)
    {
        if (a[i]==b)
        c++;
    }
    printf("%d\n",c);
    return 0;
}
