#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int SortAndCompare(int* arr, int n, int elem);   // прототип основной функции для работы с программой
int comp(int* a, int* b);
int funccompar (int* key,int* cmpelem);

#define m 1000

int main()
{
	int i;
	char c;
	int* value;
	int* arr =(int*)malloc(sizeof(int)*m);
	for(i=0;i<m;++i)
	{
		scanf("%d",&arr[i]);
	}
	SortAndCompare(arr,i,0);    // запуск сортировки и поиска
	free(arr);
	return 0;
}

int SortAndCompare(int *arr, int n, int elem)
{		

	char s1[10]="exists";				// фразы ответов
	char s2[15]="doesn't exist"; 
	qsort(arr, n,sizeof(int),( int(*) (const void *, const void*)) comp);  // сортировка массива 
	int timeqsort1=clock();
	int* ptr = (int*)bsearch(&elem, arr, n, sizeof(int), ( int(*) (const void *, const void*)) funccompar);  // бинарный поиск элемента elem
	int timeqsort2=clock();
	if (ptr!=NULL) printf("%s\n",s1);  // вывод информации о наличии элемента в массиве
	else printf("%s\n",s2);
	printf("%d\n",timeqsort2-timeqsort1);  // вывод времени на операцию бинарного поиска
	timeqsort1 =clock();
	int i=0;
	while(i<n)
	{
		if (arr[i]==elem)			// алгоритм поиска элемента с помощью перебора
		{							// в данном алгоритме при нахождении элемента следует выход из цикла
			i=n-1;					// так как результат уже известен по бинарному поиску
		}							// если элемент не был обнаружен, то алгоритм совершает количество шагов для выхода запределы массива
		++i;						// так же как и делал бы с обычным алгоритмом поиска перебором
	}
	timeqsort2=clock(); 
	if (ptr!=NULL) printf("%s\n",s1); 			 // вывод информации о наличии элемента в массиве
	else printf("%s\n",s2);						
	printf("%d\n",timeqsort2-timeqsort1);		// вывод времени на операцию поиска перебором

}
int comp(int* a, int* b)
{
	return *a - *b;
}
int funccompar (int* key,int* cmpelem)
{

  return ( *key - *cmpelem);
}