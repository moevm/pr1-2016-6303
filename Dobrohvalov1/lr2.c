nt get_max(int arr[], int n){
    int max=arr[0];
    for(int i=1; i<n; ++i)
    {
        if (arr[i]>max)
        max=arr[i];
    }
    return max;
}

int get_min(int arr[], int n){
    int min=arr[0];
    for(int i=1; i<n; ++i)
    {
        if (arr[i]<min)
        min=arr[i];
    }
    return min;
}

int get_sum(int arr[], int n){
    int s=0;
    for(int i=0; i<n; ++i)
    {
        int z;
        z=arr[i] % 2;
        if (z==0)
        {
            s=s+arr[i];
        }
    }
    return s;
}

int get_count_first_el(int arr[], int n){
    int z=0;
    int q=arr[0];
    int i=1;
    while (i<n)
    {
        if(q==arr[i])
        {
            ++z;
        }
        ++i;
        }
    return z;
}

void menu(int ch, int arr[], int n){        
    int asd=0;
    switch (ch){
        case 0:
            asd = get_max(arr,n);
            printf("%d",asd);
            break;
        case 1:
            asd = get_min(arr,n);
            printf("%d",asd);
            break;
        case 2:
            asd = get_sum(arr,n);
            printf("%d",asd);
            break;
        case 3:
            asd = get_count_first_el(arr,n);
            printf("%d",asd);
            break;
        default:
            printf("Данные некорректны");
    }
}
