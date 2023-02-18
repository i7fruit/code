/**
 * 03_collatz_conjecture.c
 *
 * Saturday, February 18 2023 12:08hrs
 *
 * The collatz conjecture applies to positive integers
 * and speculates that it's always possible to get back to 1
 * following the steps before
 *
 * if n == 1, stop
 * else if n is even, repeat operation on n/2
 * else if n is odd, repeate operation on 3n + 1
*/
#include <stdio.h>

// Function prototype
long long get_integer(char arr[]);
short collatz(int n);

int main(void)
{
    short count = 0, n = 0;

    n = get_integer("n: ");

    count = collatz(n);

    printf("%hi step%s\n", count, count>1?"s.":".");
}

/****************************************
 * get_integer() prompts the user for an integer
*/
long long get_integer(char arr[])
{
    long i = 0;

    do
    {
        printf("%s", arr);
        scanf("%li!", &i);
    }
    while (i < 1 || i > 20);

    return i;
}

/*************************************************
 * collatz()
*/
short collatz(int n)
{
    static short count = 0;

    if (n == 1)
        return count;

    else if (n % 2 == 0)
    {
        count++;
        return count + collatz(n / 2);
    }

    count++;
    return count + collatz(3 * n + 1);
}