#include <stdio.h>

void sort(int *start, int size){
    int temp;
    for(int i = 0; i < size; i++){
        for(int j = i; j < size; j++){
            if(start[j] < start[i]){
                temp = start[i];
                start[i] = start[j];
                start[j] = temp;
			}

		}
	}
}

int main()
{
    int arr[] = {9, 4, 3, 1, 8,2};
    int size = sizeof(arr) / sizeof(arr[0]);
    sort(arr, size);

    for(int i = 0; i < size; i++){
        printf("%d", arr[i]);
    }
}
