int get_max(int arr[], int n){ 
int max = arr[0]; 
for(int i = 0; i < n; i++) { 
if(arr[i] > max){ 
max = arr[i]; 
} 
} 
printf("%d", max); 
} 

int get_min(int arr[], int n){ 
int min = arr[0]; 
for(int i = 0; i < n; i++){ 
if(arr[i] < min) { 
min = arr[i]; 
} 
} 
printf("%d", min); 
} 

int get_sum(int arr[], int n){ 
int sum=0; 
for (int i = 0; i < n; i++){ 
if ((arr[i]) % 2 == 0){ 
sum = sum+arr[i];}} 
printf("%d", sum); 
} 

int get_count_first_el(int arr[], int n){ 
int count=0; 
for (int i = 1; i < n; i++) 
{ 
if (arr[i] == arr[0]){ 
count = count + 1;}} 
printf("%d", count); 
} 
void menu(int ch, int arr[], int n){ 

switch (ch) { 
case 0 : 
get_max(arr, n); 
break; 
case 1 : 
get_min(arr, n); 
break; 
case 2 : 
get_sum(arr, n); 
break; 
case 3 : 
get_count_first_el(arr, n); 
break; 
default : 
printf("Данные некорректны"); 
} 
}
