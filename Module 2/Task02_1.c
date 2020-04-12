#include <stdio.h>

void number_swap(int *p1, int *p2){
    int temp_val1;
    int temp_val2;

    temp_val1 = *p1;
    temp_val2 = *p2;

    *p2 = temp_val1;
    *p1 = temp_val2;

}

int main(void)
{
    int val1 = 4;
    int val2 = 5;
    number_swap(&val1, &val2);
    if (val1 == 5 && val2 == 4)
    {
        printf("Great, it worked!\n");
    }

}
