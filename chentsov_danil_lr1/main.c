#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_name.h"
#include "print_str.h"

 void print_str(char*);

 int main() {
   char* input = get_name();
   char output[100] = "Hello, ";
   strcat(output, input);
   print_str(output);
 }
