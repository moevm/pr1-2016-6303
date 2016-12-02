#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	int h,d,y,m,b,k,i,j=0,c,a,z=0;
	char**getall=(char**)malloc(sizeof(char*)*1000);
	for(a=0;a<1000;a++)
    {
        getall[a]=(char*)malloc(sizeof(char)*1000);
    }

    
    
    x:
	for(i=0;(c=getchar())!=EOF;i++)
	{
		if(c==';'||c=='.'||c=='?')
		{ 
			getall[j][i++]=c;
			getall[j][i]='\0';
			j++;
			goto x;
		}
        else if(c=='\n'||c=='\t')
           i= i-1;
		else
		   getall[j][i]=c;
	}
	getall[j][i]='\0';
    
    
    
    char**gatall=(char**)malloc(sizeof(char*)*(j+1));
        for(a=0;a<=j;a++)
    {
        gatall[a]=(char*)malloc(sizeof(char)*1000);
    }
    
    
    y=0;
    l:
        for(d=0;y<=j;d++)
        {        
           if(getall[y][d]==' ')
               ;
           else
           {
               for(h=0;getall[y][d]!='\0';h++)
               {   
                   gatall[y][h]=getall[y][d];
                   d++;
               }
               gatall[y][h]='\0';
               y++;
               goto l;
           }
        }
             
	
    for(b=0;b<=j;b++)
	{
        for(m=0;gatall[b][m]!='\0';m++)
        {
            if(gatall[b][m]==';'||gatall[b][m]=='.')
            {
                z++;
		        printf("%s\n",gatall[b]);
            }
        }
	}
    printf("Количество предложений до %d и количество предложений после %d\n",j,z);
	return 0;
	}
