/* Иванов Д.В. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
	int min, max;
	int i;
	int lenght;
	scanf("%d", &lenght);
	int* a = (int*)malloc(lenght*sizeof(int));
	for (i = 0; i<lenght; i++)
		scanf("%d", &a[i]);
	min = a[0];
	max = a[0];
	for (i = 1; i<lenght; i++)
	{
		if (a[i]>max) max = a[i];
		if (a[i]<min) min = a[i];
	}
	printf("%d", max - min);
	return 0;
}
