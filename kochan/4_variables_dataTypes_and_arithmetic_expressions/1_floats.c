/**
 * 1_floats.c
 * Mon, Jan 10 2022 22:29hrs
 * Displays floating point values
 */
#include <stdio.h>

int main(void)
{
    float value0 = .3, value1 = 1.7e-4, value2 = 2.43e8; // 1.7e-4 is 1.7 x 0.00010

    printf("%f\n%e\n%g\n", value0, value1, value2);

    // Prints a hexadecimal floating point number
    unsigned hex0 = 0x0.3p10;

    printf("%u\n", hex0);

    return 0;
}