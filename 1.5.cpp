#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
	int i;
	int min, max;
	int l;
	scanf("%d", &l);
	int* arr = (int*)malloc(l*sizeof(int));
		for (i = 0; i<l; i++)
		scanf("%d", &arr[i]);
		min = arr[0];
		max = arr[0];
		for (i = 1; i<l; i++)
		{
			if (arr[i]>max) max = arr[i];
			if (arr[i]<min) min = arr[i];
		}
	int a;
	a = max - min;
	printf("%d", a);
	return 0;
}
