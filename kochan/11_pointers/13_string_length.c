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

int main(void)
{
    char *word = NULL;
    int size = 0;

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

        if (word)
        {
            
        }
    }
}