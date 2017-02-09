#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str = (char*)calloc(100, 1);
    char ch;
    scanf("%s\n", str);
    scanf("%c", &ch);
    int i, count = 0;
    for(i = 0; i < 100; i++)
        if(str[i] == ch)
            count++;
    printf("%d", count);
    return 0;
}
