#include <stdio.h>
#include <math.h>

void multi_table(unsigned int xsize, unsigned int ysize)
{
    int currNum;
    for (int i = 1; i <= ysize; i++)
    {
        for (int j = 1; j <= xsize; j++)
        {
            currNum = i * j;
            printf("%4d", currNum);
        }
        printf("\n");
    }
}

void draw_triangle(unsigned int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(i < size - j - 1){
                printf(".");
            }
            else{
                printf("#");  
            }
        
        }
        printf("\n");
    };
}

double distance(int x, int y, int radius)
{
    return sqrt((x - radius) * (x - radius) + (y - radius) * (y - radius));
}

void draw_ball(unsigned int radius)
{
    double r = radius;
    for (int i = 0; i < 2 * radius + 1; i++)
    {
        for (int j = 0; j < 2 * radius + 1; j++)
        {
            double dist = distance(i, j, r);
            if (dist >= radius)
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

int main(void)
{
    multi_table(10, 5);
    draw_triangle(10);
    draw_ball(10);

}