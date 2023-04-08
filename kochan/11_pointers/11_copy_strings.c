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
    for (char *ptr = text, *ptr != '\0'; ptr++, &string++)
        *string = *ptr;

    // Prints contents of newly copied array
    for (char *ptr = string; ptr != (char *)0; ptr++)
        printf("%c", *ptr);

    return 0;
}