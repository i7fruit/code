/** 
 * 04_sieve_of_erastosthenes.c
 * 
 * Tuesday, June 14 2022 18:05hrs
 * 
 * Generates prime numbers using the sieve
 * of erastosthenes
 * 
 * 1. Define an array of integers P. Set all elements P[i] to 0, 2 <= i <= n.
 * 2. Set i to 2.
 * 3. If i > n, the algorithm terminates.
 * 4. If P[i] is 0, then i is prime.
 * 5. For all positive integer values of j, such that i * j <= n, set P[i*j] to 1.
 * 6. Add 1 to i and go to step 3.
 */
#include <stdio.h>

int main(void)
{
    const size = 150;

    // Defines an array P and initializes its elements to 0
    int P[size];
    for (short i = 0; i < size; i++)
        P[i] = 0;

    for (short i = 2; i < size; i++)
    {
        if (P[i] == 0)
        {
            printf("%i ", i);
        }

        for (short j = 0; j < size; j++)
        {
            P[i*j] = 1;
        }
    }

    putchar('\n');

    return 0;
}