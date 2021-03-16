#include "operations.h"
#include <assert.h>

int cmp(int **a, int **b, int m, int n)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != b[i][j])
                return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

START_TEST(square_matrix_with_one_elem)
{
    int **a, **b;
    int m = 1, n = 1;
    a = allocate_matrix(m, n);
    assert(a);
    b = allocate_matrix(m, n);
    assert(b);
    a[0][0] = 1;
    b[0][0] = 1;
    square(a, &m, &n);
    int rc = cmp(a, b, m, n);
    free_matrix(a, m);
    free_matrix(b, m);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(square_matrix_with_more_rows)
{
    int **a, **b;
    int m = 2, n = 3, init_m = m;
    int k = m;
    if (n < m)
        k = n;
    a = allocate_matrix(m, n);
    assert(a);
    b = allocate_matrix(k, k);
    assert(b);
    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[1][0] = 4;
    a[1][1] = 5;
    a[1][2] = 6;
    b[0][0] = 2;
    b[0][1] = 3;
    b[1][0] = 5;
    b[1][1] = 6;
    square(a, &m, &n);
    int rc = k == m && k == n && cmp(a, b, m, n);
    free_matrix(a, init_m);
    free_matrix(b, k);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(square_matrix_with_more_cols)
{
    int **a, **b;
    int m = 3, n = 2, init_m = m;
    int k = m;
    if (n < m)
        k = n;
    a = allocate_matrix(m, n);
    assert(a);
    b = allocate_matrix(k, k);
    assert(b);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;
    a[2][0] = 5;
    a[2][1] = 6;
    b[0][0] = 3;
    b[0][1] = 4;
    b[1][0] = 5;
    b[1][1] = 6;
    square(a, &m, &n);
    int rc = k == m && k == n && cmp(a, b, m, n);
    free_matrix(a, init_m);
    free_matrix(b, k);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(append_equal_square_matrixs){
    int **a, **b, **c;
    int m = 2, n = 2, p = 2, q = 2;
    int k = m;
    if (p > m)
        k = p;
    a = allocate_matrix(k, k);
    assert(a);
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 3;
    a[1][1] = 4;
    b = allocate_matrix(k, k);
    assert(b);
    b[0][0] = 1;
    b[0][1] = 2;
    b[1][0] = 3;
    b[1][1] = 4;
    c = allocate_matrix(k, k);
    assert(c);
    c[0][0] = 1;
    c[0][1] = 2;
    c[1][0] = 3;
    c[1][1] = 4;
    append(a, b, &m, &n, &p, &q);
    int rc = m == n && n == p && p == q && q == k && cmp(a, c, k, k) && cmp(b, c, k, k);
    free_matrix(a, k);
    free_matrix(b, k);
    free_matrix(c, k);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(append_first_matrix_is_bigger)
{
    int **a, **b, **c, **d;
    int m = 3, n = 3, p = 2, q = 2;
    int k = m;
    if (p > m)
        k = p;
    a = allocate_matrix(k, k);
    assert(a);
    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[1][0] = 4;
    a[1][1] = 5;
    a[1][2] = 6;
    a[2][0] = 7;
    a[2][1] = 8;
    a[2][2] = 9;
    b = allocate_matrix(k, k);
    assert(b);
    b[0][0] = -2;
    b[0][1] = 5;
    b[1][0] = 5;
    b[1][1] = 5;
    c = allocate_matrix(k, k);
    assert(c);
    c[0][0] = 2;
    c[0][1] = 5;
    c[0][2] = -2;
    c[1][0] = 5;
    c[1][1] = 5;
    c[1][2] = 5;
    c[2][0] = 3;
    c[2][1] = 5;
    c[2][2] = 3;
    d = allocate_matrix(k, k);
    assert(d);
    d[0][0] = 1;
    d[0][1] = 2;
    d[0][2] = 3;
    d[1][0] = 4;
    d[1][1] = 5;
    d[1][2] = 6;
    d[2][0] = 7;
    d[2][1] = 8;
    d[2][2] = 9;
    append(a, b, &m, &n, &p, &q);
    int rc = m == n && n == p && p == q && q == k && cmp(b, c, k, k) && cmp(a, d, k, k);
    free_matrix(a, k);
    free_matrix(b, k);
    free_matrix(c, k);
    free_matrix(d, k);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(append_second_matrix_is_bigger)
{
    int **a, **b, **c, **d;
    int m = 1, n = 1, p = 2, q = 2;
    int k = m;
    if (p > m)
        k = p;
    a = allocate_matrix(k, k);
    assert(a);
    a[0][0] = -3;
    b = allocate_matrix(k, k);
    assert(b);
    b[0][0] = 1;
    b[0][1] = 2;
    b[1][0] = 3;
    b[1][1] = 4;
    c = allocate_matrix(k, k);
    assert(c);
    c[0][0] = -3;
    c[0][1] = -3;
    c[1][0] = -3;
    c[1][1] = -3;
    d = allocate_matrix(k, k);
    assert(d);
    d[0][0] = 1;
    d[0][1] = 2;
    d[1][0] = 3;
    d[1][1] = 4;
    append(a, b, &m, &n, &p, &q);
    int rc = m == n && n == p && p == q && q == k && cmp(a, c, k, k) && cmp(b, d, k, k);
    free_matrix(a, k);
    free_matrix(b, k);
    free_matrix(c, k);
    free_matrix(d, k);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(geom_avg_one_elem)
{
    int **a;
    int m = 1, n = 1;
    a = allocate_matrix(m, n);
    assert(a);
    a[0][0] = -7;
    int rc = 7 == geom_avg(a, m, 0);
    free_matrix(a, m);
    ck_assert_int_eq(!rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(geom_avg_several_elems)
{
    int **a;
    int m = 3, n = 1;
    a = allocate_matrix(m, n);
    assert(a);
    a[0][0] = 1;
    a[1][0] = -5;
    a[2][0] = 3;
    int rc = 2 == geom_avg(a, m, 0);
    free_matrix(a, m);
    ck_assert_int_eq(!rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(square_prod_matrixs_with_one_elem)
{
    int **a, **b, **c, **d;
    int k = 1;
    a = allocate_matrix(k, k);
    assert(a);
    a[0][0] = -4;
    b = allocate_matrix(k, k);
    assert(b);
    b[0][0] = 5;
    c = allocate_matrix(k, k);
    assert(c);
    d = allocate_matrix(k, k);
    assert(d);
    d[0][0] = -20;
    square_prod(a, b, c, k);
    int rc = cmp(c, d, k, k);
    free_matrix(a, k);
    free_matrix(b, k);
    free_matrix(c, k);
    free_matrix(d, k);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(square_prod_matrixs_with_four_elems)
{
    int **a, **b, **c, **d;
    int k = 2;
    a = allocate_matrix(k, k);
    assert(a);
    a[0][0] = -4;
    a[0][1] = 5;
    a[1][0] = 2;
    a[1][1] = 0;
    b = allocate_matrix(k, k);
    assert(b);
    b[0][0] = 1;
    b[0][1] = 2;
    b[1][0] = 0;
    b[1][1] = 3;
    c = allocate_matrix(k, k);
    assert(c);
    d = allocate_matrix(k, k);
    assert(d);
    d[0][0] = -4;
    d[0][1] = 7;
    d[1][0] = 2;
    d[1][1] = 4;
    square_prod(a, b, c, k);
    int rc = cmp(c, d, k, k);
    free_matrix(a, k);
    free_matrix(b, k);
    free_matrix(c, k);
    free_matrix(d, k);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

Suite* operations_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    s = suite_create("operations");
    tc_pos = tcase_create("general");
    tcase_add_test(tc_pos, square_matrix_with_one_elem);
    tcase_add_test(tc_pos, square_matrix_with_more_rows);
    tcase_add_test(tc_pos, square_matrix_with_more_cols);
    tcase_add_test(tc_pos, append_equal_square_matrixs);
    tcase_add_test(tc_pos, append_first_matrix_is_bigger);
    tcase_add_test(tc_pos, append_second_matrix_is_bigger);
    tcase_add_test(tc_pos, geom_avg_one_elem);
    tcase_add_test(tc_pos, geom_avg_several_elems);
    tcase_add_test(tc_pos, square_prod_matrixs_with_one_elem);
    tcase_add_test(tc_pos, square_prod_matrixs_with_four_elems);
    suite_add_tcase(s, tc_pos);
    return s;
}