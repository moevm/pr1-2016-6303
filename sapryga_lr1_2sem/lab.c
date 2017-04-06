#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 int linSearch(int arr[], int key, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == size)
			return 1;
	}
	return -1;
}

int compare_integers (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}


int main()
{
    int arr[1000];
    int key = 0;
    int t1 = 0;
    int t2 = 0;
    for (int i = 0; i < 1000; ++i)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr, 1000, sizeof(int), compare_integers);
    t1 = clock();
    int *ptr = (int *)bsearch(&key, arr, 1000, sizeof(int), compare_integers);
    t2 = clock()-t1;
    if (ptr != NULL)
    {
        printf("exists\n");
    }
    else
    {
        printf("doesn't exist\n");
    }
    printf("%d\n", t2);
    t1 = clock();
    int result = linSearch(arr, key, 1000);
    t2 = clock() - t1;
    if (result == 1)
    {
        printf ("exists\n");
    }
    else
    {
        printf ("doesn't exist\n");
    }
    printf ("%d\n", t2);
    return 0;
}
