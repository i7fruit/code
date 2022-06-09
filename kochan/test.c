#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int primes[10];

    bool is_prime;

    primes[0] = 2;
    primes[1] = 3;

    int i = 1;

    for (int p = 5; p < 10; p += 2)
    {
        is_prime = true;

        for (int j = 1; is_prime && p / primes[j] >= primes[j]; i += 1)
        {
            if (p % primes[j] == 0)
                is_prime = false;
        }

        if (is_prime)
        {
            primes[++i] = p;
        }
    }

    return 0;
}