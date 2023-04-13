/**
 * 05_power_of.c
 *
 * Tuesday, July 05 2022 00:42hrs
 *
 * This program computes the value
 * of an integer raised to the power
 * of another integer.
 */
#include <stdio.h>

// Function prototype
int get_integer(void);
long int power_function(int x, int y);

int main(void)
{
    printf("Enter number: ");
    int number = get_integer();

    printf("Enter power: ");
    int power = get_integer();

    printf("%i^%i = %li\n", number, power, power_function(number, power));

    return 0;
}

/*******************************
 * get_integer()
 */
int get_integer(void)
{
    int number = 0;

    scanf("%i", &number);

    return number;
}

/*******************************
 * power()
 */
long int power_function(int x, int y)
{
    int temp = 1;

    if (y == 0)
        return 1;

    else if (y == 1)
        return x;

    else
    {
        for (short i = 0; i < y; i++)
            temp *= x;
    }

    return temp;
}