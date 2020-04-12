#include <stdio.h>
#include <ctype.h>

int count_alpha(const char *str){
    int count = 0;
    while(*str){
        if(isalpha(*str)){
            count++;
        }
        str++;
    }
    return count;
}


int main()
{
    char *str = "How many alpha in this string?";
    printf("count_alpha: %d\n", count_alpha(str));
}
