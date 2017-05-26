#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
char* string=(char*)malloc(1000*sizeof(char));
int t=0;
char *symbol=(char*)malloc(1000*sizeof(char));
scanf("%s", string);
scanf("%s", symbol);
for (int i=0; i<strlen(string); i++)
        if ( *symbol== *(string+i) )
        t++;
printf("%d", t);//(Но это не точно )
return 0;
}
