#include <stdio.h>
int main(){
	int n,i,input, max, min, summ, k;
	scanf("%d",&n);
	int a[n];
	for (i=0; i<n; i++) scanf("%d", &a[i]);
	scanf("%d", &input);
	switch(input){

		case 0:
		 max=a[0];
		 for(i=0; i<n; i++) if (max<a[i]) max=a[i];
		 printf("%d",max);
		 break;

		case 1:
 		 min=a[0];
 		 for(i=0; i<n; i++) if (min>a[i]) min=a[i];
		 printf("%d",min);
		 break;

		case 2:
		 summ=0;
		 for(i=0; i<n; i++) if (((a[i])%2)==0) summ+=a[i];
		 printf("%d",summ);
		 break;

		case 3:
		 k=0;
		 for(i=0; i<n; i++) if ((a[i])==0) k++;
		 if (k>1) k--; else k=0;
		 printf("%d",k);
		 break;

		default:
		printf("Данные некорректны");
	}	
	return 0;
}
