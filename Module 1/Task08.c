#include <stdio.h>
#include <ctype.h>

void ascii_chart(char min, char max) {
    int counter = 1;
    for (int i = min; i <= max; i++) {
        if (isprint(i))
            printf("%3d 0x%x %c", i, i, i);
        else
            printf("%3d 0x%x ?", i, i);
        if (counter++ % 4 == 0)
            printf("\n");
        else
            printf("\t");
    }
}

int main(void)
{
    ascii_chart(28, 50);
    // int a = isprint(36);
    // printf("%d", a);
}