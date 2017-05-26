#include "stdio.h"

int main()
{	
	char str[1000];
	scanf("%s", str);

	int len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		if ( !(i % 2 == 0) )
			printf("%c", str[i]);
	}

	printf("\n");
	

    return 0;
}
