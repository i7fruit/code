/**
 * 1_triangular_number_table.c
 * Sat, Apr 2 2022 12:53hrs
 *
 * Prints a table of triangular numbers
 */
#include <stdio.h>

int main(void)
{
    short triangular_number = 0;
    const short limit = 20;

    printf("TABLE OF TRIANGULAR NUMBERS FROM 1 THROUGH 20\n");
    printf("Number          Triangular Number\n");
    printf("---------------------------------------------\n");

    for (short i = 1; i <= limit; i++)
    {
        triangular_number += i;
        printf("%2hi         %3hi\n", i, triangular_number);
    }

    return 0;
}