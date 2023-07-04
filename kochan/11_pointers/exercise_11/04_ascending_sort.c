/**
 * 04_ascending_sort.c
 *
 * Tuesday, July 04, 2023 14:16hrs
 *
 * This program sorts three numbers
 * in ascending order without the use
 * of arrays
*/
#include <stdio.h>

// Function prototypes
void swap(int *ptr0, int *ptr1);

int main(void)
{
    // Variables to store three integers
    int a = 1, b = 2, c = 0;

    // First finds smallest number
    if (a > b)
    {
        // Switches values
        swap(a, b);
        if (a > c)
        {
            swap(a, c);
            if (c > b)
            {
                swap(c, b);
            }
        }
    }
}

/************************************
 * The swap() function swaps two
 * values
*/
void swap(int *ptr0, int *ptr1)
{
    int temp = *ptr0;
    *ptr0 = *ptr1;
    *ptr1 = temp;
}