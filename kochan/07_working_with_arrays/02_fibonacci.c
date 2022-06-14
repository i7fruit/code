/**
 * 02_fibonacci.c
 *
 * Tuesday, June 07 2022 23:20hrs
 *
 * This program generates the first twenty fibonacci numbers.
 */
#include <stdio.h>

int main(void)
{
    // Prompts the user for number of numbers to generate
    int size = 0;

    do
    {
        printf("How many fibonacci numbers do you want to generate? ");
        scanf("%i", &size);
    }
    while (size < 1 || size > 75);

    // Array to store the twenty numbers
    long fibonacci[size];

    for (short i = 0; i < size; i++)
        fibonacci[i] = 0;

    // The first two numbers
    fibonacci[0] = 0, fibonacci[1] = 1;

    // Computes the rest of the series
    for (short i = 2; i < size; i++)
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];

    // Prints the numbers
    for (short i = 0; i < size; i++)
        printf("%li ", fibonacci[i]);

    putchar('\n');

    return 0;
}