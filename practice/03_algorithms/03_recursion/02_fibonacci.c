/**
 * 02_fibonacci.c
 *
 * Saturday, February 18 2023 00:31hrs
*/
#include <stdio.h>

int fibonacci(int i);

int main(void)
{
    printf("%i\n", fibonacci(3));
}

/*******************************************
 * fibonacci()
*/
int fibonacci(int i)
{
    if (i == 1)
        return 0;

    else if (i == 2)
        return 1;

    return fibonacci(i + (i - 1));
}