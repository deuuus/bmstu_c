#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "file_size.h"
#include "func.h"

#define FOPEN_ERR          -2
#define COMMAND_ERR        53

int main(int argc, char *argv[])
{
    setbuf(stdout, NULL);
    int rc = EXIT_SUCCESS;
    if (argc != 3 && argc != 4)
        return COMMAND_ERR;
    else if (argc == 4)
    {
        if (strcmp(argv[1], "sb") == 0)
        {
            FILE *f_in, *f_out;
            f_in = fopen(argv[2], "rb+");
            f_out = fopen(argv[3], "wb+");
            if (f_in == NULL || f_out == NULL)
                return FOPEN_ERR;
            size_t n = 0;
            rc = file_size(f_in, &n);
            if (rc == 0)
                rc = sort(f_in, f_out, n);
            fclose(f_in);
            fclose(f_out);
            return rc;
        }
        else if (strcmp(argv[1], "fb") == 0)
        {
            if (argc != 4)
                return COMMAND_ERR;
            FILE *f_in;
            f_in = fopen(argv[2], "rb");
            if (f_in == NULL)
                return FOPEN_ERR;
            size_t n = 0;
            rc = file_size(f_in, &n);
            if (rc == 0)
                rc = end_substr(f_in, argv[3], n);
            fclose(f_in);
            return rc;
        }
        else
            return COMMAND_ERR;
    }
    else if (argc == 3)
    {
        if (strcmp(argv[1], "ab") == 0)
        {
            if (argc != 3)
                return COMMAND_ERR;
            FILE *f_in;
            f_in = fopen(argv[2], "rb+");
            if (f_in == NULL)
                return FOPEN_ERR;
            size_t n = 0;
            rc = file_size(f_in, &n);
            if (rc == 0)
                rc = insert(f_in, n);
            fclose(f_in);
            return rc;
        }
        else
            return COMMAND_ERR;
    }
    else
        return EXIT_SUCCESS;
}