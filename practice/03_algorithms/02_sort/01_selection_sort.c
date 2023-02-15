/**
 * 01_selection_sort.c
 *
 * Tuesday, February 14 2023 18:45hrs
 *
 * This program iterates through an array of
 * values to find the lowest value and places
 * it in its proper element. It repeats this
 * process for each subsequent smallest value
 * until the array is completely sorted.
*/
#include <stdio.h>

int main(void)
{
    // Array size
    int size = 7;

    int arr[] = {1, 129, 4, 3, 2, 5, 0};

    // Loops through the array
    for (int i = 0; i < size; i++)
    {
        // Sets array element with assumed smallest value
        int min = i;

        // Loops though the elements comparing their values with the assumed smallest
        for (int j = i + 1; j < size; j++)
        {
            // Sets a new element as that with the smallest value if new smallest value found in said element
            if (arr[min] > arr[j])
                min = j;
        }

        /**
         *  If after iterating through array, the element with the smallest value
         * is not the same as the initial element with the smallest value, swap
         * the contents of these elements
         */
        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }

    // Prints the sorted array
    for (int k = 0; k < size; k++)
        printf("%i ", arr[k]);
}