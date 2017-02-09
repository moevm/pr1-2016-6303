#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char string;
    int counter=0;
    do
    {
        string = getchar();
        counter++;
        if (counter%2 == 0)
        {
            printf("%c",string);
        }
    }
    while (string != EOF);
    return 0;
}
