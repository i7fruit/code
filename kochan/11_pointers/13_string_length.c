/**
 * 13_string_length.c
 *
 * Friday, April 14 2023 00:17hrs
 *
 * This program finds the length of a
 * string by finding the difference between
 * the the pointer value of the last element
 * of the string, and the first element of the
 * string
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void)
{
    char *word = NULL;
    int size = 0;

    printf("Enter a string\n");

    while (true)
    {
        char c = getchar();

        if (c == '\n')
            break;

        char *nu = realloc(word, (sizeof(char) * (size + 1)));
        if (!nu)
        {
            fprintf(stderr, "Insufficient memory\n");
            if (word)
                free(word);

            return 1;
        }

        word = nu;

        word[size] = c;
        size++;
    }

    // Terminates the string
    word[size] = '\0';

    // Computes the length of the string
    char *ptr = word;
    while (*ptr != '\0')
        ptr++;

    // Finds difference between pointer at end and pointer at start or string
    printf("%p -", ptr);
    printf(" %p\n", word);

    int length = ptr - word;

    printf("The length of \"%s\" is %i\n", word, length);

    free(word);

    return 0;
}