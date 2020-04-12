#include <stdlib.h>
#include <stdio.h>

int *join_arrays(int n1, int *arr1, int n2, int *arr2, int n3, int *arr3){
    int n = n1 + n2 + n3;

    int *arrp = malloc(n * sizeof(int));
    if(arrp == NULL){
        return -1;
    }

    int *p = memcpy(arrp, arr1, n1*sizeof(int));
    p = p + n1;
    p = memcpy(p, arr2, n2*sizeof(int));
    p = p + n2;
    p = memcpy(p, arr3, n3*sizeof(int));
    p = p + n3;


    return arrp;




}

int main()
{
    /* testing exercise. Feel free to modify */
    int a1[] = { 1, 2, 3, 4, 5 };
    int a2[] = { 10, 11, 12, 13, 14, 15, 16, 17 };
    int a3[] = { 20, 21, 22 };

    int *joined = join_arrays(5, a1, 8, a2, 3, a3);
//
    for (int i = 0; i < 5 + 8 + 3; i++) {
        printf("%d\n", *joined);
        joined++;
    }
    printf("\n");

    return 0;
}
