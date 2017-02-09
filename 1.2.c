#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str = (char*)calloc(100, 1);
    scanf("%s", str);
    int i;
    for(i = 0; i < 100; i++)
        if((i+1)%2 == 0 )
        printf("%c", str[i]);
    return 0;
}
