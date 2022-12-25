/**
 * 05_replace_string.c
 *
 * Saturday, December 24, 2022 21:48hrs
 *
 * This program scans through a string of
 * characters to identify a substring to
 * be replaced, and replaces that substring
 * with a new string of characters.
 */
#include <stdio.h>

int main(void)
{
    const int size = 64;

    char text[size] = "";
    //char str_to_delete[size] = "";
    //char str_to_insert[size] = "";
    int i;

    for (i = 0; i < 10; i++)
        text[i] = getchar();

    text[--i] = '\0';

    printf("%s\n", text);

    return 0;
}