#include <stdio.h>
#include "get_count_first_el.h"

int get_count_first_el(int arr[], int n)
{
  int j, amount = 0;
  for (j = 1; j < n; ++j)
    if (arr[j] == arr[0])
      ++amount;
  printf("%d\n", amount);
}
