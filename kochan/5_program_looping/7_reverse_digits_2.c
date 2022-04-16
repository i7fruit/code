/**
 * 7_reverse_digits_2.c
 * Tuesday, April 12 2022 00:30hrs
 *
 * This program uses a do-while loop to compute
 * the reverse of the digits of an integer.
 */
#include <stdio.h>

int main(void)
{
    signed number = 0;

    do
    {
        printf("Enter a positive integer to reverse: ");
        scanf("%i", &number);
    } while (number == 0);

    signed reversed_digits = 0;

    while (number != 0)
    {
        // Computes last digit and saves it to the reversed_digits variable
        int x = number % 10;
        reversed_digits = reversed_digits * 10 + x;

        // Updates the number
        number /= 10;
    }

    printf("%i\n", reversed_digits);

    return 0;
}