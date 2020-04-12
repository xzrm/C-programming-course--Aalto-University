#include <stdio.h>
#include <stdlib.h>
#include "polisher.c"


int main(void)
{
    char *code = read_file("test_file.c");
    if (!code) {
        printf("No code read");
        return -1;
    }


    printf("\n-- Original:\n");
    fputs(code, stdout);
    code = remove_comments(code);
    printf("\n-- Comments removed:\n");
    fputs(code, stdout);


    // code = indent(code, "    ");
    // printf("-- After indenting:\n");
    // fputs(code, stdout);
   
    // free(code);

    // char str[10];
    // *str = 'a';
    // printf("%s", str);
}