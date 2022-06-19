/**
 * 7_polynomial.c
 * Tue, Jan 18, 2022 23:01hrs
 * 
 * Evaluates 3x3 - 5x2 + 6
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
    float x = 2.25;

    float y = (3 * pow(x, 3)) - (5 * pow(x, 2)) + 6;

    printf("3x3 - 5x2 + 6 = %.2f where x = %.2f\n", y, x);

    return 0;
}