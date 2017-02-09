#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char string,el;
    int counter=0;
    scanf("%c\n",&el);
    do
    {
        string=getchar();
        if ( string == el ) continue;
        printf("%c",string);
    }
    while (string != '\n');
    printf("%d",counter);
    return 0;
}
