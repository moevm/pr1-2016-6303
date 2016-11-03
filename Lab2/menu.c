#include <stdio.h>
#include "menu.h"
#include "get_max.h"
#include "get_min.h"
#include "get_sum.h"
#include "get_count_first_el.h"

void menu(int ch, int arr[], int n)
{
  switch(ch)
  {
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
      get_count_first_el(arr, n);
      break;
    default:
      printf("Данные некорректны\n");
      break;
  }
}
