#include <stdio.h>
#include <stdlib.h>

int get_max(int n, int arr[]){
        int max = arr[0];
        int i;
        for(i = 0; i < n; ++i){
        if (arr[i] > max)
        max = arr[i];}
printf("%d", max);
    return 0;
}

int get_min(int n, int arr[]){
        int min = arr[0];
        int i;
        for(i = 0; i < n; ++i){
        if (arr[i] < min)
        min = arr[i];}
printf("%d", min);
    return 0;
}

int get_sum(int n, int arr[]){
        int sum = 0;
        int i;
        for(i = 0; i < n; ++i){
        if (arr[i]%2==0)
        sum = sum + arr[i];
        }
printf("%d", sum);
    return 0;
}

int get_count_first_el(int n, int arr[])
{
        int i;
        int zeros=0;
        int funct = arr[0];
        for(i = 1; i < n; ++i){
        if (arr[i] == funct)
         {
        ++zeros;
         }
        }
printf("%d", zeros);
    return 0;
}



void menu(int ch, int arr[],int n){
        switch(ch){
                case 0:
                get_max(n, arr);
                break;
                case 1:
                get_min(n, arr);
                break;
                case 2:
                get_sum(n, arr);
                break;
                case 3:
                get_count_first_el( n, arr );
                break;
                default:
                printf("Данные некорректны");}
}

