#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	char **arr = (char **) malloc(n * sizeof(char *));
        int i, j;
        for (i = 0; i < n; i++) {
            arr[i] = (char *) malloc(n * sizeof(char *));
        }
    for(i=0;i<n;i++){
    	for(j=0;j<n;j++){
    		arr[i][j]=i+j+1;
    	}
    }
}
