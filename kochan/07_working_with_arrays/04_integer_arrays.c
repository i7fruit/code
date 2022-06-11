/** 
 * 04_integer_arrays.c
 * 
 * Friday, June 10 2022 00:48hrs
 * 
 * Illustrates how integer arrays can be initialized.
 */
#include <stdio.h>

#define SIZE 10

int main(void)
{
    // An array of integers
    short numbers[SIZE] = {23, 9, 0, 3};

    // Initializes numbers[5] through numbers[9] to the square of their element numbers
    for (short i = 4; i < SIZE; i++)
        numbers[i] = i * i;

    for (short i = 0; i < SIZE; i++)
        printf("numbers[%hi] = %hi\n", i, numbers[i]);

    return 0;
}