/**
 * 02_greatest_common_divisor_1.c
 *
 * Tuesday, June 14 2022 21:41hrs
 *
 * The greatest common divisor (gcd)
 * of two integers is the greatest
 * integer that can divide them evenly.
 * This program use's Euclid's algorithm
 * to achieve this.
 */
#include <stdio.h>

// Function prototype
void gcd(int u, int v);

int main(void)
{
    int value0, value1;

    printf("Enter two integers to find their gcd\n");
    scanf("%i%i", &value0, &value1);

    gcd(value0, value1);

    return 0;
}

// Function definition
void gcd(int u, int v)
{
    int temp = 0;

    printf("The gcd of %i and %i ", u, v);

    while (v != 0)
    {
        temp = u % v;
        u = v;
        v = temp;
    }

    printf("= %i\n", u);
}