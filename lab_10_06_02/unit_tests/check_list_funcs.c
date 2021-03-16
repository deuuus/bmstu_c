#include "list_funcs.h"

node_t *init(elem_t elems[], int begin, int end, node_t *head)
{
    for (int i = begin; i < end; i++)
        head = push_back(head, create(elems[i].item, elems[i].row, elems[i].col));
    return head;
}

START_TEST(expand_lists_with_all_matching_non_zero_elems)
{
    node_t *head_a = NULL, *head_b = NULL;
    elem_t elems[4];
    int n = sizeof(elems) / sizeof(elems[0]);
    elems[0].item = 1, elems[0].row = 0, elems[0].col = 0;
    elems[1].item = 5, elems[1].row = 1, elems[1].col = 1;
    elems[2].item = 6, elems[2].row = 0, elems[2].col = 0;
    elems[3].item = 17, elems[3].row = 1, elems[3].col = 1; 
    head_a = init(elems, 0, n / 2, head_a);
    head_b = init(elems, n / 2, n, head_b);
    head_a = expand(head_a, head_b);
    head_b = expand(head_b, head_a);
    int rc = 0;
    node_t *cur_a = head_a, *cur_b = head_b;
    rc += cmp(cur_a->data, 1, 0, 0) + cmp(cur_b->data, 6, 0, 0);
    cur_a = cur_a->next;
    cur_b = cur_b->next;
    rc += cmp(cur_a->data, 5, 1, 1) + cmp(cur_b->data, 17, 1, 1);
    rc += !(cur_a->next == NULL && cur_b->next == NULL);
    free_all(head_a);
    free_all(head_b);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(expand_lists_new_non_zero_positions_in_one_of_the_lists)
{
    node_t *head_a = NULL, *head_b = NULL;
    elem_t elems[5];
    int n = sizeof(elems) / sizeof(elems[0]);
    elems[0].item = 1, elems[0].row = 0, elems[0].col = 0;
    elems[1].item = 5, elems[1].row = 0, elems[1].col = 1;
    elems[2].item = 3, elems[2].row = 1, elems[2].col = 0;
    elems[3].item = 4, elems[3].row = 0, elems[3].col = 1;
    elems[4].item = 7, elems[4].row = 1, elems[4].col = 1; 
    head_a = init(elems, 0, 3, head_a);
    head_b = init(elems, 3, n, head_b);
    head_a = expand(head_a, head_b);
    head_b = expand(head_b, head_a);
    int rc = 0;
    node_t *cur_a = head_a, *cur_b = head_b;
    rc += cmp(cur_a->data, 1, 0, 0) + cmp(cur_b->data, 0, 0, 0);
    cur_a = cur_a->next;
    cur_b = cur_b->next;
    rc += cmp(cur_a->data, 5, 0, 1) + cmp(cur_b->data, 4, 0, 1);
    cur_a = cur_a->next;
    cur_b = cur_b->next;
    rc += cmp(cur_a->data, 3, 1, 0) + cmp(cur_b->data, 0, 1, 0);
    cur_a = cur_a->next;
    cur_b = cur_b->next;
    rc += cmp(cur_a->data, 0, 1, 1) + cmp(cur_b->data, 7, 1, 1);
    rc += !(cur_a->next == NULL && cur_b->next == NULL);
    free_all(head_a);
    free_all(head_b);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(expand_add_new_position_to_the_middle_of_the_row)
{
    node_t *head_a = NULL, *head_b = NULL;
    elem_t elems[5];
    int n = sizeof(elems) / sizeof(elems[0]);
    elems[0].item = 5, elems[0].row = 0, elems[0].col = 1;
    elems[1].item = 1, elems[1].row = 1, elems[1].col = 0;
    elems[2].item = 7, elems[2].row = 1, elems[2].col = 2;
    elems[3].item = 4, elems[3].row = 0, elems[3].col = 1;
    elems[4].item = 5, elems[4].row = 1, elems[4].col = 1; 
    head_a = init(elems, 0, 3, head_a);
    head_b = init(elems, 3, n, head_b);
    head_a = expand(head_a, head_b);
    head_b = expand(head_b, head_a);
    int rc = 0;
    node_t *cur_a = head_a, *cur_b = head_b;
    rc += cmp(cur_a->data, 5, 0, 1) + cmp(cur_b->data, 4, 0, 1);
    cur_a = cur_a->next;
    cur_b = cur_b->next;
    rc += cmp(cur_a->data, 1, 1, 0) + cmp(cur_b->data, 0, 1, 0);
    cur_a = cur_a->next;
    cur_b = cur_b->next;
    rc += cmp(cur_a->data, 0, 1, 1) + cmp(cur_b->data, 5, 1, 1);
    cur_a = cur_a->next;
    cur_b = cur_b->next;
    rc += cmp(cur_a->data, 7, 1, 2) + cmp(cur_b->data, 0, 1, 2);
    rc += !(cur_a->next == NULL && cur_b->next == NULL);
    free_all(head_a);
    free_all(head_b);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(expand_add_new_column)
{
    node_t *head_a = NULL, *head_b = NULL;
    elem_t elems[3];
    int n = sizeof(elems) / sizeof(elems[0]);
    elems[0].item = 1, elems[0].row = 0, elems[0].col = 0;
    elems[1].item = 2, elems[1].row = 1, elems[1].col = 1;
    elems[2].item = 3, elems[2].row = 1, elems[2].col = 2; 
    head_a = init(elems, 0, 2, head_a);
    head_b = init(elems, 2, n, head_b);
    head_a = expand(head_a, head_b);
    head_b = expand(head_b, head_a);
    int rc = 0;
    node_t *cur_a = head_a, *cur_b = head_b;
    rc += cmp(cur_a->data, 1, 0, 0) + cmp(cur_b->data, 0, 0, 0);
    cur_a = cur_a->next;
    cur_b = cur_b->next;
    rc += cmp(cur_a->data, 2, 1, 1) + cmp(cur_b->data, 0, 1, 1);
    cur_a = cur_a->next;
    cur_b = cur_b->next;
    rc += cmp(cur_a->data, 0, 1, 2) + cmp(cur_b->data, 3, 1, 2);
    rc += !(cur_a->next == NULL && cur_b->next == NULL);
    free_all(head_a);
    free_all(head_b);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

Suite* expand_suite(void)
{
    Suite *s;
    TCase *tc;
    s = suite_create("expand");
    tc = tcase_create("general");
    tcase_add_test(tc, expand_lists_with_all_matching_non_zero_elems);
    tcase_add_test(tc, expand_lists_new_non_zero_positions_in_one_of_the_lists);
    tcase_add_test(tc, expand_add_new_position_to_the_middle_of_the_row);
    tcase_add_test(tc, expand_add_new_column);
    suite_add_tcase(s, tc);
    return s;
}

START_TEST(insert_in_empty_list)
{
    node_t *head = NULL;
    node_t *to_insert = create(5, 5, 5);
    head = insert(head, to_insert, head);
    int rc = cmp(head->data, 5, 5, 5);
    free_all(head);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(insert_before_head)
{
    node_t *head = NULL;
    elem_t elems[2];
    int n = sizeof(elems) / sizeof(elems[0]);
    elems[0].item = 1, elems[0].row = 0, elems[0].col = 0;
    elems[1].item = 5, elems[1].row = 1, elems[1].col = 1;
    head = init(elems, 0, n, head);
    node_t *to_insert = create(2, 3, 4);
    head = insert(head, to_insert, head);
    node_t *cur = head;
    int rc = cmp(cur->data, 2, 3, 4);
    cur = cur->next;
    rc += cmp(cur->data, 1, 0, 0);
    cur = cur->next;
    rc += cmp(cur->data, 5, 1, 1);
    free_all(head);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(insert_before_tail)
{
    node_t *head = NULL;
    elem_t elems[2];
    int n = sizeof(elems) / sizeof(elems[0]);
    elems[0].item = 1, elems[0].row = 0, elems[0].col = 0;
    elems[1].item = 5, elems[1].row = 1, elems[1].col = 1;
    head = init(elems, 0, n, head);
    node_t *to_insert = create(2, 3, 4);
    head = insert(head, to_insert, head->next);
    node_t *cur = head;
    int rc = cmp(cur->data, 1, 0, 0);
    cur = cur->next;
    rc += cmp(cur->data, 2, 3, 4);
    cur = cur->next;
    rc += cmp(cur->data, 5, 1, 1);
    free_all(head);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(insert_in_list)
{
    node_t *head = NULL;
    elem_t elems[5];
    int n = sizeof(elems) / sizeof(elems[0]);
    elems[0].item = 5, elems[0].row = 0, elems[0].col = 1;
    elems[1].item = 1, elems[1].row = 1, elems[1].col = 0;
    elems[2].item = 7, elems[2].row = 1, elems[2].col = 2;
    elems[3].item = 4, elems[3].row = 0, elems[3].col = 1;
    elems[4].item = 5, elems[4].row = 1, elems[4].col = 1; 
    head = init(elems, 0, n, head);
    node_t *to_insert = create(2, 3, 4);
    head = insert(head, to_insert, head->next->next->next);
    node_t *cur = head;
    int rc = cmp(cur->data, 5, 0, 1);
    cur = cur->next;
    rc += cmp(cur->data, 1, 1, 0);
    cur = cur->next;
    rc += cmp(cur->data, 7, 1, 2);
    cur = cur->next;
    rc += cmp(cur->data, 2, 3, 4);
    cur = cur->next;
    rc += cmp(cur->data, 4, 0, 1);
    cur = cur->next;
    rc += cmp(cur->data, 5, 1, 1);
    free_all(head);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

Suite* insert_suite(void)
{
    Suite *s;
    TCase *tc;
    s = suite_create("insert");
    tc = tcase_create("general");
    tcase_add_test(tc, insert_in_empty_list);
    tcase_add_test(tc, insert_before_head);
    tcase_add_test(tc, insert_before_tail);
    tcase_add_test(tc, insert_in_list);
    suite_add_tcase(s, tc);
    return s;
}

START_TEST(remove_zeros_in_list_without_zeros)
{
    node_t *head = NULL;
    elem_t elems[3];
    int n = sizeof(elems) / sizeof(elems[0]);
    elems[0].item = 5, elems[0].row = 0, elems[0].col = 1;
    elems[1].item = 1, elems[1].row = 1, elems[1].col = 0;
    elems[2].item = 7, elems[2].row = 1, elems[2].col = 2;
    head = init(elems, 0, n, head);
    head = remove_zeros(head);
    int rc = 0;
    node_t *cur = head;
    rc += cmp(cur->data, 5, 0, 1);
    cur = cur->next;
    rc += cmp(cur->data, 1, 1, 0);
    cur = cur->next;
    rc += cmp(cur->data, 7, 1, 2);
    free_all(head);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(remove_zeroes_in_list_where_all_elems_are_zero)
{
    node_t *head = NULL;
    elem_t elems[3];
    int n = sizeof(elems) / sizeof(elems[0]);
    elems[0].item = 0, elems[0].row = 0, elems[0].col = 1;
    elems[1].item = 0, elems[1].row = 1, elems[1].col = 0;
    elems[2].item = 0, elems[2].row = 1, elems[2].col = 2;
    head = init(elems, 0, n, head);
    head = remove_zeros(head);
    int rc = !(head == NULL);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(remove_zeroes_in_the_middle_of_the_list)
{
    node_t *head = NULL;
    elem_t elems[3];
    int n = sizeof(elems) / sizeof(elems[0]);
    elems[0].item = 1, elems[0].row = 0, elems[0].col = 1;
    elems[1].item = 0, elems[1].row = 1, elems[1].col = 0;
    elems[2].item = 2, elems[2].row = 1, elems[2].col = 2;
    head = init(elems, 0, n, head);
    head = remove_zeros(head);
    int rc = 0;
    node_t *cur = head;
    rc += cmp(cur->data, 1, 0, 1);
    cur = cur->next;
    rc += cmp(cur->data, 2, 1, 2);
    free_all(head);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(remove_zeros_at_the_end_of_the_list)
{
    node_t *head = NULL;
    elem_t elems[4];
    int n = sizeof(elems) / sizeof(elems[0]);
    elems[0].item = 1, elems[0].row = 0, elems[0].col = 1;
    elems[1].item = 2, elems[1].row = 1, elems[1].col = 2;
    elems[2].item = 0, elems[2].row = 1, elems[2].col = 0;
    elems[3].item = 0, elems[2].row = 1, elems[2].col = 1;
    head = init(elems, 0, n, head);
    head = remove_zeros(head);
    int rc = 0;
    node_t *cur = head;
    rc += cmp(cur->data, 1, 0, 1);
    cur = cur->next;
    rc += cmp(cur->data, 2, 1, 2);
    free_all(head);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(remove_zeros_from_the_begining_of_the_list)
{
    node_t *head = NULL;
    elem_t elems[4];
    int n = sizeof(elems) / sizeof(elems[0]);
    elems[0].item = 0, elems[0].row = 0, elems[0].col = 1;
    elems[1].item = 0, elems[1].row = 1, elems[1].col = 2;
    elems[2].item = 1, elems[2].row = 1, elems[2].col = 0;
    elems[3].item = 2, elems[3].row = 1, elems[3].col = 1;
    head = init(elems, 0, n, head);
    head = remove_zeros(head);
    int rc = 0;
    node_t *cur = head;
    rc += cmp(cur->data, 1, 1, 0);
    cur = cur->next;
    rc += cmp(cur->data, 2, 1, 1);
    free_all(head);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

Suite* remove_zeros_suite(void)
{
    Suite *s;
    TCase *tc;
    s = suite_create("remove_zeros");
    tc = tcase_create("general");
    tcase_add_test(tc, remove_zeros_in_list_without_zeros);
    tcase_add_test(tc, remove_zeroes_in_list_where_all_elems_are_zero);
    tcase_add_test(tc, remove_zeroes_in_the_middle_of_the_list);
    tcase_add_test(tc, remove_zeros_at_the_end_of_the_list);
    tcase_add_test(tc, remove_zeros_from_the_begining_of_the_list);
    suite_add_tcase(s, tc);
    return s;
}

START_TEST(add_matrices_with_matching_non_zero_positions)
{
    node_t *head_a = NULL, *head_b = NULL;
    elem_t elems[4];
    int n = sizeof(elems) / sizeof(elems[0]);
    elems[0].item = 1, elems[0].row = 0, elems[0].col = 0;
    elems[1].item = 2, elems[1].row = 1, elems[1].col = 1;
    elems[2].item = 2, elems[2].row = 0, elems[2].col = 0;
    elems[3].item = 1, elems[3].row = 1, elems[3].col = 1; 
    head_a = init(elems, 0, 2, head_a);
    head_b = init(elems, 2, n, head_b);
    head_a = add(head_a, head_b);
    int rc = 0;
    node_t *cur = head_a;
    rc += cmp(cur->data, 3, 0, 0);
    cur = cur->next;
    rc += cmp(cur->data, 3, 1, 1);
    free_all(head_a);
    free_all(head_b);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

// START_TEST(add_matrices_with_the_need_to_extend)
// {
//     node_t *head_a = NULL, *head_b = NULL;
//     elem_t elems[4];
//     int n = sizeof(elems) / sizeof(elems[0]);
//     elems[0].item = 1, elems[0].row = 0, elems[0].col = 0;
//     elems[1].item = 2, elems[1].row = 1, elems[1].col = 1;
//     elems[2].item = 5, elems[2].row = 0, elems[2].col = 1;
//     elems[3].item = 1, elems[3].row = 1, elems[3].col = 1; 
//     head_a = init(elems, 0, 2, head_a);
//     head_b = init(elems, 2, n, head_b);
//     head_a = add(head_a, head_b);
//     int rc = 0;
//     node_t *cur = head_a;
//     rc += cmp(cur->data, 1, 0, 0);
//     cur = cur->next;
//     rc += cmp(cur->data, 5, 0, 1);
//     cur = cur->next;
//     rc += cmp(cur->data, 3, 1, 1);
//     free_all(head_a);
//     free_all(head_b);
//     ck_assert_int_eq(rc, EXIT_SUCCESS);
// }
// END_TEST

START_TEST(add_matrices_some_elems_become_zero)
{
    node_t *head_a = NULL, *head_b = NULL;
    elem_t elems[4];
    int n = sizeof(elems) / sizeof(elems[0]);
    elems[0].item = 1, elems[0].row = 0, elems[0].col = 0;
    elems[1].item = 2, elems[1].row = 1, elems[1].col = 1;
    elems[2].item = 5, elems[2].row = 0, elems[2].col = 0;
    elems[3].item = -2, elems[3].row = 1, elems[3].col = 1; 
    head_a = init(elems, 0, 2, head_a);
    head_b = init(elems, 2, n, head_b);
    head_a = add(head_a, head_b);
    int rc = 0;
    node_t *cur = head_a;
    rc += cmp(cur->data, 6, 0, 0);
    free_all(head_a);
    free_all(head_b);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(add_matrices_the_matrix_becomes_zero)
{
    node_t *head_a = NULL, *head_b = NULL;
    elem_t elems[4];
    int n = sizeof(elems) / sizeof(elems[0]);
    elems[0].item = -5, elems[0].row = 0, elems[0].col = 0;
    elems[1].item = 2, elems[1].row = 1, elems[1].col = 1;
    elems[2].item = 5, elems[2].row = 0, elems[2].col = 0;
    elems[3].item = -2, elems[3].row = 1, elems[3].col = 1; 
    head_a = init(elems, 0, 2, head_a);
    head_b = init(elems, 2, n, head_b);
    head_a = add(head_a, head_b);
    int rc = !(head_a == NULL);
    free_all(head_a);
    free_all(head_b);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

Suite* add_suite(void)
{
    Suite *s;
    TCase *tc;
    s = suite_create("add");
    tc = tcase_create("general");
    tcase_add_test(tc, add_matrices_with_matching_non_zero_positions);
    //tcase_add_test(tc, add_matrices_with_the_need_to_extend);
    tcase_add_test(tc, add_matrices_some_elems_become_zero);
    tcase_add_test(tc, add_matrices_the_matrix_becomes_zero);
    suite_add_tcase(s, tc);
    return s;
}

START_TEST(mul_matrices_first_matrix_is_zero)
{
    node_t *head_a = NULL, *head_b = NULL;
    elem_t elems[2];
    int n = sizeof(elems) / sizeof(elems[0]);
    elems[0].item = 1, elems[0].row = 0, elems[0].col = 0;
    elems[1].item = 2, elems[1].row = 1, elems[1].col = 1;
    head_b = init(elems, 0, n, head_b);
    node_t *prod = mul(head_a, head_b);
    int rc = !(prod == NULL);
    free_all(head_b);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(mul_matrices_second_matrix_is_zero)
{
    node_t *head_a = NULL, *head_b = NULL;
    elem_t elems[2];
    int n = sizeof(elems) / sizeof(elems[0]);
    elems[0].item = 1, elems[0].row = 0, elems[0].col = 0;
    elems[1].item = 2, elems[1].row = 1, elems[1].col = 1;
    head_a = init(elems, 0, n, head_a);
    node_t *prod = mul(head_a, head_b);
    int rc = !(prod == NULL);
    free_all(head_a);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(mul_matrices_non_zero_result)
{
    node_t *head_a = NULL, *head_b = NULL;
    elem_t elems[4];
    int n = sizeof(elems) / sizeof(elems[0]);
    elems[0].item = 1, elems[0].row = 0, elems[0].col = 0;
    elems[1].item = 2, elems[1].row = 1, elems[1].col = 1;
    elems[2].item = 3, elems[2].row = 0, elems[2].col = 0;
    elems[3].item = 4, elems[3].row = 1, elems[3].col = 0;
    head_a = init(elems, 0, 2, head_a);
    head_b = init(elems, 2, n, head_b);
    node_t *prod = mul(head_a, head_b);
    int rc = 0;
    rc += cmp(prod->data, 3, 0, 0);
    rc += cmp(prod->next->data, 8, 1, 0);
    free_all(prod);
    free_all(head_a);
    free_all(head_b);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

Suite* mul_suite(void)
{
    Suite *s;
    TCase *tc;
    s = suite_create("mul");
    tc = tcase_create("general");
    tcase_add_test(tc, mul_matrices_first_matrix_is_zero);
    tcase_add_test(tc, mul_matrices_second_matrix_is_zero);
    tcase_add_test(tc, mul_matrices_non_zero_result);
    suite_add_tcase(s, tc);
    return s;
}

START_TEST(remove_line_with_max_in_matrix_with_one_non_zero_elem)
{
    node_t *head = create(1, 0, 0);
    head = remove_line_with_max(head);
    int rc = !(head == NULL);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(remove_line_with_max_remove_middle_non_zero_row)
{
    node_t *head = NULL;
    elem_t elems[4];
    int n = sizeof(elems) / sizeof(elems[0]);
    elems[0].item = 1, elems[0].row = 0, elems[0].col = 1;
    elems[1].item = 2, elems[1].row = 1, elems[1].col = 0;
    elems[2].item = 7, elems[2].row = 1, elems[2].col = 2;
    elems[3].item = 4, elems[3].row = 2, elems[3].col = 0;
    head = init(elems, 0, n, head);
    head = remove_line_with_max(head);
    int rc = 0;
    node_t *cur = head;
    rc += cmp(cur->data, 1, 0, 1);
    cur = cur->next;
    rc += cmp(cur->data, 4, 2, 0);
    free_all(head);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(remove_line_with_max_remove_last_row)
{
    node_t *head = NULL;
    elem_t elems[4];
    int n = sizeof(elems) / sizeof(elems[0]);
    elems[0].item = 1, elems[0].row = 0, elems[0].col = 1;
    elems[1].item = 2, elems[1].row = 1, elems[1].col = 0;
    elems[2].item = 7, elems[2].row = 1, elems[2].col = 2;
    elems[3].item = 9, elems[3].row = 2, elems[3].col = 0;
    head = init(elems, 0, n, head);
    head = remove_line_with_max(head);
    int rc = 0;
    node_t *cur = head;
    rc += cmp(cur->data, 1, 0, 1);
    cur = cur->next;
    rc += cmp(cur->data, 2, 1, 0);
    cur = cur->next;
    rc += cmp(cur->data, 7, 1, 2);
    free_all(head);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(remove_line_with_max_remove_first_row)
{
    node_t *head = NULL;
    elem_t elems[4];
    int n = sizeof(elems) / sizeof(elems[0]);
    elems[0].item = 11, elems[0].row = 0, elems[0].col = 1;
    elems[1].item = 2, elems[1].row = 1, elems[1].col = 0;
    elems[2].item = 7, elems[2].row = 1, elems[2].col = 2;
    elems[3].item = 9, elems[3].row = 2, elems[3].col = 0;
    head = init(elems, 0, n, head);
    head = remove_line_with_max(head);
    int rc = 0;
    node_t *cur = head;
    rc += cmp(cur->data, 2, 1, 0);
    cur = cur->next;
    rc += cmp(cur->data, 7, 1, 2);
    cur = cur->next;
    rc += cmp(cur->data, 9, 2, 0);
    free_all(head);
    ck_assert_int_eq(rc, EXIT_SUCCESS);    
}
END_TEST

Suite* remove_line_with_max_suite(void)
{
    Suite *s;
    TCase *tc;
    s = suite_create("remove_line_with_max");
    tc = tcase_create("general");
    tcase_add_test(tc, remove_line_with_max_in_matrix_with_one_non_zero_elem);
    tcase_add_test(tc, remove_line_with_max_remove_middle_non_zero_row);
    tcase_add_test(tc, remove_line_with_max_remove_last_row);
    tcase_add_test(tc, remove_line_with_max_remove_first_row);
    suite_add_tcase(s, tc);
    return s;
}