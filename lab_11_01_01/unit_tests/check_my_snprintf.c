#include "my_snprintf.h"
#include <assert.h>

#define SIZE 10

START_TEST(my_snprintf_ld_long_max)
{
    char buf_1[2 * SIZE], buf_2[2 * SIZE];
    int rc = EXIT_FAILURE;
    int res = my_snprintf(buf_1, sizeof(buf_1), "%ld", LONG_MAX);
    if (res == snprintf(buf_2, sizeof(buf_2), "%ld", LONG_MAX))
        rc = strcmp(buf_1, buf_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(my_snprintf_ld_long_min)
{
    char buf_1[2 * SIZE], buf_2[2 * SIZE];
    int rc = EXIT_FAILURE;
    int res = my_snprintf(buf_1, sizeof(buf_1), "%ld", LONG_MIN);
    if (res == snprintf(buf_2, sizeof(buf_2), "%ld", LONG_MIN))
        rc = strcmp(buf_1, buf_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(my_snprintf_ld_init_size_of_buf_is_more_than_param)
{
    char buf_1[SIZE + 1], buf_2[SIZE + 1];
    int rc = EXIT_FAILURE;
    int res = my_snprintf(buf_1, 2, "%ld", LONG_MIN);
    if (res == snprintf(buf_2, 2, "%ld", LONG_MIN))
        rc = strcmp(buf_1, buf_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(my_snprintf_ld_init_size_is_one_more_than_size)
{
    char buf_1[SIZE + 1], buf_2[SIZE + 1];
    long a = 1234567891;
    int rc = EXIT_FAILURE;
    int res = my_snprintf(buf_1, SIZE, "%ld", a);
    if (res == snprintf(buf_2, SIZE, "%ld", a))
        rc = strcmp(buf_1, buf_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(my_snprintf_d_int_max)
{
    char buf_1[2 * SIZE], buf_2[2 * SIZE];
    int rc = EXIT_FAILURE;
    int res = my_snprintf(buf_1, sizeof(buf_1), "%d", INT_MAX);
    if (res == snprintf(buf_2, sizeof(buf_2), "%d", INT_MAX))
        rc = strcmp(buf_1, buf_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(my_snprintf_d_int_min)
{
    char buf_1[2 * SIZE], buf_2[2 * SIZE];
    int rc = EXIT_FAILURE;
    int res = my_snprintf(buf_1, sizeof(buf_1), "%d", INT_MIN);
    if (res == snprintf(buf_2, sizeof(buf_2), "%d", INT_MIN))
        rc = strcmp(buf_1, buf_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(my_snprintf_d_init_size_of_buf_is_more_than_param)
{
    char buf_1[SIZE + 1], buf_2[SIZE + 1];
    int rc = EXIT_FAILURE;
    int res = my_snprintf(buf_1, 2, "%d", INT_MIN);
    if (res == snprintf(buf_2, 2, "%d", INT_MIN))
        rc = strcmp(buf_1, buf_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(my_snprintf_d_init_size_is_one_more_than_size)
{
    char buf_1[SIZE + 1], buf_2[SIZE + 1];
    int a = 1234891;
    int rc = EXIT_FAILURE;
    int res = my_snprintf(buf_1, SIZE, "abc%d", a);
    if (res == snprintf(buf_2, SIZE, "abc%d", a))
        rc = strcmp(buf_1, buf_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(my_snprintf_hd_short_max)
{
    char buf_1[2 * SIZE], buf_2[2 * SIZE];
    int rc = EXIT_FAILURE;
    int res = my_snprintf(buf_1, sizeof(buf_1), "%hd", SHRT_MAX);
    if (res == snprintf(buf_2, sizeof(buf_2), "%hd", SHRT_MAX))
        rc = strcmp(buf_1, buf_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(my_snprintf_hd_short_min)
{
    char buf_1[2 * SIZE], buf_2[2 * SIZE];
    int rc = EXIT_FAILURE;
    int res = my_snprintf(buf_1, sizeof(buf_1), "%hd", SHRT_MIN);
    if (res == snprintf(buf_2, sizeof(buf_2), "%hd", SHRT_MIN))
        rc = strcmp(buf_1, buf_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(my_snprintf_hd_init_size_of_buf_is_more_than_param)
{
    char buf_1[SIZE + 1], buf_2[SIZE + 1];
    int rc = EXIT_FAILURE;
    int res = my_snprintf(buf_1, 2, "%hd", SHRT_MIN);
    if (res == snprintf(buf_2, 2, "%hd", SHRT_MIN))
        rc = strcmp(buf_1, buf_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(my_snprintf_hd_init_size_is_one_more_than_size)
{
    char buf_1[SIZE + 1], buf_2[SIZE + 1];
    short a = 123;
    int rc = EXIT_FAILURE;
    int res = my_snprintf(buf_1, SIZE, "abcabca%hd", a);
    if (res == snprintf(buf_2, SIZE, "abcabca%hd", a))
        rc = strcmp(buf_1, buf_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(my_snprintf_s_result_len_is_less_than_size_param)
{
    char buf_1[SIZE + 1], buf_2[SIZE + 1];
    int rc = EXIT_FAILURE;
    char s[] = "ab"; 
    int res = my_snprintf(buf_1, 5, "a%s", s);
    if (res == snprintf(buf_2, 5, "a%s", s))
        rc = strcmp(buf_1, buf_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}

START_TEST(my_snprintf_s_russian_alphabet_is_used)
{
    char buf_1[SIZE + 1], buf_2[SIZE + 1];
    int rc = EXIT_FAILURE;
    char s[] = "ab"; 
    int res = my_snprintf(buf_1, 5, "тык%s", s);
    if (res == snprintf(buf_2, 5, "тык%s", s))
        rc = strcmp(buf_1, buf_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}

START_TEST(my_snprintf_s_result_len_is_more_than_size_param)
{
    char buf_1[SIZE + 1], buf_2[SIZE + 1];
    int rc = EXIT_FAILURE;
    char s[] = "ab"; 
    int res = my_snprintf(buf_1, 5, "abc%s", s);
    if (res == snprintf(buf_2, 5, "abc%s", s))
        rc = strcmp(buf_1, buf_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}

START_TEST(my_snprintf_s_will_be_not_included)
{
    char buf_1[SIZE + 1], buf_2[SIZE + 1];
    int rc = EXIT_FAILURE;
    char s[] = "ab"; 
    int res = my_snprintf(buf_1, 5, "abcdef%s", s);
    if (res == my_snprintf(buf_2, 5, "abcdef%s", s))
        rc = strcmp(buf_1, buf_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}

START_TEST(my_snprintf_c_result_len_is_less_than_size_param)
{
    char buf_1[SIZE + 1], buf_2[SIZE + 1];
    int rc = EXIT_FAILURE;
    char c = 'a';
    int res = my_snprintf(buf_1, 5, "a%cb", c);
    if (res == snprintf(buf_2, 5, "a%cb", c))
        rc = strcmp(buf_1, buf_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}

START_TEST(my_snprintf_c_result_len_is_more_than_size_param)
{
    char buf_1[SIZE + 1], buf_2[SIZE + 1];
    int rc = EXIT_FAILURE;
    char c = 'a';
    int res = my_snprintf(buf_1, 5, "abcd%c", c);
    if (res == snprintf(buf_2, 5, "abcd%c", c))
        rc = strcmp(buf_1, buf_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}

START_TEST(my_snprintf_c_will_be_not_included)
{
    char buf_1[SIZE + 1], buf_2[SIZE + 1];
    int rc = EXIT_FAILURE;
    char c = 'a';
    int res = my_snprintf(buf_1, 5, "abcdef%c", c);
    if (res == snprintf(buf_2, 5, "abcdef%c", c))
        rc = strcmp(buf_1, buf_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}

START_TEST(my_snprintf_c_is_passed_into_func_like_int)
{
    char buf_1[SIZE + 1], buf_2[SIZE + 1];
    int rc = EXIT_FAILURE;
    char c = 97; 
    int res = my_snprintf(buf_1, 5, "ab%c", c);
    if (res == snprintf(buf_2, 5, "ab%c", c))
    {
        rc = EXIT_SUCCESS;
        rc += strcmp(buf_1, buf_2);
    }
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}

START_TEST(my_snprintf_all_size_param_is_zero)
{
    char buf_1[SIZE + 1], buf_2[SIZE + 1];
    int rc = EXIT_SUCCESS;
    int res = my_snprintf(buf_1, 0, "%d", 5);
    if (res == snprintf(buf_2, 0, "%d", 5))
        rc = strcmp(buf_1, buf_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}

START_TEST(my_snprintf_all_several_specifiers)
{
    char buf_1[SIZE + 1], buf_2[SIZE + 1];
    int rc = EXIT_SUCCESS;
    int res = my_snprintf(buf_1, 10, "%d%s%c", 5, "Hello", 5);
    if (res == snprintf(buf_2, 10, "%d%s%c", 5, "Hello", 5))
        rc = strcmp(buf_1, buf_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}

START_TEST(my_snprintf_all_passing_more_argumnets_than_in_format)
{
    char buf_1[SIZE + 1], buf_2[SIZE + 1];
    int rc = EXIT_SUCCESS;
    int res = my_snprintf(buf_1, 10, "%d%s%c", 5, "Hello", 5, 5);
    if (res == snprintf(buf_2, 10, "%d%s%c", 5, "Hello", 5, 5))
        rc = strcmp(buf_1, buf_2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}

Suite* my_snprintf_ld_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;
    s = suite_create("ld");
    tc_pos = tcase_create("positive");
    tcase_add_test(tc_pos, my_snprintf_ld_long_max);
    tcase_add_test(tc_pos, my_snprintf_ld_long_min);
    tcase_add_test(tc_pos, my_snprintf_ld_init_size_of_buf_is_more_than_param);
    tc_neg = tcase_create("negative");
    tcase_add_test(tc_neg, my_snprintf_ld_init_size_is_one_more_than_size);
    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    return s;
}

Suite* my_snprintf_d_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;
    s = suite_create("d");
    tc_pos = tcase_create("positive");
    tcase_add_test(tc_pos, my_snprintf_d_int_max);
    tcase_add_test(tc_pos, my_snprintf_d_int_min);
    tcase_add_test(tc_pos, my_snprintf_d_init_size_of_buf_is_more_than_param);
    tc_neg = tcase_create("negative");
    tcase_add_test(tc_neg, my_snprintf_d_init_size_is_one_more_than_size);
    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    return s;
}

Suite* my_snprintf_hd_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;
    s = suite_create("hd");
    tc_pos = tcase_create("positive");
    tcase_add_test(tc_pos, my_snprintf_hd_short_max);
    tcase_add_test(tc_pos, my_snprintf_hd_short_min);
    tcase_add_test(tc_pos, my_snprintf_hd_init_size_of_buf_is_more_than_param);
    tc_neg = tcase_create("negative");
    tcase_add_test(tc_neg, my_snprintf_hd_init_size_is_one_more_than_size);
    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    return s;
}

Suite* my_snprintf_s_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;
    s = suite_create("s");
    tc_pos = tcase_create("positive");
    tcase_add_test(tc_pos, my_snprintf_s_result_len_is_less_than_size_param);
    tc_neg = tcase_create("negative");
    tcase_add_test(tc_neg, my_snprintf_s_result_len_is_more_than_size_param);
    tcase_add_test(tc_neg, my_snprintf_s_will_be_not_included);
    tcase_add_test(tc_neg, my_snprintf_s_russian_alphabet_is_used);
    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    return s;
}

Suite* my_snprintf_c_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;
    s = suite_create("c");
    tc_pos = tcase_create("positive");
    tcase_add_test(tc_pos, my_snprintf_c_result_len_is_less_than_size_param);
    tcase_add_test(tc_pos, my_snprintf_c_is_passed_into_func_like_int);
    tc_neg = tcase_create("negative");
    tcase_add_test(tc_neg, my_snprintf_c_result_len_is_more_than_size_param);
    tcase_add_test(tc_neg, my_snprintf_c_will_be_not_included);
    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    return s;
}

Suite* my_snprintf_all_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;
    s = suite_create("all");
    tc_pos = tcase_create("positive");
    tcase_add_test(tc_pos, my_snprintf_all_several_specifiers);
    tc_neg = tcase_create("negative");
    tcase_add_test(tc_neg, my_snprintf_c_will_be_not_included);
    tcase_add_test(tc_neg, my_snprintf_all_passing_more_argumnets_than_in_format);
    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    return s;
}