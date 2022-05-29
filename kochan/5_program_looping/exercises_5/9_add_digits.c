/*
 * 9_add_digits.c
 *
 * Sunday, May 29 2022 09:30hrs
 *
 * This program gets a positive integer
 * from a user and computes the sum of its
 * individual digits.
 */
#include <stdio.h>

int main(void)
{
    unsigned short digits = 0;

    // Prompts user for input
    do
    {
        printf("Please enter a positive integer between" \
    " 1 and 60000\n");
        scanf("%hu", &digits);
    }
    while (digits > 60000 || digits < 0);

    printf("The sum of digits in %hu is ", digits);

    // Computes sum of digits
    unsigned short sum = 0;

    while (digits > 0)
    {
        sum += (digits % 10);

        digits /= 10;
    }

    printf("%hu\n", sum);

    return 0;
}