#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	int **arr = (int**)malloc(sizeof(int*)*n);
	int i;
	for(i=0;i<n;++i)
	{
		arr[i]=(int*)malloc(sizeof(int)*n);
	}
	for (i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			arr[i][j]=i+j+1;
			printf("%d",arr[i][j]);
		}
		printf("\n");
	}
	return 0;

}