#include <stdio.h>
#include <math.h>

int main(){
	int n = 0;
	int wtd = 0;
	int i = 0;
	int big = 0;
	int small = 0;
	int sum = 0;
	int count = 0;
	scanf("%d\n %d\n",n, wtd);
	int a[n];
	if (wtd = 0) {
		for (i = 0; i < n; ++i ){
			if (a[i] > big) {
				big = a[i];
			}
		}
		printf("%d\n", big);
	}
	if (wtd = 1){
		small = a[1];
		for (i = 0; i < n; ++i){
			if (a[i] < small){
				small = a[i];
			}
		}
		printf("%d\n",small);
	}
	if (wtd = 2){
		for (int i = 0; i < n; ++i){
			if ((fmod(a[i],2)) = 0){
				sum = sum + a[i];
			}
		}
		printf("%d\n", sum);
	}
	if (wtd = 3){
		for (int i = 0; i < n; ++i){
			if (a[i] = a[0]){
				count = count + 1; 
			}	
		}
		printf("%d\n", count);
	}

}