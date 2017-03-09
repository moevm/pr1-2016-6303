#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000

int cmpval (const void * a, const void * b){
	return (abs(*(int*)b)-abs(*(int*)a));
}

int main(){
	int i;
	int arr[N];
	clock_t t;
	for(i=0;i<N;i++){
		scanf("%d", &arr[i]);
	}
	t = clock();
	qsort(arr, N, sizeof(int), cmpval);
	for(i=0;i<N;i++){
		printf("%d ", arr[i]);
	}
	printf("\nIt tooks %d ticks to sort array.", clock()-t);
	return(0);
}
