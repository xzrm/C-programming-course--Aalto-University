#include <stdio.h>
#include <string.h>

void korsoroi(char *dest, const char *src)
{
    int num_words;
    char str1[] = "niinku";
    char str2[] = "totanoin";
    char *p;
    while (*src)
    {

        if ((*src == 'k') && (*(src + 1) == 's'))
        {
            *dest = 'x';
            src++;
        }
        else if ((*src == 't') && (*(src + 1) == 's'))
        {
            *dest = 'y';
            src++;
        }
        else
        {
            *dest = *src;
        }

        if (*src == ' ')
        {
            num_words++;
            char *pstr1 = str1;
            if (num_words % 3 == 0)
            {
                while (*pstr1)
                {
                    dest++;
                    *dest = *pstr1;
                    pstr1++;
                }
                dest++;
                *dest = ' ';
            }
            if (num_words % 4 == 0)
            {
                num_words++;
                char *pstr2 = str2;
                while (*pstr2)
                {
                    dest++;
                    *dest = *pstr2;
                    pstr2++;
                }
                dest++;
                *dest = ' ';
            }
        }
        src++;
        dest++;
    }
    *dest = '\0';
}

int main()
{

    /* Korsoroi */
    char buf[100], dest[200];
    char str[] = "yksi auto valui itsekseen ilman kuljettajaa mak ts alas ts";
    korsoroi(dest, str);
    printf("\n%s", str);
    printf("\n%s", dest);
    return 0;
}