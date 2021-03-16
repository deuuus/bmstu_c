#include "node.h"
#include <assert.h>

int cmp(person_t *a, person_t b)
{
    return !(a->born_year == b.born_year && !strcmp(a->surname, b.surname));
}

START_TEST(push_back_elem)
{  
    node_t *head = NULL;
    person_t people[3];
    people[0].born_year = 1756;
    strcpy(people[0].surname, "Ivanov");
    people[1].born_year = 1757;
    strcpy(people[1].surname, "Petrov");
    people[2].born_year = 1758;
    strcpy(people[2].surname, "Sidorov");
    head = create(&people[0]);
    assert(head);
    head->next = create(&people[1]);
    assert(head->next);
    node_t *new = create(&people[2]);
    assert(new);
    head = push_back(head, new);
    int n = sizeof(people) / sizeof(people[0]);
    int rc = 0, i = 0;
    node_t *cur = head;
    for(; cur && i < n; i++, cur = cur->next)
        rc += cmp(cur->data, people[i]);
    rc += !(cur == NULL && i == n);
    free_all(head);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(push_back_null)
{  
    person_t people[2];
    people[0].born_year = 1756;
    strcpy(people[0].surname, "Ivanov");
    people[1].born_year = 1757;
    strcpy(people[1].surname, "Petrov");
    node_t *head = NULL;
    head = create(&people[0]);
    assert(head);
    head->next = create(&people[1]);
    assert(head->next);
    node_t *new = NULL;
    head = push_back(head, new);
    int n = sizeof(people) / sizeof(people[0]);
    int rc = 0, i = 0;
    node_t *cur = head;
    for(; cur && i < n; i++, cur = cur->next)
        rc += cmp(cur->data, people[i]);
    rc += !(cur == NULL && i == n);
    free_all(head);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(push_back_in_empty_list)
{  
    person_t person;
    person.born_year = 1756;
    strcpy(person.surname, "Ivanov");
    node_t *head = NULL;
    node_t *new = create(&person);
    assert(new);
    head = push_back(head, new);
    int rc = cmp(head->data, person);
    rc += !(head->next == NULL);
    free_all(head);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

Suite* push_back_suite(void)
{
    Suite *s;
    TCase *tc;
    s = suite_create("push_back");
    tc = tcase_create("general");
    tcase_add_test(tc, push_back_elem);
    tcase_add_test(tc, push_back_null);
    tcase_add_test(tc, push_back_in_empty_list);
    suite_add_tcase(s, tc);
    return s;
}

START_TEST(init_one_elem)
{
    person_t people[1];
    people[0].born_year = 1756;
    strcpy(people[0].surname, "Ivanov");
    node_t *head = NULL;
    int n = sizeof(people) / sizeof(people[0]);
    int rc = init(people, n, &head);
    if (!rc)
    {
        rc += cmp(head->data, people[0]);
        rc += !(head->next == NULL);
        free_all(head);
    }
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(init_one_elem_with_non_null_head_ptr)
{
    person_t people[1];
    people[0].born_year = 1756;
    strcpy(people[0].surname, "Ivanov");
    node_t *head = NULL;
    person_t to_create;
    to_create.born_year = 1000;
    strcpy(to_create.surname, "Petrov");
    head = create(&to_create);
    int n = sizeof(people) / sizeof(people[0]);
    int rc = init(people, n, &head);
    if (!rc)
    {
        rc += cmp(head->data, people[0]);
        rc += !(head->next == NULL);
        free_all(head);
    }
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(init_several_elems)
{
    person_t people[3];
    people[0].born_year = 1756;
    strcpy(people[0].surname, "Ivanov");
    people[1].born_year = 1757;
    strcpy(people[1].surname, "Petrov");
    people[2].born_year = 1758;
    strcpy(people[2].surname, "Sidorov");
    node_t *head = NULL;
    int n = sizeof(people) / sizeof(people[0]);
    int rc = init(people, n, &head);
    if (!rc)
    {
        node_t *cur = head;
        int i = 0;
        for (; cur && i < n; i++, cur = cur->next)
            rc += cmp(cur->data, people[i]);
        rc += !(cur == NULL && i == n);
        free_all(head);
    }
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

Suite* init_suite(void)
{
    Suite *s;
    TCase *tc;
    s = suite_create("init");
    tc = tcase_create("general");
    tcase_add_test(tc, init_one_elem);
    tcase_add_test(tc, init_one_elem_with_non_null_head_ptr);
    tcase_add_test(tc, init_several_elems);
    suite_add_tcase(s, tc);
    return s;
}