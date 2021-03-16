#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "check_arr.c"

int main()
{
    int no_failed_fill_fib = 0, no_failed_remove_duplicates = 0, no_failed_unique_count = 0;
    Suite *s;
    SRunner *runner;

    s = fill_fib_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed_fill_fib = srunner_ntests_failed(runner);
    srunner_free(runner);

    s = fill_fib_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed_remove_duplicates = srunner_ntests_failed(runner);
    srunner_free(runner);

    s = fill_fib_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed_unique_count = srunner_ntests_failed(runner);
    srunner_free(runner);

    int rc = no_failed_fill_fib;
    rc += no_failed_remove_duplicates;
    rc += no_failed_unique_count;

    return (rc == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}