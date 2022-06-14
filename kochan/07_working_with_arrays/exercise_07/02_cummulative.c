/** 
 * 02_cummulative.c
 * 
 * Tuesday, June 14 2022 00:25hrs
 * 
 * This program populates each succeding
 * element with the sum of the values of
 * the preceeding elements
 */
#include <stdio.h>

int main(void)
{
    int numbers[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // Computes array size
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // Prints array before change
    for (short i = 0; i < size; i++)
        printf("%i ", numbers[i]);

    putchar('\n');

    for (short i = 0; i < size; i++)
        for (short j = 0; j < i; j++)
            numbers[i] += numbers[j];

    // Prints array after change
    for (short i = 0; i < size; i++)
        printf("%i ", numbers[i]);

    putchar('\n');

    return 0;
}