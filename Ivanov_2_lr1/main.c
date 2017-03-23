/* 
Главный файл main.c, содержащий код программы
Иванов Д.В. Группа 6303
Лабораторная работа №1
*/
#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
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

	return 0; 
}

int compare(const void * a, const void * b) 
{ 
	return (abs(*(int*)b) - abs(*(int*)a)); 
}
