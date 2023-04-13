/**
 * 3_operators.c
 * Illustrates the use of
 * arithmetic operators in C
 */
#include <stdio.h>

int main(void)
{
    short value0 = 100, value1 = 2, value2 = 25, value3 = 4;

    // Addition
    printf("%hi + %hi = %i\n", value0, value1, value0 + value1);

    // Subtraction
    printf("%hi - %hi = %i\n", value1, value2, value1 - value2);

    // Integer Division
    printf("%hi / %hi = %i\n", value2, value3, value2 / value3);

    // Modulo Division
    printf("%hi %% %hi = %i (Modulo division)\n", value2, value3, value2 % value3);

    // Multiplication
    printf("%hi * %hi = %i\n", value1, value2, value1 * value2);

    // Illustrates operator precedence
    printf("%hi + %hi * %hi = %i\n", value0, value1, value2, value0 + value1 * value2);

    printf("%hi * %hi + %hi * %hi = %i\n", value0, value1, value2, value3, value0 * value1 + value2 * value3);

    return 0;
}