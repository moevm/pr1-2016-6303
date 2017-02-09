#include <stdio.h>

int main() {
int x, step, result = 1;
scanf("%d", &x);
scanf("%d", &step);
for(int i = 0; i < step; i++)
result = result * x;
printf("%d", result);

return 0;
}