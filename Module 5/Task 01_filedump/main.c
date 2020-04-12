#include <stdio.h>
#include <string.h>
#include "fileread.c"


int main(void)
{
    if (textdump("test.c") == -1) {
        if (textdump("test.c") == -1) {
            fprintf(stderr, "Could not open main.c\n");
        }
    }
    
    printf("\n");
    
    if (hexdump("test.c") == -1) {
        if (hexdump("test.c") == -1) {
            fprintf(stderr, "Could not open main.c\n");
        }
    }

}