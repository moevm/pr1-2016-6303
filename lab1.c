#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define LENGTH 1000 //lenth of array

int compare(const void * a, const void * b);

int main()
{
	int array1[LENGTH], array2[LENGTH];
	int i, j;
	for (i = 0; i < LENGTH; i++)
		scanf("%d", &array1[i]);
	memcpy(array2, array1, LENGTH * sizeof(int)); //array duplication
	clock_t sort_start, sort_end, qsort_start, qsort_end;
	sort_start = clock();
	for (i = 0; i < (LENGTH - 1); i++)
		for (j = 0; j < (LENGTH - i - 1); j++)
			if (array1[j] > array1[j + 1])
			{
				int tmp = array1[j];
				array1[j] = array1[j + 1];
				array1[j + 1] = tmp;
			}
	sort_end = clock();
	qsort_start = clock();
	qsort(array2, LENGTH, sizeof(int), compare);
	qsort_end = clock();
	for (i = 0; i < LENGTH; i++)
		printf("%d ", array2[i]);
	printf("\n");
	printf("%f\n", (float)(sort_end - sort_start) / CLOCKS_PER_SEC);
	printf("%f\n", (float)(qsort_end - qsort_start) / CLOCKS_PER_SEC);
	return 0;
}


int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}
