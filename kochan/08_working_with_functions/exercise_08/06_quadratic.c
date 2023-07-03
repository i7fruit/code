/**
 * 06_quadratic.c
 *
 * Tuesday, July 05 2022 16:01hrs
 *
 * This program solves a quadratic equation.
 */
#include <stdio.h>

// Global variables for roots
double x1, x2;

// Function prototypes
void find_roots(double a, double b, double c);
double discriminant(double a, double b, double c);
double get_square_root(double number, double epsilon);
double absolute_value(double number);

int main(void)
{
    double a = 0, b = 0, c = 0;

    printf("𝑎𝑥² + 𝑏𝑥 + 𝑐\n");

    printf("Enter Values for 𝑎, 𝑏, and 𝑐 for the quadratic equation above\n");
    scanf("%lf%lf%lf", &a, &b, &c);

    find_roots(a, b, c);

    double discriminant_result = discriminant(a, b, c);

    if (discriminant_result < 0)
    {
        printf("%lf and %lf are imaginary\n", x1, x2);
        return -1;
    }

    printf("x1 = %lf\nx2 = %lf\n", x1, x2);

    return 0;
}

/*********************************
 * find_roots()
 */
void find_roots(double a, double b, double c)
{
    double epsilon = 0.00001;

    double discriminant = (b * b) - (4 * a * c);

    x1 = (-b + get_square_root(discriminant, epsilon)) / (2 * a);

    x2 = (-b - get_square_root(discriminant, epsilon)) / (2 * a);
}

/********************************
 * discriminant_result()
 */
double discriminant(double a, double b, double c)
{
    return b * b - (4 * a * c);
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
    // printf("Initial guess = %.10f\n", guess);

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
        // double comparison = absolute_value(1 - square_of_guess / number);
        // printf("Ratio of guess^2 and number, to 1: %.10f\n", comparison);

        // Tracks number of iterations
        static short iteration;

        // Repeats calculation of guess as above and finds its square.
        guess = (number / guess + guess) / 2;
        square_of_guess = guess * guess;

        // Prints out values of guess with each iteration
        // printf("Iteration %i Guess = %20.10f\n", iteration + 1, guess);
        iteration++;
    }

    return guess;
}