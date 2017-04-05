#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define len 1000 //длина массива
	
int compare(const void * x1, const void * x2) //функция сравнения двух элементов по модулю невозрастания
{
	  return ( abs(*(int*)x2) – abs(*(int*)x1 ));
}
	
int main()
{
	int array[len];
	int i;
	 
	for(i=0; i<len; i++)
	{
		scanf("%d",&array[i]); //считывание массива
	}

	clock_t sort_start, sort_end; //объявление переменных типа clock_t, в которые будет записываться время
	
	sort_start = clock(); //записываем время перед запуском сортировки
	    
	qsort(array, len, sizeof(int), compare); //запускаем сортировку
	    
	sort_end = clock(); //записыванием время после сортировки
	    
	for(i=0; i<len; i++)
	{
	    printf("%d ",array[i]); //выводим отсортированный массив
 	}   
	
	printf("\n%f", (float)(sort_end - sort_start)/CLOCKS_PER_SEC); //вывод времени работы массив в секундах
	/*CLOCKS_PER_SEC содержится в библиотеке time.h и переводит значение времени в тактах в секунды*/
	    
return 0;
}
