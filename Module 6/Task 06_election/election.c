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
    char name[40];
    char *p_newline;
    unsigned int unique_names = 0;
    unsigned int unique_name;

    struct votes *votes_arr = malloc(unique_names * sizeof(struct votes));

    while (fgets(name, sizeof(name), fp) != NULL)
    {
        if ((p_newline = strchr(name, '\n')) != NULL)
            *p_newline = '\0';

        unique_name = 1;
        for (unsigned int i = 0; i <= unique_names; i++)
        {
            if (strcmp(name, votes_arr[i].name) == 0)
            {
                votes_arr[i].votes++;
                // printf("name: %s, votes: %d \n", votes_arr[i].name, votes_arr[i].votes);
                unique_name = 0;
                break;
            }
        }
        if (unique_name == 1)
        {

            unique_names++;
            struct votes new_vote;
            votes_arr = realloc(votes_arr, unique_names * sizeof(struct votes));

            char *p_name = malloc(sizeof(char) * 40);
            strcpy(p_name, name);
            memcpy(new_vote.name, p_name, 40);
            new_vote.votes = 1;

            votes_arr[unique_names - 1] = new_vote;
            // printf("ADDED: unique name: %s, votes: %d\n", new_vote.name, new_vote.votes);
        }
    }

    votes_arr = realloc(votes_arr, (unique_names + 1) * sizeof(struct votes));
    struct votes last;
    last.name[0] = '\0';
    votes_arr[unique_names] = last;

    fclose(fp);

    return votes_arr;
}

int compare(const void *a, const void *b)
{
    const struct votes *vote1 = a;
    const struct votes *vote2 = b;

    // first compare the last names

    int diff = vote2->votes - vote1->votes;
    if (diff != 0)
        return diff;
    else
        return strcmp(vote1->name, vote2->name);
}

void results(struct votes *vlist)
{

    int len = 0;
    struct votes *dummy_ptr = vlist;
    while (*(dummy_ptr->name) != '\0')
    {
        dummy_ptr++;
        len++;
    }
    // printf("%d", len);

    qsort(vlist, len, sizeof(struct votes), compare);
    for (int i = 0; i < len; i++)
    {
        struct votes *ptr = vlist + i;
        printf("name: %s, votes: %d\n", ptr->name, ptr->votes);
    }
}