#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 

int compare(const void * x1, const void * x2) 
{ 
return (*(int*)x1 - *(int*)x2); 
}

int main() 
{ 
int numbers[1000],numberscopy[1000]; 
int i=0,j,len=1000; 
for (i; i < len; i++)
{
scanf("%d", &numbers[i]); 
}
memcpy(numberscopy, numbers, 1000 * sizeof (int));  //копируем исходный массив, дабы провести две разных сортировки
clock_t bubblesort_start, bubblesort_end, qsort_start, qsort_end; 
/* сортировка пузырьком (bubble) */
bubblesort_start = clock(); 
for (i = 0; i < (len-1); i++) 
{
    for (j = 0; j < (len - i - 1); j++) 
    {
        if (numbers[j] > numbers[j + 1]) 
        { 
            int tmp = numbers[j]; 
            numbers[j] = numbers[j + 1]; 
            numbers[j + 1] = tmp; 
        }
    }
}
bubblesort_end = clock();
/* Сортировка с помощью qsort */   
qsort_start = clock(); 
qsort(numberscopy, len, sizeof (int), compare); 
qsort_end = clock(); 
    
for (i = 0; i < len; i++)
{
    printf("%d ", numbers[i]); 
}
printf("\n"); 
printf("%f\n", (float)(bubblesort_end - bubblesort_start) / CLOCKS_PER_SEC); 
printf("%f\n", (float)(qsort_end - qsort_start) / CLOCKS_PER_SEC); 
return 0; 
} 
