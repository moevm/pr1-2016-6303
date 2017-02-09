#include <stdio.h>

int main()
{
    int i,c=0,j=0;
    char a[100],b,d[100];
    scanf("%s %c",a,&b);
    for(i=0;a[i]!=NULL;i++)
    {
        if (a[i]==b)
        i++;
        d[j++]=a[i];
    }
    printf("%s\n",d);
    return 0;
}
