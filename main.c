#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int collect(char**getall);
void copy(char**gatall,char**getall,int a);
int main()
{
	int m,b,j,a,z=0;
	char**getall=(char**)malloc(sizeof(char*)*1000);
	for(a=0;a<1000;a++)
    {
        getall[a]=(char*)malloc(sizeof(char)*1000);
    }

    j=collect(getall);
 
  char**gatall=(char**)malloc(sizeof(char*)*(j+1));
        for(a=0;a<=j;a++)
    {
        gatall[a]=(char*)malloc(sizeof(char)*1000);
    }
       
  copy(gatall,getall,j);
	
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

int collect(char** getall)
{
    int i,c,j=0;
	for(i=0;(c=getchar())!=EOF;i++)
	{
		if(c==';'||c=='.'||c=='?')
		{ 
			getall[j][i++]=c;
			getall[j][i]='\0';
			j++;
			i=0;
		}
        else if(c=='\n'||c=='\t')
           i= i-1;
		else
		   getall[j][i]=c;
	}
	getall[j][i]='\0';
    
    return j;
}
void copy(char**gatall,char**getall,int j)
{
 int y,d,h;
    y=0;
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
               d=0;
           }
        }
}
    
