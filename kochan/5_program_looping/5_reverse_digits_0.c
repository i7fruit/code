/**
 * 5_reverse_digits_0.c
 * Monday, April 11 2022 23:59hrs
 *
 * This program uses a while loop to
 * print the digits of an integer to
 * the screen in reverse.
 */
#include <stdio.h>

int main(void)
{
    signed number = 0;

    printf("Enter a positive integer to reverse: ");
    scanf("%i", &number);

    // Returns zero if user entered zero
    if (number == 0)
    {
        printf("0\n");
        return 0;
    }

    while (number != 0)
    {
        // Computes last digit and prints it to the screen
        printf("%i", number % 10);

        // Updates the number
        number /= 10;
    }

    printf("\n");

    return 0;
}