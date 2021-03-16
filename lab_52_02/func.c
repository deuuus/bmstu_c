#include "func.h"

struct item
{
    char name[MAX_NAME_LEN + 1];
    char producer[MAX_PRODUCER_LEN + 1];
    uint32_t price;
    uint32_t amount;
};

int copy(FILE *f, FILE *f_copy);
int get_struct(FILE *f, size_t pos, struct item *example);
int put_struct(FILE *f, size_t pos, struct item *example);

int sort(FILE *f_in, FILE *f_out, size_t n)
{
    struct item item_cur, item_next;
    memset(&item_cur, 0, sizeof(item_cur));
    memset(&item_next, 0, sizeof(item_next));
    if (!n || n % sizeof(struct item) || copy(f_in, f_out) != EXIT_SUCCESS)
        return FILE_ERR;
    size_t k = n / sizeof(struct item);
    for (size_t i = 0; i < k - 1; i++)
        for (size_t j = 0; j < k - i - 1; j++)
        {
            if (get_struct(f_out, j, &item_cur) != EXIT_SUCCESS)
                return GET_ERR;
            if (get_struct(f_out, j + 1, &item_next) != EXIT_SUCCESS)
                return GET_ERR;
            if (item_cur.price < item_next.price || (item_cur.price == item_next.price && item_cur.amount < item_next.amount))
            {
                if (put_struct(f_out, j, &item_next) != EXIT_SUCCESS)
                    return PUT_ERR;
                if (put_struct(f_out, j + 1, &item_cur) != EXIT_SUCCESS)
                    return PUT_ERR;
            }
        }
    return EXIT_SUCCESS;
}

int insert(FILE *f, size_t n)
{
    if (!n || n % sizeof(struct item))
        return FILE_ERR;
    struct item item_cur, item_add;
    memset(&item_cur, 0, sizeof(struct item));
    memset(&item_add, 0, sizeof(struct item));
    size_t k = n / sizeof(struct item);
    size_t pos;
    int rc = -1;
    if (scanf("%s", item_add.name) != 1 || scanf("%s", item_add.producer) != 1)
        return SCAN_ERR;
    if (scanf("%u", &item_add.price) != 1 || scanf("%u", &item_add.amount) != 1)
        return SCAN_ERR;
    for (size_t i = 0; i < k; i++)
    {
        if (get_struct(f, i, &item_cur) != EXIT_SUCCESS)
            return GET_ERR;
        if (item_cur.price < item_add.price || (item_cur.price == item_add.price && item_cur.amount < item_add.amount))
        {
            pos = i;
            rc = 1;
            while (k > pos)
            {
                if (get_struct(f, k - 1, &item_cur))
                    return GET_ERR;
                if (put_struct(f, k, &item_cur))
                    return PUT_ERR;
                k--;
            }
            if (fseek(f, pos * sizeof(item_add), SEEK_SET))
                return SEEK_ERR;
            if (fwrite(&item_add, sizeof(item_add), 1, f) != 1)
                return WRITE_ERR;
            return EXIT_SUCCESS;
        }
    }
    if (rc != 1)
    {
        if (fseek(f, 0, SEEK_END) < 0)
            return SEEK_ERR;
        if (fwrite(&item_add, sizeof(item_add), 1, f) != 1)
            return WRITE_ERR;
    }
    return EXIT_SUCCESS;
}

int end_substr(FILE *f, const char *substr, size_t n)
{
    struct item item_cur;
    memset(&item_cur, 0, sizeof(item_cur));
    char name[MAX_NAME_LEN + 1];
    name[0] = '\0';
    char *p;
    int rc = -1;
    size_t k = 0;
    if (!n || n % sizeof(item_cur))
        return FILE_ERR;
    while (fread(&item_cur, sizeof(item_cur), 1, f) == 1)
    {
        if ((p = strrchr(item_cur.name, substr[0])))
        {
            strncpy(name, p, sizeof(name));
            if (!strcmp(substr, name) || (strstr(item_cur.name, substr) == item_cur.name && strlen(substr) == strlen(item_cur.name)))
            {
                rc = 0;
                k++;
                printf("%s\n%s\n%u\n%u\n", item_cur.name, item_cur.producer, item_cur.price, item_cur.amount);
            }
        }
    }
    if (feof(f) == 0 || k == 0)
        return FILE_ERR;
    else
        return rc;
}

int copy(FILE *f, FILE *f_copy)
{
    struct item example;
    size_t k = 0;
    memset(&example, 0, sizeof(example));
    while (fread(&example, sizeof(example), 1, f) == 1)
    {
        if (fwrite(&example, sizeof(example), 1, f_copy) != 1)
            return WRITE_ERR;
        k++;
    }
    if (feof(f) == 0 || k == 0)
        return FILE_ERR;
    else
        return EXIT_SUCCESS;
}

int get_struct(FILE *f, size_t pos, struct item *example)
{
    if (fseek(f, pos * sizeof(struct item), SEEK_SET))
        return SEEK_ERR;
    if (fread(example, sizeof(struct item), 1, f) != 1)
        return SEEK_ERR;
    if (fseek(f, 0, SEEK_SET))
        return SEEK_ERR;
    return EXIT_SUCCESS;
}

int put_struct(FILE *f, size_t pos, struct item *example)
{
    if (fseek(f, pos * sizeof(struct item), SEEK_SET))
        return SEEK_ERR;
    if (fwrite(example, sizeof(struct item), 1, f) != 1)
        return SEEK_ERR;
    if (fseek(f, 0, SEEK_SET))
        return SEEK_ERR;
    return EXIT_SUCCESS;
}