#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

char *read_file(const char *filename)
{

    FILE *f = fopen(filename, "r");
    if (!f)
    {
        fprintf(stderr, "Opening file failed\n");
        exit(EXIT_FAILURE);
    }

    fseek(f, 0, SEEK_END);
    long int f_size = ftell(f);
    // printf("%d", f_size);
    rewind(f);

    char *p = malloc((f_size + 1) * sizeof(char));
    char *s = p;
    if (!p)
        return NULL;

    // char c;
    // while ((c = fgetc(f)) != EOF)
    // {
    //     *p=c;
    //     p++;
    // }
    // *p='\0';
    // return s;
    fread(p, 1, f_size, f);
    p[f_size] = '\0';

    return p;
}

char *remove_comments(char *input)
{
    char *content = input;
    unsigned int length = 0;

    while (*content)
    {
        length++;
        content++;
    }
    content = input;
    char c;

    char *polished = malloc(sizeof(char) * (length + 1));
    if (!polished)
        return NULL;
        
    char *polished_p = polished;
    unsigned int skip_lines = 0;
    unsigned int skip_line = 0;

    for (unsigned int i = 0; i < length - 1; i++)
    {
        if (!skip_line && content[i] == '/' && content[i + 1] == '*')
        {
            skip_lines = 1;
            continue;
        }

        if (skip_lines && content[i] == '*' && content[i + 1] == '/')
        {
            skip_lines = 0;
            i = i + 2;
        }
        if (!skip_lines)
        {
            if (content[i] == '/' && content[i + 1] == '/')
            {
                skip_line = 1;
                continue;
            }
            if (skip_line && content[i] == '\n')
            {
                skip_line = 0;
                continue;
            }
            if (!skip_line)
            {
                // printf("%c", content[i]);
                *polished = content[i];
                polished++;
            }
        }
    }

    *polished = '\n';

    free(input);
    return polished_p;
}