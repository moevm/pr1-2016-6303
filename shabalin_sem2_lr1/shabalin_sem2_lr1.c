/* Шабалин Михаил 6303*/
/* Лабораторная работа #1 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// функция возвращает текущее время в секундах
double current_timestamp() {
    struct timeval te; 
    gettimeofday(&te, NULL);
    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000;
    double seconds = (double)(milliseconds) / 1000.0;
    return seconds;
}

// вспомогательная функция для сортировки массива
int cmpfunc(const void* a, const void* b) {
    int val1 = *(int*)a;
    int val2 = *(int*)b;
    return (abs(val2) - abs(val1));
}

// основной модуль
int main() {
	int n = 1000;							// устанавливаем размер массива
	int array[n];							// выделяем в стеке массив из 1000 элементов
	for (int i=0; i<n; i++) {
		scanf("%d", &array[i]);				// считываем его из консоли
	}
	
	double time1 = current_timestamp();
    qsort(array, n, sizeof(n), cmpfunc);	// сортируем массив быстрой сортировкой
    double time2 = current_timestamp();
    double elapsed_time = time2 - time1;
	
	printf("\n");
	for (int i=0; i<n; i++) {
		printf("%d ", array[i]);			// выводим отсортированный массив через пробел
	}
	printf("\n");
	printf("%.12f", elapsed_time);			// выводим затраченное время в секундах
	
	return 0;
}

