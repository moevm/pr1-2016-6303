#include <stdio.h>
#include "get_max.h"
#include "get_min.h"
#include "get_sum.h"
#include "get_count_first_el.h"
#include "menu.h"

int main()
{
  int i, n, ch, arr[1000] = {0};
  scanf("%d%d", &n, &ch);
    for (i = 0; i < n; ++i)
      scanf("%d", &arr[i]);
  menu(ch, arr, n);
}

