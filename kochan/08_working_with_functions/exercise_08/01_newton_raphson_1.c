/**
 * 01_newton_raphson_1.c
 *
 * Saturday, July 02 2022 21:59hrs
 *
 * This program uses the Newton Raphson
 * iteration technique to arrive at an
 * approximation of the square root of
 * a number.
 *
 * Here the user gets to pass in different
 * values of Epsilon to see the effect it has
 * on the value of the square root.
 */
#include <stdio.h>

// Function prototypes
float get_number(float number);
float get_square_root(float number);
float absolute_value(float number);

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
    printf("Enter a value to find its square root: ");
    scanf("%f", &number);

    return number;
}

/************************************
 * get_square_root()
 */
float get_square_root(float number)
{
    // Terminates if the number is negative
    if (number < 0)
    {
        printf("Invalid input.\n");
        return -1.0;
    }

    /**
     * Epsilon E, is used to determine when to end
     * the interation process, while the guess variable
     * is the user's initial guess of what the square root
     * is.
     */

    float E = 0000.1, guess = 1.0;

    /**
     * Divides the number by the initial value of guess: 1.0, the
     * result of which is added to the same initial value of 1.0,
     * this next result is then divided by 2, to get a new value
     * for guess.
     */
    guess = (number / guess + guess) / 2;

    // Computes the square of the guess
    float square_of_guess = guess * guess;

    /**
     * This while loop terminates when the absolute difference
     * between the square of the guess and the number for which the
     * user's trying to find its square root, becomes less than the
     * epsilon, E.
     */
    while (absolute_value(square_of_guess - number) >= E)
    {
         // Repeats calculation of guess as above and finds its square.
         guess = (number / guess + guess) / 2;
         square_of_guess = guess * guess;
    }

    return guess;
}

/*****************************************
 * absolute_value()
 */
float absolute_value(float number)
{
    if (number < 0)
        number = -(number);

    return number;
}