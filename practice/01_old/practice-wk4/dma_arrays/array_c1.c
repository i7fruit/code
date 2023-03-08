/**
 * array_c0.c
 *
 * Fri, Sept 21 2018 13:40hrs
 *
 * How to allocate memory for
 * an array of strings
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    /**
     * Declares an array of char pointers
     * to hold three sets of strings
     */
    char *c[3];

    /**
     * Allocates memory space for three sets of strings
     * each capable of being up to 80 characters long
     */
    short i = 0;
    for (; i < 3; i++)
    {
        c[i] = (char *)malloc(sizeof(char) * 81);
        if (c[i] == NULL)
            return -1;
    }

    // Gets input from the user
    for (i = 0; i < 3; i++)
    {
        printf("Enter string set %hi\n", i);
        fgets(c[i], 81, stdin);
    }

    putchar('\n');

    for (i = 0; i < 3; i++)
        printf("%s\n", c[i]);

    for (i = 0; i < 3; i++)
        free(c[i]);

    return 0;
}