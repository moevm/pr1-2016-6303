#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define LENGTH 1000

int compare(const void * a, const void * b);

int main()
{
	int array[LENGTH];
	int i, j;
	for (i = 0; i < LENGTH; i++)
		scanf("%d", &array[i]);
	clock_t sort_start, sort_end, qsort_start, qsort_end;
	sort_start = clock();
	for (i = 0; i < (LENGTH - 1); i++)
		for (j = 0; j < (LENGTH - i - 1); j++)
			if (array[j] > array[j + 1])
			{
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
	sort_end = clock();
	qsort_start = clock();
	qsort(array, LENGTH, sizeof(int), compare);
	qsort_end = clock();
	for (i = 0; i < LENGTH; i++)
		printf("%d ", array[i]);
	printf("\n");
	printf("%f\n", (float)(sort_end - sort_start) / CLOCKS_PER_SEC);
	printf("%f\n", (float)(qsort_end - qsort_start) / CLOCKS_PER_SEC);
	return 0;
}


int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}
