#include <stdio.h>
#include "get_sum.h"

int get_sum(int arr[], int n)
{
  int j, sum = 0;
  for (j = 0; j < n; ++j)
    if ((arr[j] % 2) == 0)
      sum += arr[j];
  printf("%d\n", sum);
}
