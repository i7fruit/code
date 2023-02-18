/**
 * 02_fibonacci.c
 *
 * Saturday, February 18 2023 00:31hrs
*/
#include <stdio.h>

int get_integer(char arr[]);
int fibonacci(int i);

int main(void)
{
    int number = get_integer("Fibonacci number: ");

    printf("%i\n", fibonacci(number));
}

/****************************************
 * get_integer() prompts the user for an integer
*/
int get_integer(char arr[])
{
    int i = 0;

    do
    {
        printf("%s", arr);
        scanf("%i", &i);
    }
    while (i < 0 || i > 20);

    return i;
}

/*******************************************
 * The fibonacci() function returns the sum of
 * the previous two fibonacci numbers. The first
 * two numbers are defined to be 0 and 1.
*/
int fibonacci(int i)
{
    if (i == 0)
        return 0;

    else if (i == 1)
        return 1;

    // Returns the sum of the last two values
    return fibonacci(i - 2) + fibonacci(i - 1);
}