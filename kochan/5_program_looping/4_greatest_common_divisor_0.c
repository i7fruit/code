/**
 * 4_greatest_common_divisor_0.c
 *
 * Monday, April 11 2022 19:59hrs
 *
 * The greatest common divisor (gcd)
 * of two integers is the greatest
 * integer that can divide them evenly.
 * This program use's Euclid's algorithm
 * to achieve this.
 */
#include <stdio.h>

int main(void)
{
    short temp, u, v;
    temp = u = v = 0;

    printf("Enter two integers to find their gcd\n");
    scanf("%hi%hi", &u, &v);

    printf("The gcd of %hi and %hi = ", u, v);

    while (v != 0)
    {
        temp = u % v;
        u = v;
        v = temp;
    }

    printf("%hi\n", u);

    return 0;
}