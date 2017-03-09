#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define length 10

int comp (const int *a, const int *b)
{
return *a - *b;
}

int main()
{
    int i=0, j=0,temp=0;
    int arr1[length], arr2[length];
    int t1, t2, t3, t4;


    for (i=0; i<length; ++i)
    {
        scanf( "%d", &arr1[i]);
        arr2[i]=arr1[i];
    }

    t1 = clock();
    for ( i=0; i < length-1; i++ )
    {
        for ( j = length-2; j >= i; j-- )
        {
            if ( arr1[j] > arr1[j+1] )
            {
                temp = arr1[j];
                arr1[j] = arr1[j+1];
                arr1[j+1] = temp;
            }
        }
    }
    t2 = clock();

    t3 = clock();
    qsort(&arr2, length, sizeof(arr2)/length, (int(*)(const void *, const void *))comp);
    t4 = clock();

    for (i=0; i<length; ++i)
    {
        if (i!=length-1) printf("%d ", arr2[i]);
        else printf("%d\n", arr2[i]);
    }
    printf("%i\n", t2-t1);
    printf("%i", t4-t3);
    return 0;
}
