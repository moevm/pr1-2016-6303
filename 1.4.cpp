#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
  char s[100], c;
	scanf("%s %c", s, &c);
	int l=strlen(s);
	for (int i=0; i<l; i++)
	{
		if (c == s[i]);
		else
			printf("%c", s[i]);
	}
	printf("\n");
}
