#include "movie.h"
#include <assert.h>

START_TEST(get_count_one_struct)
{
    FILE *f = fopen("unit_tests/shared/test_01.txt", "r");
    assert(f);
    int n;
    ck_assert_int_eq(get_count(f, &n) && n == 1, EXIT_SUCCESS);
    fclose(f);
}
END_TEST

START_TEST(get_count_several_structs)
{
    FILE *f = fopen("unit_tests/shared/test_02.txt", "r");
    assert(f);
    int n;
    ck_assert_int_eq(get_count(f, &n) && n == 3, EXIT_SUCCESS);
    fclose(f);
}
END_TEST

START_TEST(my_getline_one_word_in_string)
{
    FILE *f = fopen("unit_tests/shared/test_05.txt", "r");
    assert(f);
    char *line = NULL;
    ck_assert_int_eq(my_getline(&line, f) && !strcmp(line, "string"), EXIT_SUCCESS);
    free(line);
    fclose(f);
}
END_TEST

START_TEST(my_getline_several_words_in_string)
{
    FILE *f = fopen("unit_tests/shared/test_06.txt", "r");
    assert(f);
    char *line = NULL;
    ck_assert_int_eq(my_getline(&line, f) && !strcmp(line, "one two free"), EXIT_SUCCESS);
    free(line);
    fclose(f);
}
END_TEST

int cmp(movie a, char *title, char *name, int year);

START_TEST(replace_in_empty_struct)
{
    movie to_replace = { NULL, NULL, 0 };
    int rc = replace(&to_replace, "title", "name", 100);
    if (!rc)
        rc += cmp(to_replace, "title", "name", 100);
    free_one(&to_replace);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(replace_other_struct)
{
    movie to_replace = { NULL, NULL, 0 };
    int rc = replace(&to_replace, "title", "name", 10);
    if (!rc)
    {
        rc += replace(&to_replace, "title2", "name2", 100);
        rc += cmp(to_replace, "title2", "name2", 100);
    }
    free_one(&to_replace);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(binary_search_incorrect_key_year_neg)
{
    int n = 1;
    movie *movies = calloc(n, sizeof(movie));
    assert(movies);
    replace(&(movies[0]), "title", "name", 10);
    int rc = binary_search(movies, n, "year", "-10");
    free_all(&movies, n);
    ck_assert_int_eq(rc, KEY_ERR);
}
END_TEST

START_TEST(binary_search_incorrect_key_year_smb)
{
    int n = 1;
    movie *movies = calloc(n, sizeof(movie));
    assert(movies);
    replace(&(movies[0]), "title", "name", 10);
    int rc = binary_search(movies, n, "year", "-dsd10");
    free_all(&movies, n);
    ck_assert_int_eq(rc, KEY_ERR);
}
END_TEST

START_TEST(insert_array_one_struct_insert_by_year)
{
    int n = 1;
    movie *movies = calloc(n, sizeof(movie));
    assert(movies);
    replace(&(movies[0]), "title", "name", 10);
    int rc = insert(&movies, n, cmp_year);
    if (!rc)
        rc += cmp(movies[0], "title", "name", 10);
    free_all(&movies, n);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(insert_array_one_struct_insert_by_title)
{
    int n = 1;
    movie *movies = calloc(n, sizeof(movie));
    assert(movies);
    replace(&(movies[0]), "title", "name", 10);
    int rc = insert(&movies, n, cmp_title);
    if (!rc)
        rc += cmp(movies[0], "title", "name", 10);
    free_all(&movies, n);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(insert_array_one_struct_insert_by_name)
{
    int n = 1;
    movie *movies = calloc(n, sizeof(movie));
    assert(movies);
    replace(&(movies[0]), "title", "name", 10);
    int rc = insert(&movies, n, cmp_name);
    if (!rc)
        rc += cmp(movies[0], "title", "name", 10);
    free_all(&movies, n);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(insert_array_several_struct_insert_by_year)
{
    int n = 3;
    movie *movies = calloc(n, sizeof(movie));
    assert(movies);
    replace(&(movies[0]), "title", "name", 10);
    replace(&(movies[1]), "title", "name", 30);
    replace(&(movies[2]), "title", "name", 20);
    int rc = insert(&movies, n, cmp_year);
    if (!rc)
    {
        rc += cmp(movies[0], "title", "name", 10);
        rc += cmp(movies[1], "title", "name", 20);
        rc += cmp(movies[2], "title", "name", 30);
    }
    free_all(&movies, n);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(insert_array_several_struct_insert_by_title)
{
    int n = 3;
    movie *movies = calloc(n, sizeof(movie));
    assert(movies);
    replace(&(movies[0]), "title", "name", 10);
    replace(&(movies[1]), "title3", "name", 30);
    replace(&(movies[2]), "titl", "name", 20);
    int rc = insert(&movies, n, cmp_title);
    if (!rc)
    {
        rc += cmp(movies[0], "titl", "name", 20);
        rc += cmp(movies[1], "title", "name", 10);
        rc += cmp(movies[2], "title3", "name", 30);
    }
    free_all(&movies, n);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(insert_array_several_struct_insert_by_name)
{
    int n = 3;
    movie *movies = calloc(n, sizeof(movie));
    assert(movies);
    replace(&(movies[0]), "title", "name3", 10);
    replace(&(movies[1]), "title", "name5", 10);
    replace(&(movies[2]), "title", "name4", 10);
    int rc = insert(&movies, n, cmp_year);
    if (!rc)
    {
        rc += cmp(movies[0], "title", "name3", 10);
        rc += cmp(movies[1], "title", "name4", 10);
        rc += cmp(movies[2], "title", "name5", 10);
    }
    free_all(&movies, n);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(insert_array_with_equal_title)
{
    int n = 3;
    movie *movies = calloc(n, sizeof(movie));
    assert(movies);
    replace(&(movies[0]), "title", "name", 10);
    replace(&(movies[1]), "title", "name", 20);
    replace(&(movies[2]), "title", "name", 30);
    int rc = insert(&movies, n, cmp_year);
    if (!rc)
    {
        rc += cmp(movies[0], "title", "name", 10);
        rc += cmp(movies[1], "title", "name", 20);
        rc += cmp(movies[2], "title", "name", 30);
    }
    free_all(&movies, n);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(insert_array_with_equal_name)
{
    int n = 3;
    movie *movies = calloc(n, sizeof(movie));
    assert(movies);
    replace(&(movies[0]), "title", "name", 10);
    replace(&(movies[1]), "title", "name", 20);
    replace(&(movies[2]), "title", "name", 30);
    int rc = insert(&movies, n, cmp_name);
    if (!rc)
    {
        rc += cmp(movies[0], "title", "name", 10);
        rc += cmp(movies[1], "title", "name", 20);
        rc += cmp(movies[2], "title", "name", 30);
    }
    free_all(&movies, n);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(insert_array_with_equal_year)
{
    int n = 3;
    movie *movies = calloc(n, sizeof(movie));
    assert(movies);
    replace(&(movies[0]), "title", "name", 10);
    replace(&(movies[1]), "title", "name", 10);
    replace(&(movies[2]), "title", "name", 10);
    int rc = insert(&movies, n, cmp_title);
    if (!rc)
    {
        rc += cmp(movies[0], "title", "name", 10);
        rc += cmp(movies[1], "title", "name", 10);
        rc += cmp(movies[2], "title", "name", 10);
    }
    free_all(&movies, n);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

Suite* get_count_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    s = suite_create("movie");
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, get_count_one_struct);
    tcase_add_test(tc_pos, get_count_several_structs);
    suite_add_tcase(s, tc_pos);
    return s;
}

Suite* my_getline_suite(void)
{
    Suite *s;
    TCase *tc_pos;
    s = suite_create("my_getline");
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, my_getline_one_word_in_string);
    tcase_add_test(tc_pos, my_getline_several_words_in_string);
    suite_add_tcase(s, tc_pos);
    return s;
}

Suite* replace_suite(void)
{
    Suite *s;
    TCase *tc;
    s = suite_create("replace");
    tc = tcase_create("general");
    tcase_add_test(tc, replace_in_empty_struct);
    tcase_add_test(tc, replace_other_struct);
    suite_add_tcase(s, tc);
    return s;
}

Suite* binary_search_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    s = suite_create("movie");
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, binary_search_incorrect_key_year_neg);
    tcase_add_test(tc_neg, binary_search_incorrect_key_year_smb);
    suite_add_tcase(s, tc_neg);
    return s;
}

Suite* insert_suite(void)
{
    Suite *s;
    TCase *tc;
    s = suite_create("insert");
    tc = tcase_create("general");
    tcase_add_test(tc, insert_array_one_struct_insert_by_title);
    tcase_add_test(tc, insert_array_one_struct_insert_by_name);
    tcase_add_test(tc, insert_array_one_struct_insert_by_year);
    tcase_add_test(tc, insert_array_several_struct_insert_by_title);
    tcase_add_test(tc, insert_array_several_struct_insert_by_name);
    tcase_add_test(tc, insert_array_several_struct_insert_by_year);
    tcase_add_test(tc, insert_array_with_equal_title);
    tcase_add_test(tc, insert_array_with_equal_name);
    tcase_add_test(tc, insert_array_with_equal_year);
    suite_add_tcase(s, tc);
    return s;
}

int cmp(movie a, char *title, char *name, int year)
{
    return strcmp(a.title, title) + strcmp(a.name, name) + !(a.year == year);
}