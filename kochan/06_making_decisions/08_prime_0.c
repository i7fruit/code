/**
 * 08_prime_0.c
 *
 * Tuesday, May 31 2022 22:10hrs
 *
 * Computes prime numbers by checking to see
 * if a number p, is divisible by any number
 * from 2 through p-1.
 */
#include <stdio.h>

#define LIMIT 1000

int main(void)
{
    for (short i = 2; i <= LIMIT; i++)
    {
        _Bool is_prime = 1;

        for (short j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                is_prime = 0;
                break;
            }
        }

        if (is_prime)
            printf(" %hi", i);
    }
    putchar('\n');

    return 0;
}