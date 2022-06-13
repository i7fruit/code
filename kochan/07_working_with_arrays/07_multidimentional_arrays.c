/**
 * 07_multidimentional_arrays.c
 *
 * Saturday, June 11 2022 22:35hrs
 *
 * This program illustrates how a multidimentional
 * array is declared and initialized in C.
 */
#include <stdio.h>

int main(void)
{
    /**
     * Declares and initializes a two-dimentional array
     * with two rows and three columes.
     */
    int values[2][3] =
    {
        {1, 2, 3},
        {4, 5, 6}
    };

    // Prints 6
    printf("%i\n", values[1][2]);

    // Three-dimentional array
    int numbers[3][2][4] =
    {
        {{1, 2, 3, 4}, {5, 6, 7, 8}},
        {{9, 10, 11, 12}, {13, 14, 15, 16}},
        {{17, 18, 19, 20}, {21, 22, 23, 24}}
    };

    // Prints 13
    printf("%i\n", numbers[1][1][0]);

    // Some array elements can be left uninitialized
    int values[4][5] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (short i = 0; i < 4; i++)
        for (short j = 0; j < 5; j++)
            printf("%i ", values[i][j]);

    return 0;
}