#include "list_funcs.h"
#include <assert.h>

START_TEST(append_empty_list_in_empty_list)
{
    node_t *head_a = NULL, *head_b = NULL;
    append(&head_a, &head_b);
    int rc = !(head_a == NULL);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(append_non_empty_list_in_non_empty_list)
{
    node_t *head_a = NULL, *head_b = NULL;
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
    for (int i = 0; i < 2; i++)
    {
        to_push = create(&people[i]);
        assert(to_push);
        head_a = push_back(head_a, to_push);
        to_push = create(&people[i + 2]);
        assert(to_push);
        head_b = push_back(head_b, to_push);
    }
    append(&head_a, &head_b);
    int rc = 0;
    int i = 0;
    node_t *cur = head_a;
    for (; cur && i < n; i++, cur = cur->next)
        rc += cmp(cur->data, people[i]);
    rc += !(i == n);
    free_all(head_a);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(append_empty_list_in_non_empty_list)
{
    node_t *head_a = NULL, *head_b = NULL;
    person_t people[2];
    int n = sizeof(people) / sizeof(people[0]);
    people[0].born_year = 1756;
    strcpy(people[0].surname, "Ivanov");
    people[1].born_year = 1757;
    strcpy(people[1].surname, "Petrov");
    node_t *to_push;
    for (int i = 0; i < 2; i++)
    {
        to_push = create(&people[i]);
        assert(to_push);
        head_a = push_back(head_a, to_push);
    }
    append(&head_a, &head_b);
    int rc = 0;
    int i = 0;
    node_t *cur = head_a;
    for (; cur && i < n; i++, cur = cur->next)
        rc += cmp(cur->data, people[i]);
    rc += !(i == n);
    free_all(head_a);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}

START_TEST(append_non_empty_list_in_empty_list)
{
    node_t *head_a = NULL, *head_b = NULL;
    person_t people[2];
    int n = sizeof(people) / sizeof(people[0]);
    people[0].born_year = 1756;
    strcpy(people[0].surname, "Ivanov");
    people[1].born_year = 1757;
    strcpy(people[1].surname, "Petrov");
    node_t *to_push;
    for (int i = 0; i < 2; i++)
    {
        to_push = create(&people[i]);
        assert(to_push);
        head_b = push_back(head_b, to_push);
    }
    append(&head_a, &head_b);
    int i = 0, rc = 0;
    node_t *cur = head_a;
    for (; cur && i < n; i++, cur = cur->next)
        rc += cmp(cur->data, people[i]);
    rc += !(i == n);
    free_all(head_a);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}

Suite* append_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;
    s = suite_create("append");
    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, append_empty_list_in_empty_list);
    tcase_add_test(tc_pos, append_empty_list_in_non_empty_list);
    tcase_add_test(tc_pos, append_non_empty_list_in_non_empty_list);
    tcase_add_test(tc_pos, append_non_empty_list_in_empty_list);
    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    return s;
}

START_TEST(remove_duplicates_in_empty_list)
{
    node_t *head = NULL;
    remove_duplicates(&head, cmp_people);
    int rc = !(head == NULL);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(remove_duplicates_in_unique_list)
{
    node_t *head = NULL;
    person_t people[3];
    int n = sizeof(people) / sizeof(people[0]);
    people[0].born_year = 1756;
    strcpy(people[0].surname, "Ivanov");
    people[1].born_year = 1757;
    strcpy(people[1].surname, "Petrov");
    people[2].born_year = 1758;
    strcpy(people[2].surname, "Sidorov");
    node_t *to_push;
    for (int i = 0; i < n; i++)
    {
        to_push = create(&people[i]);
        assert(to_push);
        head = push_back(head, to_push);
    }
    remove_duplicates(&head, cmp_people);
    int rc = 0;
    node_t *cur = head;
    int i = 0;
    for (; cur && i < n; i++, cur = cur->next)
        rc += cmp(cur->data, people[i]);
    rc += !(cur == NULL && i == n);
    free_all(head);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(remove_duplicates_in_list_with_one_duplicated_node_two_times)
{
    node_t *head = NULL;
    person_t people[4];
    int n = sizeof(people) / sizeof(people[0]);
    people[0].born_year = 1756;
    strcpy(people[0].surname, "Ivanov");
    people[1].born_year = 1757;
    strcpy(people[1].surname, "Petrov");
    people[2].born_year = 1757;
    strcpy(people[2].surname, "Petrov");
    people[3].born_year = 1758;
    strcpy(people[3].surname, "Sidorov");
    node_t *to_push;
    for (int i = 0; i < n; i++)
    {
        to_push = create(&people[i]);
        assert(to_push);
        head = push_back(head, to_push);
    }
    remove_duplicates(&head, cmp_people);
    int rc = 0;
    node_t *cur = head;
    rc += !(cur != NULL && !cmp(cur->data, people[0]));
    cur = cur->next;
    rc += !(cur != NULL && !cmp(cur->data, people[1]));
    cur = cur->next;
    rc += !(cur != NULL && cur->next == NULL && !cmp(cur->data, people[3]));
    free_all(head);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(remove_duplicates_in_list_with_one_duplicated_node_several_times)
{
    node_t *head = NULL;
    person_t people[6];
    int n = sizeof(people) / sizeof(people[0]);
    people[0].born_year = 1756;
    strcpy(people[0].surname, "Ivanov");
    people[1].born_year = 1757;
    strcpy(people[1].surname, "Petrov");
    people[2].born_year = 1757;
    strcpy(people[2].surname, "Petrov");
    people[3].born_year = 1757;
    strcpy(people[3].surname, "Petrov");
    people[4].born_year = 1757;
    strcpy(people[4].surname, "Petrov");
    people[5].born_year = 1758;
    strcpy(people[5].surname, "Sidorov");
    node_t *to_push;
    for (int i = 0; i < n; i++)
    {
        to_push = create(&people[i]);
        assert(to_push);
        head = push_back(head, to_push);
    }
    remove_duplicates(&head, cmp_people);
    int rc = 0;
    node_t *cur = head;
    rc += !(cur != NULL && !cmp(cur->data, people[0]));
    cur = cur->next;
    rc += !(cur != NULL && !cmp(cur->data, people[1]));
    cur = cur->next;
    rc += !(cur != NULL && cur->next == NULL && !cmp(cur->data, people[5]));
    free_all(head);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(remove_duplicates_in_list_with_several_duplicated_nodes_several_times)
{
    node_t *head = NULL;
    person_t people[9];
    int n = sizeof(people) / sizeof(people[0]);
    people[0].born_year = 1756;
    strcpy(people[0].surname, "Ivanov");
    people[1].born_year = 1756;
    strcpy(people[1].surname, "Ivanov");
    people[2].born_year = 1757;
    strcpy(people[2].surname, "Petrov");
    people[3].born_year = 1757;
    strcpy(people[3].surname, "Petrov");
    people[4].born_year = 1757;
    strcpy(people[4].surname, "Petrov");
    people[5].born_year = 1757;
    strcpy(people[5].surname, "Petrov");
    people[6].born_year = 1758;
    strcpy(people[6].surname, "Sidorov");
    people[7].born_year = 1758;
    strcpy(people[7].surname, "Sidorov");
    people[8].born_year = 1798;
    strcpy(people[8].surname, "Fedorov");
    node_t *to_push;
    for (int i = 0; i < n; i++)
    {
        to_push = create(&people[i]);
        assert(to_push);
        head = push_back(head, to_push);
    }
    remove_duplicates(&head, cmp_people);
    int rc = 0;
    node_t *cur = head;
    rc += !(cur != NULL && !cmp(cur->data, people[0]));
    cur = cur->next;
    rc += !(cur != NULL && !cmp(cur->data, people[2]));
    cur = cur->next;
    rc += !(cur != NULL && !cmp(cur->data, people[6]));
    cur = cur->next;
    rc += !(cur != NULL && cur->next == NULL && !cmp(cur->data, people[8]));
    free_all(head);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST 

Suite* remove_duplicates_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;
    s = suite_create("remove_duplicates");
    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_pos, remove_duplicates_in_empty_list);
    tcase_add_test(tc_pos, remove_duplicates_in_unique_list);
    tcase_add_test(tc_pos, remove_duplicates_in_list_with_one_duplicated_node_two_times);
    tcase_add_test(tc_pos, remove_duplicates_in_list_with_one_duplicated_node_several_times);
    tcase_add_test(tc_pos, remove_duplicates_in_list_with_several_duplicated_nodes_several_times);
    tcase_add_test(tc_neg, remove_duplicates_in_empty_list);
    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    return s;
}