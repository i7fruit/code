/** 
 * 01_integer_division.c
 * 
 * Wednesday, June 01 2022 12:55hrs
 * 
 * This program prints the result to
 * three decimal places, of dividing two integers.
 */
#include <stdio.h>

int main(void)
{
    int value0, value1 = 0;

    printf("Enter two integers: ");
    scanf("%i%i", &value0, &value1);

    if (value1 == 0)
    {
        printf("Cannot divide by zero\n");
        return 1;
    }
    else
    {
        float result = (float)value0 / value1;
        printf("%i / %i = %.3f\n", value0, value1, result);
    }

    return 0;
}