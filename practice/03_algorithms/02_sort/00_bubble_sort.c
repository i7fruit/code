/**
 * 00_bubble_sort.c
 *
 * Tuesday, February 14 2023 18:30hrs
 *
 * This program iterates through an array
 * of values comparing two adjacent values
 * and swapping them to arranging them in
 * a specific order. The sorting is completed
 * when there are no more swaps made.
*/
#include <stdio.h>

int main(void)
{
    // Array size
    int size = 7;

    int arr[] = {1, 129, 4, 3, 2, 5, 0};
    
    int counter = -1;

    do
    {
        // Sets up a counter to track number of swaps
        counter = 0;

        // Iterates from the first to the second to last element
        for (int i = 0, j = 1; i < size - 1; i++, j++)
        {
            // Compares two adjacent values and swaps them if out of order
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] =  temp;
                counter++;
            }
        }
    }
    while (counter > 0); // Iterates through the array again if any swaps occurred

    // Prints the sorted array
    for (int i = 0; i < size; i++)
        printf("%i ", arr[i]);

    putchar('\n');

    return 0;
}