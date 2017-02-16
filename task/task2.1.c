#include <stdio.h>
#include <string.h>
int main()
{
	int prev,tech;
	int max;
	int count=1, maxcount=0;
    scanf("%d",&prev);
    max=prev;
    while(scanf("%d",&tech)==1)
    {  
       if (tech==prev)
       {
       	count++;
       }
       if (count>maxcount)
       {
       	maxcount=count;
       	max=tech;
       }
       prev=tech;
    }
    printf("%d (%d)",maxcount,max);
    return 0;
}