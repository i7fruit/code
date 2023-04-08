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

    int length = sizeof(text) / sizeof(text[0]);

    char string[length];

    for (char *ptr = text; ptr != '\0'; ptr++)
        *(string
}