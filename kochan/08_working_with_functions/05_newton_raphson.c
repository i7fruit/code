/**
 * 05_newton_raphson.c
 *
 * Saturday, June 18 2022 21:49hrs
 *
 * This program uses the Newton Raphson
 * iteration technique to arrive at an
 * approximation of the square root of
 * a number.
 */
#include <stdio.h>

// Function prototypes
int get_integer(int number);

int main(void)
{
    int value = 0, square_root = 0;

    // Prompts the user for a number to find its square root
    value = get_integer(value);

    printf("The square root of %i is ");

    square_root = get_square_root(value);

    printf("%i\n", square_root);

    return 0;
}

/***********************************
 * get_integer()
 */
int get_integer(int number)
{
    do
    {
        printf("Enter a non-negative value to find its square root: ");
        scanf("%i", &number);
    }
    while (number < 0);

    return number;
}