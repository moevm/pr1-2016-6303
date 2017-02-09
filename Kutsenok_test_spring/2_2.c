#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int** arr = (int**) malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(n * sizeof(int));
        for(int j = 0; j < n; j++) {
            arr[i][j] = i+j+1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}