/**
 * 04_ascending_sort.c
 * Sunday, July 02, 23:57hrs
 *
 * This program sorts three integers
 * in ascending order without using
 * an array.
 */

#include <stdio.h>

int main(void)
{
    short a = 3, b = 1, c = 8;

    if (a < b)
    {
       if (a < c)
           printf("%i ", a);
        else
            printf("%i %i %i\n", c, a, b);
    }
    else if (b < a)
    {
        if (b < c)
            printf("%i ", b);
        else
            printf("%i %i %i\n", c, b, a);
    }
    else if (c < a)
    {
        if (c < b)
            printf("%i ", c);
        else
            printf("%i %i %i\n", b, c, a);
    }

    return 0;
}