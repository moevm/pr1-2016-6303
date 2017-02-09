#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* const argv[]){
	int n;
	int a=1;
	int b=a;
	scanf("%d", &n);
	int **array=(int**)malloc(n*sizeof(int*));
	for (int i=0; i<n; ++i){
		array[i]=(int*)malloc(n*sizeof(int));
	}
	for(int i=0; i<n; ++i){
		for(int j=0; j<n;++j){
			array[i][j]=b;
			++b;	
		}
		++a;
		b=a;
	}
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			printf ("%d ", array[i][j]);
		}
		printf("\n");
	}
	return 0;
}
