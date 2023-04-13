/**
 * 04_newton_raphson_4.c
 *
 * Sunday, July 04 2022 00:41hrs
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
 * 
 * This program is modified so that the square_root() function takes
 * double-precision argument and returns double-precision values.
 */
#include <stdio.h>

// Function prototypes
double get_number(void);
double get_square_root(double number, double epsilon);
double absolute_value(double number);

int main(void)
{
    double value = 0, square_root = 0;

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
    double E = get_number();

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
double get_number(void)
{
    double number = 0;

    scanf("%lf", &number);

    return number;
}

/************************************
 * get_square_root()
 */
double get_square_root(double number, double epsilon)
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
    double guess = 1.0;
    printf("Initial guess = %.10f\n", guess);

    /**
     * Divides the number by the initial value of guess: 1.0, the
     * result of which is added to the same initial value of 1.0,
     * this next result is then divided by 2, to get a new value
     * for guess.
     */
    guess = (number / guess + guess) / 2;

    // Computes the square of the guess
    double square_of_guess = guess * guess;

    /**
     * This while loop terminates when the absolute ratio
     * of the square of the guess and the number for which the
     * user is trying to find its square root, becomes less than the
     * epsilon, E.
     *
     * This while loop executes as long as the comparison between
     * the absolute ratio of guess^2 and the number to which the user
     * wishes to find its square root, and 1, is less than the value of
     * the epsilon. The closer the value of this comparison is to 1, the
     * more accurate the square root approximation.
     */
    while (absolute_value(1 - square_of_guess / number) >= epsilon)
    {
        // Prints result of comparison of the ratio to 1
        double comparison = absolute_value(1 - square_of_guess / number);
        printf("Ratio of guess^2 and number, to 1: %.10f\n", comparison);
        
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
double absolute_value(double number)
{
    if (number < 0)
        number = -(number);

    return number;
}