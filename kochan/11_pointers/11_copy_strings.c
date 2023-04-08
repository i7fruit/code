/**
 * 11_copy_strings.c
 *
 * Saturday, April 08 2023 18:56hrs
 *
 * Uses pointer notation to copy strings
 * to an array
*/
#include <stdio.h>

int main(void)
{
    char text[] = "Copy this string.";

    // Computes length of string to be copied
    int length = sizeof(text) / sizeof(text[0]);

    // Array to store copied string
    char string[length];

    // Iterates through text and copies contents to string
    for (char *ptr = text, *nu = string; *ptr != '\0'; ptr++, nu++)
        *nu = *ptr;

    // Prints the contents of the string array
    for (char *ptr = string; *ptr != '\0'; ptr++)
        printf("%c", *ptr);

    putchar('\n');

    return 0;
}