/**
 * 0_triangular_number.c
 * Tuesday, March 29 2022 18:19hrs
 *
 * This program calculates the triangular
 * number of a triangle containing n rows.
 *
 * A triangular number is the number of dots it
 * takes to draw a triangle of n rows. It is the
 * sum of the numbers from 1 through n.
 */

#include <stdio.h>

int main(void)
{
    short rows = 0;
    // Prompts the user for input
    printf("Enter number of rows: ");
    scanf("%hi", &rows);

    unsigned short triangular_number = 0;
    unsigned short space = rows - 1;

    // Computes triangular number
    for (short i = 1; i <= rows; i++)
    {
        triangular_number += i;

        // Prints spaces before stars
        for (short j = 0; j < space; j++)
        {
            printf(" ");
        }

        // Prints a star and a space equal to the row number
        short k = 0;
        while (k < i)
        {
            printf("* ");
            k++;
        }
        printf("\n");

        // Decreases prefix spaces as rows increase
        space -= 1;
    }

    printf("%hu\n", triangular_number);

    return 0;
}