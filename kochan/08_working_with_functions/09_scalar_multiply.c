/**
 * 09_scalar_multiply.c
 *
 * Saturday, June 25 2022 12:49hrs
 *
 * This program illustrates how a multidimentional
 * array can be used as an argument to a function.
 */
#include <stdio.h>

#define ROW 3
#define COLUME 5
#define SCALAR 4

// Function prototype
void display_matrix(int arr[ROW][COLUME]);
void scalar_matrix(int arr[ROW][COLUME], int s);

int main(void)
{
    int sample_matrix[ROW][COLUME] =
    {
        {7, 16, 55, 13, 12},
        {12, 10, 52, 0, 7},
        {-2, 1, 2, 4, 9}
    };

    display_matrix(sample_matrix);
    putchar('\n');

    scalar_matrix(sample_matrix, SCALAR);

    display_matrix(sample_matrix);

    return 0;
}

/**********************************
 * The display_matrix() function uses
 * a nested forloop to print the contents
 * of the array to standard output.
 */
void display_matrix(int arr[ROW][COLUME])
{
    for (short i = 0; i < ROW; i++)
    {
        for (short j = 0; j < COLUME; j++)
            printf("%2i ", arr[i][j]);

        putchar('\n');
    }
}

/**************************************
 * The scalar_matrix() function, takes
 * an array argument and multiplies the
 * value in each of the elements in the
 * array, by a scalar number earlier
 * specified.
 */
void scalar_matrix(int arr[ROW][COLUME], int s)
{
    for (short i = 0; i < ROW; i++)
        for (short j = 0; j < COLUME; j++)
            arr[i][j] *= SCALAR;
}