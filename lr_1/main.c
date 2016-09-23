#include <string.h>
#include <stdio.h>
#include "print_str.h"
#include "get_name.h"
void main()
{
    char hello[90] = "Hello, ";
    char* result;
    result = get_name();
    print_str(strncat(hello, result, 80));
}
