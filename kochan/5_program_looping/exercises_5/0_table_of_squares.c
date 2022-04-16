/**
 * 0_table_of_squares.c
 *
 * Tuesday, April 12 2022 17:47hrs
 *
 * This program prints a table of squares
 */
#include <stdio.h>

int main(void)
{
    printf("TABLE OF SQUARES\n");
    printf("-----------------\n");
    printf("  x      x^2\n");
    for (short i = 1; i <= 100; i++)
    {
        printf("%3i   %5i\n", i, (i * i));
    }

    return 0;
}