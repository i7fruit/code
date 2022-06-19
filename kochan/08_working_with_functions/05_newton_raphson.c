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
float get_number(float number);
float get_square_root(float number);

int main(void)
{
    float value = 0, square_root = 0;

    // Prompts the user for a number to find its square root
    value = get_number(value);

    printf("The square root of %.3f is ", value);

    square_root = get_square_root(value);

    printf("%.3f\n", square_root);

    return 0;
}

/***********************************
 * get_number()
 */
float get_number(float number)
{
    do
    {
        printf("Enter a non-negative value to find its square root: ");
        scanf("%f", &number);
    }
    while (number < 0);

    return number;
}

/************************************
 * get_square_root()
 */
float get_square_root(float number)
{
    // Epsilon
    float E = 0000.1, guess = 1.0;

    float square_of_guess = guess * guess;

    while (square_of_guess - number >= E)
    {
         guess = (number / guess + guess) / 2;
    }

    return guess;
}