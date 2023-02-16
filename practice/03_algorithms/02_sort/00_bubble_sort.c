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
        counter = 0;

        for (int i = 0, j = 1; i < size - 1; i++, j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] =  temp;
                counter++;
            }
        }
    }
    while (counter > 0);

    for (int k = 0; k < size; k++)
        printf("%i ", arr[k]);

    return 0;
}