
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "get_name.h"
#include "print_str.h"
int main()
{
char hello[90] = "Hello, ";
char* name = get_name();
strcat(hello,name);
print_str(hello);
return 0;
}

