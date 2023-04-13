/**
 * 6_triangular_while_loop_0.c
 *
 * Saturday, April 16 2022 12:50hrs
 *
 * Computes a table of triangular numbers of
 * 1 through 10 using a while loop.
 */
#include <stdio.h>

int main(void)
{
    const short rows = 10;

    signed short triangular_number = 0, counter = 1;

    printf("Table of triangular numbers 1 - 10\n");
    printf("Number     Triangular number\n");
    printf("----------------------------\n");

    while (counter <= rows)
    {
        triangular_number += counter;
        printf("%2hi %10hi\n", counter, triangular_number);
        counter++;
    }

    return 0;
}