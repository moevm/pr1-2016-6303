#include "stdafx.h"
#include <stdio.h>

int main()
{
	int numb = 0;
	int buf = 1;
	int counter = 0;
	int max = 0;
	int max_numb;
	while (1)
	{
		scanf("%d", &numb);
		if (numb == buf)
		{
			counter++;
		}
		else
			counter = 0;
		if (counter > max)
		{
			max = counter;
			max_numb = numb;
		}
		if (getchar() == '\n')
			break;
		buf = numb;
	}
	printf("%d (%d)", max+1, max_numb);
	return 0;
}