#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "election.h"

struct votes *read_votes(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        return NULL;
    }

    unsigned int count_lines = 0;
    char name[40];
    while (fgets(name, sizeof(name), fp) != NULL)
    {
        count_lines++;
    }
    
    struct votes **votes_arr = malloc(sizeof(struct votes *) * count_lines);
    // struct votes *p_votes_arr = malloc(sizeof(*votes_arr[count_lines]));
    // struct votes *p_votes_arr = calloc(count_lines, sizeof(struct votes *));
    unsigned int arr_idx = 0;

    rewind(fp);
    while (fgets(name, sizeof(name), fp) != NULL)
    {
        if (arr_idx > 0)
        {
            struct votes *new_vote = malloc(sizeof(struct votes));
            char *p_name = malloc(sizeof(char) * 40);
            char *d = strcpy(p_name, name);
            memcpy(new_vote->name, d, 40);
            new_vote->votes = 1;
            *(votes_arr + arr_idx) = new_vote;
            printf("%s", votes_arr[arr_idx]->name);
            arr_idx++;
        }
        else
        {
            struct votes *new_vote = malloc(sizeof(struct votes));
            char *p_name = malloc(sizeof(char) * 40);
            char *d = strcpy(p_name, name);
            memcpy(new_vote->name, d, 40);
            new_vote->votes = 1;
            *(votes_arr + arr_idx) = new_vote;
            printf("%s", votes_arr[arr_idx]->name);
            arr_idx++;
        }
    }

    return NULL;
}