/**
 * 2_nested_forloop.c
 * Wednesday April 6, 2022 23:17hrs
 * Illustrates nested for loops
 */
#include <stdio.h>

int main(void)
{
    unsigned short triangular_number = 0;
    short row = 0, frequency = 5;

    // Prompts the user for input five times
    for (short i = 0, j = 1; i < frequency; i++, j = 1, triangular_number = 0)
    {
        printf("What triangular number would you like to find? ");
        scanf("%hi", &row);

        // Computes the triangular number by adding values from j through row.
        for (; j <= row; j++)
            triangular_number += j;

        printf("Triangular number %hi is %hu.\n", row, triangular_number);
    }

    return 0;
}