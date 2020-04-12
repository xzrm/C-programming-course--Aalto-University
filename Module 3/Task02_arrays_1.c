#include <stdio.h>
#include <stdlib.h>

int* dyn_reader(int n){
    int *arr;
    arr = malloc(n * sizeof(int));
    if(arr == NULL){
        printf("returning");
        return -1;
    }

    int val;
    int ret_a;
    int i = 0;
    do{
        ret_a = scanf("%d", &val);
        if(ret_a == 1){
            arr[i] = val;
            i++;
        }
        else {
            return -1;
        }
    }while(i < n);

    return arr;
}

int* add_to_array(int *arr, int num, int newval){
    int *new_arr;
    new_arr = realloc(arr, (num + 1) * sizeof(int));
    if(!new_arr){
        free(arr);
        return -1;
    }
    new_arr[num] = newval;
    printf("Value %d",  new_arr[num]);
    return new_arr;
}


void main()
{
    int n = 5;
    int *arr = dyn_reader(n);
    int i = 0;
    int *new_arr;

//    while(i < n){
//        printf("Value %d\n", *arr);
//        arr++;
//        i++;
//    }
    new_arr = add_to_array(arr, n, 9);
    n++;
    new_arr = add_to_array(new_arr, n, 10);
    n++;
    new_arr = add_to_array(new_arr, n, 11);

    while(i < n+1){
        printf("Value %d\n", *new_arr);
        new_arr++;
        i++;
    }


    free(*new_arr);

}
