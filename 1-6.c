#include <stdio.h>
#include <stdlib.h>
int main() {
int n;
int * *p;
scanf("%d", &n);

p = (int **)calloc(n, sizeof(*p));
for(int i = 0; i < n; i++) {
p[i] = (int*)calloc(n, sizeof(*p[i]));
}

p[0][0]=1;
p[n-1][n-1]=1;
p[n-1][0]=2;
p[0][n-1]=2;

for(int i=0; i<n; i++){
for(int j=0; j<n; j++){
printf("%d ", p[i][j]);
}
printf("\n");
}
return 0;
}
