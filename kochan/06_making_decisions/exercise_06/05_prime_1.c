/** 
 * 05_prime_1.c
 * 
 * Monday, June 06 2022 22:17hrs
 * 
 * Computes prime numbers skipping even numbers
 */
#include <stdio.h>
#include <stdbool.h>

#define LIMIT 20

int main(void)
{
    short x = 0;

    // Prints the first prime number
    printf("Enter first prime: ");
    scanf("%hi", &x);

    for (short i = 3; i < LIMIT; i+= 2)
    {
        bool is_prime = true;

        for (short j = 3; j < i && is_prime; j+= 2)
        {
            if (i % j == 0)
            {
                is_prime = false;
                break;
            }
        }

        if (is_prime)
        {
            printf("%i ", i);
        }
    }

    return 0;
}