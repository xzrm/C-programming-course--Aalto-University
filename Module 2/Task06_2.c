#include <stdio.h>
#include <string.h>

int count_substr(const char *str, const char *sub){

    char *p;
    int counter = 0;
    while(p = strstr(str, sub)){
        counter ++;
        str = p + 1;
        p = strstr(str, sub);
    }
    return counter;
}

int main()
{
    int a = count_substr("one aaaa two one twotwo three twotwotwo", "one");
    printf("%d", a);


}
