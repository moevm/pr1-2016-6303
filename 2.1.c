#include <stdio.h>
#include <stdlib.h>


int main()
{

    int max = 0;
    int max_n;
    int n = 0;
    int buf = 1;
    int counter = 0;
    while (1)
    {
        scanf("%d", &n);
        if (n == buf)
            counter++;
        else
            counter = 0;
        if (counter > max)
        {
            max = counter;
            max_n = n;
        }
        if (getchar() == '\n')
            break;
        buf = n;
    }
    printf("%d (%d)", max+1, max_n);
    return 0;
}
