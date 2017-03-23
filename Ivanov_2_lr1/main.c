/* 
Главный файл main.c, содержащий код программы
Иванов Д.В. Группа 6303
Лабораторная работа №1
*/
#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
<<<<<<< HEAD
#define LenghtOfArray 1000

int compare(const void *, const void *);

int main() 
{ 
	int ArrayOfNumbers[LenghtOfArray];		//Создание и заполнение массива чисел
	for (int i = 0; i < LenghtOfArray; i++) 
	{	
		scanf("%d", &ArrayOfNumbers[i]);
	}
	
	clock_t clock_of_start, clock_of_end; 		//Инициализация переменных для подсчета  кол-ва тактов процессора
	clock_of_start = clock(); 
	qsort(ArrayOfNumbers, LenghtOfArray, sizeof(int), compare); 	//Быстрая сортировка массива посредством фунцкии qsort
	clock_of_end = clock(); 

	for (int i = 0; i < LenghtOfArray; i++) 
	{
		printf("%d ", ArrayOfNumbers[i]); 	//Вывод отсортированного массива
	}
	printf("\n%f",(float)(clock_of_end-clock_of_start)/CLOCKS_PER_SEC);	//Вывод времени работы функции qsort

=======
#define LenghtOfArray 100

int compare(const void *, const void *); 

int main() 
{ 
	int ArrayOfNumbers[LenghtOfArray];
	for (int i = 0; i < LenghtOfArray; i++) 
		scanf("%d", &ArrayOfNumbers[i]); 
	time_t time_of_start, time_of_end; 
	time_of_start = time(NULL); 
	qsort(ArrayOfNumbers, LenghtOfArray, sizeof(int), compare); 
	time_of_end = time(NULL); 
	for (int i = 0; i < LenghtOfArray; i++) 
		printf("%d ", ArrayOfNumbers[i]); 
	printf("\n%f", difftime(time_of_end, time_of_start)); 
>>>>>>> 61ec710cab0f254dfdea240bbd5d1ac54ef21300
	return 0; 
}

int compare(const void * a, const void * b) 
{ 
	return (abs(*(int*)b) - abs(*(int*)a)); 
}
