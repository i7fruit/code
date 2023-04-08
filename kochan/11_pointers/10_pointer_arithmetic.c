/**
 * 10_pointer_arithmetic.c
 *
 * Saturday, April 08 2023 17:24hrs
 *
 * This program illustrates the use of
 * pointer arithmetic to sum up the values
 * of the elements in an array
*/
#include <stdio.h>

int main(void)
{
    // Array to store values
    int values[] = {1, 2, 8, 2, 7};

    // Length of values array
    const int size = sizeof(values) / sizeof(values[0]);

    // Marks memory location just outside the last element
    int *const end = values + size;

    /**
     * Iterates through the array using pointer arithmetic.
     * The loop iterates though the array iterating the size
     * of the pointer by one. When it reaches the pointer outside
     * the scope of the array, the loop terminates
     */
    for (int *ptr = values; ptr < end; ptr++)
        static int sum += 

    return 0;
}