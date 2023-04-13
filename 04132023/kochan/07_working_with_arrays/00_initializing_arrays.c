/**
 * 00_initializing_arrays.c
 * 
 * Tuesday, June 07 2022 20:13hrs
 * 
 * Illustrates how arrays are initialized.
 */
#include <stdio.h>

#define SIZE 10

int main(void)
{
    // Declares an array of ten elements
    short values[SIZE];

    values[0] = 197;
    values[2] = -100;
    values[5] = 350;
    values[3] = values[0] + values[5];
    values[9] = values[5] / 10;
    values[2]--;

    // Prints values in the array
    for (short i = 0; i < SIZE; i++)
        printf("values[%i] = %hi\n", i, values[i]);

    return 0;
}