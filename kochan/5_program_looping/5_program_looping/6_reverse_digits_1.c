/**
 * 6_reverse_digits_1.c
 * Tuesday, April 12 2022 00:15hrs
 *
 * This program uses a while to save
 * the digits of an integer to a variable
 * in reverse order
 */
#include <stdio.h>

int main(void)
{
    signed number = 0;

    printf("Enter a positive integer to reverse: ");
    scanf("%i", &number);

    signed reversed_digits = 0;

    while (number != 0)
    {
        // Computes last digit and saves it to the reversed_digits variable
        reversed_digits = reversed_digits * 10 + (number % 10);

        // Updates the number
        number /= 10;
    }

    printf("%i\n", reversed_digits);

    return 0;
}