/* Иванов Д.В. */
#include <stdio.h>

int main()
{	
	char c;
	int n=1;
	c=getchar();
	while (c!='\n')
	{
		if (n % 2 == 0)
			printf("%c", c);
		c=getchar();
		n++;
	}
	printf("\n");
    return 0;
}
