#include "my_string.h"
#include "unit_tests.h"


int main(void)
{
    test_my_strpbrk();
    test_my_strspn();
    test_my_strcspn();
    test_my_strchr();
    test_my_strrchr();
    return EXIT_SUCCESS;
}