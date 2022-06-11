/**
 * 06_base_converter.c
 *
 * Saturday, June 11 2022 11:16hrs
 *
 * This program prompts a user for a number and a base
 * to convert that number to.
 */
#include <stdio.h>

#define SIZE 64

int main(void)
{
    // Base digits
    const char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b',\
    'c', 'd', 'e', 'f'};

    // Array to store digits of converted number. Digits are stored in reverse order
    int converted[SIZE];
    int base = 0, number = 0;

    // Prompts user for input
    do
    {
        printf("Enter a number to convert: ");
        scanf("%i", &number);
    }
    while (number < 0);

    do
    {
        printf("Enter base to convert number to: ");
        scanf("%i", &base);
    }
    while (base < 1);

    if (number == 0)
    {
        printf("0\n");
        return 0;
    }

    int i = 0;

    while (number != 0)
    {
        // Stores converted digits BEFORE increasing index
        converted[i++] = number % base;
        // Resets the number
        number /= base;
    }

    // Prints out the converted digits
    for (--i; i >= 0; i--)
    {
        printf("%c", digits[converted[i]]);
    }

    putchar('\n');

    return 0;
}