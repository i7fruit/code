/**
 * 6_triangular_while_loop_0.c
 *
 * Saturday, April 16 2022 12:44hrs
 *
 * Computes the triangular number of a triangle
 * of 200 rows, using a while loop.
 */
#include <stdio.h>

int main(void)
{
    const short rows = 200;

    signed short triangular_number = 0, counter = 1;

    while (counter <= rows)
    {
        triangular_number += counter;
        counter++;
    }

    printf("The 200th triangular number is %hi\n", triangular_number);

    return 0;
}