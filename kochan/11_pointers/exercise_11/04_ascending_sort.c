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

    // Checks a
    if (a > b)
    {
        // Switches values
        swap(&a, &b);
        if (a > c)
        {
            swap(&a, &c);
            if (c > b)
            {
                swap(&c, &b);
                printf("%i %i %i\n", c, b, a);
            }
        }
    }

    // Checks b
    if (b > a)
    {
        // Switches values
        swap(&b, &a);
        if (b > c)
        {
            swap(&b, &c);
            if (c > a)
            {
                swap(&c, &a);
                printf("%i %i %i\n", c, a, b);
            }
        }
    }

    // Checks c
    if (c > a)
    {
        // Switches values
        swap(&c, &a);
        if (c > b)
        {
            swap(&c, &b);
            if (b > a)
            {
                swap(&b, &a);
                printf("%i %i %i\n", a, b, c);
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