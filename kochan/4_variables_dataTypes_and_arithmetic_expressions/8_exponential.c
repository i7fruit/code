/**
 * 8_exponential.c
 * Tue, Jan 18, 2022 23:09hrs
 * 
 * Evaluates (3.31 x 10-8 x 2.01 x 10-7) / (7.16 x 10-6 + 2.01 x 10-8)
 */
#include <stdio.h>

int main(void)
{
    float x = (3.31 * 10e-8) * (2.01 * 10e-7);
    float y = (7.16 * 10e-6) + (2.01 * 10e-8);

    float z = x / y;

    printf("%.3g\n", z);

    return 0;
}