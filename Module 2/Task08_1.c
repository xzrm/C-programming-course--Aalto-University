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
            dest++;
            src += 2;
        }
        else if ((*src == 't') && (*(src + 1) == 's'))
        {
            *dest = 'y';
            dest++;
            src += 2;
        }
        else if (*src == ' ')
        {
            num_words++;
            *dest = ' ';
            dest++;
            if (num_words % 3 == 0)
            {
                strcpy(dest, "niinku ");
                dest += 7;
            }
            else if (num_words % 4 == 0)
            {
                strcpy(dest, "totanoin ");
                dest += 9;
            }
            src++;
        }
        else
        {
            *dest = *src;
            src++;
            dest++;
        }
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