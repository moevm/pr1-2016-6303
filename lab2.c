void menu(int ch,int arr[], int n){ 
switch(ch){ 
case 0: 
printf("%d\n", get_max(arr, n)); 
break; 
case 1: 
printf("%d\n", get_min(arr, n)); 
break; 
case 2: 
printf("%d\n", get_sum(arr, n)); 
break; 
case 3: 
printf("%d\n", get_count_first_el(arr, n)); 
break; 
default: 
printf("Данные некорректны"); 
break; 
} 
} 

int get_max(int arr[], int n){ 
int i,max=arr[0]; 
//for(i=1;i<n;i++) 
    i=1;
    while(i<n){
if(max<arr[i]) 
max=arr[i];
        i++;}
return max; 
} 

int get_min(int arr[], int n){ 
int i,min=arr[0]; 
//for(i=1;i<n;i++)
    i=1;
    while(i<n){
if(min>arr[i]) 
min=arr[i];
        i++;}
return min; 
} 

int get_sum(int arr[], int n){ 
int i, sum = 0; 
//for(i=0;i<n;i++)
    i=0;
    while(i<n){
if((arr[i]%2)==0) 
sum = sum + arr[i];
        i++;}
return sum; 
} 

int get_count_first_el(int arr[], int n){ 
int i, count, s=0; 
count= arr[0]; 
//for(i=1;i<n;i++)
    i=1;
    while(i<n){ 
if(count==arr[i]) 
s=s+1; 
i++;} 
return s; 
}
