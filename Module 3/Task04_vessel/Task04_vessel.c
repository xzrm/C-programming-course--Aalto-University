#include <string.h>
#include <stdio.h>
#include <string.h>
#include "source.h"

struct vessel create_vessel(const char *vname, double vlength, double vdepth, struct cargo vcrg)
{

    struct vessel v;
    strncpy(v.name, vname, 30);
    v.name[30] = '\0';

    v.length = vlength;
    v.depth = vdepth;
    v.crg = vcrg;

    printf("%s\n", v.name);
    return v;
}

void print_vessel(const struct vessel *v)
{
    printf("%s\n%.1f\n%.1f\n", v->name, v->length, v->depth);
    printf("%s\n%d\n%.1f\n", v->crg.title, v->crg.quantity, v->crg.weight);
}

int main()
{
    /* testing exercise. Feel free to modify */
    struct cargo c = {"Bananas", 10000, 1500};

    struct vessel v = create_vessel("Apinalaiva", 180, 8.5, c);
    printf("Length of the name: %lu\n", strlen(v.name));

    // shortening the name, if it is very long
    //v.name[19] = 0;

    if (v.length < 1)
        printf("Length is too short!\n");

    if (v.depth > 100)
        printf("Submarines not allowed\n");

    printf("cargo: %s\n", v.crg.title);

    print_vessel(&v);

}
