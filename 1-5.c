#include <stdio.h>
#include <stdlib.h>
 
int main() {
int n, min, max;
printf("Размер массива=\n");
scanf("%d", &n);
int *mass=malloc(n*sizeof(int));
 
for(int i=0; i<n; i++){
scanf("%d", &mass[i]);
}
 
max=mass[0];
min=mass[0];
printf("%d\n", max);
for (int i=0; i<n; i++){
if (max<mass[i]) max=mass[i];
if (min>mass[i]) min=mass[i];
}
 
printf("%d", max-min);
return 0;
}