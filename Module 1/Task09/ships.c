#include <stdio.h>
#include <stdlib.h>
#include "ships.h"

const unsigned int xsize = 10;
const unsigned int ysize = 10;
const unsigned int shiplen = 3;

/* implement these functions */

/* Task a: Place <num> ships on the game map.
 */
void set_ships(unsigned int num)
{
    unsigned int x;
    unsigned int y;
    unsigned int dir;
    for (int i = 0; i < num; i++)
    {
        while (1)
        {
            x = rand() % 10;
            y = rand() % 10;
            dir = rand() % 2;

            if (place_ship(x, y, dir) == 1)
            {
                break;
            };
        }
    }
}

/* Task b: print the game field
 */
void print_field(void)
{
    for (int y = 0; y < ysize; y++)
    {
        for (int x = 0; x < xsize; x++)
        {
            if (is_visible(x, y) == 0)
            {
                printf("?");
            }
            else
            {
                printf("%c", is_ship(x, y));
            }
        }
        printf("\n");
    }
}

/* Task c: Ask coordinates (two integers) from user, and shoot the location.
 * Returns -1 if user gave invalid input or coordinates, 0 if there was no ship
 * at the given location; and 1 if there was a ship hit at the location.
 */
int shoot(void)
{
    unsigned int x, y;
    char space;
    int ret_x = scanf("%u", &x);
    int ret_space = scanf("%c", &space);
    int ret_y = scanf("%u", &y);

    if (ret_x == 0 || ret_y == 0 || ret_space == 0)
    {
        return -1;
    }

    if (x > xsize || y > ysize)
    {
        return -1;
    }
    checked(x, y);
    if (is_ship(x, y) == '+')
    {
        hit_ship(x, y);
        return 1;
    }
    return 0;
}

/* Task d: Returns 1 if game is over (all ships are sunk), or 0 if there
 * still are locations that have not yet been hit. <num> is the number of
 * ships on the game map. It is assumed to be the same as in the call to
 * set_ships function.
 */
int game_over(unsigned int num)
// this could be also implement by having a global variable int hits = 0; 
// the var would be increased by one when is_ship in function shoot(void) is true
// the game breaks when hits == num * 3
{
    int hits = 0;
    for (int i = 0; i < xsize; i++)
    {
        for (int j = 0; j < ysize; j++)
        {
            if (is_ship(i, j) == '#')
            {
                hits++;
            }
        }
    }
    if (hits == num * 3)
    {
        return 1;
    }
    return 0;
}