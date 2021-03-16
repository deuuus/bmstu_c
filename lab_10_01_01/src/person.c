#include "person.h"

int read_all(FILE *f, person_t people[], int *num)
{
    int rc;
    *num = 0;
    while (!(rc = read_one(f, &people[*num])))
        (*num)++;
    if (!feof(f))
        return ERR_FILE_DATA;
    return EXIT_SUCCESS;
}

int read_one(FILE *f, person_t *person)
{
    if (fscanf(f, "%d", &person->born_year) != 1)
        return ERR_READ;
    if (!fgets(person->surname, sizeof(person->surname), f))
        return ERR_READ;
    if (person->surname[strlen(person->surname) - 1] == '\n')
        person->surname[strlen(person->surname) - 1] = '\0';
    if (!strlen(person->surname))
        return ERR_READ;
    return EXIT_SUCCESS;
}

void print_people(person_t people[], int num)
{
    for (int i = 0; i < num; i++)
        printf("Born year: %d\nSurname: %s\n\n", people[i].born_year, people[i].surname);
}