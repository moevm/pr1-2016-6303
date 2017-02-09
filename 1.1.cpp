#include "stdio.h"


int main()
{
	int a, b;
	
	scanf("%d %d", &a, &b);
	int c = a;

	for (int i = 0; i < b-1; i++)
	{
		a *= c;
	}

	printf("%d \n", a);


    return 0;
}
