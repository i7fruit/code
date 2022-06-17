/**
 * 04_absolute_1.c
 *
 * Friday, June 17 2022 01:03hrs
 *
 * This program prints out the absolute
 * value of a floating-point number to standard output
 */
#include <stdio.h>

float absolute_val(float f);

int main(void)
{
    float value = 0;

    printf("Enter a floating-point value: ");
    scanf("%f", &value);

    printf("The absolute value of %.2f is ", value);

    float result = absolute_val(value);

    printf("%.2f\n", result);

    return 0;
}

/*************************************
 * absolute_val() function
 */
float absolute_val(float f)
{
    if (f < 0)
        return -(f);
    else
        return f;
}