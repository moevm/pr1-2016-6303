#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fun()
{
    char c;
    char *com1="Dragon flew away!";
    char *str=(char*)malloc(1*sizeof(char));
    int kold=0, kolp=0;
    do
    {
        int a=1, i=0, x=0;

        do
        {
            c=getchar();
            if ( c=='?' || c==';' ||  c=='.' ||  c=='!') x=1;
            if (c!='\n')
            {
                if (i == 0)
                {
                    i++;
                }
                else
                {
                	if ( c == '\t' && ( (i == 0) || i == 1)  );
                	else
                	{
                    str[i-1]=c;
                    a++;
                    i++;
                    str=(char*)realloc(str, a*sizeof(char));
                	}
                }
            }
        }while (x == 0);
        kold++;
        i--;
        str[i]='\0';

        if ( str[i-1] == ';' )
        {
            printf("%s",str);
            printf("\n");
            kolp++;
        }
        if ( str[i-1] == '.' )
        {
            printf("%s",str);
            printf("\n");
            kolp++;
        }
    }while(strstr(str, com1) == 0);
    printf("Количество предложений до %d и количество предложений после %d", (kold-1), kolp);
}

int main()
{
    fun();
    return 0;
}
