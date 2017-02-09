#include "stdio.h"

int main()
{
    int a, x, amount = 1, max = 1, max_n;

    scanf("%d", &a);
    max_n = a;
    while (scanf("%d", &x))
    {
        if (x == a)
            ++amount;
        else
            if (amount > max)
            {
                max = amount;
                max_n = a;
                amount = 1;
            }
        a = x;
    }
    printf("%d(%d)", max_n, max);

    return 0;
}
