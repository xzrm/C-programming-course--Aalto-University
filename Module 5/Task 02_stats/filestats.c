#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int line_count(const char *filename)
{
    FILE *fp = fopen("lines_test.txt", "r");
    int count = 0;
    char c;

    if (!fp)
    {
        fprintf(stderr, "Could not open file\n");
        return -1;
    }

    while ((c = getc(fp)) != EOF)
    {
        if (c == '\n')
        {
            count++;
        }
        fprintf(stdout, "%c", c);
    }
    fclose(fp);
    return count;
}

int word_count(const char *filename)
{
    FILE *fp = fopen("lines_test.txt", "r");
    int count = 0;
    char c;
    unsigned int EOS = 1;

    while ((c = getc(fp)) != EOF)
    {
        if (!isspace(c))
        {
            fprintf(stdout, "%c", c);

            if (isalpha(c))
            {
                EOS = 0;
            }
        }
        else if (isspace(c) && EOS == 0)
        {
            fprintf(stdout, "%c", c);
            count++;
            EOS = 1;
        }
    }
    fclose(fp);
    return count;
}
