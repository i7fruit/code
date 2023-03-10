/**
 * 03_swap.c
 *
 * Friday, March 10 2023 12:39hrs
 *
 * Swaps the values of two variables
 */
#include <stdio.h>

// Function prototype
void swap(int *a, int *b);

int main(void)
{
    int x = 1, y = 2;

    printf("x = %i, y = %i\n", x, y);

    swap(&x, &y);

    printf("x = %i, y = %i\n", x, y);

    return 0;
}

/**************************************
 * swap()
*/
void swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;

    *b = temp;

}