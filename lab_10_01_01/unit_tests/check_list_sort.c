#include "list_sort.h"

START_TEST(front_back_split_empty_list)
{
    node_t *head = NULL, *back = NULL;
    front_back_split(head, &back);
    int rc = !(head == NULL && back == NULL);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(front_back_split_empty_head_with_non_empty_back)
{
    node_t *head = NULL, *back = NULL;
    person_t people[2];
    people[0].born_year = 1756;
    strcpy(people[0].surname, "Ivanov");
    people[1].born_year = 1757;
    strcpy(people[1].surname, "Petrov");
    node_t *to_push;
    for (int i = 0; i < 2; i++)
    {
        to_push = create(&people[i]);
        assert(to_push);
        back = push_back(back, to_push);
    }
    front_back_split(head, &back);
    int rc = !(head == NULL);
    free_all(back);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(front_back_split_list_with_even_num_of_elems)
{
    node_t *head = NULL, *back = NULL;
    person_t people[4];
    int n = sizeof(people) / sizeof(people[0]);
    people[0].born_year = 1756;
    strcpy(people[0].surname, "Ivanov");
    people[1].born_year = 1757;
    strcpy(people[1].surname, "Petrov");
    people[2].born_year = 1746;
    strcpy(people[2].surname, "Sidorov");
    people[3].born_year = 1777;
    strcpy(people[3].surname, "Fedorov");
    node_t *to_push;
    for (int i = 0; i < n; i++)
    {
        to_push = create(&people[i]);
        assert(to_push);
        head = push_back(head, to_push);
    }
    front_back_split(head, &back);
    int rc = 0, i = 0;
    node_t *cur_a = head, *cur_b = back;
    for (; cur_a && cur_b && 2 * i < n; i++, cur_a = cur_a->next, cur_b = cur_b->next)
    {
        rc += cmp(cur_a->data, people[i]);
        rc += cmp(cur_b->data, people[2 + i]);
    }
    rc += !(2 * i == n);
    free_all(head);
    free_all(back);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(front_back_split_list_with_odd_num_of_elems)
{
node_t *head = NULL, *back = NULL;
    person_t people[3];
    int n = sizeof(people) / sizeof(people[0]);
    people[0].born_year = 1756;
    strcpy(people[0].surname, "Ivanov");
    people[1].born_year = 1757;
    strcpy(people[1].surname, "Petrov");
    people[2].born_year = 1746;
    strcpy(people[2].surname, "Sidorov");
    node_t *to_push;
    for (int i = 0; i < n; i++)
    {
        to_push = create(&people[i]);
        assert(to_push);
        head = push_back(head, to_push);
    }
    front_back_split(head, &back);
    int rc = 0;
    node_t *cur = head;
    rc += cmp(cur->data, people[0]);
    cur = cur->next;
    rc += cmp(cur->data, people[1]);
    cur = back;
    rc += cmp(cur->data, people[2]);
    free_all(head);
    free_all(back);
    ck_assert_int_eq(rc, EXIT_SUCCESS);   
}
END_TEST

Suite* front_back_split_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;
    s = suite_create("front_back_split");
    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, front_back_split_empty_list);
    tcase_add_test(tc_pos, front_back_split_empty_head_with_non_empty_back);
    tcase_add_test(tc_pos, front_back_split_list_with_even_num_of_elems);
    tcase_add_test(tc_pos, front_back_split_list_with_odd_num_of_elems);
    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    return s;
}

START_TEST(sorted_merge_both_lists_are_empty)
{
    node_t *head_a = NULL, *head_b = NULL;
    node_t *new_head = sorted_merge(&head_a, &head_b, cmp_people);
    int rc = !(new_head == NULL && head_a == NULL && head_b == NULL);
    ck_assert_int_eq(rc, EXIT_SUCCESS); 
}

START_TEST(sorted_merge_first_list_is_empty)
{
    node_t *head_a = NULL, *head_b = NULL;
    person_t people[2];
    people[0].born_year = 1756;
    strcpy(people[0].surname, "Ivanov");
    people[1].born_year = 1757;
    strcpy(people[1].surname, "Petrov");
    int n = sizeof(people) / sizeof(people[0]);
    node_t *to_push;
    for (int i = 0; i < n; i++)
    {
        to_push = create(&people[i]);
        assert(to_push);
        head_b = push_back(head_b, to_push);
    }
    node_t *new_head = sorted_merge(&head_a, &head_b, cmp_people);
    int rc = 0;
    node_t *cur = new_head;
    int i = 0;
    for (; cur && i < n; i++, cur = cur->next)
        rc += cmp(cur->data, people[i]);
    rc += !(i == n);
    free_all(new_head);
    ck_assert_int_eq(rc, EXIT_SUCCESS); 
}
END_TEST

START_TEST(sorted_merge_second_list_is_empty)
{
    node_t *head_a = NULL, *head_b = NULL;
    person_t people[2];
    people[0].born_year = 1756;
    strcpy(people[0].surname, "Ivanov");
    people[1].born_year = 1757;
    strcpy(people[1].surname, "Petrov");
    int n = sizeof(people) / sizeof(people[0]);
    node_t *to_push;
    for (int i = 0; i < n; i++)
    {
        to_push = create(&people[i]);
        assert(to_push);
        head_a = push_back(head_a, to_push);
    }
    node_t *new_head = sorted_merge(&head_a, &head_b, cmp_people);
    int rc = 0;
    node_t *cur = new_head;
    int i = 0;
    for (; cur && i < n; i++, cur = cur->next)
        rc += cmp(cur->data, people[i]);
    rc += !(i == n);
    free_all(new_head);
    ck_assert_int_eq(rc, EXIT_SUCCESS); 
}
END_TEST

START_TEST(sorted_merge_already_mutually_sorted_lists)
{
    node_t *head_a = NULL, *head_b = NULL;
    person_t people[4];
    people[0].born_year = 1756;
    strcpy(people[0].surname, "Ivanov");
    people[1].born_year = 1757;
    strcpy(people[1].surname, "Petrov");
    people[2].born_year = 1758;
    strcpy(people[2].surname, "Sidorov");
    people[3].born_year = 1759;
    strcpy(people[3].surname, "Fedorov");
    int n = sizeof(people) / sizeof(people[0]);
    node_t *to_push;
    for (int i = 0; 2 * i < n; i++)
    {
        to_push = create(&people[i]);
        assert(to_push);
        head_a = push_back(head_a, to_push);
        to_push = create(&people[2 + i]);
        assert(to_push);
        head_b = push_back(head_b, to_push);
    }
    node_t *new_head = sorted_merge(&head_a, &head_b, cmp_people);
    int rc = 0;
    node_t *cur = new_head;
    int i = 0;
    for (; cur && i < n; i++, cur = cur->next)
        rc += cmp(cur->data, people[i]);
    rc += !(i == n);
    free_all(new_head);
    ck_assert_int_eq(rc, EXIT_SUCCESS); 
}
END_TEST

START_TEST(sorted_merge_non_mutually_sorted_lists)
{
    node_t *head_a = NULL, *head_b = NULL;
    person_t people[4];
    people[0].born_year = 1756;
    strcpy(people[0].surname, "Ivanov");
    people[1].born_year = 1758;
    strcpy(people[1].surname, "Sidorov");
    people[2].born_year = 1757;
    strcpy(people[2].surname, "Petrov");
    people[3].born_year = 1759;
    strcpy(people[3].surname, "Fedorov");
    int n = sizeof(people) / sizeof(people[0]);
    node_t *to_push;
    for (int i = 0; 2 * i < n; i++)
    {
        to_push = create(&people[i]);
        assert(to_push);
        head_a = push_back(head_a, to_push);
        to_push = create(&people[2 + i]);
        assert(to_push);
        head_b = push_back(head_b, to_push);
    }
    node_t *new_head = sorted_merge(&head_a, &head_b, cmp_people);
    int rc = 0;
    node_t *cur = new_head;
    rc += cmp(cur->data, people[0]);
    cur = cur->next;
    rc += cmp(cur->data, people[2]);
    cur = cur->next;
    rc += cmp(cur->data, people[1]);
    cur = cur->next;
    rc += cmp(cur->data, people[3]);
    free_all(new_head);
    ck_assert_int_eq(rc, EXIT_SUCCESS); 
}
END_TEST

Suite* sorted_merge_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;
    s = suite_create("sorted_merge");
    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, sorted_merge_both_lists_are_empty);
    tcase_add_test(tc_pos, sorted_merge_first_list_is_empty);
    tcase_add_test(tc_pos, sorted_merge_second_list_is_empty);
    tcase_add_test(tc_pos, sorted_merge_already_mutually_sorted_lists);
    tcase_add_test(tc_pos, sorted_merge_non_mutually_sorted_lists);
    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    return s;
}

START_TEST(sort_empty_list)
{
    node_t *head = NULL;
    node_t *sorted = sort(head, cmp_people);
    int rc = !(head == NULL && sorted == NULL);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(sort_already_sorted_list)
{
    node_t *head = NULL;
    person_t people[4];
    int n = sizeof(people) / sizeof(people[0]);
    people[0].born_year = 1756;
    strcpy(people[0].surname, "Ivanov");
    people[1].born_year = 1757;
    strcpy(people[1].surname, "Petrov");
    people[2].born_year = 1758;
    strcpy(people[2].surname, "Sidorov");
    people[3].born_year = 1759;
    strcpy(people[3].surname, "Fedorov");
    node_t *to_push;
    for (int i = 0; i < n; i++)
    {
        to_push = create(&people[i]);
        assert(to_push);
        head = push_back(head, to_push);
    }
    head = sort(head, cmp_people);
    int rc = 0;
    node_t *cur = head;
    int i = 0;
    for (; cur && i < n; i++, cur = cur->next)
        rc += cmp(cur->data, people[i]);
    rc += !(i == n);
    free_all(head);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(sort_list)
{
    node_t *head = NULL;
    person_t people[4];
    int n = sizeof(people) / sizeof(people[0]);
    people[0].born_year = 1756;
    strcpy(people[0].surname, "Ivanov");
    people[1].born_year = 1758;
    strcpy(people[1].surname, "Sidorov");
    people[2].born_year = 1759;
    strcpy(people[2].surname, "Fedorov");
    people[3].born_year = 1757;
    strcpy(people[3].surname, "Ivanov");
    node_t *to_push;
    for (int i = 0; i < n; i++)
    {
        to_push = create(&people[i]);
        assert(to_push);
        head = push_back(head, to_push);
    }
    head = sort(head, cmp_people);
    int rc = 0;
    node_t *cur = head;
    rc += cmp(cur->data, people[0]);
    cur = cur->next;
    rc += cmp(cur->data, people[3]);
    cur = cur->next;
    rc += cmp(cur->data, people[1]);
    cur = cur->next;
    rc += cmp(cur->data, people[2]);
    free_all(head);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

Suite* sort_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;
    s = suite_create("sort");
    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, sort_empty_list);
    tcase_add_test(tc_pos, sort_already_sorted_list);
    tcase_add_test(tc_pos, sort_list);
    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    return s;
}