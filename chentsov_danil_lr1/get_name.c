#include <stdio.h>
#include <stdlib.h>
#include "get_name.h"

char* get_name() { 
  int c;
  int i = 0;
   static char input[100];
  while((c = getchar()) != '\n') {
          input[i] = c;
          i++;
  }
  input[i] = '\0';
  return input;
}
