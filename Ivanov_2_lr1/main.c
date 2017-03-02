#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#define lenght 1000

int compare(const void *, const void *);	//прототив функции compare(для функции сортировки qsort)

int main() 
{ 
	int arr[lenght];
	for (int i = 0; i < lenght; i++) 
		scanf("%d", &arr[i]); 
	time_t sort_start, sort_end; 
	sort_start = time(NULL); 
	qsort(arr, lenght, sizeof(int), compare);	//сортировка посредством функции qsort)
	sort_end = time(NULL); 
	for (int i = 0; i < lenght; i++) 
		printf("%d ", arr[i]); 
	printf("\n%f", difftime(sort_end, sort_start));		//вывод времени сортировки (разность между временем начала sort_start и временем окончания sort_end)
	return 0; 
} 


int compare(const void * a, const void * b) 
{ 
	return (abs(*(int*)b) - abs(*(int*)a)); 
}
