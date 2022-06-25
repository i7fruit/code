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

// Function prototype
void display_matrix(int m, int n, int arr[][n]);

int main(void)
{
    int sample_matrix[ROW][COLUME] =
    {
        {7, 16, 55, 13, 12},
        {12, 10, 52, 0, 7},
        {-2, 1, 2, 4, 9}
    };

    display_matrix(ROW, COLUME, sample_matrix);

    return 0;
}

/**********************************
 * The display_matrix() function uses
 * a nested forloop to print the contents
 * of the array to standard output.
 */
void display_matrix(int m, int n, int arr[][n])
{
    for (short i = 0; i < m; i++)
    {
        for (short j = 0; j < n; j++)
            printf("%2i ", arr[i][j]);

        putchar('\n');
    }
}