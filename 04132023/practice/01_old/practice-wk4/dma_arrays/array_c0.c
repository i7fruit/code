/**
 * array_c0.c
 *
 * Fri, Sept 21 2018 13:29hrs
 *
 * How to allocate memory for
 * an array of characters
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Allocates memory to store twenty characters
    char *c = (char *)malloc(sizeof(char) * 20);
    if (c == NULL)
    {
        fprintf(stderr, "Insufficient memory\n");
        return -1;
    }

    puts("Enter string of text");
    c = fgets(c, 20, stdin);
    printf("%s\n", c);

    free(c);

    return 0;
}