// #include <stdio.h>
// #include <stdlib.h>

// int main(void) {
//     FILE *f;
//     char buffer[100];

//     f = fopen("test.c", "r"); // open file for reading
//     if (!f) {
//         fprintf(stderr, "Opening file failed\n");
//         return EXIT_FAILURE;
//     }
//     /*
//     char *fgets(char *s, int size, FILE *stream)
//     reads at most size-1 characters to the buffer pointed by s from I/O stream stream. This function is intended for working with text files.
//     The function also reads at most one line, and stops reading if there is a newline character in file (which is included in the buffer).
//      fgets automatically appends '\0' to the end of the buffer. 
//      In other words, fgets is primarily intended to operate with text files that can be converted into strings. 
//     The function pointer to the string that was read, or NULL if we are at the end of file, or if there was a failure in reading.
//    */

//     while (fgets(buffer, sizeof(buffer), f) != NULL) {
//         if (fputs(buffer, stdout) == EOF) {
//             fprintf(stderr, "Error writing to stdout\n");
//             fclose(f);
//             return EXIT_FAILURE;
//         }
//     }
//     fclose(f);
// }

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int numbers[10] = { 1, 0, -2, 3, 10, 4, 3, 2, 3, 9 };
    FILE *fp = fopen("intarray", "w");
    if (!fp) {
        fprintf(stderr, "Could not open file\n");
        return EXIT_FAILURE;
    }
    size_t n = fwrite(numbers, sizeof(int), 10, fp);
    if (ferror(fp)) {
        fprintf(stderr, "Error occurred\n");
        return EXIT_FAILURE;
    }
    fprintf(stdout, "%lu items written\n", n);  // same as printf
    fclose(fp);

    // re-open file for reading, and read the integers
    fp = fopen("intarray", "r");
    int *num2 = malloc(10 * sizeof(int));
    n = fread(num2, sizeof(int), 10, fp);

    // feof indicator should not be set yet, because we did not read
    // past the end of file
    if (feof(fp)) {
        fprintf(stderr, "prematurely reached end of file\n");
        return EXIT_FAILURE;
    } else if (ferror(fp)) {
        fprintf(stderr, "error occurred\n");
        return EXIT_FAILURE;
    }
    fprintf(stdout, "%lu items read\n", n);

    // should not read anything, because we should be at the end of file
    n = fread(num2, sizeof(int), 10, fp);
    if (feof(fp)) {
        fprintf(stdout, "%lu items read, EOF indicator is set\n", n);
    }

    fclose(fp);
    free(num2);
    return EXIT_SUCCESS;
}