/**
 * 03_insertion_sort.c
 *
 * Thursday, February 16 2023 22:43hrs
 *
 * This program iterates through an array
 * comparing values in its sorted and unsorted
 * parts and shifting the values into the right
 * order.
*/
#include <stdio.h>

int main(void)
{
    const short size = 7;

    int values[] = {1, 129, 4, 3, 2, 5, 0};

    /**
     * Iterates through the array considering the first element
     * as sorted, and the rest of the array as unsorted
     */
    for (int i = 0; i < size; i++)
    {

        int j = i;

        /**
         * Iterates through each element of the unsorted part of the array
         * and shifting that value into the right position in the sorted
         * part of the array
        */
        while (j > 0)
        {
            if (values[j] < values[j - 1])
            {
                int temp = values[j];
                values[j] = values[j - 1];
                values[j - 1] = temp;
            }

            j--;
        }
    }

    // Prints the sorted array
    for (int i = 0; i < size; i++)
        printf("%i ", values[i]);

    putchar('\n');
}