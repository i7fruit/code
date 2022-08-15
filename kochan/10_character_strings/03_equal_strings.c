/**
 * 03_equal_strings.c
 *
 * Friday, August 12, 2022 00:41hrs
 *
 * This program uses a while loop to iterate
 * through the elements of two arrays, comparing
 * the characters in each element to see if they
 * are equal or not.
 */
#include <stdio.h>

_Bool equal_strings(const char arr_0[], const char arr_1[]);

int main(void)
{
    // Strings to compare
    const char word_0[] = "Welcome";
    const char word_1[] = "Welcome";

    if (equal_strings(word_0, word_1))
        printf("Both strings are the same.\n");

    else
        printf("Both strings ARE NOT the same.\n");

    return 0;
}

/***********************************************************
 * The equal_strings() functions compares each character in
 * two different arrays for equality. The function returns a
 * 1 if both strings of text are equal, and 0 if they are not.
 */
_Bool equal_strings(const char arr_0[], const char arr_1[])
{
    short i = 0;

    while (arr_0[i] == arr_1[i] && arr_0[i] != '\0')
        i++;

    if (arr_0[i] == '\0' && arr_1[i] == '\0')
        return 1;

    return 0;
}