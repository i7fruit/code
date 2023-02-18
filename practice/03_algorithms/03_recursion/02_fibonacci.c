/**
 * 02_fibonacci.c
 *
 * Saturday, February 18 2023 00:31hrs
*/
#include <stdio.h>

int fibonacci(int i);

int main(void)
{
    printf("%i\n", fibonacci(6));
}

/*******************************************
 * fibonacci()
*/
int fibonacci(int i)
{
    if (i == 0)
        return 0;

    else if (i == 1)
        return 1;

    else
        return fibonacci(i - 2) + fibonacci(i - 1);
}