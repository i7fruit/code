/** 
 * 10_transpose_0.c
 * 
 * Friday, July 22 2022 17:20hrs
 * 
 * This program takes a 4 x 5 matrix and
 * transposes it to a 5 x 4 matrix.
 */
#include <stdio.h>

// Function prototypes
void print_matrix(int array[][5]);
void transpose_matrix(int array0[][5], int array1[][4]);
void print_transposed_matrix(int array[][4]);

int main(void)
{
    int values0[4][5] =
    {
        {0, 1, 2, 3, 4},
        {5, 6, 7, 8, 9},
        {10, 11, 12, 13, 14},
        {15, 16, 17, 18, 19}
    };

    // Variable to store transposed data
    int values1[5][4];

    for (short i = 0; i < 5; i++)
        for (short j = 0; j < 4; j++)
            values1[i][j] = 0;

    print_matrix(values0);

    transpose_matrix(values0, values1);

    print_transposed_matrix(values1);

    return 0;
}

/**************************************
 * print_matrix()
 */
void print_matrix(int array[][5])
{
    for (short i = 0; i < 4; i++)
    {
        for (short j = 0; j < 5; j++)
            printf("%2i ", array[i][j]);

        putchar('\n');
    }

    putchar('\n');
}

/*************************************
 * transpose_matrix()
 */
void transpose_matrix(int array0[][5], int array1[][4])
{
    for (short i = 0; i < 4; i++)
        for (short j = 0; j < 5; j++)
            array1[j][i] = array0[i][j];
}

/****************************************
 * print_transposed_matrix()
 */
void print_transposed_matrix(int array[][4])
{
    for (short i = 0; i < 5; i++)
    {
        for (short j = 0; j < 4; j++)
            printf("%2i ", array[i][j]);

        putchar('\n');
    }
}
