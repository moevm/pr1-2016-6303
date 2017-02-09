#include <stdio.h>

int main()
{
    int i;
    char a[100];
    scanf("%s",a);
    for(i=0;a[i]!=NULL;i++)
    {
        if(i%2!=0)
        printf("%c",a[i]);
    }
    return 0;
}
