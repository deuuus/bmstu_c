#include "matrix.h"
#include "operations.h"
#include <check.h>
#include "check_operations.c"

int main()
{
    int no_failed_operations = 0;
    Suite *s;
    SRunner *runner;
    s = operations_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed_operations = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (no_failed_operations == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}