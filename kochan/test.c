#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int primes[10];

    bool is_prime;

    primes[0] = 2;
    primes[1] = 3;

    int i = 0;

    for (int p = 5; p < 10; p += 2)
    {
        is_prime = true;

        for (i = 1; is_prime && p / primes[i] >= primes[i]; i += 1)
        {
            if (p % primes[i] == 0)
                is_primes = false;
        }

        if (is_prime)
        {
            
        }
    }
}