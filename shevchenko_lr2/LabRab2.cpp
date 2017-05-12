#include <stdio.h>

int get_max(int arr[], int n)
{
    int max=arr[0], i;
    for(i=1; i<=n; i++)
    {if(arr[i]>max)
        max=arr[i];}
        printf("%d\n ", max);
}
int get_min(int arr[], int n)
{
    int min=arr[0], i;
    {for(i=1; i<n; i++) {
        if(arr[i]<min)
            min=arr[i];}}
    printf("%d\n ", min);         
}
int get_sum(int arr[], int n)
{
int sum=0;
int sumsum=0;
int i;
    for(i=0; i<n; i++){
        sum=arr[i]%2;
            if(sum==0){
            sumsum=arr[i]+sumsum;}
    }
        printf("%d\n ", sumsum);
}
int get_count_first_el(int arr[], int n)
{
    int i, first=arr[0], counter=0;
    for(i=1; i<n; i++){
        if(arr[0]==arr[i]){
            counter++;
        }
    }
    printf("%d\n", counter);
}
void menu(int ch, int arr[], int n)
{
    switch(ch) {
        case 0:
        get_max(arr, n);
        break;
        case 1:
        get_min(arr, n);
        break;
        case 2:
        get_sum(arr, n);
        break;
        case 3:
        get_count_first_el(arr,n);
        break;
        default:
        printf("Данные некорректны\n");
        break;
    }
}