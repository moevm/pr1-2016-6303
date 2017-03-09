#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#define LenghtOfArray 1000

int compare(const void *a, const void *b); 

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
	return 0; 
} 


int compare(const void *a, const void *b) 
{ 
	return (abs(*(int*)b) - abs(*(int*)a)); 
}

