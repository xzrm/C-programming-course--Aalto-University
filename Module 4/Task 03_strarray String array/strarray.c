#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "strarray.h"

char **init_array(void)
{
	char **str_arr = malloc(sizeof(char *));
	str_arr[0] = NULL;
	return str_arr;
}

void free_strings(char **array)
{
	char **arr_p = array;
	while (*arr_p)
	{
		free(*arr_p);
		arr_p++;
	}

	free(array);
}

char **add_string(char **array, const char *string)
{
	//find number of elements in an array
	unsigned int i = 0;
	char **curr_ptr = array;
	while (*curr_ptr)
	{
		i++;
		curr_ptr++;
	}
	char *str_p = malloc(strlen(string) + 1 * sizeof(char));
	strcpy(str_p, string);
	char **new_arr = realloc(array, (i + 1 + 1) * sizeof(char *));

	new_arr[i] = str_p;
	new_arr[i + 1] = NULL;
	return new_arr;
}

void make_lower(char **array)
{
	while (*array)
	{
		char *s = *array;
		for (unsigned int i = 0; i < strlen(s); i++)
		{
			s[i] = tolower(s[i]);
		}
		//alternatively:
		// while(*s){
		// 	*s= tolower(*s);
		// 	s++;
		// }
		array++;
	}
}

void sort_strings(char **array)
{
	unsigned int size = 0;
	char **curr_ptr = array;
	while (*curr_ptr)
	{
		size++;
		curr_ptr++;
	}

	char **arr = array;
	char *temp;
	for (unsigned int i = 0; i < size; i++)
	{
		// printf(" outer %s and %d\n", *(arr+i), i);
		for (unsigned int j = i; j < size; j++)
		{
			// printf(" inner %s and %d\n", *(arr+j), j);
			if (strcmp(*(arr + i), *(arr + j)) > 0)
			{
				temp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = temp;
			}
		}
	}
}

void print_strings(char **array)
{
	if (!array)
		return;
	while (*array)
	{
		printf("%s  ", *array);
		array++;
	}
	printf("\n");
}