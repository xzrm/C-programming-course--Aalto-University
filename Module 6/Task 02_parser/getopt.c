
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "getopt.h"

struct options *get_options(int argc, char *argv[])
{

    struct options *first = NULL;
    struct options *last = NULL;

    unsigned int is_opt = 0;

    for (unsigned int i = 1; i < argc; i++)
    {

        struct options *current_opt = malloc(sizeof(struct options));
        current_opt->next = NULL;

        if (strchr(argv[i], '-'))
        {
            if (isalpha(argv[i][1]))
            {
                current_opt->optchar = argv[i][1];
                is_opt = 1;
            }
        }
        else
        {
            free(current_opt);
            continue;
        }

        if (is_opt && i + 1 < argc && strchr(argv[i + 1], '-') == 0)
        {
            unsigned int arg_len = strlen(argv[i + 1]);
            char *p_str = malloc(sizeof(char) * arg_len);
            strcpy(p_str, argv[i + 1]);
            current_opt->optarg = p_str;
            i++;
        }
        else
        {
            current_opt->optarg = NULL;
        }

        if (first == NULL)
        {
            first = current_opt;
        }
        else
        {
            last->next = current_opt;
        }
        last = current_opt;
    }

    return first;
}

void free_options(struct options *opt)
{
    if (opt == NULL)
    {
        return;
    }

    struct options *current = opt;
    struct options *next_opt;

    while (current)
    {
        printf("%c is free ", current->optchar);
        next_opt = current->next;
        if (current->optarg)
        {
            free(current->optarg);
        }
        free(current);
        current = next_opt;

    }
}

int is_option(struct options *opt, char optc)
{
    if (opt == NULL)
    {
        return 0;
    }

    struct options *current = opt;
    struct options *next_opt;
    while (current)
    {
        if (current->optchar == optc)
            return 1;
        current = current->next;
    }
    return 0;
}

char *get_optarg(struct options *opt, char optc)
{
    {
        if (opt == NULL)
        {
            return NULL;
        }

        struct options *current = opt;
        struct options *next_opt;
        while (current)
        {
            if (current->optchar == optc)
                return current->optarg;
            current = current->next;
        }
        return NULL;
    }
}