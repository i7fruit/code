/**
 * array_a1.c
 *
 * Saturday, September 15 2018 20:22hrs
 *
 * This program just declares and populates
 * a regular array of a predetermined size,
 * with non-repetitive values
 */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompts the user for an array size
    short size = 0;

    do
    {
        size = get_int("What's the size of your array?: ");
    }
    while (size < 1);

    int array[size];

    // Prompts the user for input
    short i = 0;
    while (i < size)
    {
        // Gets values from the user
        int value = get_int("Enter value %hi: ", i);

        if (value == INT_MAX)
            break;

        // Checks if value's already in the array
        bool flag = false;

        // Iterates through numbers already in array
        for (short j = 0; j < i; j++)
        {
            if (array[j] == value)
            {
                flag = true;
                break;
            }
        }

        // Adds value to the array if not already included
        if (!flag)
        {
            array[i] = value;
            i++;
        }
    }

    // Prints the array
    for (short j = 0; j < size; j++)
        printf("%i ", array[j]);

    putchar('\n');

    return 0;
}