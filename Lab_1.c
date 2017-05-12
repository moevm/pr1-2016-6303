#include <stdio.h>
#include <stdlib.h>
#include <time.h> // работа со временем

#define ARR_SIZE 1000 // для тестирования мне была необходима возможность установки меньшего размера массива в кратчайшие сроки

int compare(const void* arg_1, const void* arg_2); // прототип функции сравнения чисел для qsort и bsearch

int main() {
	int key = 0; // искомое число
	int nums[ARR_SIZE]; // массив чисел

	for (int i = 0; i<ARR_SIZE; i++)
	{
		scanf("%d", &nums[i]); // цикл заполняющий массив числами с потока ввода
	}

	qsort(nums, ARR_SIZE, sizeof(int), compare); // сортировка массива quicksort-ом

	clock_t t_active = clock(); // запись времени начала поиска

	int * ptrItem = (int*)bsearch(&key, nums, 1000, sizeof(int), compare);

	t_active = clock() - t_active; // запись времени окончания поиска

	if (ptrItem != NULL)
		printf("exists\n"); // вывод exists если флаг поднят (ноль найден) и doesn't exist если нет
	else
		printf("doesn't exist\n");
	ptrItem = NULL;

	printf("%f\n", (double)t_active / CLOCKS_PER_SEC); // вывод разницы между временем начала и конца поиска

	t_active = clock();

	for (int i = 0; i<ARR_SIZE; i++) // поиск пузырьком
	{
		if (nums[i] == key)
		{
			ptrItem = &key; // установка флага 1 если ноль найден
			break;
		}
	}

	t_active = clock() - t_active; // запись времени окончания поиска

	if (ptrItem != NULL)
		printf("exists\n"); // вывод exists если флаг поднят (ноль найден) и doesn't exist если нет
	else
		printf("doesn't exist\n");

	printf("%f\n", (double)t_active / CLOCKS_PER_SEC); // вывод времени поиска пузырьком
	return 0;
}

int compare(const void* arg_1, const void* arg_2)
{
	return (*(int*)arg_1 - *(int*)arg_2); // функция сравнивающая числа, используется для qsort и bsearch
}