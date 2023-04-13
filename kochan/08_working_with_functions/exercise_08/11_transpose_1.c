/**
 * 11_transpose_1.c
 *
 * Friday, July 22 2022 21:29hrs
 *
 * This program takes a user-defined m by n matrix,
 * and transposes it.
 */
#include <stdio.h>

// Function prototypes
int get_integer(void);
void fill_array(int r, int c, int array[][c]);
void print_array(int r, int c, int array[][c]);
void zero_out_array(int r, int c, int array[][c]);
void transpose_matrix(int r, int c, int array0[r][c], int array1[c][r]);

int main(void)
{
    int rows = 0, col = 0;

    printf("Rows: ");
    rows = get_integer();

    printf("Columes: ");
    col = get_integer();

    int values[rows][col];

    fill_array(rows, col, values);

    print_array(rows, col, values);

    // For output readability
    putchar('\n');

    // Variable to store transposed data
    int transposed_matrix[col][rows];

    zero_out_array(rows, col, transposed_matrix);

    transpose_matrix(rows, col, values, transposed_matrix);

    // Switch values of col and rows to match rows and columes of the transposed matrix
    print_array(col, rows, transposed_matrix);

    return 0;
}

/*******************************
 * get_integer()
 */
int get_integer(void)
{
    int value = 0;

    do
    {
        scanf("%i", &value);
    }
    while (value < 1 || value > 8);

    return value;
}

/***********************************
 * fill_array()
 */
void fill_array(int r, int c, int array[][c])
{
    int size = r * c;
    int count = 0;

    for (short i = 0; i < r; i++)
        for (short j = 0; j < c; j++, count++)
        {
            printf("Value[%i]: ", count);
            scanf("%i", &array[i][j]);
        }
}

/**************************************
 * print_array()
 */
void print_array(int r, int c, int array[][c])
{
    for (short i = 0; i < r; i++)
    {
        for (short j = 0; j < c; j++)
            printf("%2i ", array[i][j]);

        putchar('\n');
    }
}

/************************************
 * The zero_out_matrix() function stores
 * a zero in every element of the array
 */
void zero_out_array(int r, int c, int array[][c])
{
    for (short i = 0; i < r; i++)
        for (short j = 0; j < c; j++)
            array[i][j] = 0;
}

/*************************************
 * transpose_matrix()
 */
void transpose_matrix(int r, int c, int array0[r][c], int array1[c][r])
{
    for (short i = 0; i < r; i++)
        for (short j = 0; j < c; j++)
            array1[j][i] = array0[i][j];
}