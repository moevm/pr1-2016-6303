#include <stdio.h>
#include <string.h>
#include "print_str.h"
#include "get_name.h"

int main()
{
    char hello[90] = "Hello, ";
    char* result;
    result = get_name();
    print_str(strncat(hello, result, 80));
    free(result);
    return 0;
}
