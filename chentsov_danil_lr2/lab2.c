
int get_max(int arr[], int n){
         int max, i;
         max=arr[0];
		 for(i=0; i<n; i++) if (max<arr[i]) max=arr[i];
		 return max;
}

int get_min(int arr[], int n){
         int min,i;
         min=arr[0];
 		 for(i=0; i<n; i++) if (min>arr[i]) min=arr[i];
		 return min;
}

int get_sum(int arr[], int n){
         int summ,i;
         summ=0;
		 for(i=0; i<n; i++) if (((arr[i])%2)==0) summ+=arr[i];
		 return summ;
}

int get_count_first_el(int arr[], int n){
	     int k,i;
         k=0;
		 for(i=1; i<n; i++) if (arr[0]==arr[i]) k++;
		 return k;
}
void menu(int ch, int arr[], int n){        
    
	switch(ch){
        
		case 0:
		  printf("%d", get_max(arr, n));
		 break;

		case 1:
 		 printf("%d", get_min(arr, n));
		 break;

		case 2:
		  printf("%d", get_sum(arr, n));
		 break;

		case 3:
	     printf("%d", get_count_first_el(arr, n));
         break;
                
		default:
		printf("Данные некорректны");
	}	
}

