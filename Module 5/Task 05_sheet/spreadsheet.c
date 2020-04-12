#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <float.h>
#include "spreadsheet.h"

#include "spreadsheet.h"

const struct {
    char *name;
    double (*fptr)(Sheet *, Point, Point);
} functions[] = {
    { "sum", sumfunc},
    { "max", maxfunc},
    { "count", countfunc},
    { NULL, NULL}
};


Sheet *create_sheet(unsigned int xsize, unsigned int ysize)
{
    Sheet *sheet;
    sheet = malloc(sizeof(Sheet));

    sheet->xsize = xsize;
    sheet->ysize = ysize;

    //allocates memory to array of Cell pointers = rows
    sheet->cells = malloc(ysize * sizeof(Cell *));

    if (!sheet->cells)
        return NULL; // memory allocation failed

    for (int j = 0; j < ysize; j++)
    {
        sheet->cells[j] = malloc(xsize * sizeof(Cell));
        if (!sheet->cells[j])
        {
            // memory allocation failed, release memory
            // will have to go through previously allocated rows
            for (int i = 0; i < j; i++)
            {
                free(sheet->cells[i]);
            }
            free(sheet->cells);
            return NULL;
        }

        for (int i = 0; i < xsize; i++)
        {
            Cell cell;
            cell.type = UNSPEC;
            sheet->cells[j][i] = cell;
        }
    }
    return sheet;
}

void free_sheet(Sheet *sheet)
{
    unsigned int ysize = sheet->ysize;

    for (int j = 0; j < ysize; j++)
    {
        free(sheet->cells[j]);
    }
    free(sheet->cells);
    free(sheet);
}

Cell *get_cell(Sheet *sheet, Point p)
{
    unsigned int idx = p.x;
    unsigned int idy = p.y;

    if (idx < sheet->xsize && idy < sheet->ysize)
    {
        return &sheet->cells[idy][idx];
    }
    else
    {
        return NULL;
    }
}

void set_value(Sheet *sheet, Point p, double value)
{
    Cell *cell = get_cell(sheet, p);
    if (cell == NULL)
    {
        return;
    }
    cell->type = VALUE;
    cell->un.value = value;
}

void set_func(Sheet *sheet, Point p,
              double (*func)(Sheet *, Point, Point),
              Point ul, Point dr)
{
    Cell *cell = get_cell(sheet, p);
    if (cell == NULL)
    {
        return;
    }
    cell->type = FUNC;
    Func f;
    f.upleft = ul;
    f.downright = dr;
    f.fptr = func;
    cell->un.func = f;
}

double eval_cell(Sheet *sheet, Point p)
{
    Cell *cell = get_cell(sheet, p);
    if (cell == NULL)
    {
        return NAN;
    }
    Celltype type = cell->type;

    switch (type)
    {
    case VALUE:
        return cell->un.value;
    case UNSPEC:
        return NAN;
    case FUNC:
        return cell->un.func.fptr(sheet, cell->un.func.upleft, cell->un.func.downright);
    }
    return NAN;
}

double maxfunc(Sheet *sheet, Point ul, Point dr)
{
    double max_val = 0;
    double val;
    for (unsigned int i = ul.y; i <= dr.y; i++)
    {
        for (unsigned int j = ul.x; j <= dr.x; j++)
        {
            if (i < sheet->ysize && j < sheet->xsize)
            {
                Point p = {i, j};
                val = eval_cell(sheet, p);
                if (val != NAN && val > max_val)
                    max_val = val;
            }
        }
    }
    return max_val;
}

double sumfunc(Sheet *sheet, Point ul, Point dr)
{
    double sum = 0;
    double val;
    for (unsigned int i = ul.y; i <= dr.y; i++)
    {
        for (unsigned int j = ul.x; j <= dr.x; j++)
        {
            if (i < sheet->ysize && j < sheet->xsize)
            {
                Point p = {i, j};
                val = eval_cell(sheet, p);
                if (!isnan(val))
                    sum += val;
            }
        }
    }
    return sum;
}

double countfunc(Sheet *sheet, Point ul, Point dr)
{
    double count = 0;
    for (unsigned int i = ul.y; i <= dr.y; i++)
    {
        for (unsigned int j = ul.x; j <= dr.x; j++)
        {
            if (i < sheet->ysize && j < sheet->xsize)
            {
                Point p = {i, j};
                Cell *cell = get_cell(sheet, p);
                if (cell->type != UNSPEC)
                {
                    count++;
                }
            }
        }
    }
    return count;
}

/* Convert two-letter user input into coordinates of type Point.
 */
Point get_point(char xc, char yc)
{
    Point p;
    p.x = toupper(xc) - 'A';
    p.y = toupper(yc) - 'A';
    return p;
}

/* Parses user input in <command> and applies it in spreadsheet <sheet>.
 * Returns 1 if input was valid, or 0 if it was not.
 */
int parse_command(Sheet *sheet, const char *command)
{
    double val;
    Point p;
    char xc, yc;
    int ret = sscanf(command, "%c%c %lf", &xc, &yc, &val);
    if (ret == 3)
    {
        p = get_point(xc, yc);
        set_value(sheet, p, val);
        return 1;
    }

    char func[10];
    Point ul, dr;
    char xc1, yc1, xc2, yc2;

    ret = sscanf(command, "%c%c %9s %c%c %c%c", &xc, &yc, func, &xc1, &yc1, &xc2, &yc2);
    if (ret == 7)
    {
        p = get_point(xc, yc);
        ul = get_point(xc1, yc1);
        dr = get_point(xc2, yc2);
        int i = 0;
        while (functions[i].name)
        {
            if (!strcmp(functions[i].name, func))
            {
                set_func(sheet, p, functions[i].fptr, ul, dr);
                return 1;
            }
            i++;
        }
    }
    return 0;
}

/* Prints the content of given spreadsheet.
 */
void print_sheet(Sheet *sheet)
{
    printf("%-8c", ' ');
    for (unsigned int x = 0; x < sheet->xsize; x++)
    {
        printf("%-8c", 'A' + x);
    }
    fputs("\n", stdout);

    for (unsigned int y = 0; y < sheet->ysize; y++)
    {
        printf("%-8c", 'A' + y);
        for (unsigned int x = 0; x < sheet->xsize; x++)
        {
            Point p;
            p.x = x;
            p.y = y;
            Cell *c = get_cell(sheet, p);
            switch (c->type)
            {
            case VALUE:
            case FUNC:
                printf("%-8.1f", eval_cell(sheet, p));
                break;

            default:
                printf("%-8c", '*');
                break;
            }
        }
        fputs("\n", stdout);
    }
}