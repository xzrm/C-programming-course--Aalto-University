#include <stdio.h>
#include <stdlib.h>
#include "strarray.c"

int main(void)
{
    char **strings = init_array();
    
    strings = add_string(strings, "oNe");
    strings = add_string(strings, "TWO");
    strings = add_string(strings, "zzzz");
    strings = add_string(strings, "three");
    strings = add_string(strings, "Four");
    strings = add_string(strings, "aaaaa");
    strings = add_string(strings, "tahree");
    
    // print_strings(strings);
    
    make_lower(strings);
    print_strings(strings);
    sort_strings(strings);
    
    print_strings(strings);
    free_strings(strings);
    
    return EXIT_SUCCESS;




}