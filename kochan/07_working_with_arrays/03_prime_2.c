/** 
 * 03_prime_2.c
 * 
 * Wednesday, June 08 2022 12:34hrs
 * 
 * This program generates prime numbers
 * and stores them in an array.
 */
#include <stdio.h>
#include <stdbool.h>

#define SIZE 20

int main(void)
{
    short primes[SIZE];
    short index = 2;

    // Saves the first two prime numbers
    primes[0] = 2, primes[1] = 3;

    /** 
     * A number is prime if it is not evenly divisible by
     * any previously generated prime. Any non-prime integer n,
     * has as one of its factors an integer that is less than
     * or equal to the square root of n. Therefore it is only necessary
     * to check if an integer is prime by checking for even divisibilty with
     * all prime numbers up to the square root of the integer
     */

    for (short p = 5; p < SIZE; p += 2)
    {
        bool is_prime = true;

        /** 
         * p / primes[i] >= primes[i] tests to make sure that
         * primes[i] is not greater than the square root of p
         */
        
        for (short j = 1; is_prime && (p / primes[j] >= primes[j]); j++)
        {
            /** 
             * Sets the prime flag to false if the integer
             * is evenly divisible by any previously generated
             * prime number.
             */

            if (p % primes[j] == 0)
            {
                is_prime = false;
            }
        }

        if (is_prime)
        {
            primes[index] = p;
            index++;
        }
    }

    // Prints contents of the primes[] array up to the last index
    for (short i = 0; i < index; i++)
        printf("%hi ", primes[i]);

    return 0;
}