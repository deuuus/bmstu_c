#include "key.h"

int cmp_ptr(const int *ptr, const int *ptr_end, const int arr[], int n)
{
    for (int i = 0; i < n; i++)
        if (arr[i] != *(ptr + i))
            return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

START_TEST(key_test_no_elems)
{
    int a[] = { 1 };
    int n = 0;
    int *b = NULL, *b_end = NULL;
    int rc = key(a, a + n, &b, &b_end);
    ck_assert_int_eq(rc, KEY_PARAM_ERR);
}   
END_TEST

START_TEST(key_test_invalid_src_order)
{
    int a[] = { 1, 2 };
    int n = sizeof(a) / sizeof(a[0]);
    int *b = NULL, *b_end = NULL;
    int rc = key(a + n, a, &b, &b_end);
    ck_assert_int_eq(rc, KEY_PARAM_ERR);
}   
END_TEST

START_TEST(key_test_one_elem)
{
    int a[] = { 1 };
    int n = sizeof(a) / sizeof(a[0]);
    int *b = NULL, *b_end = NULL;
    int rc = key(a, a + n, &b, &b_end);
    ck_assert_int_eq(rc, NO_DATA);
}   
END_TEST

START_TEST(key_test_all_eq_elems)
{
    int a[] = { 7, 7, 7 };
    int n = sizeof(a) / sizeof(a[0]);
    int *b = NULL, *b_end = NULL;
    int rc = key(a, a + n, &b, &b_end);
    ck_assert_int_eq(rc, NO_DATA);
}   
END_TEST

START_TEST(key_test_two_different_elems)
{
    int a[] = { 1, 7 };
    int n = sizeof(a) / sizeof(a[0]);
    int *b = NULL, *b_end = NULL;
    int rc = key(a, a + n, &b, &b_end);
    int res[] = { 7 };
    rc += cmp_ptr(b, b_end, res, sizeof(res) / sizeof(res[0]));
    free(b);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}   
END_TEST

START_TEST(key_test_two_different_neg_elems)
{
    int a[] = { -1, -7 };
    int n = sizeof(a) / sizeof(a[0]);
    int *b = NULL, *b_end = NULL;
    int rc = key(a, a + n, &b, &b_end);
    int res[] = { -1 };
    rc += cmp_ptr(b, b_end, res, sizeof(res) / sizeof(res[0]));
    free(b);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}   
END_TEST

Suite* key_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;
    s = suite_create("key");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, key_test_no_elems);
    tcase_add_test(tc_neg, key_test_invalid_src_order);
    tcase_add_test(tc_neg, key_test_one_elem);
    tcase_add_test(tc_neg, key_test_all_eq_elems);
    suite_add_tcase(s, tc_neg);
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, key_test_two_different_elems);
    tcase_add_test(tc_pos, key_test_two_different_neg_elems);
    suite_add_tcase(s, tc_pos);
    return s;
}