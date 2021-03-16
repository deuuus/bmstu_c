#include "node.h"
#include <assert.h>

int cmp(elem_t elem, int item, int row, int col)
{
    return !(elem.item == item && elem.row == row && elem.col == col);
}

START_TEST(push_back_elem)
{  
    node_t *head = NULL;
    head = create(1, 0, 0);
    assert(head);
    head->next = create(2, 0, 1);
    assert(head->next);
    node_t *new = create(3, 1, 1);
    assert(new);
    head = push_back(head, new);
    int rc = 0;
    rc += cmp(head->data, 1, 0, 0);
    rc += cmp(head->next->data, 2, 0, 1);
    rc += cmp(head->next->next->data, 3, 1, 1);
    free_all(head);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(push_back_null)
{  
    node_t *head = NULL;
    head = create(1, 0, 0);
    assert(head);
    head->next = create(2, 0, 1);
    assert(head->next);
    node_t *new = NULL;
    head = push_back(head, new);
    int rc = 0;
    rc += cmp(head->data, 1, 0, 0);
    rc += cmp(head->next->data, 2, 0, 1);
    free_all(head);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(push_back_in_empty_list)
{  
    node_t *head = NULL;
    node_t *new = create(2, 0, 0);
    assert(new);
    head = push_back(head, new);
    int rc = cmp(head->data, 2, 0, 0);
    free_all(head);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

Suite* push_back_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;
    s = suite_create("push_back");
    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_pos, push_back_elem);
    tcase_add_test(tc_pos, push_back_in_empty_list);
    tcase_add_test(tc_neg, push_back_null);
    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    return s;
}