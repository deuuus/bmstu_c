#include <check.h>
#include "check_my_snprintf.c"

int main()
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;
    s = my_snprintf_ld_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    s = my_snprintf_d_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    s = my_snprintf_hd_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    s = my_snprintf_s_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    s = my_snprintf_c_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    s = my_snprintf_all_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}