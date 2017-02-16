#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
  char str[100]; 
  char c;
	scanf("%s %c", str, &c);
	for (int i=0; i<strlen(str); i++)
	{
		if (c == str[i]);
		else
			printf("%c", str[i]);
	}
	printf("\n");
}
