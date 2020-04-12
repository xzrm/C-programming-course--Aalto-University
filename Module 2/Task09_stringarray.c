#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Print string array, last element is NULL */

/* Parameters:
 * array: string array to be printed, each string on own line */
void print_strarray(char *array[])
{
    while (*array != NULL)
    {
        printf("%s\n", *array);
        array++;
    }
}

void str_to_strarray(char *str, char **arr)
{
    int i = 0;
    int j = 0;
    while (*str)
    {
        if (*str == ' ')
        {
            arr[i][j] = '\0';
            j = 0;
            i++;
        }
        else
        {
            arr[i][j] = *str;
            j++;
        };
        str++;
    }
    arr[i][j] = '\0';
    arr[i+1] = NULL;
}

int main()
{

    char *strings[] = {"Paasikivi", "Kekkonen", "Koivisto",
                       "Ahtisaari", "Halonen", NULL};

    // print_strarray(strings);

    char string[] = "Test string, that is different";
    char **arr = malloc(sizeof(char *) * 6);

    // Save pointers for later use
    char **save = arr, **begin = arr;

    for (int i = 0; i < 5; i++)
        arr[i] = malloc(10);
    arr[5] = NULL;

    // Test b.
    str_to_strarray(string, arr);
    print_strarray(arr);

    // Free array
    while (*save)
    {
        free(*save);
        save++;
    }
    free(begin);

    return 0;
}