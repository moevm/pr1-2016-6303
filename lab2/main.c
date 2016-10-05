
#include <stdio.h>


int main()
{
int n;
int a;
int i;
scanf("%i", &n);
scanf("%i", &a);
int mas[n];
for (i = 0; i < n; i++) {
	scanf("%i", &mas[i]);
}
if(a == 0){
	 int max = mas[0];
        for(i = 0; i < n; i++)
                if (mas[i] > max)
                        max = mas[i];
printf("%i\n", max);
}else if(a == 1){
 int min = mas[0];
        for(i = 0; i < n; i++)
                if (mas[i] < min)
                        min = mas[i];
printf("%i\n", min);
}else if(a == 2){
int sum;
for(i = 0; i < n; i++)
	if(mas[i]%2 == 0)
		sum = sum + mas[i];
printf("%i\n", sum);
}else if(a == 3){
int povt;
for(i = 1; i < n; i++)
	if(mas[i] == mas[0])
		povt++;
printf("%i\n", povt);
}else{
puts("Данные некорректны");
}
    return 0;
}
