#include <stdio.h>
int main()
{
    int array[100], *minimum, *maximum, n, c = 1;
    int povtor = 0;
    int sumch,sw;
    scanf("%d",&n);
    scanf("%d",&sw);
    for ( c = 0 ; c < n ; c++ )
        scanf("%d", &array[c]);

    minimum = array;
    *minimum = *array;
    maximum = array;
    *maximum = *array;
    switch (sw)
    {
        case 0:
            for ( c = 1 ; c < n ; c++ )
            {
                if ( *(array+c) > *maximum )
                {
                    *maximum = *(array+c);
                }
            }

            printf("%d\n",*maximum);break;
        case 1:
            for ( c = 1 ; c < n ; c++ )
            {
                if ( *(array+c) < *minimum )
                {
                    *minimum = *(array+c);
                }
            }
            printf("%d\n",*minimum);break;
        case 2:
            for ( c = 1 ; c < n ; c++ )
                for ( c = 0 ; c < n ; c++ )
                {
                    if (array[c] % 2 == 0)
                    {
                        sumch +=  array[c];
                    }
                }
            printf("%d\n",sumch);break;
        case 3:
            for ( c = 1 ; c < n ; c++ )
            {
                if (array[c] == 0)
                {
                    povtor++;
                }
            }
            printf("%d\n",povtor);break;
    }
    return 0;
}
