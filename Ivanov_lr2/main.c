void menu (int ch, int arr[], int n){
    switch (ch)
   {
    case 0: get_max(&arr[0], n); break;
    case 1: get_min(&arr[0], n); break;
    case 2: get_sum(&arr[0], n); break;
    case 3: get_count_first_el(&arr[0], n); break;
    default: printf("Данные неверны\n");
   }
}

int get_max(int arr[],int n)
{
        int max=arr[0];
        for (int i=1; i<n; i++)
                {
                if (arr[i]>max) max=arr[i];
                }
        printf("%d \n", max);
}

int get_min(int arr[],int n)
{
        int min=arr[0];
        for (int i=1; i<n; i++)
                {
                if (arr[i]<min) min=arr[i];
                }
        printf("%d \n", min);
}

int get_sum(int arr[], int n)
{
        int sum=0;
        for (int i=0; i<n; i++)
                {
                if (arr[i] % 2 == 0) sum+=arr[i];
                }
        printf("%d \n", sum);
}

int get_count_first_el(int arr[],int n)
{
        int a=arr[0];
        for (int i=1; i<n; i++)
                {
                if (arr[i]==a) c++;
                }
        printf("%d \n", c);
}

