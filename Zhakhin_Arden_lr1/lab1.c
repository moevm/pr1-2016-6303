#include <stdio.h>
#include <time.h>
#define N 1000

int cmp(const void *a, const void *b)  //функция сравнения
{
     return *(int*)a - *(int*)b;
}

int main()
{
    int arr_puz[N]; // массив для метода пузырька
    int arr_qsort[N]; // массив для быстрой сортировки

    int i = 0;
    int j = 0;
    for (i = 0; i<N; i++)
        scanf("%d", &arr_puz[i]); //запишем входные данные в один из массивов

    for (i = 0; i<N; i++)
    {
      arr_qsort[i] = arr_puz[i]; //скопируем один массив в другой
    }

    clock_t t_puz;
    t_puz = clock();  //засекаем начальное время
    for(i = 0 ; i < N - 1; i++)
    {
       // сравниваем два соседних элемента.
       for(j = 0 ; j < N - i - 1 ; j++)
       {
           if(arr_puz[j] > arr_puz[j+1])
           {
              // если они идут в неправильном порядке, то меняем их местами.
              int tmp = arr_puz[j];
              arr_puz[j] = arr_puz[j+1] ;
              arr_puz[j+1] = tmp;
           }
        }
    }
    t_puz = clock() - t_puz;  //вычисляем время сортировки пузырьком

    clock_t t_qsort;
    t_qsort = clock();  // засекаем начальное время
    qsort(arr_qsort, N, sizeof(int), cmp );  //выполняем быструю сортировку
    t_qsort = clock() - t_qsort;  // вычисляем время быстрой сортировки

    for(i = 0 ; i < N; i++) // выводим отсортированный массив
    {
        printf("%d ", arr_qsort[i]);
    }

    printf("\n");
    printf("%f\n", t_puz);
    printf("%f\n", t_qsort);

  return 0;
}
