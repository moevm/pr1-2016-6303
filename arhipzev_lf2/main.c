void menu(int ch, int arr[], int n){        
    if (n == 0){printf("0");} 
    else{
    switch (ch){
        case 0:get_max(arr,n);break;
        case 1:get_min(arr,n);break;
        case 2:get_sum(arr,n);break;
        case 3:get_count_first_el(arr,n);break;
        default :
            printf("Äŕííűĺ íĺęîđđĺęňíű");  break;  
    }
}
}
int get_max(int arr[], int n){
    int mx = arr[0];
    
    for( int i=1;i<n;i++){
        if (mx<arr[i]){mx = arr[i];}
    }
     printf("%d",mx); 

}
int get_min(int arr[], int n){
    int mn=arr[0];
   
    for(int i=1;i<n;i++){
        if (mn>arr[i]){mn = arr[i];}
    }
    
    printf("%d",mn);

}
int get_sum(int arr[], int n){
    int sum =0;
 
 
    for(int i=0;i<n;i++){
        if (arr[i] % 2 == 0){sum += arr[i];}
    }
    
    printf("%d",sum);
    }

int get_count_first_el(int arr[], int n){
    int k = arr[0],kol = 0;
    
    for (int i = 1;i<=n;i++){
        if (arr[i] == k){kol++;}
    }
    printf("%d",kol);    
    }
