#include <stdio.h>
#include <stdlib.h>
#include <time.h> // работа со временем

#define S_NUMBER 0 // искомое число
#define ARR_SIZE 1000 // для тестирования мне была необходима возможность установки меньшего размера массива в кратчайшие сроки

int compare(const void* arg_1, const void* arg_2); // прототип функции сравнения чисел для qsort

int main() {
	short exist = 0; // принимает 1 или 0 в зависимости от того существует ноль или нет
	int low = 0; // нижняя граница при бинарном поиске
	int high = ARR_SIZE-1; // верхняя граница при бинарном поиске
	int count; // счетчик, в целом используется несколько раз в качестве счетчика в разных местах
	int nums[ARR_SIZE]; // массив чисел
	
	for (int i = 0; i<ARR_SIZE; i++)
	{
		scanf("%d", &nums[i]); // цикл заполняющий массив числами с потока ввода
	}
	
	qsort(nums, ARR_SIZE, sizeof(int), compare); // сортировка массива quicksort-ом

	time_t time_start = time(NULL); // запись времени начала поиска

	while (low != high)
	{
		count = (low + high) / 2; // если число больше искомого числа, значит мы находимся выше этого числа и это становится
		if (nums[count] > S_NUMBER)	// верхней границей в дальнейшем поиске
		{
			high = count;
			continue;
		}
		if (nums[count] < S_NUMBER) // меньше искомого числа - нижняя граница
		{
			low = count;
			continue;
		}
		if (nums[count] == S_NUMBER) // если число равно искомому, то exist принимает значение "1"
		{			//что эквивалентно "ноль существует" в логике программы
			exist = 1;
			break;
		}
	}

	time_t time_finish = time(NULL); // запись времени окончания поиска

	if (exist == 1)
		printf("exists\n"); // вывод exists если флаг поднят (ноль найден) и doesn't exist если нет
	else 
		printf("doesn't exist\n");
	exist = 0; // установка флага равным нулю, для дальнейшего его использования в повторном поиске

	printf("%f\n", difftime(time_finish, time_start)); // вывод разницы между временем начала и конца поиска

	time_start = time(NULL); // запись времени старта поиска

	for (count = 0; count<ARR_SIZE; count++) // поиск пузырьком
	{
		if (nums[count] == S_NUMBER)
		{
			exist = 1; // установка флага 1 если ноль найден
			break;
		}
	}

	time_finish = time(NULL); // запись времени окончания поиска

	if (exist == 1) // вывод exists если флаг поднят (ноль найден) и doesn't exist если нет
		printf("exists\n");
	else
		printf("doesn't exist\n");

	printf("%f\n", difftime(time_finish, time_start)); // вывод времени поиска пузырьком
	return 0;
}

int compare(const void* arg_1, const void* arg_2)
{
	return (*(int*)arg_1 - *(int*)arg_2); // функция сравнивающая числа, используется для qsort-а
}
