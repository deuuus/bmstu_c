#include "sort.h"

int cmp(const int *a, const int *b, int n)
{
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
} 

START_TEST(test_one_elem)
{
    int a[] = { 7 };
    int n = sizeof(a) / sizeof(a[0]);
    int b[] = { 7 };
    mysort(a, n, sizeof(int), (int (*)(const void *, const void *))compare_int);
    ck_assert_int_eq(cmp(a, b, n), EXIT_SUCCESS);
}   
END_TEST

START_TEST(test_two_different_elem){
    int a[] = { 5, 3 };
    int n = sizeof(a) / sizeof(a[0]);
    int b[] = { 3, 5 };
    mysort(a, n, sizeof(int), (int (*)(const void *, const void *))compare_int);
    ck_assert_int_eq(cmp(a, b, n), EXIT_SUCCESS);
}
END_TEST

START_TEST(test_with_some_eq_elem){
    int a[] = { 3, 1, 3 };
    int n = sizeof(a) / sizeof(a[0]);
    int b[] = { 1, 3, 3 };
    mysort(a, n, sizeof(int), (int (*)(const void *, const void *))compare_int);
    ck_assert_int_eq(cmp(a, b, n), EXIT_SUCCESS);
}
END_TEST

START_TEST(test_three_different_ordered_elem){
    int a[] = { 1, 2, 3 };
    int n = sizeof(a) / sizeof(a[0]);
    int b[] = { 1, 2, 3 };
    mysort(a, n, sizeof(int), (int (*)(const void *, const void *))compare_int);
    ck_assert_int_eq(cmp(a, b, n), EXIT_SUCCESS);
}
END_TEST

START_TEST(test_with_neg_elems){
    int a[] = { 1, -3, 22 };
    int n = sizeof(a) / sizeof(a[0]);
    int b[] = { -3, 1, 22 };
    mysort(a, n, sizeof(int), (int (*)(const void *, const void *))compare_int);
    ck_assert_int_eq(cmp(a, b, n), EXIT_SUCCESS);
}
END_TEST

Suite* mysort_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    s = suite_create("mysort");
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_one_elem);
    tcase_add_test(tc_pos, test_two_different_elem);
    tcase_add_test(tc_pos, test_with_some_eq_elem);
    tcase_add_test(tc_pos,test_three_different_ordered_elem);
    tcase_add_test(tc_pos, test_with_neg_elems);
    suite_add_tcase(s, tc_pos);
    return s;
}