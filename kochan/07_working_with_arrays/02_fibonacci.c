/** 
 * 02_fibonacci.c
 * 
 * Tuesday, June 07 2022 23:20hrs
 * 
 * This program generates the first twenty fibonacci numbers.
 */
#include <stdio.h>

#define SIZE 20

int main(void)
{
    // Array to store the twenty numbers
    int fibonacci[SIZE];

    for (short i = 0; i < SIZE; i++)
        fibonacci[i] = 0;

    // The first two numbers
    fibonacci[0] = 0, fibonacci[1] = 1;

    // Computes the rest of the series
    for (short i = 2; i < SIZE; i++)
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];

    // Prints the numbers
    for (short i = 0; i < SIZE; i++)
        printf("%i ", fibonacci[i]);

    putchar('\n');

    return 0;
}