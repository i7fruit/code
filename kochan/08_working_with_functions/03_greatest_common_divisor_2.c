/**
 * 03_greatest_common_divisor_2.c
 *
 * Wednesday, June 15 2022 22:25hrs
 *
 * The greatest common divisor (gcd)
 * of two integers is the greatest
 * integer that can divide them evenly.
 * This program use's Euclid's algorithm
 * to achieve this.
 *
 * The gcd() function returns an integer
 * to the main() function.
 */
#include <stdio.h>

// Function prototype
int gcd(int u, int v);

int main(void)
{
    int value0, value1;

    printf("Enter two integers to find their gcd\n");
    scanf("%i%i", &value0, &value1);

    printf("The gcd of %i and %i is ", value0, value1);

    printf("%i\n", gcd(value0, value1));

    return 0;
}

// Function definition
int gcd(int u, int v)
{
    int temp = 0;



    while (v != 0)
    {
        temp = u % v;
        u = v;
        v = temp;
    }

    return u;
}