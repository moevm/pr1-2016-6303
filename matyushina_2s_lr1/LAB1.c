#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

int cmpfunc(const void * a, const void * b) {
	return ( *(int*)a - *(int*)b );
}

int main() {
 int * element = (int*)malloc(SIZE*sizeof(int));
 int i;
 for ( i=0; i<SIZE; i++){
	 scanf("%d", &element[i]);
 }

 qsort(element, SIZE, sizeof(int), cmpfunc);
 int key=0;
 int time;
 time = (int)clock();
 int* search;
 search = (int*) bsearch (&key, element, SIZE, sizeof (int), cmpfunc);
 time=(int)clock()-time;
 if (search!=NULL) {
 	printf("exists\n");
 }
 else {
 	printf ("doesn't exist\n");
 }
 printf("%d\n", time);
//перебор
 int control=0;
 time = (int)clock();
 for (i=0; i<SIZE; ++i) {
 	if (element[i]==0) {
 		control=1;
 		break;
 	}
 }
 time=(int)clock()-time;
 if (control==1) {
 	printf("exists\n");
 }
 else {
 	printf("doesn't exist\n");
 }
 printf("%d\n", time);
 free(element);
 return 0;
}
