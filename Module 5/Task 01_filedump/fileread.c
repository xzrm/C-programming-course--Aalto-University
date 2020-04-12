#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "fileread.h"

int textdump(const char *filename)
{
    FILE *f;
    f = fopen(filename, "r"); // open file for reading
    if (!f)
    {
        fprintf(stderr, "Opening file failed\n");
        return -1;
    }

    int count = 0;
    char c;

    while ((c = fgetc(f)) != EOF)
    {
        if (isprint(c))
        {
            fprintf(stdout, "%c", c);
        }
        else
        {
            fprintf(stdout, "%c", c);
        }
        count++;
    }
    fclose(f);
    return count;
}

int hexdump(const char *filename)
{
    FILE *f;
    f = fopen(filename, "r"); // open file for reading
    if (!f)
    {
        fprintf(stderr, "Opening file failed\n");
        return -1;
    }
    int count = 0;
    char c;

    while ((c = fgetc(f)) != EOF)
    {
        if (c < 0x10)
        {
            fprintf(stdout, "0%.x", c);
        }
        else
        {
            fprintf(stdout, "%.2x", c);
        }
        fprintf(stdout, " ");
        count++;
        if (count % 16 == 0)
        {
            fprintf(stdout, "\n");
        }
    }
    fclose(f);
    return count;
}