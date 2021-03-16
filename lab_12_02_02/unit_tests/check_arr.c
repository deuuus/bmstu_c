#include "arr.h"
#include <assert.h>

START_TEST(fill_fib_size_is_zero)
{
    int n = 0;
    int rc = EXIT_SUCCESS;
    long *a = malloc(sizeof(long) * (n + 1));
    assert(a);
    fill_fib(a, n);
    free(a);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(fill_fib_one_elem)
{
    int n = 1;
    long *a = malloc(sizeof(long) * (n));
    assert(a);
    fill_fib(a, n);
    int rc = !(a[0] == 1);
    free(a);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(fill_fib_several_elems)
{
    int n = 10;
    long *a = malloc(sizeof(long) * (n));
    assert(a);
    fill_fib(a, n);
    int rc = !(a[0] == 1);
    rc += !(a[1] == 1);
    rc += !(a[2] == 2);
    rc += !(a[3] == 3);
    rc += !(a[4] == 5);
    rc += !(a[5] == 8);
    rc += !(a[6] == 13);
    rc += !(a[7] == 21);
    rc += !(a[8] == 34);
    rc += !(a[9] == 55);
    free(a);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

Suite* fill_fib_suite(void)
{
    Suite *s;
    TCase *tc;
    s = suite_create("fill_fib");
    tc = tcase_create("general");
    tcase_add_test(tc, fill_fib_size_is_zero);
    tcase_add_test(tc, fill_fib_one_elem);
    tcase_add_test(tc, fill_fib_several_elems);
    suite_add_tcase(s, tc);
    return s;
}

START_TEST(unique_count_size_is_zero)
{
    int n = 0;
    int a[n + 1];
    int k = unique_count(a, n);
    int rc = !(k == 0);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(unique_count_one_elem)
{
    int n = 1;
    int a[n];
    a[0] = 7;
    int k = unique_count(a, n);
    int rc = !(k == 1 && a[0] == 7);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(unique_count_several_equal_elems)
{
    int n = 5;
    int a[n];
    a[0] = a[1] = a[2] = a[3] = a[4] = 7;
    int k = unique_count(a, n);
    int rc = !(k == 1);
    for (int i = 0; i < n; i++)
        rc += !(a[i] == 7);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(unique_count_several_elems_with_duplicates)
{
    int n = 10;
    int a[n];
    a[0] = 1;
    a[1] = 3;
    a[2] = 1;
    a[3] = 5;
    a[4] = 7;
    a[5] = 3;
    a[6] = 1;
    a[7] = 12;
    a[8] = 8;
    a[9] = 3;
    int k = unique_count(a, n);
    int rc = !(k == 6);
    rc += !(a[0] == 1);
    rc += !(a[1] == 3);
    rc += !(a[2] == 1);
    rc += !(a[3] == 5);
    rc += !(a[4] == 7);
    rc += !(a[5] == 3);
    rc += !(a[6] == 1);
    rc += !(a[7] == 12);
    rc += !(a[8] == 8);
    rc += !(a[9] == 3);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(unique_count_all_elems_are_unique)
{
    int n = 10;
    int a[n];
    for (int i = 0; i < n; i++)
        a[i] = i;
    int k = unique_count(a, n);
    int rc = !(k == 10);
    for (int i = 0; i < n; i++)
        rc += !(a[i] == i);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

Suite* unique_count_suite(void)
{
    Suite *s;
    TCase *tc;
    s = suite_create("unique_count");
    tc = tcase_create("general");
    tcase_add_test(tc, unique_count_size_is_zero);
    tcase_add_test(tc, unique_count_one_elem);
    tcase_add_test(tc, unique_count_several_equal_elems);
    tcase_add_test(tc, unique_count_several_elems_with_duplicates);
    tcase_add_test(tc, unique_count_all_elems_are_unique);
    suite_add_tcase(s, tc);
    return s;
}

START_TEST(remove_duplicates_size_is_zero)
{
    int n = 0;
    int a[n + 1], b[n + 1];
    int k = remove_duplicates(a, b, n);
    int rc = !(k == 0);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(remove_duplicates_one_elem)
{
    int n = 1;
    int a[n], b[n];
    a[0] = 7;
    int k = remove_duplicates(a, b, n);
    int rc = !(k == 1 && a[0] == b[0]);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(remove_duplicates_several_equal_elems)
{
    int n = 5;
    int a[n], b[n];
    a[0] = a[1] = a[2] = a[3] = a[4] = 7;
    int k = remove_duplicates(a, b, n);
    int rc = !(k == 1);
    for (int i = 0; i < n; i++)
        rc += !(a[i] == 7);
    rc += (b[0] == 7);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(remove_duplicates_several_elems_with_duplicates)
{
    int n = 10;
    int a[n], b[n];
    a[0] = 1;
    a[1] = 3;
    a[2] = 1;
    a[3] = 5;
    a[4] = 7;
    a[5] = 3;
    a[6] = 1;
    a[7] = 12;
    a[8] = 8;
    a[9] = 3;
    int k = remove_duplicates(a, b, n);
    int rc = !(k == 6);
    rc += !(a[0] == 1);
    rc += !(a[1] == 3);
    rc += !(a[2] == 1);
    rc += !(a[3] == 5);
    rc += !(a[4] == 7);
    rc += !(a[5] == 3);
    rc += !(a[6] == 1);
    rc += !(a[7] == 12);
    rc += !(a[8] == 8);
    rc += !(a[9] == 3);

    rc += !(b[0] == 1);
    rc += !(b[1] == 3);
    rc += !(b[2] == 5);
    rc += !(b[3] == 7);
    rc += !(b[4] == 12);
    rc += !(b[5] == 8);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(remove_duplicates_all_elems_are_unique)
{
    int n = 10;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
        a[i] = i;
    int k = remove_duplicates(a, b, n);
    int rc = !(k == 10);
    for (int i = 0; i < n; i++)
        rc += !(a[i] == i && b[i] == i);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

Suite* remove_duplicates_suite(void)
{
    Suite *s;
    TCase *tc;
    s = suite_create("remove_duplicates");
    tc = tcase_create("general");
    tcase_add_test(tc, remove_duplicates_size_is_zero);
    tcase_add_test(tc, remove_duplicates_one_elem);
    tcase_add_test(tc, remove_duplicates_several_equal_elems);
    tcase_add_test(tc, remove_duplicates_several_elems_with_duplicates);
    tcase_add_test(tc, remove_duplicates_all_elems_are_unique);
    return s;
}