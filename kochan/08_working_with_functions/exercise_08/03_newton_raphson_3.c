/**
 * 03_newton_raphson_3.c
 *
 * Sunday, July 03 2022 21:01hrs
 *
 * This program uses the Newton Raphson
 * iteration technique to arrive at an
 * approximation of the square root of
 * a number.
 *
 * In addition to being able to pass in
 * different values for Epsilon, the value
 * of guess is also printed each time through
 * the while loop showing how quickly the value
 * of guess converges to the square root.
 *
 * For a more accurate approximation of the square root,
 * it is better to compare the ratio of guess^2 and x to 1
 * inside the condition of the while loop. The closer the ratio
 * gets to 1, the more accurate the approximation of the square root.
 * This change is suitable for calculating the square root of very
 * large or very small numbers.
 */
#include <stdio.h>

// Function prototypes
float get_number(void);
float get_square_root(float number, float epsilon);
float absolute_value(float number);

int main(void)
{
    float value = 0, square_root = 0;

    // Prompts the user for a number to find its square root
    printf("Enter number to find its square root: ");
    value = get_number();

    /**
     * Prompts the user to enter a value for Epsilon
     *
     * Epsilon E, is used to determine when to end
     * the interation process, while the guess variable
     * is the user's initial guess of what the square root
     * is.
     */
    printf("Enter a value for Epsilon: ");
    float E = get_number();

    square_root = get_square_root(value, E);

    if (square_root != -1.0 && square_root != -2.0)
        printf("Square root of %.10f = %.10f\n", value, square_root);
    else
        printf("%.1f\n", square_root);

    return 0;
}

/***********************************
 * get_number()
 */
float get_number(void)
{
    float number = 0;

    scanf("%f", &number);

    return number;
}

/************************************
 * get_square_root()
 */
float get_square_root(float number, float epsilon)
{
    // Terminates if the number is negative
    if (number < 0)
    {
        printf("Invalid input for value.\n");
        return -1.0;
    }

    // Terminates if epsilon is less than one
    if (epsilon <= 0)
    {
        printf("Invalid input for epsilon\n");
        return -2.0;
    }

    // The initial guess at the square root
    float guess = 1.0;
    printf("Initial guess = %.10f\n", guess);

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
    while (absolute_value(square_of_guess - number) >= epsilon)
    {
        // Tracks number of iterations
        static short iteration;

        // Repeats calculation of guess as above and finds its square.
         guess = (number / guess + guess) / 2;
         square_of_guess = guess * guess;

         // Prints out values of guess with each iteration
         printf("Iteration %i Guess = %20.10f\n", iteration + 1, guess);
         iteration++;
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