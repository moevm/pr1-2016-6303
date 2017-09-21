int get_max(int arr[], int n)
{
    int j, max = arr[0];
    for (j = 1; j < n; ++j)
        if (arr[j] > max)
            max = arr[j];
    printf("%d\n", max);
}

int get_min(int arr[], int n)
{
    int j, min = arr[0];
    for (j = 1; j < n; ++j)
        if (arr[j] < min)
            min = arr[j];
    printf("%d\n", min);
}

int get_sum(int arr[], int n)
{
    int j, sum = 0;
    for (j = 0; j < n; ++j)
        if ((arr[j] % 2) == 0)
            sum += arr[j];
    printf("%d\n", sum);
}

int get_count_first_el(int arr[], int n)
{
    int j, amount = 0;
    for (j = 1; j < n; ++j)
        if (arr[j] == arr[0])
            ++amount;
    printf("%d\n", amount);
}

void menu(int ch, int arr[], int n)
{
    int i;
    scanf("%d%d", n, ch);
    for (i = 0; i < n; ++i)
        scanf("%d", arr[i]);
    switch(ch)
    {
        case 0:
        {
            get_max(arr, n);
            break;
        }
        case 1:
        {
            get_min(arr, n);
            break;
        }
        case 2:
        {
            get_sum(arr, n);
            break;
        }
        case 3:
        {
            get_count_first_el(arr, n);
            break;
        }
        default:
        {
            printf("Данные некорректны\n");
            break;
        }
    }
}
