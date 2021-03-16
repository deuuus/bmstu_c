#include "node_funcs.h"
#include <assert.h>

START_TEST(find_in_empty_list)
{
    node_t *head = NULL;
    person_t person;
    person.born_year = 1756;
    strcpy(person.surname, "Ivanov");
    node_t *f = find(head, &person, cmp_people);
    int rc = !(f == NULL);
    free_one(f);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}

START_TEST(find_non_list_node)
{
    node_t *head = NULL;
    person_t people[3];
    people[0].born_year = 1756;
    strcpy(people[0].surname, "Ivanov");
    people[1].born_year = 1757;
    strcpy(people[1].surname, "Petrov");
    people[2].born_year = 1758;
    strcpy(people[2].surname, "Sidorov");
    node_t *to_push;
    for (int i = 0; i < 2; i++)
    {
        to_push = create(&people[i]);
        assert(to_push);
        head = push_back(head, to_push);
    }
    node_t *f = find(head, &people[2], cmp_people);
    int rc = !(f == NULL);
    free_all(head);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(find_node_that_is_in_list)
{
    node_t *head = NULL;
    person_t people[3];
    people[0].born_year = 1756;
    strcpy(people[0].surname, "Ivanov");
    people[1].born_year = 1757;
    strcpy(people[1].surname, "Petrov");
    people[2].born_year = 1758;
    strcpy(people[2].surname, "Sidorov");
    node_t *to_push;
    for (int i = 0; i < 3; i++)
    {
        to_push = create(&people[i]);
        assert(to_push);
        head = push_back(head, to_push);
    }
    node_t *f = find(head, &people[2], cmp_people);
    int rc = f == NULL;
    if (!f)
        rc += cmp(f->data, people[2]);
    free_all(head);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}

Suite* find_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;
    s = suite_create("find");
    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, find_in_empty_list);
    tcase_add_test(tc_neg, find_non_list_node);
    tcase_add_test(tc_pos, find_node_that_is_in_list);
    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    return s;
}

START_TEST(pop_front_from_empty_list)
{
    node_t *head = NULL;
    void *data = pop_front(&head);
    int rc = !(data == NULL);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}

START_TEST(pop_front_in_list_with_one_elem)
{
    node_t *head = NULL;
    person_t person;
    person.born_year = 1756;
    strcpy(person.surname, "Ivanov");
    head = create(&person);
    assert(head);
    void *data = pop_front(&head);
    int rc = !(data == &person);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}

START_TEST(pop_front_in_list_with_several_elems)
{
    node_t *head = NULL;
    person_t people[3];
    people[0].born_year = 1756;
    strcpy(people[0].surname, "Ivanov");
    people[1].born_year = 1757;
    strcpy(people[1].surname, "Petrov");
    people[2].born_year = 1758;
    strcpy(people[2].surname, "Sidorov");
    node_t *to_push;
    for (int i = 0; i < 3; i++)
    {
        to_push = create(&people[i]);
        assert(to_push);
        head = push_back(head, to_push);
    }
    void *data = pop_front(&head);
    int rc = !(data == &people[0]);
    free_all(head);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}

Suite* pop_front_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;
    s = suite_create("pop_front");
    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_pos, pop_front_in_list_with_one_elem);
    tcase_add_test(tc_pos, pop_front_in_list_with_several_elems);
    tcase_add_test(tc_neg, pop_front_from_empty_list);
    suite_add_tcase(s, tc_pos);
    suite_add_tcase(s, tc_neg);
    return s;
}
