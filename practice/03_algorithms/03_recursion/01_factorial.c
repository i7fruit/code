/**
 * 01_factorial.c
 *
 * Friday, February 17 2023 23:30hrs
 *
 * The factorial of any number is the product
 * of all the numbers from 1 up to that number.
 * This program uses a recursive function to
 * compute the factorial of any given number
*/
#include <stdio.h>

// Function prototypes
long get_integer(char arr[]);
long factorial(long n);

int main(void)
{
    long number = 0;

    number = get_integer("Number: ");

    printf("%li! = ", number);

    number = factorial(number);

    printf("%li\n", number);

    return 0;
}

/****************************************
 * get_integer() prompts the user for an integer
*/
long get_integer(char arr[])
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

/******************************************
 * factorial()
*/
long factorial(long n)
{
    if (n == 0 || n == 1)
        return 1;

    else
        return factorial(n * (n - 1));
}