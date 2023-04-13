/**
 * array_b1.c
 *
 * Saturday, September 15 2018 20:58hrs
 *
 * This program prints out the contents
 * of an array declared without a pre-
 * determined size, with non-repetitive
 * values
 */

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(void)
{
    int *array = NULL; // NULL also (int *)0
    short size = 0; // Current size of array

    // Prompts the user for numbers to put in the array
    short i = 0;
    while (true)
    {
        // Gets numbers
        int value = get_int("Enter value %hi: ", i);

        // Checks if user has stopped keying in input with get_int()
        if (value == INT_MAX)
        {
            printf("END\n"); // For formatting
            break;
        }

        // Checks if number exists in the array so far
        bool flag = false;

        for (short j = 0; j < size; j++)
        {
            if (array[j] == value)
            {
                flag = true; // Indicates value is already in the array
                break;
            }
        }

        // If it doesn't exist...


        // ...checks if there's enough space for the number
        if (!flag)
        {
            // If the iterator has reached the end of the array...
            if (i == size)
            {
                // ...creates space for value
                int *tmp = (int *)realloc(array, sizeof(int) * (size + 1));

                if (tmp == (int *)0)
                {
                    fprintf(stderr, "Insufficient memory\n");

                    if (array != NULL)
                        free(array);

                    return -1;
                }
                array = tmp;
                size++;
            }

            array[i] = value;
            i++;
        }
    }

    // Prints the array
    for (short j = 0; j < size; j++)
        printf("%i ", array[j]);

    printf("\n");

    if (array != NULL)
        free(array);

    return 0;
}