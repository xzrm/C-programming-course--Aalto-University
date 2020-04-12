#include <stdio.h>
#include <stddef.h>

void es_print(const char *s)
{
    while (!(*s == '#'))
    {
        printf("%c", *s);
        s++;
    }
}

unsigned int es_length(const char *s)
{
    int len = 0;
    while (!(*s == '#'))
    {
        s++;
        len++;
    }
    return len;
}

int es_copy(char *dst, const char *src)
{
    int count = 0;
    while (!(*src == '#'))
    {
        *dst = *src;
        src++;
        dst++;
        count++;
    }
    *dst = '#';
    return count;
}



char *es_token(char *s, char c)
{
    while ((*s != '#'))
    {
        if (*s == c)
        {
            *s = '#';
            return s + 1;
        };
        s++;
    };
    return NULL;
}

void main()
{
    //    char *str = "Auto ajoi#kilparataa";
    //    printf("%d", es_length(str));

    char str[] = "yksi,kaksi,kymmenen#nelja,viisi";
    // char *p = es_token(str, ',');
    // es_print(str);
    // printf("\n%s", str);
    char buf[80] = {0};
    int ret = es_copy(buf, str);
    printf("after copy: '%s'  (ret: %d)\n", buf, ret);
}
