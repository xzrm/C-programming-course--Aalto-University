#include <stdio.h>


int array_sum(int *arr, int count){
    int sum = 0;

    for(int i=0; i < count; i++){
        sum = sum + *arr;
        arr++;
    }
    return sum;
}

int main(void)
{
    int valarray[] = {10, 100, 1000};
    int ret = array_sum(valarray, 3);
    printf("%d", ret);
}