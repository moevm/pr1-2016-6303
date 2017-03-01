#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 

int compare(const void * a, const void * b); 

int main() 
{ 
int numbers[1000]; 
int i=0,j,len=1000; 
for (i; i < len; i++) 
scanf("%d", &numbers[i]); 
time_t sort_start, sort_end, qsort_start, qsort_end; 
sort_start = time(NULL); 
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
sort_end = time(NULL); 
qsort_start = time(NULL); 
qsort(numbers, len, sizeof(int), compare); 
qsort_end = time(NULL); 
for (i = 0; i < len; i++) printf("%d ", numbers[i]); 
printf("\n"); 
printf("%f\n", difftime(sort_end, sort_start)); 
printf("%f", difftime(qsort_end, qsort_start)); 
return 0; 
} 


int compare(const void * a, const void * b) 
{ 
return (*(int*)a - *(int*)b); 
}
