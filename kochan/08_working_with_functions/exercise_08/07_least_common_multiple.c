/**
 * 07_least_common_multiple.c
 *
 * Saturday, July 09, 2022 22:00hrs
 *
 * The least common multiple of two positive
 * numbers is the smallest number that can be
 * evenly divided by the two numbers.
 *
 * The lcm of u and v can be computed by dividing the
 * product of u * v by the greatest common divisor of u and v
 *
 * lcm = uv / gcd(u,v)
 */
#include <stdio.h>

// Function protocols
int gcd(int u, int v);
int lcd(int u, int v);

int main(void)
{
    int u, v;

    do
    {
        printf("Enter two positive values to find their lcm\n");
        scanf("%i%i", &u, &v);
    }
    while (u < 1 && v < 1);

    printf("The lowest common multiple of %i and %i is ", u, v);

    printf("%i\n", lcd(u, v));

    return 0;
}

/****************************
 * gcd() finds the greatest
 * common divisor between two
 * positve integers
 */
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

/*****************************
 * lcd()
 */
int lcd(int u, int v)
{
    return u * v / gcd(u, v);
}