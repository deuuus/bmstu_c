#include <stdio.h>
#include "my_snprintf.h"

#define SIZE 15

int main()
{
    printf("Testing:\n");
    char buf_lib[SIZE + 1], buf_my[SIZE + 1];
    long a = 156;
    snprintf(buf_lib, SIZE + 1, "test %ld", a);
    printf("\nlib result = %s\n", buf_lib);
    my_snprintf(buf_my, SIZE + 1, "test %ld", a);
    printf("my result = %s\n", buf_my);
    return EXIT_SUCCESS;
}
