#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define len 1000

int compare(const void * x1, const void * x2)
{
  return ( *(int*)x2 - *(int*)x1 );
}

int main()
{
   int array[len];
   int i;
 
   for(i=0; i<len; i++)
   scanf("%d",&array[i]);
    
    time_t sort_start, sort_end; 
	sort_start = time(NULL);
    
    qsort(array, 1000, sizeof(int), compare);
    
    sort_end = time(NULL);
    
    for(i=0; i<len; i++)
    printf("%d ",array[i]);
    
    printf("\n%f", difftime(sort_end, sort_start));
    
  return 0;
}