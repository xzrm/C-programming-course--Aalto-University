#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(int **arr){
    printf("%d", *(arr + 4));
    *(arr + 4) = 9999;
    printf("%d", *(arr + 4));

}
void main(){
    int A[2][3] = {{1,2, 3}, {66, 4, 9}};
    func(A);
}