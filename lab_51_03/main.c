#define __USE_MINGW_ANSI_STDIO 1
#include <stdlib.h>
#include <string.h>
#include "file_size.h"
#include "func.h"

#define MAX_LEN 256
#define INPUT_ERROR 1
#define OPEN_ERROR 2
#define DAMAGED_FILE 3
#define COMMAND_ERROR 4

//направление сортировки - по возрастанию. Выбранный тип - int. Алгоритм сортировки - вставками.

int main(int argc, char *argv[])
{
    setbuf(stdout, NULL);
    FILE *f;
    int rc = EXIT_SUCCESS;
    if (argc != 3)
        return INPUT_ERROR;       
    if (strcmp(argv[1], "c") == 0)
    {
        f = fopen(argv[2], "wb");
        if (f == NULL)
            return OPEN_ERROR;
        int rc = create_bin(f);
        fclose(f);
        return rc;
    }
    else if (strcmp(argv[1], "p") == 0)
    {
        f = fopen(argv[2], "rb");
        if (f == NULL)
            return OPEN_ERROR;
        size_t size;
        if (file_size(f, &size) != EXIT_SUCCESS || size % sizeof(int))
           return DAMAGED_FILE;
        rc = print_bin_file(f);
        fclose(f);
        return rc;
    }
    else if (strcmp(argv[1], "s") == 0)
    {
        f = fopen(argv[2], "rb+");
        if (f == NULL)
            return OPEN_ERROR;
        size_t size;
        if (file_size(f, &size) != EXIT_SUCCESS || size % sizeof(int))
            return DAMAGED_FILE;
        rc = sort(f);
        fclose(f);
        return rc;
    }
    return COMMAND_ERROR;
}