#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_name.h" 
#include "print_str.h"
int main() {
  char* input = get_name();
  char output[107] = "Hello, ";
  strcat(output, input);
  print_str(output);
}
