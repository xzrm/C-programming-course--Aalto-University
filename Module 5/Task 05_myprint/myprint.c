#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "myprint.h"

int myprint(const char *string, ...)
{
    unsigned int count = 0;
    char c;
    char *pch;
    char *str = string;
    int i;

    pch = strchr(string, '&');
    while (pch != NULL)
    {
        count++;

        pch = strchr(pch + 1, '&');
    }

    va_list args;
    va_start(args, string);
    while (*str)
    {
        if (*str == '&')
        {
            i = va_arg(args, int);
            printf("%d", i);
        }
        else
        {
            fputc(*str, stdout);
        }
        str++;
    }

    va_end(args);

    return count;
}