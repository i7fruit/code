/** 
 * 06_arrays_as_arguments.c
 * 
 * Wednesday, June 22, 2022 01:30hrs
 * 
 * This program illustrates how arrays
 * can be arguments to a function.
 */
#include <stdio.h>

#define SIZE 10

// Function prototype
int minimum(int arr[SIZE]);

int main(void)
{
    // An array that holds ten integer values
    int values[SIZE];

    printf("Enter ten integers\n");

    for (short i = 0; i < SIZE; i++)
        scanf("%i", &values[i]);

    // Finds the smallest value
    int min = minimum(values);

    printf("Mininum value is %i\n", min);

    return 0;
}

/************************************
 * minimum()
 */
int minimum(int arr[SIZE])
{
    int min = arr[0];

    for (short i = 1; i < SIZE; i++)
    {
        if (min > arr[i])
            min = arr[i];
    }

    return min;
}