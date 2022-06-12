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
        {},
        {},
        {}
    };

    return 0;
}