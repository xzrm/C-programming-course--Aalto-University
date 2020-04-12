#include <stdio.h>

void mastermind(const int *solution, const int *guess, char *result, unsigned int len){
    for(int i = 0; i < len; i++){
        result[i] = '-';
        for(int j = 0; j < len; j++){
            if(guess[i] == solution[j]){
                result[i] = '*';
            };
        };
        if(guess[i] == solution[i]){
            result[i] = '+';
            }

        printf("%c", result[i]);
    }
}


int main()
{
    int s[] = {2, 6, 6, 3, 5, 3};
    int g[] = {4, 5, 6, 1, 2, 2};
    int len = sizeof(s)/ sizeof(s[0]);
    printf("len is %d \n", len);
    char r[len];

    mastermind(s, g, r, len);


}
