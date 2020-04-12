#include <stdio.h>
#include <ctype.h>

int array_reader(int *vals, int n)
{
    int i = 0;
    int j;
    while(scanf("%d", &j) == 1 && i < n){
        vals[i] = j;
        i++;
    }
    return i;
}

int main(void)
{
    int array[10];
    int n = array_reader(array, 10);
    printf("%d numbers read\n", n);
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}

