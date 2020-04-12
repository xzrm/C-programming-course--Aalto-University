#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "gameoflife.h"

Field *createField(unsigned int xsize, unsigned int ysize)
{
    Field *field = malloc(sizeof(Field));

    field->xsize = xsize;
    field->ysize = ysize;
    field->cells = malloc(ysize * sizeof(State *));
    for (unsigned int i = 0; i < ysize; i++)
    {
        field->cells[i] = malloc(xsize * sizeof(State));
        {
            for (unsigned int j = 0; j < xsize; j++)
            {
                field->cells[i][j] = DEAD;
            }
        }
    }

    return field;
}

void releaseField(Field *f)
{
    for (unsigned int i = 0; i < f->ysize; i++)
    {
        free(f->cells[i]);
    }
    free(f->cells);
    free(f);
}

void initField(Field *f, unsigned int n)
{
    unsigned int i = 0;
    while (i < n)
    {
        unsigned int x = rand() % f->xsize;
        unsigned int y = rand() % f->ysize;
        if (f->cells[y][x] != ALIVE)
        {
            // printf("%d, %d, %d\n", x, y, i);
            f->cells[y][x] = ALIVE;
            i++;
        }
    }
}

void printField(const Field *f)
{
    for (unsigned int i = 0; i < f->ysize; i++)
    {
        for (unsigned int j = 0; j < f->xsize; j++)
        {
            if (f->cells[i][j] == DEAD)
            {
                printf(".");
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
    }
}

unsigned int get_living_neighbors(Field f, int x, int y)
{
    unsigned int count = 0;

    for (int i = y - 1; i <= y + 1; i++)
    {
        for (int j = x - 1; j <= x + 1; j++)
        {
            if (i == y && j == x)
            {
                continue;
            }
            if (i < 0 || i >= f.ysize)
            {
                continue;
            }
            if (j < 0 || j >= f.xsize)
            {
                continue;
            }

            if (f.cells[i][j] == ALIVE)
            {
                count++;
                // printf("%d, %d \n", i,j);
            }
            
        }
        
    }
    
    return count;
}

void tick(Field *f)
{
    Field curr_field;
    State **curr_state;
    curr_state = malloc(f->ysize * sizeof(State *));
    for (unsigned int i = 0; i < f->ysize; i++)
    {
        curr_state[i] = malloc(f->xsize * sizeof(State));
        memcpy(curr_state[i], f->cells[i], f->xsize * sizeof(State));
    }

    curr_field.cells = curr_state;
    curr_field.ysize = f->ysize;
    curr_field.xsize = f->xsize;

    for (unsigned int i = 0; i < f->ysize; i++)
    {
        for (unsigned int j = 0; j < f->xsize; j++)
        {
            unsigned int alive_cells = get_living_neighbors(curr_field, j, i);
            // printf("%d, %d, %d\n", i,j, alive_cells);
            if (curr_state[i][j] == ALIVE && (alive_cells < 2 || alive_cells > 3))
            {
                f->cells[i][j] = DEAD;
            }
            else if (curr_state[i][j] == DEAD && alive_cells == 3)
            {
                f->cells[i][j] = ALIVE;
            }
        }
    }

    for (unsigned int i = 0; i < f->ysize; i++)
    {
        free(curr_state[i]);
    }
    free(curr_state);
}



