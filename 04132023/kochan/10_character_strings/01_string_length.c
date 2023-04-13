/**
 * 01_string_length.c
 *
 * Wednesday, August 10 2022 11:46hrs
 *
 * This program iterates through an array of
 * characters while updating a counter variable
 * by 1 to determine the number of characters in the
 * array. The counting stops when the program encounters
 * a binary 0 '\0' character in the array.
 */
#include <stdio.h>

// Function prototypes
int string_length(const char arr[]);

int main(void)
{
    char word[] = {'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!', '\0'};

    printf("String length is %i\n", string_length(word));

    return 0;
}

/****************************************************************************
 * string_length()
 */
int string_length(const achar arr[])
{
    short i = 0;

    while (arr[i] != '\0')
        i++;

    return i;
}