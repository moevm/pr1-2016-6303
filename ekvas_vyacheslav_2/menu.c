int get_max(int arr[], int n){
	int i;
	int count = arr[0];
	for(i=1; i<n; i++){
		if(arr[i]>count)
			count=arr[i];
	}
	printf("%d\n", count);
}

int get_min(int arr[], int n){
	int i;
	int count = arr[0];
	for(i=1; i<n; i++){
		if(arr[i]<count)
			count=arr[i];
	}
	printf("%d\n", count);
}

int get_sum(int arr[], int n){
	int i;
	int count = 0;
	for(i=0; i<n; i++){
	if(arr[i]%2==0)
		count+=arr[i];
	}
	printf("%d\n", count);
}

int get_count_first_el(int arr[], int n){
	int i;
	int count = 0;
	for(i=1; i<n; i++){
		if(arr[i]==arr[0])
			count++;
	}
	printf("%d\n", count);
}
void menu (int ch, int arr[], int n){
	switch(ch){
		case 0:get_max(&arr[0], n);break;
		case 1:get_min(&arr[0], n);break;
		case 2:get_sum(&arr[0], n);break;
		case 3:get_count_first_el(&arr[0], n);break;
		default:puts("Данные некорректны");
	}
}

