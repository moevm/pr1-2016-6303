#include <stdio.h>

int main()
{
	int a = 0;
	int max_a;
	int temp = 0;
	int counter = 0;
	int max = 0;
	while (2)
	{
		scanf("%d", &a);
		if (a == temp)
		{
			counter++;
		}
		else
			counter = 0;
		if (counter > max)
		{
			max = counter;
			max_a = a;
		}
		if (getchar() == '\n')
			break;
		temp = a;
	}
	printf("%d (%d)", max+1, max_a);
	return 0;
}
