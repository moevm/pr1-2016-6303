#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str = (char*)calloc(100, 1);
    char ch;
    scanf("%s\n", str);
    scanf("%c", &ch);
    int i;
    for(i = 0; i < 100; i++)
        if(str[i] != ch)
            printf("%c", str[i]);
    return 0;
}
