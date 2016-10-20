#include <stdio.h>

int main()
{
        int n;
        scanf("%d", &n);
        char arr[10][10];
        int i,j;
        for(i = 0; i<n; ++i)
                for(j = 0; j<n; ++j)
                {
                        arr[i][j] = '*';
                }
        for(i = 0; i<n; i++)
                for(j = 0; j<n; j++)
                        {
                        if(i == j) arr[i][j] = '+';
                        if((i+j+1) == n) arr[i][j] = '-';
                        }
        for(i = 0; i<n; ++i)
        {
                for(j = 0; j<n; ++j)
                {
                        printf("%c", arr[i][j]);
                }
                printf("\n");
        }
}

