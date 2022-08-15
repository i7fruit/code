/**
 * 04_reading_strings.c
 *
 * Friday, August 12 2022 11:45hrs
 *
 * This program uses the scanf() function
 * to read strings of characters into arrays.
 */
#include <stdio.h>

int main(void)
{
    const int size = 16;

    char string_0[size], string_1[size], string_2[size];

    // Prompts user for input
    printf("Enter three words\n");

    /**
     * The 15 in the scanf() tells the function
     * to read no more than 15 characters into each
     * array. Room is also made for the ASCII-0.
     */
    scanf("%15s%15s%15s", string_0, string_1, string_2);

    printf("%s\n%s\n%s\n", string_0, string_1, string_2);

    return 0;
}